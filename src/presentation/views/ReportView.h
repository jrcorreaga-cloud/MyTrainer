/**
 * @file ReportView.h
 * @brief View for displaying KPI Reports
 */

#pragma once

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include "../../business_logic/services/IReportService.h"

/**
 * @class ReportView
 * @brief View class for displaying reports
 */
class ReportView : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Constructor for ReportView
     * @param reportService Pointer to the report service
     * @param parent Parent widget
     */
    explicit ReportView(IReportService* reportService, QWidget *parent = nullptr);

    /**
     * @brief Refreshes the displayed report
     */
    void refreshReport();

signals:
    /**
     * @brief Signal emitted when back button is clicked
     */
    void backRequested();

private slots:
    void onBackClicked();

private:
    IReportService* m_reportService;
    QTextEdit* m_reportTextEdit;
    QPushButton* m_backButton;
    
    void setupUi();
};
