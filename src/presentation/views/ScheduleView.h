/**
 * @file ScheduleView.h
 * @brief Core functionality for ScheduleView
 */

#pragma once

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/ISchedulingService.h"

/**
 * @class ScheduleView
 * @brief Main class for ScheduleView
 */
class ScheduleView : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Executes ScheduleView operation.
     * @return Result of the operation.
     */
    explicit ScheduleView(ISchedulingService* scheduleService, QWidget *parent = nullptr);
    /**
     * @brief Executes refreshSchedule operation.
     * @return Result of the operation.
     */
    void refreshSchedule();

signals:
    /**
     * @brief Executes backRequested operation.
     * @return Result of the operation.
     */
    void backRequested();

private slots:
    /**
     * @brief Executes onBackClicked operation.
     * @return Result of the operation.
     */
    void onBackClicked();
    /**
     * @brief Executes onRefreshClicked operation.
     * @return Result of the operation.
     */
    void onRefreshClicked();

private:
    ISchedulingService* m_scheduleService;
    QListWidget* m_scheduleList;
    QPushButton* m_backButton;
    QPushButton* m_refreshButton;

    /**
     * @brief Executes setupUi operation.
     * @return Result of the operation.
     */
    void setupUi();
};
