/**
 * @file RegisterTrainerView.h
 * @brief Core functionality for RegisterTrainerView
 */

#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IUserService.h"

/**
 * @class RegisterTrainerView
 * @brief Main class for RegisterTrainerView
 */
class RegisterTrainerView : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Executes RegisterTrainerView operation.
     * @return Result of the operation.
     */
    explicit RegisterTrainerView(IUserService* userService, QWidget *parent = nullptr);

signals:
    /**
     * @brief Executes backRequested operation.
     * @return Result of the operation.
     */
    void backRequested();

private slots:
    /**
     * @brief Executes onRegisterClicked operation.
     * @return Result of the operation.
     */
    void onRegisterClicked();
    /**
     * @brief Executes onBackClicked operation.
     * @return Result of the operation.
     */
    void onBackClicked();

private:
    IUserService* m_userService;
    QLineEdit* m_emailInput;
    QLineEdit* m_passwordInput;
    QLineEdit* m_specialtiesInput;
    QPushButton* m_registerButton;
    QPushButton* m_backButton;
    QLabel* m_statusLabel;

    /**
     * @brief Executes setupUi operation.
     * @return Result of the operation.
     */
    void setupUi();
};
