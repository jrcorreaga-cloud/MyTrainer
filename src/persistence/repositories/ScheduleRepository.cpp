#include "ScheduleRepository.h"

ScheduleRepository::ScheduleRepository() {
    // Generate some mock slots for Trainer ID 2
    m_mockSlots.push_back(ScheduleSlot(1, 2, -1, "2026-07-08 09:00", false));
    m_mockSlots.push_back(ScheduleSlot(2, 2, 3, "2026-07-08 10:00", true)); // Booked by Student 3
    m_mockSlots.push_back(ScheduleSlot(3, 2, -1, "2026-07-08 11:00", false));
}

std::vector<ScheduleSlot> ScheduleRepository::getAllSlots() {
    return m_mockSlots;
}

bool ScheduleRepository::updateSlotBooking(int slotId, int studentId) {
    for (auto& slot : m_mockSlots) {
        if (slot.getId() == slotId && !slot.getIsBooked()) {
            slot = ScheduleSlot(slot.getId(), slot.getTrainerId(), studentId, slot.getDateTime(), true);
            return true;
        }
    }
    return false;
}
