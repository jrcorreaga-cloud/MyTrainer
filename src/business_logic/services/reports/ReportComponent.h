/**
 * @file ReportComponent.h
 * @brief Base component for the Composite Pattern in Reporting
 */

#pragma once

#include <QString>

/**
 * @class ReportComponent
 * @brief Abstract base class for Report elements (Composite Pattern)
 */
class ReportComponent {
public:
    virtual ~ReportComponent() = default;

    /**
     * @brief Generates the report content
     * @return Formatted string with report data
     */
    virtual QString generateReport() const = 0;
};
