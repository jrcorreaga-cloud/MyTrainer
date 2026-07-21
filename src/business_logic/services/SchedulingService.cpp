#include "SchedulingService.h"
#include "../models/ScheduleSlot.h"
#include <iostream>

SchedulingService::SchedulingService(IScheduleRepository* scheduleRepository, ISubject* notifier) 
    : m_scheduleRepository(scheduleRepository), m_notifier(notifier) {}

std::vector<QString> SchedulingService::getFormattedSchedule() {
    std::vector<QString> formatted;
    auto allSlots = m_scheduleRepository->getAllSlots();
    for (const auto& slot : allSlots) {
        QString status = slot.getIsBooked() ? "BOOKED" : "AVAILABLE";
        formatted.push_back(QString("%1 - Trainer %2 - [%3]").arg(slot.getDateTime()).arg(slot.getTrainerId()).arg(status));
    }
    return formatted;
}

std::vector<ScheduleSlot> SchedulingService::getAvailableSlots() {
    std::vector<ScheduleSlot> available;
    auto allSlots = m_scheduleRepository->getAllSlots();
    for (const auto& slot : allSlots) {
        if (!slot.getIsBooked()) {
            available.push_back(slot);
        }
    }
    return available;
}

bool SchedulingService::bookClass(int slotId, int studentId) {
    if (slotId <= 0 || studentId <= 0) return false;
    bool success = m_scheduleRepository->updateSlotBooking(slotId, studentId);
    if (success && m_notifier) {
        m_notifier->notify("Your class has been successfully booked!", "student@mytrainer.com");
    }
    return success;
}