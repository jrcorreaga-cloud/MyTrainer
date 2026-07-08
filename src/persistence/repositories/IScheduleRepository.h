#pragma once
#include "../../business_logic/models/ScheduleSlot.h"
#include <vector>

class IScheduleRepository {
public:
    virtual ~IScheduleRepository() = default;
    virtual std::vector<ScheduleSlot> getAllSlots() = 0;
};
