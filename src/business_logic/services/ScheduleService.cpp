#include "ScheduleService.h"
#include "../models/ScheduleSlot.h"

ScheduleService::ScheduleService(IScheduleRepository* scheduleRepository) 
    : m_scheduleRepository(scheduleRepository) {}

std::vector<QString> ScheduleService::getFormattedSchedule() {
    std::vector<QString> formatted;
    auto allSlots = m_scheduleRepository->getAllSlots();
    for (const auto& slot : allSlots) {
        QString status = slot.getIsBooked() ? "BOOKED" : "AVAILABLE";
        formatted.push_back(QString("%1 - Trainer %2 - [%3]").arg(slot.getDateTime()).arg(slot.getTrainerId()).arg(status));
    }
    return formatted;
}

std::vector<ScheduleSlot> ScheduleService::getAvailableSlots() {
    std::vector<ScheduleSlot> available;
    auto allSlots = m_scheduleRepository->getAllSlots();
    for (const auto& slot : allSlots) {
        if (!slot.getIsBooked()) {
            available.push_back(slot);
        }
    }
    return available;
}

bool ScheduleService::bookClass(int slotId, int studentId) {
    if (slotId <= 0 || studentId <= 0) return false;
    return m_scheduleRepository->updateSlotBooking(slotId, studentId);
}