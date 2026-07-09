/**
 * @file LoginView.h
 * @brief Core functionality for LoginView
 */

#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IAuthService.h"

/**
 * @class LoginView
 * @brief Main class for LoginView
 */
class LoginView : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Executes LoginView operation.
     * @return Result of the operation.
     */
    explicit LoginView(IAuthService* authService, QWidget *parent = nullptr);

signals:
    /**
     * @brief Executes loginSuccessful operation.
     * @return Result of the operation.
     */
    void loginSuccessful(const User& user);

private slots:
    /**
     * @brief Executes onLoginClicked operation.
     * @return Result of the operation.
     */
    void onLoginClicked();

private:
    IAuthService* m_authService;
    QLineEdit* m_emailInput;
    QLineEdit* m_passwordInput;
    QPushButton* m_loginButton;
    QLabel* m_errorLabel;

    /**
     * @brief Executes setupUi operation.
     * @return Result of the operation.
     */
    void setupUi();
};
