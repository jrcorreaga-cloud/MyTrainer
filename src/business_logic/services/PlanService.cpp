#include "PlanService.h"
#include "../models/Plan.h"

PlanService::PlanService(IPlanRepository* planRepository) : m_planRepository(planRepository) {}

bool PlanService::createPlan(const QString& name, double price, int durationMonths) {
    if (name.isEmpty() || price <= 0.0 || durationMonths <= 0) {
        return false; // Basic validation
    }
    Plan newPlan(0, name, price, durationMonths);
    return m_planRepository->addPlan(newPlan);
}
