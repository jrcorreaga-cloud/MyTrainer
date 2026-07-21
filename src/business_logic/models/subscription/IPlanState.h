/**
 * @file IPlanState.h
 * @brief Interface for Subscription State
 */
#pragma once

class Subscription;

/**
 * @class IPlanState
 * @brief State interface for Subscription lifecycle
 */
class IPlanState {
public:
    virtual ~IPlanState() = default;
    virtual void suspend(Subscription* context) = 0;
    virtual void activate(Subscription* context) = 0;
    virtual void cancel(Subscription* context) = 0;
    virtual const char* getStateName() const = 0;
};
