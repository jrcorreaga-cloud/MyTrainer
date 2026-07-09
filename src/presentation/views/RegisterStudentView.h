/**
 * @file RegisterStudentView.h
 * @brief Core functionality for RegisterStudentView
 */

#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IAdminService.h"

/**
 * @class RegisterStudentView
 * @brief Main class for RegisterStudentView
 */
class RegisterStudentView : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Executes RegisterStudentView operation.
     * @return Result of the operation.
     */
    explicit RegisterStudentView(IAdminService* adminService, QWidget *parent = nullptr);

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
    IAdminService* m_adminService;
    QLineEdit* m_emailInput;
    QLineEdit* m_passwordInput;
    QPushButton* m_registerButton;
    QPushButton* m_backButton;
    QLabel* m_statusLabel;

    /**
     * @brief Executes setupUi operation.
     * @return Result of the operation.
     */
    void setupUi();
};
