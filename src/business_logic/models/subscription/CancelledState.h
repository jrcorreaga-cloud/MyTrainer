/**
 * @file CancelledState.h
 * @brief Cancelled state for Subscription
 */
#pragma once
#include "IPlanState.h"

class CancelledState : public IPlanState {
public:
    void suspend(Subscription* context) override;
    void activate(Subscription* context) override;
    void cancel(Subscription* context) override;
    const char* getStateName() const override { return "Cancelled"; }
};
