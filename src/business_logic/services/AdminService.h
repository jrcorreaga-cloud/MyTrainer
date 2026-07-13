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

private:
    IUserRepository* m_userRepository;
};
