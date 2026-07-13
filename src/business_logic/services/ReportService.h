/**
 * @file ReportService.h
 * @brief Core functionality for ReportService
 */

#pragma once

#include "IReportService.h"
#include "../../persistence/repositories/IScheduleRepository.h"
#include "../../persistence/repositories/IUserRepository.h"
#include "../../persistence/repositories/IPlanRepository.h"

/**
 * @class ReportService
 * @brief Service responsible for generating KPIs and reports using the Composite Pattern
 */
class ReportService : public IReportService {
public:
    /**
     * @brief Constructor for ReportService
     * @param scheduleRepo Pointer to schedule repository
     * @param userRepo Pointer to user repository
     * @param planRepo Pointer to plan repository
     */
    ReportService(IScheduleRepository* scheduleRepo, IUserRepository* userRepo, IPlanRepository* planRepo);

    /**
     * @brief Generates the global KPI report
     * @return Formatted string containing the report
     */
    QString generateGlobalReport() override;

private:
    IScheduleRepository* m_scheduleRepository;
    IUserRepository* m_userRepository;
    IPlanRepository* m_planRepository;
};
