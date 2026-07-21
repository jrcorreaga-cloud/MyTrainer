/**
 * @file PlanService.h
 * @brief Core functionality for PlanService
 */

#pragma once
#include "IPlanService.h"
#include "../../persistence/repositories/IPlanRepository.h"
#include "../models/subscription/Subscription.h"
#include <vector>

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

    /**
     * @brief Subscribes a user to a plan
     */
    void subscribeUser(int userId, int planId);

    /**
     * @brief Suspends a user's subscription
     */
    bool suspendSubscription(int userId);

    /**
     * @brief Cancels a user's subscription
     */
    bool cancelSubscription(int userId);

    /**
     * @brief Gets the status of a user's subscription
     */
    QString getSubscriptionStatus(int userId) const;

private:
    IPlanRepository* m_planRepository;
    std::vector<std::shared_ptr<Subscription>> m_subscriptions;
};
