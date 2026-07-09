#pragma once
#include <QString>

class ScheduleSlotBody;

/**
 * @class ScheduleSlot
 * @brief Handle class for ScheduleSlot entity using Pimpl idiom.
 */
class ScheduleSlot {
public:
    ScheduleSlot();
    ScheduleSlot(int id, int trainerId, int studentId, const QString& dateTime, bool isBooked);
    ScheduleSlot(const ScheduleSlot& other);
    ScheduleSlot& operator=(const ScheduleSlot& other);
    ~ScheduleSlot();

    int getId() const;
    int getTrainerId() const;
    int getStudentId() const;
    QString getDateTime() const;
    bool getIsBooked() const;

private:
    ScheduleSlotBody* pImpl;
};