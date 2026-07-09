/**
 * @file AdminService.h
 * @brief Core functionality for AdminService
 */

#pragma once

#include "IAdminService.h"
#include "../../persistence/repositories/IUserRepository.h"

/**
 * @class AdminService
 * @brief Main class for AdminService
 */
class AdminService : public IAdminService {
public:
    /**
     * @brief Executes AdminService operation.
     * @return Result of the operation.
     */
    explicit AdminService(IUserRepository* userRepository);

    /**
     * @brief Executes registerTrainer operation.
     * @return Result of the operation.
     */
    bool registerTrainer(const QString& email, const QString& password, const QString& specialties) override;
    /**
     * @brief Executes registerStudent operation.
     * @return Result of the operation.
     */
    bool registerStudent(const QString& email, const QString& password) override;

private:
    IUserRepository* m_userRepository;
};
