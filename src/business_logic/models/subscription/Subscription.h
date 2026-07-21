/**
 * @file Subscription.h
 * @brief Context class for Subscription State Pattern
 */
#pragma once
#include <memory>
#include <QString>
#include "IPlanState.h"

/**
 * @class Subscription
 * @brief Context that maintains an instance of a ConcreteState subclass that defines the current state.
 */
class Subscription {
public:
    Subscription(int userId, int planId);
    
    void setState(std::shared_ptr<IPlanState> state);
    std::shared_ptr<IPlanState> getState() const;
    
    void suspend();
    void activate();
    void cancel();
    
    QString getStatus() const;
    int getUserId() const { return m_userId; }
    int getPlanId() const { return m_planId; }

private:
    std::shared_ptr<IPlanState> m_state;
    int m_userId;
    int m_planId;
};
