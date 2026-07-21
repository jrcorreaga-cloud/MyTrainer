/**
 * @file PushNotifier.h
 * @brief Concrete observer for Push notifications
 */
#pragma once
#include "IObserver.h"

/**
 * @class PushNotifier
 * @brief Sends push notifications when notified
 */
class PushNotifier : public IObserver {
public:
    void update(const QString& message, const QString& userEmail) override;
};
