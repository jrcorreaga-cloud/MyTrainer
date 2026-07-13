/**
 * @file IReportService.h
 * @brief Core functionality for IReportService
 */

#pragma once

#include <QString>

/**
 * @class IReportService
 * @brief Main interface for Report Generation
 */
class IReportService {
public:
    /**
     * @brief Destructor for IReportService.
     */
    virtual ~IReportService() = default;

    /**
     * @brief Generates the global KPI report
     * @return Formatted string containing the report
     */
    virtual QString generateGlobalReport() = 0;
};
