#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IAuthService.h"

class LoginView : public QWidget {
    Q_OBJECT

public:
    explicit LoginView(IAuthService* authService, QWidget *parent = nullptr);

signals:
    void loginSuccessful(const User& user);

private slots:
    void onLoginClicked();

private:
    IAuthService* m_authService;
    QLineEdit* m_emailInput;
    QLineEdit* m_passwordInput;
    QPushButton* m_loginButton;
    QLabel* m_errorLabel;

    void setupUi();
};
