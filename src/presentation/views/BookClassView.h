/**
 * @file BookClassView.h
 * @brief Core functionality for BookClassView
 */

#pragma once

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IScheduleService.h"

/**
 * @class BookClassView
 * @brief Main class for BookClassView
 */
class BookClassView : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Executes BookClassView operation.
     * @return Result of the operation.
     */
    explicit BookClassView(IScheduleService* scheduleService, QWidget *parent = nullptr);
    /**
     * @brief Executes setCurrentStudentId operation.
     * @return Result of the operation.
     */
    void setCurrentStudentId(int studentId);
    /**
     * @brief Executes refreshAvailableSlots operation.
     * @return Result of the operation.
     */
    void refreshAvailableSlots();

signals:
    /**
     * @brief Executes backRequested operation.
     * @return Result of the operation.
     */
    void backRequested();

private slots:
    /**
     * @brief Executes onBookClicked operation.
     * @return Result of the operation.
     */
    void onBookClicked();
    /**
     * @brief Executes onBackClicked operation.
     * @return Result of the operation.
     */
    void onBackClicked();

private:
    IScheduleService* m_scheduleService;
    int m_currentStudentId;
    QComboBox* m_slotCombo;
    QPushButton* m_bookButton;
    QPushButton* m_backButton;
    QLabel* m_statusLabel;

    /**
     * @brief Executes setupUi operation.
     * @return Result of the operation.
     */
    void setupUi();
};
