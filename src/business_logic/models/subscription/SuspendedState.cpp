#include "SuspendedState.h"
#include "ActiveState.h"
#include "CancelledState.h"
#include "Subscription.h"

void SuspendedState::suspend(Subscription* context) {
    // Already suspended
}

void SuspendedState::activate(Subscription* context) {
    context->setState(std::make_shared<ActiveState>());
}

void SuspendedState::cancel(Subscription* context) {
    context->setState(std::make_shared<CancelledState>());
}
