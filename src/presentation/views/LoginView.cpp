#include "LoginView.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QApplication>

LoginView::LoginView(IAuthService* authService, QWidget *parent)
    : QWidget(parent), m_authService(authService) {
    setupUi();
}

void LoginView::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("MyTrainer - Login", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; margin-bottom: 20px;");
    mainLayout->addWidget(titleLabel);

    QFormLayout* formLayout = new QFormLayout();
    
    m_emailInput = new QLineEdit(this);
    m_emailInput->setPlaceholderText("Enter your email");
    formLayout->addRow("Email:", m_emailInput);

    m_passwordInput = new QLineEdit(this);
    m_passwordInput->setPlaceholderText("Enter your password");
    m_passwordInput->setEchoMode(QLineEdit::Password);
    formLayout->addRow("Password:", m_passwordInput);

    mainLayout->addLayout(formLayout);

    m_errorLabel = new QLabel("", this);
    m_errorLabel->setStyleSheet("color: red;");
    m_errorLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(m_errorLabel);

    m_loginButton = new QPushButton("Login", this);
    mainLayout->addWidget(m_loginButton);

    QPushButton* exitBtn = new QPushButton("Exit Program", this);
    exitBtn->setStyleSheet("background-color: darkred; color: white; font-weight: bold; margin-top: 10px;");
    mainLayout->addWidget(exitBtn);

    connect(m_loginButton, &QPushButton::clicked, this, &LoginView::onLoginClicked);
    connect(exitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(m_passwordInput, &QLineEdit::returnPressed, this, &LoginView::onLoginClicked);
}

void LoginView::onLoginClicked() {
    QString email = m_emailInput->text();
    QString password = m_passwordInput->text();

    if (email.isEmpty() || password.isEmpty()) {
        m_errorLabel->setText("Please enter both email and password.");
        return;
    }

    auto userOpt = m_authService->login(email, password);
    if (userOpt.has_value()) {
        m_errorLabel->setText("");
        emit loginSuccessful(userOpt.value());
    } else {
        m_errorLabel->setText("Invalid credentials. Please try again.");
    }
}
