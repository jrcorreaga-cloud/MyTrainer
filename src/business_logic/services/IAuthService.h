/**
 * @file IAuthService.h
 * @brief Core functionality for IAuthService
 */

#pragma once

#include <optional>
#include <QString>
#include "../models/User.h"

/**
 * @class IAuthService
 * @brief Main class for IAuthService
 */
class IAuthService {
public:
    /**
     * @brief Executes ~IAuthService operation.
     * @return Result of the operation.
     */
    virtual ~IAuthService() = default;
    /**
     * @brief Executes login operation.
     * @return Result of the operation.
     */
    virtual std::optional<User> login(const QString& email, const QString& password) = 0;
};
