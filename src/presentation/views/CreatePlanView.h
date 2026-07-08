#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IPlanService.h"

class CreatePlanView : public QWidget {
    Q_OBJECT

public:
    explicit CreatePlanView(IPlanService* planService, QWidget *parent = nullptr);

signals:
    void backRequested();

private slots:
    void onCreateClicked();
    void onBackClicked();

private:
    IPlanService* m_planService;
    QLineEdit* m_nameInput;
    QLineEdit* m_priceInput;
    QLineEdit* m_durationInput;
    QPushButton* m_createButton;
    QPushButton* m_backButton;
    QLabel* m_statusLabel;

    void setupUi();
};
