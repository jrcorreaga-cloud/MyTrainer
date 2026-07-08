#pragma once

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IScheduleService.h"

class ScheduleView : public QWidget {
    Q_OBJECT

public:
    explicit ScheduleView(IScheduleService* scheduleService, QWidget *parent = nullptr);
    void refreshSchedule();

signals:
    void backRequested();

private slots:
    void onBackClicked();
    void onRefreshClicked();

private:
    IScheduleService* m_scheduleService;
    QListWidget* m_scheduleList;
    QPushButton* m_backButton;
    QPushButton* m_refreshButton;

    void setupUi();
};
