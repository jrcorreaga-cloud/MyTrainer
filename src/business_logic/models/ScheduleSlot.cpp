#include "ScheduleSlot.h"

class ScheduleSlotBody {
public:
    int id;
    int trainerId;
    int studentId;
    QString dateTime;
    bool isBooked;

    ScheduleSlotBody() : id(0), trainerId(0), studentId(0), isBooked(false) {}
    ScheduleSlotBody(int i, int t, int s, QString d, bool b)
        : id(i), trainerId(t), studentId(s), dateTime(d), isBooked(b) {}
    ScheduleSlotBody* clone() const { return new ScheduleSlotBody(*this); }
};

ScheduleSlot::ScheduleSlot() : pImpl(new ScheduleSlotBody()) {}

ScheduleSlot::ScheduleSlot(int id, int trainerId, int studentId, const QString& dateTime, bool isBooked)
    : pImpl(new ScheduleSlotBody(id, trainerId, studentId, dateTime, isBooked)) {}

ScheduleSlot::ScheduleSlot(const ScheduleSlot& other)
    : pImpl(other.pImpl ? other.pImpl->clone() : nullptr) {}

ScheduleSlot& ScheduleSlot::operator=(const ScheduleSlot& other) {
    if (this != &other) {
        delete pImpl;
        pImpl = other.pImpl ? other.pImpl->clone() : nullptr;
    }
    return *this;
}

ScheduleSlot::~ScheduleSlot() {
    delete pImpl;
}

int ScheduleSlot::getId() const { return pImpl->id; }
int ScheduleSlot::getTrainerId() const { return pImpl->trainerId; }
int ScheduleSlot::getStudentId() const { return pImpl->studentId; }
QString ScheduleSlot::getDateTime() const { return pImpl->dateTime; }
bool ScheduleSlot::getIsBooked() const { return pImpl->isBooked; }
