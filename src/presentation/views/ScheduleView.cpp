#include "ScheduleView.h"
#include <QVBoxLayout>

ScheduleView::ScheduleView(ISchedulingService* scheduleService, QWidget *parent)
    : QWidget(parent), m_scheduleService(scheduleService) {
    setupUi();
}

void ScheduleView::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("Trainer Schedules", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; margin-bottom: 20px;");
    mainLayout->addWidget(titleLabel);

    m_scheduleList = new QListWidget(this);
    mainLayout->addWidget(m_scheduleList);

    m_refreshButton = new QPushButton("Refresh", this);
    mainLayout->addWidget(m_refreshButton);

    m_backButton = new QPushButton("Back to Dashboard", this);
    mainLayout->addWidget(m_backButton);

    connect(m_refreshButton, &QPushButton::clicked, this, &ScheduleView::onRefreshClicked);
    connect(m_backButton, &QPushButton::clicked, this, &ScheduleView::onBackClicked);

    refreshSchedule();
}

void ScheduleView::refreshSchedule() {
    m_scheduleList->clear();
    auto allSlots = m_scheduleService->getFormattedSchedule();
    for (const auto& slotStr : allSlots) {
        m_scheduleList->addItem(slotStr);
    }
}

void ScheduleView::onRefreshClicked() {
    refreshSchedule();
}

void ScheduleView::onBackClicked() {
    emit backRequested();
}
