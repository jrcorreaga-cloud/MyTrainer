#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IAdminService.h"

class RegisterTrainerView : public QWidget {
    Q_OBJECT

public:
    explicit RegisterTrainerView(IAdminService* adminService, QWidget *parent = nullptr);

signals:
    void backRequested();

private slots:
    void onRegisterClicked();
    void onBackClicked();

private:
    IAdminService* m_adminService;
    QLineEdit* m_emailInput;
    QLineEdit* m_passwordInput;
    QLineEdit* m_specialtiesInput;
    QPushButton* m_registerButton;
    QPushButton* m_backButton;
    QLabel* m_statusLabel;

    void setupUi();
};
