/**
 * @file CompositeReport.h
 * @brief Composite component for the Composite Pattern in Reporting
 */

#pragma once

#include "ReportComponent.h"
#include <vector>
#include <memory>
#include <QString>

/**
 * @class CompositeReport
 * @brief Represents a group of reports or metrics (Composite in Composite Pattern)
 */
class CompositeReport : public ReportComponent {
public:
    /**
     * @brief Constructor for CompositeReport
     * @param title Title of the composite report
     */
    explicit CompositeReport(const QString& title) : m_title(title) {}

    /**
     * @brief Adds a child component to this report
     * @param component Shared pointer to a ReportComponent
     */
    void addComponent(std::shared_ptr<ReportComponent> component) {
        m_components.push_back(component);
    }

    /**
     * @brief Generates the composite report
     * @return Formatted string containing the title and all child reports
     */
    QString generateReport() const override {
        QString report = QString("=== %1 ===\n").arg(m_title);
        for (const auto& component : m_components) {
            report += component->generateReport();
        }
        report += "\n";
        return report;
    }

private:
    QString m_title;
    std::vector<std::shared_ptr<ReportComponent>> m_components;
};
