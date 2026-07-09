/**
 * @file IPlanService.h
 * @brief Core functionality for IPlanService
 */

#pragma once
#include <QString>

/**
 * @class IPlanService
 * @brief Main class for IPlanService
 */
class IPlanService {
public:
    /**
     * @brief Executes ~IPlanService operation.
     * @return Result of the operation.
     */
    virtual ~IPlanService() = default;
    /**
     * @brief Executes createPlan operation.
     * @return Result of the operation.
     */
    virtual bool createPlan(const QString& name, double price, int durationMonths) = 0;
};
