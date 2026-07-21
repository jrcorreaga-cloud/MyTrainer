/**
 * @file NotificationManager.h
 * @brief Manages notifications as a Subject
 */
#pragma once
#include "ISubject.h"
#include <vector>
#include <algorithm>

/**
 * @class NotificationManager
 * @brief Subject that manages and notifies all observers
 */
class NotificationManager : public ISubject {
public:
    void attach(std::shared_ptr<IObserver> observer) override;
    void detach(std::shared_ptr<IObserver> observer) override;
    void notify(const QString& message, const QString& userEmail) override;

private:
    std::vector<std::shared_ptr<IObserver>> m_observers;
};
