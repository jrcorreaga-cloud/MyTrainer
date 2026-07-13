/**
 * @file ISchedulingService.h
 * @brief Core functionality for ISchedulingService
 */

#pragma once
#include <vector>
#include <QString>
#include "../../business_logic/models/ScheduleSlot.h"

/**
 * @class ISchedulingService
 * @brief Main class for ISchedulingService
 */
class ISchedulingService {
public:
    /**
     * @brief Executes ~ISchedulingService operation.
     * @return Result of the operation.
     */
    virtual ~ISchedulingService() = default;
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
