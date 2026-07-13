#include "ReportService.h"
#include "reports/CompositeReport.h"
#include "reports/KPIMetric.h"

ReportService::ReportService(IScheduleRepository* scheduleRepo, IUserRepository* userRepo, IPlanRepository* planRepo)
    : m_scheduleRepository(scheduleRepo), m_userRepository(userRepo), m_planRepository(planRepo) {}

QString ReportService::generateGlobalReport() {
    // Simulated KPI data retrieval
    // In a real scenario, this would query repositories to calculate actual metrics.
    int totalUsers = m_userRepository ? 150 : 0; // Mock value
    int activePlans = m_planRepository ? 120 : 0; // Mock value
    int bookedSlots = m_scheduleRepository ? 45 : 0; // Mock value

    auto globalReport = std::make_shared<CompositeReport>("Global Performance Report");
    
    auto userMetrics = std::make_shared<CompositeReport>("User Metrics");
    userMetrics->addComponent(std::make_shared<KPIMetric>("Total Users", QString::number(totalUsers)));
    userMetrics->addComponent(std::make_shared<KPIMetric>("Active Plans", QString::number(activePlans)));

    auto scheduleMetrics = std::make_shared<CompositeReport>("Schedule Metrics");
    scheduleMetrics->addComponent(std::make_shared<KPIMetric>("Total Booked Slots", QString::number(bookedSlots)));
    scheduleMetrics->addComponent(std::make_shared<KPIMetric>("Occupancy Rate", "75%"));

    globalReport->addComponent(userMetrics);
    globalReport->addComponent(scheduleMetrics);

    return globalReport->generateReport();
}
