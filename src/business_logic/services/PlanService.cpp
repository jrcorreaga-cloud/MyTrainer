#include "PlanService.h"
#include "../models/Plan.h"
#include "../models/ModelFactory.h"

PlanService::PlanService(IPlanRepository* planRepository) : m_planRepository(planRepository) {}

bool PlanService::createPlan(const QString& name, double price, int durationMonths) {
    if (name.isEmpty() || price < 0 || durationMonths <= 0) return false;
    Plan newPlan(0, name, price, durationMonths);
    return m_planRepository->addPlan(newPlan);
}

void PlanService::subscribeUser(int userId, int planId) {
    m_subscriptions.push_back(std::make_shared<Subscription>(userId, planId));
}

bool PlanService::suspendSubscription(int userId) {
    for (auto& sub : m_subscriptions) {
        if (sub->getUserId() == userId) {
            sub->suspend();
            return true;
        }
    }
    return false;
}

bool PlanService::cancelSubscription(int userId) {
    for (auto& sub : m_subscriptions) {
        if (sub->getUserId() == userId) {
            sub->cancel();
            return true;
        }
    }
    return false;
}

QString PlanService::getSubscriptionStatus(int userId) const {
    for (const auto& sub : m_subscriptions) {
        if (sub->getUserId() == userId) {
            return sub->getStatus();
        }
    }
    return "No Subscription";
}
