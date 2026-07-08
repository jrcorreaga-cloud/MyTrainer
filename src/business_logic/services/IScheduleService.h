#pragma once
#include <vector>
#include <QString>

class IScheduleService {
public:
    virtual ~IScheduleService() = default;
    virtual std::vector<QString> getFormattedSchedule() = 0;
};
