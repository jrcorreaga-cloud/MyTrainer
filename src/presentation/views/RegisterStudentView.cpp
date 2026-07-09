#include "RegisterStudentView.h"
#include <QVBoxLayout>
#include <QFormLayout>

RegisterStudentView::RegisterStudentView(IAdminService* adminService, QWidget *parent)
    : QWidget(parent), m_adminService(adminService) {
    setupUi();
}

void RegisterStudentView::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("Register New Student", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; margin-bottom: 20px;");
    mainLayout->addWidget(titleLabel);

    QFormLayout* formLayout = new QFormLayout();
    
    m_emailInput = new QLineEdit(this);
    formLayout->addRow("Email:", m_emailInput);

    m_passwordInput = new QLineEdit(this);
    m_passwordInput->setEchoMode(QLineEdit::Password);
    formLayout->addRow("Password:", m_passwordInput);

    mainLayout->addLayout(formLayout);

    m_statusLabel = new QLabel("", this);
    m_statusLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(m_statusLabel);

    m_registerButton = new QPushButton("Register Student", this);
    mainLayout->addWidget(m_registerButton);

    m_backButton = new QPushButton("Back to Dashboard", this);
    mainLayout->addWidget(m_backButton);

    connect(m_registerButton, &QPushButton::clicked, this, &RegisterStudentView::onRegisterClicked);
    connect(m_backButton, &QPushButton::clicked, this, &RegisterStudentView::onBackClicked);
}

void RegisterStudentView::onRegisterClicked() {
    QString email = m_emailInput->text();
    QString password = m_passwordInput->text();

    if (m_adminService->registerStudent(email, password)) {
        m_statusLabel->setStyleSheet("color: green;");
        m_statusLabel->setText("Student registered successfully!");
        m_emailInput->clear();
        m_passwordInput->clear();
    } else {
        m_statusLabel->setStyleSheet("color: red;");
        m_statusLabel->setText("Failed to register. Email may already exist or fields are empty.");
    }
}

void RegisterStudentView::onBackClicked() {
    emit backRequested();
}
