/**
 * @file PlanRepository.h
 * @brief Core functionality for PlanRepository
 */

#pragma once
#include "IPlanRepository.h"

/**
 * @class PlanRepository
 * @brief Main class for PlanRepository
 */
class PlanRepository : public IPlanRepository {
public:
    /**
     * @brief Executes PlanRepository operation.
     * @return Result of the operation.
     */
    PlanRepository();
    /**
     * @brief Executes addPlan operation.
     * @return Result of the operation.
     */
    bool addPlan(const Plan& plan) override;
    /**
     * @brief Executes getAllPlans operation.
     * @return Result of the operation.
     */
    std::vector<Plan> getAllPlans() override;

private:
    std::vector<Plan> m_mockPlans;
    int m_nextId;
};
