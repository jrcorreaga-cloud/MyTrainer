#pragma once

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include "../../business_logic/services/IScheduleService.h"

class BookClassView : public QWidget {
    Q_OBJECT

public:
    explicit BookClassView(IScheduleService* scheduleService, QWidget *parent = nullptr);
    void setCurrentStudentId(int studentId);
    void refreshAvailableSlots();

signals:
    void backRequested();

private slots:
    void onBookClicked();
    void onBackClicked();

private:
    IScheduleService* m_scheduleService;
    int m_currentStudentId;
    QComboBox* m_slotCombo;
    QPushButton* m_bookButton;
    QPushButton* m_backButton;
    QLabel* m_statusLabel;

    void setupUi();
};
