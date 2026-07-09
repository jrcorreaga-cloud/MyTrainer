#pragma once
#include "../../business_logic/models/Plan.h"
#include <vector>

class IPlanRepository {
public:
    virtual ~IPlanRepository() = default;
    virtual bool addPlan(const Plan& plan) = 0;
    virtual std::vector<Plan> getAllPlans() = 0;
};
