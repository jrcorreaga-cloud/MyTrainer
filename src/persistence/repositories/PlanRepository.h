#pragma once
#include "IPlanRepository.h"

class PlanRepository : public IPlanRepository {
public:
    PlanRepository();
    bool addPlan(const Plan& plan) override;
    std::vector<Plan> getAllPlans() override;

private:
    std::vector<Plan> m_mockPlans;
    int m_nextId;
};
