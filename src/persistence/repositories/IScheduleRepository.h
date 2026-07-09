/**
 * @file IScheduleRepository.h
 * @brief Core functionality for IScheduleRepository
 */

#pragma once
#include "../../business_logic/models/ScheduleSlot.h"
#include <vector>

/**
 * @class IScheduleRepository
 * @brief Main class for IScheduleRepository
 */
class IScheduleRepository {
public:
    /**
     * @brief Executes ~IScheduleRepository operation.
     * @return Result of the operation.
     */
    virtual ~IScheduleRepository() = default;
    /**
     * @brief Executes getAllSlots operation.
     * @return Result of the operation.
     */
    virtual std::vector<ScheduleSlot> getAllSlots() = 0;
    /**
     * @brief Executes updateSlotBooking operation.
     * @return Result of the operation.
     */
    virtual bool updateSlotBooking(int slotId, int studentId) = 0;
};
