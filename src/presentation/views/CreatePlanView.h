/**
 * @file CreatePlanView.h
 * @brief Core functionality for CreatePlanView
 */

#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IPlanService.h"

/**
 * @class CreatePlanView
 * @brief Main class for CreatePlanView
 */
class CreatePlanView : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Executes CreatePlanView operation.
     * @return Result of the operation.
     */
    explicit CreatePlanView(IPlanService* planService, QWidget *parent = nullptr);

signals:
    /**
     * @brief Executes backRequested operation.
     * @return Result of the operation.
     */
    void backRequested();

private slots:
    /**
     * @brief Executes onCreateClicked operation.
     * @return Result of the operation.
     */
    void onCreateClicked();
    /**
     * @brief Executes onBackClicked operation.
     * @return Result of the operation.
     */
    void onBackClicked();

private:
    IPlanService* m_planService;
    QLineEdit* m_nameInput;
    QLineEdit* m_priceInput;
    QLineEdit* m_durationInput;
    QPushButton* m_createButton;
    QPushButton* m_backButton;
    QLabel* m_statusLabel;

    /**
     * @brief Executes setupUi operation.
     * @return Result of the operation.
     */
    void setupUi();
};
