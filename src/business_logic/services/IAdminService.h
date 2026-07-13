/**
 * @file IAdminService.h
 * @brief Core functionality for IAdminService
 */

#pragma once

#include <QString>

/**
 * @class IAdminService
 * @brief Main class for IAdminService
 */
class IAdminService {
public:
    /**
     * @brief Executes ~IAdminService operation.
     * @return Result of the operation.
     */
    virtual ~IAdminService() = default;
    virtual bool registerStudent(const QString& email, const QString& password) = 0;
    virtual bool registerTrainer(const QString& email, const QString& password, const QString& specialties) = 0;
};
