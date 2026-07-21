/**
 * @file UserServiceProxy.h
 * @brief Proxy for UserService to handle auditing and security logs
 */

#pragma once

#include "IUserService.h"
#include <memory>
#include <QString>

/**
 * @class UserServiceProxy
 * @brief Proxy class implementing the Proxy Pattern for security auditing.
 */
class UserServiceProxy : public IUserService {
public:
    /**
     * @brief Constructor for UserServiceProxy
     * @param realService The actual IUserService implementation
     */
    explicit UserServiceProxy(std::shared_ptr<IUserService> realService);

    bool registerTrainer(const QString& email, const QString& password, const QString& specialties) override;
    bool registerStudent(const QString& email, const QString& password) override;

private:
    std::shared_ptr<IUserService> m_realService;

    /**
     * @brief Writes a log entry to the audit file
     */
    void logOperation(const QString& operation, const QString& details);
};
