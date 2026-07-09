#include "PlanRepository.h"
#include "../../business_logic/models/ModelFactory.h"

PlanRepository::PlanRepository() : m_nextId(1) {}

bool PlanRepository::addPlan(const Plan& plan) {
    Plan newPlan = ModelFactory::createPlan(m_nextId++, plan.getName(), plan.getPrice(), plan.getDurationMonths());
    m_mockPlans.push_back(newPlan);
    return true;
}

std::vector<Plan> PlanRepository::getAllPlans() {
    return m_mockPlans;
}
