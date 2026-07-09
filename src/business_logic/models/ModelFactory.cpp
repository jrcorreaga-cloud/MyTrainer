#include "ModelFactory.h"

User ModelFactory::createUser(int id, const QString& email, const QString& passwordHash, Role role, const QString& specialties) {
    return User(id, email, passwordHash, role, specialties);
}

Plan ModelFactory::createPlan(int id, const QString& name, double price, int durationMonths) {
    return Plan(id, name, price, durationMonths);
}

ScheduleSlot ModelFactory::createScheduleSlot(int id, int trainerId, int studentId, const QString& dateTime, bool isBooked) {
    return ScheduleSlot(id, trainerId, studentId, dateTime, isBooked);
}
