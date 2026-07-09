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
    /**
     * @brief Executes registerTrainer operation.
     * @return Result of the operation.
     */
    virtual bool registerTrainer(const QString& email, const QString& password, const QString& specialties) = 0;
    /**
     * @brief Executes registerStudent operation.
     * @return Result of the operation.
     */
    virtual bool registerStudent(const QString& email, const QString& password) = 0;
};
