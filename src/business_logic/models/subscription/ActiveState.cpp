#include "ActiveState.h"
#include "SuspendedState.h"
#include "CancelledState.h"
#include "Subscription.h"

void ActiveState::suspend(Subscription* context) {
    context->setState(std::make_shared<SuspendedState>());
}

void ActiveState::activate(Subscription* context) {
    // Already active
}

void ActiveState::cancel(Subscription* context) {
    context->setState(std::make_shared<CancelledState>());
}
