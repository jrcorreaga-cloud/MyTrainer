#include "Subscription.h"
#include "ActiveState.h"

Subscription::Subscription(int userId, int planId) 
    : m_userId(userId), m_planId(planId) {
    m_state = std::make_shared<ActiveState>();
}

void Subscription::setState(std::shared_ptr<IPlanState> state) {
    m_state = state;
}

std::shared_ptr<IPlanState> Subscription::getState() const {
    return m_state;
}

void Subscription::suspend() {
    m_state->suspend(this);
}

void Subscription::activate() {
    m_state->activate(this);
}

void Subscription::cancel() {
    m_state->cancel(this);
}

QString Subscription::getStatus() const {
    return QString(m_state->getStateName());
}
