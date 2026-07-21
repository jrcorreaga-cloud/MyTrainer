/**
 * @file SuspendedState.h
 * @brief Suspended state for Subscription
 */
#pragma once
#include "IPlanState.h"

class SuspendedState : public IPlanState {
public:
    void suspend(Subscription* context) override;
    void activate(Subscription* context) override;
    void cancel(Subscription* context) override;
    const char* getStateName() const override { return "Suspended"; }
};
