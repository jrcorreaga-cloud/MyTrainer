#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IAdminService.h"

class RegisterStudentView : public QWidget {
    Q_OBJECT

public:
    explicit RegisterStudentView(IAdminService* adminService, QWidget *parent = nullptr);

signals:
    void backRequested();

private slots:
    void onRegisterClicked();
    void onBackClicked();

private:
    IAdminService* m_adminService;
    QLineEdit* m_emailInput;
    QLineEdit* m_passwordInput;
    QPushButton* m_registerButton;
    QPushButton* m_backButton;
    QLabel* m_statusLabel;

    void setupUi();
};
