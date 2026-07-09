#pragma once
#include <QString>

class IPlanService {
public:
    virtual ~IPlanService() = default;
    virtual bool createPlan(const QString& name, double price, int durationMonths) = 0;
};
