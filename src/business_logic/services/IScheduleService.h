#pragma once
#include <vector>
#include <QString>
#include "../../business_logic/models/ScheduleSlot.h"

class IScheduleService {
public:
    virtual ~IScheduleService() = default;
    virtual std::vector<QString> getFormattedSchedule() = 0;
    virtual std::vector<ScheduleSlot> getAvailableSlots() = 0;
    virtual bool bookClass(int slotId, int studentId) = 0;
};
