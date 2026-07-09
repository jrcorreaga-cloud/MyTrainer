/**
 * @file AuthService.h
 * @brief Core functionality for AuthService
 */

#pragma once

#include "IAuthService.h"
#include "../../persistence/repositories/IUserRepository.h"

/**
 * @class AuthService
 * @brief Main class for AuthService
 */
class AuthService : public IAuthService {
public:
    /**
     * @brief Executes AuthService operation.
     * @return Result of the operation.
     */
    explicit AuthService(IUserRepository* userRepository);
    /**
     * @brief Executes login operation.
     * @return Result of the operation.
     */
    std::optional<User> login(const QString& email, const QString& password) override;

private:
    IUserRepository* m_userRepository;
};
