/**
 * @file UserRepository.h
 * @brief Core functionality for UserRepository
 */

#pragma once

#include <vector>
#include "IUserRepository.h"

/**
 * @class UserRepository
 * @brief Main class for UserRepository
 */
class UserRepository : public IUserRepository {
public:
    /**
     * @brief Executes UserRepository operation.
     * @return Result of the operation.
     */
    UserRepository();
    /**
     * @brief Executes getUserByEmail operation.
     * @return Result of the operation.
     */
    std::optional<User> getUserByEmail(const QString& email) override;
    /**
     * @brief Executes addUser operation.
     * @return Result of the operation.
     */
    bool addUser(const User& user) override;

private:
    std::vector<User> m_mockUsers;
    int m_nextId;
};
