/**
 * @file IObserver.h
 * @brief Interface for Observer pattern
 */
#pragma once
#include <QString>

/**
 * @class IObserver
 * @brief Interface that all notifiers must implement
 */
class IObserver {
public:
    virtual ~IObserver() = default;
    
    /**
     * @brief Method called by the Subject to update the observer
     * @param message The notification message
     * @param userEmail The target user
     */
    virtual void update(const QString& message, const QString& userEmail) = 0;
};
