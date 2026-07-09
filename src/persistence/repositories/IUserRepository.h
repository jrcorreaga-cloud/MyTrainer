/**
 * @file IUserRepository.h
 * @brief Core functionality for IUserRepository
 */

#pragma once

#include <optional>
#include <QString>
#include "../../business_logic/models/User.h"

/**
 * @class IUserRepository
 * @brief Main class for IUserRepository
 */
class IUserRepository {
public:
    /**
     * @brief Executes ~IUserRepository operation.
     * @return Result of the operation.
     */
    virtual ~IUserRepository() = default;
    /**
     * @brief Executes getUserByEmail operation.
     * @return Result of the operation.
     */
    virtual std::optional<User> getUserByEmail(const QString& email) = 0;
    /**
     * @brief Executes addUser operation.
     * @return Result of the operation.
     */
    virtual bool addUser(const User& user) = 0;
};
