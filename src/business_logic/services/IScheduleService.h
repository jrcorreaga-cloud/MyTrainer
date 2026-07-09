/**
 * @file IScheduleService.h
 * @brief Core functionality for IScheduleService
 */

#pragma once
#include <vector>
#include <QString>
#include "../../business_logic/models/ScheduleSlot.h"

/**
 * @class IScheduleService
 * @brief Main class for IScheduleService
 */
class IScheduleService {
public:
    /**
     * @brief Executes ~IScheduleService operation.
     * @return Result of the operation.
     */
    virtual ~IScheduleService() = default;
    /**
     * @brief Executes getFormattedSchedule operation.
     * @return Result of the operation.
     */
    virtual std::vector<QString> getFormattedSchedule() = 0;
    /**
     * @brief Executes getAvailableSlots operation.
     * @return Result of the operation.
     */
    virtual std::vector<ScheduleSlot> getAvailableSlots() = 0;
    /**
     * @brief Executes bookClass operation.
     * @return Result of the operation.
     */
    virtual bool bookClass(int slotId, int studentId) = 0;
};
