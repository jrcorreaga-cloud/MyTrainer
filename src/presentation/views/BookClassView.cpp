#include "BookClassView.h"
#include <QVBoxLayout>

BookClassView::BookClassView(IScheduleService* scheduleService, QWidget *parent)
    : QWidget(parent), m_scheduleService(scheduleService), m_currentStudentId(-1) {
    setupUi();
}

void BookClassView::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("Book a Class", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; margin-bottom: 20px;");
    mainLayout->addWidget(titleLabel);

    m_slotCombo = new QComboBox(this);
    mainLayout->addWidget(m_slotCombo);

    m_statusLabel = new QLabel("", this);
    m_statusLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(m_statusLabel);

    m_bookButton = new QPushButton("Book Selected Class", this);
    mainLayout->addWidget(m_bookButton);

    m_backButton = new QPushButton("Back to Dashboard", this);
    mainLayout->addWidget(m_backButton);

    connect(m_bookButton, &QPushButton::clicked, this, &BookClassView::onBookClicked);
    connect(m_backButton, &QPushButton::clicked, this, &BookClassView::onBackClicked);
}

void BookClassView::setCurrentStudentId(int studentId) {
    m_currentStudentId = studentId;
}

void BookClassView::refreshAvailableSlots() {
    m_slotCombo->clear();
    auto available = m_scheduleService->getAvailableSlots();
    for (const auto& slot : available) {
        QString display = QString("%1 - Trainer %2").arg(slot.getDateTime()).arg(slot.getTrainerId());
        // Store the slot ID in the combo box's item data
        m_slotCombo->addItem(display, QVariant(slot.getId()));
    }
    m_statusLabel->clear();
}

void BookClassView::onBookClicked() {
    if (m_slotCombo->currentIndex() == -1) {
        m_statusLabel->setStyleSheet("color: red;");
        m_statusLabel->setText("No classes available to book.");
        return;
    }

    int slotId = m_slotCombo->currentData().toInt();
    if (m_scheduleService->bookClass(slotId, m_currentStudentId)) {
        m_statusLabel->setStyleSheet("color: green;");
        m_statusLabel->setText("Class booked successfully!");
        refreshAvailableSlots(); // Remove it from the list
    } else {
        m_statusLabel->setStyleSheet("color: red;");
        m_statusLabel->setText("Failed to book class. It might be already taken.");
    }
}

void BookClassView::onBackClicked() {
    emit backRequested();
}
