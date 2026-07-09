/**
 * @file PlanService.h
 * @brief Core functionality for PlanService
 */

#pragma once
#include "IPlanService.h"
#include "../../persistence/repositories/IPlanRepository.h"

/**
 * @class PlanService
 * @brief Main class for PlanService
 */
class PlanService : public IPlanService {
public:
    /**
     * @brief Executes PlanService operation.
     * @return Result of the operation.
     */
    explicit PlanService(IPlanRepository* planRepository);
    /**
     * @brief Executes createPlan operation.
     * @return Result of the operation.
     */
    bool createPlan(const QString& name, double price, int durationMonths) override;

private:
    IPlanRepository* m_planRepository;
};
