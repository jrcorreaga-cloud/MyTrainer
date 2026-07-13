/**
 * @file KPIMetric.h
 * @brief Leaf component for the Composite Pattern in Reporting
 */

#pragma once

#include "ReportComponent.h"
#include <QString>

/**
 * @class KPIMetric
 * @brief Represents a single KPI metric (Leaf in Composite Pattern)
 */
class KPIMetric : public ReportComponent {
public:
    /**
     * @brief Constructor for KPIMetric
     * @param name Name of the KPI
     * @param value Value of the KPI
     */
    KPIMetric(const QString& name, const QString& value)
        : m_name(name), m_value(value) {}

    /**
     * @brief Generates the metric report
     * @return Formatted string with the metric
     */
    QString generateReport() const override {
        return QString("- %1: %2\n").arg(m_name).arg(m_value);
    }

private:
    QString m_name;
    QString m_value;
};
