/**
 * @file UserService.h
 * @brief Core functionality for UserService
 */

#pragma once

#include "IUserService.h"
#include "../../persistence/repositories/IUserRepository.h"

/**
 * @class UserService
 * @brief Main class for UserService handling user registration and roles
 */
class UserService : public IUserService {
public:
    /**
     * @brief Constructor for UserService.
     * @param userRepository Pointer to the user repository.
     */
    explicit UserService(IUserRepository* userRepository);

    /**
     * @brief Executes registerTrainer operation.
     * @param email The trainer's email
     * @param password The trainer's password
     * @param specialties The trainer's specialties
     * @return Result of the operation.
     */
    bool registerTrainer(const QString& email, const QString& password, const QString& specialties) override;

    /**
     * @brief Executes registerStudent operation.
     * @param email The student's email
     * @param password The student's password
     * @return Result of the operation.
     */
    bool registerStudent(const QString& email, const QString& password) override;

private:
    IUserRepository* m_userRepository;
};
