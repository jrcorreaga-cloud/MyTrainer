#pragma once
#include "IScheduleService.h"
#include "../../persistence/repositories/IScheduleRepository.h"

class ScheduleService : public IScheduleService {
public:
    explicit ScheduleService(IScheduleRepository* scheduleRepository);
    std::vector<QString> getFormattedSchedule() override;
    std::vector<ScheduleSlot> getAvailableSlots() override;
    bool bookClass(int slotId, int studentId) override;

private:
    IScheduleRepository* m_scheduleRepository;
};
