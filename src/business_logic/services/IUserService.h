/**
 * @file IUserService.h
 * @brief Core functionality for IUserService
 */

#pragma once

#include <QString>

/**
 * @class IUserService
 * @brief Main interface for User Registration and Management
 */
class IUserService {
public:
    /**
     * @brief Destructor for IUserService.
     */
    virtual ~IUserService() = default;

    /**
     * @brief Executes registerTrainer operation.
     * @param email The trainer's email
     * @param password The trainer's password
     * @param specialties The trainer's specialties
     * @return Result of the operation.
     */
    virtual bool registerTrainer(const QString& email, const QString& password, const QString& specialties) = 0;

    /**
     * @brief Executes registerStudent operation.
     * @param email The student's email
     * @param password The student's password
     * @return Result of the operation.
     */
    virtual bool registerStudent(const QString& email, const QString& password) = 0;
};
