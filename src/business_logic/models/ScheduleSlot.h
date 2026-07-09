#pragma once
#include <QString>

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
    int m_id;
    int m_trainerId;
    int m_studentId;
    QString m_dateTime;
    bool m_isBooked;
};