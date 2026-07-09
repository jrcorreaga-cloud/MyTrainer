/**
 * @file IPlanRepository.h
 * @brief Core functionality for IPlanRepository
 */

#pragma once
#include "../../business_logic/models/Plan.h"
#include <vector>

/**
 * @class IPlanRepository
 * @brief Main class for IPlanRepository
 */
class IPlanRepository {
public:
    /**
     * @brief Executes ~IPlanRepository operation.
     * @return Result of the operation.
     */
    virtual ~IPlanRepository() = default;
    /**
     * @brief Executes addPlan operation.
     * @return Result of the operation.
     */
    virtual bool addPlan(const Plan& plan) = 0;
    /**
     * @brief Executes getAllPlans operation.
     * @return Result of the operation.
     */
    virtual std::vector<Plan> getAllPlans() = 0;
};
