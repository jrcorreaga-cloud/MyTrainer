/**
 * @file ActiveState.h
 * @brief Active state for Subscription
 */
#pragma once
#include "IPlanState.h"

class ActiveState : public IPlanState {
public:
    void suspend(Subscription* context) override;
    void activate(Subscription* context) override;
    void cancel(Subscription* context) override;
    const char* getStateName() const override { return "Active"; }
};
