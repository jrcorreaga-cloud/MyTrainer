/**
 * @file SchedulingService.h
 * @brief Core functionality for SchedulingService
 */

#pragma once
#include "ISchedulingService.h"
#include "../../persistence/repositories/IScheduleRepository.h"

/**
 * @class SchedulingService
 * @brief Main class for SchedulingService
 */
class SchedulingService : public ISchedulingService {
public:
    /**
     * @brief Executes SchedulingService operation.
     * @return Result of the operation.
     */
    explicit SchedulingService(IScheduleRepository* scheduleRepository);
    /**
     * @brief Executes getFormattedSchedule operation.
     * @return Result of the operation.
     */
    std::vector<QString> getFormattedSchedule() override;
    /**
     * @brief Executes getAvailableSlots operation.
     * @return Result of the operation.
     */
    std::vector<ScheduleSlot> getAvailableSlots() override;
    /**
     * @brief Executes bookClass operation.
     * @return Result of the operation.
     */
    bool bookClass(int slotId, int studentId) override;

private:
    IScheduleRepository* m_scheduleRepository;
};
