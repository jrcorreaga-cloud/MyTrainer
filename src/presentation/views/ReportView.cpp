#include "ReportView.h"
#include <QVBoxLayout>
#include <QLabel>

ReportView::ReportView(IReportService* reportService, QWidget *parent)
    : QWidget(parent), m_reportService(reportService) {
    setupUi();
}

void ReportView::setupUi() {
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("KPI & Performance Reports", this);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
    layout->addWidget(titleLabel);

    m_reportTextEdit = new QTextEdit(this);
    m_reportTextEdit->setReadOnly(true);
    layout->addWidget(m_reportTextEdit);

    m_backButton = new QPushButton("Back to Dashboard", this);
    layout->addWidget(m_backButton);
    connect(m_backButton, &QPushButton::clicked, this, &ReportView::onBackClicked);
}

void ReportView::refreshReport() {
    if (m_reportService) {
        m_reportTextEdit->setText(m_reportService->generateGlobalReport());
    }
}

void ReportView::onBackClicked() {
    emit backRequested();
}
