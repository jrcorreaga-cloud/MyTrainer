#include "ScheduleSlot.h"

ScheduleSlot::ScheduleSlot() : m_id(0), m_trainerId(0), m_studentId(0), m_dateTime(""), m_isBooked(false) {}

ScheduleSlot::ScheduleSlot(int id, int trainerId, int studentId, const QString& dateTime, bool isBooked)
    : m_id(id), m_trainerId(trainerId), m_studentId(studentId), m_dateTime(dateTime), m_isBooked(isBooked) {}

ScheduleSlot::ScheduleSlot(const ScheduleSlot& other)
    : m_id(other.m_id), m_trainerId(other.m_trainerId), m_studentId(other.m_studentId), 
      m_dateTime(other.m_dateTime), m_isBooked(other.m_isBooked) {}

ScheduleSlot& ScheduleSlot::operator=(const ScheduleSlot& other) {
    if (this != &other) {
        m_id = other.m_id;
        m_trainerId = other.m_trainerId;
        m_studentId = other.m_studentId;
        m_dateTime = other.m_dateTime;
        m_isBooked = other.m_isBooked;
    }
    return *this;
}

ScheduleSlot::~ScheduleSlot() {}

int ScheduleSlot::getId() const { return m_id; }
int ScheduleSlot::getTrainerId() const { return m_trainerId; }
int ScheduleSlot::getStudentId() const { return m_studentId; }
QString ScheduleSlot::getDateTime() const { return m_dateTime; }
bool ScheduleSlot::getIsBooked() const { return m_isBooked; }
