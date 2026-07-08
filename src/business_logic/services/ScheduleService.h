#pragma once
#include "IScheduleService.h"
#include "../../persistence/repositories/IScheduleRepository.h"

class ScheduleService : public IScheduleService {
public:
    explicit ScheduleService(IScheduleRepository* scheduleRepository);
    std::vector<QString> getFormattedSchedule() override;

private:
    IScheduleRepository* m_scheduleRepository;
};
