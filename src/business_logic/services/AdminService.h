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
    bool registerStudent(const QString& email, const QString& password) override;
    bool registerTrainer(const QString& email, const QString& password, const QString& specialties) override;

private:
    IUserRepository* m_userRepository;
};
