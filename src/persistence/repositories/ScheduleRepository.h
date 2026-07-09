/**
 * @file ScheduleRepository.h
 * @brief Core functionality for ScheduleRepository
 */

#pragma once
#include "IScheduleRepository.h"

/**
 * @class ScheduleRepository
 * @brief Main class for ScheduleRepository
 */
class ScheduleRepository : public IScheduleRepository {
public:
    /**
     * @brief Executes ScheduleRepository operation.
     * @return Result of the operation.
     */
    ScheduleRepository();
    /**
     * @brief Executes getAllSlots operation.
     * @return Result of the operation.
     */
    std::vector<ScheduleSlot> getAllSlots() override;
    /**
     * @brief Executes updateSlotBooking operation.
     * @return Result of the operation.
     */
    bool updateSlotBooking(int slotId, int studentId) override;

private:
    std::vector<ScheduleSlot> m_mockSlots;
};
