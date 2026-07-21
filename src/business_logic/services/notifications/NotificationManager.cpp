#include "NotificationManager.h"

void NotificationManager::attach(std::shared_ptr<IObserver> observer) {
    m_observers.push_back(observer);
}

void NotificationManager::detach(std::shared_ptr<IObserver> observer) {
    auto it = std::find(m_observers.begin(), m_observers.end(), observer);
    if (it != m_observers.end()) {
        m_observers.erase(it);
    }
}

void NotificationManager::notify(const QString& message, const QString& userEmail) {
    for (auto& observer : m_observers) {
        observer->update(message, userEmail);
    }
}
