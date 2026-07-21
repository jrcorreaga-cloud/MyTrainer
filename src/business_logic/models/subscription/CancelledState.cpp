#include "CancelledState.h"
#include "Subscription.h"

void CancelledState::suspend(Subscription* context) {
    // Cannot suspend a cancelled subscription
}

void CancelledState::activate(Subscription* context) {
    // Cannot activate a cancelled subscription
}

void CancelledState::cancel(Subscription* context) {
    // Already cancelled
}
