/**
 * @file EmailNotifier.h
 * @brief Concrete observer for Email notifications
 */
#pragma once
#include "IObserver.h"

/**
 * @class EmailNotifier
 * @brief Sends emails when notified
 */
class EmailNotifier : public IObserver {
public:
    void update(const QString& message, const QString& userEmail) override;
};
