#include "RegisterTrainerView.h"
#include <QVBoxLayout>
#include <QFormLayout>

RegisterTrainerView::RegisterTrainerView(IUserService* userService, QWidget *parent)
    : QWidget(parent), m_userService(userService) {
    setupUi();
}

void RegisterTrainerView::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("Register Personal Trainer", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; margin-bottom: 20px;");
    mainLayout->addWidget(titleLabel);

    QFormLayout* formLayout = new QFormLayout();
    
    m_emailInput = new QLineEdit(this);
    formLayout->addRow("Email:", m_emailInput);

    m_passwordInput = new QLineEdit(this);
    m_passwordInput->setEchoMode(QLineEdit::Password);
    formLayout->addRow("Password:", m_passwordInput);

    m_specialtiesInput = new QLineEdit(this);
    formLayout->addRow("Specialties:", m_specialtiesInput);

    mainLayout->addLayout(formLayout);

    m_statusLabel = new QLabel("", this);
    m_statusLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(m_statusLabel);

    m_registerButton = new QPushButton("Register Trainer", this);
    mainLayout->addWidget(m_registerButton);

    m_backButton = new QPushButton("Back to Dashboard", this);
    mainLayout->addWidget(m_backButton);

    connect(m_registerButton, &QPushButton::clicked, this, &RegisterTrainerView::onRegisterClicked);
    connect(m_backButton, &QPushButton::clicked, this, &RegisterTrainerView::onBackClicked);
}

void RegisterTrainerView::onRegisterClicked() {
    QString email = m_emailInput->text();
    QString password = m_passwordInput->text();
    QString specialties = m_specialtiesInput->text();

    if (m_userService->registerTrainer(email, password, specialties)) {
        m_statusLabel->setStyleSheet("color: green;");
        m_statusLabel->setText("Trainer registered successfully!");
        m_emailInput->clear();
        m_passwordInput->clear();
        m_specialtiesInput->clear();
    } else {
        m_statusLabel->setStyleSheet("color: red;");
        m_statusLabel->setText("Failed to register. Email may already exist or fields are empty.");
    }
}

void RegisterTrainerView::onBackClicked() {
    emit backRequested();
}
