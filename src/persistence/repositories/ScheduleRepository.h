#pragma once
#include "IScheduleRepository.h"

class ScheduleRepository : public IScheduleRepository {
public:
    ScheduleRepository();
    std::vector<ScheduleSlot> getAllSlots() override;
    bool updateSlotBooking(int slotId, int studentId) override;

private:
    std::vector<ScheduleSlot> m_mockSlots;
};
