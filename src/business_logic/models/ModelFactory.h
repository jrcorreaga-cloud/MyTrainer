#pragma once
#include "User.h"
#include "Plan.h"
#include "ScheduleSlot.h"

/**
 * @class ModelFactory
 * @brief Factory class to create Handle-Body models.
 */
class ModelFactory {
public:
    static User createUser(int id, const QString& email, const QString& passwordHash, Role role, const QString& specialties = "");
    static Plan createPlan(int id, const QString& name, double price, int durationMonths);
    static ScheduleSlot createScheduleSlot(int id, int trainerId, int studentId, const QString& dateTime, bool isBooked);
};
