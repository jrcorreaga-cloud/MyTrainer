/**
 * @file ScheduleService.h
 * @brief Core functionality for ScheduleService
 */

#pragma once
#include "IScheduleService.h"
#include "../../persistence/repositories/IScheduleRepository.h"

/**
 * @class ScheduleService
 * @brief Main class for ScheduleService
 */
class ScheduleService : public IScheduleService {
public:
    /**
     * @brief Executes ScheduleService operation.
     * @return Result of the operation.
     */
    explicit ScheduleService(IScheduleRepository* scheduleRepository);
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
