/**
 * @file ISubject.h
 * @brief Interface for Subject in Observer pattern
 */
#pragma once
#include "IObserver.h"
#include <memory>
#include <QString>

/**
 * @class ISubject
 * @brief Interface for the Subject that holds observers
 */
class ISubject {
public:
    virtual ~ISubject() = default;
    
    /**
     * @brief Attach an observer
     */
    virtual void attach(std::shared_ptr<IObserver> observer) = 0;
    
    /**
     * @brief Detach an observer
     */
    virtual void detach(std::shared_ptr<IObserver> observer) = 0;
    
    /**
     * @brief Notify all attached observers
     */
    virtual void notify(const QString& message, const QString& userEmail) = 0;
};
