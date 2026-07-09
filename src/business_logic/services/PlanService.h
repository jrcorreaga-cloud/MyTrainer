#pragma once
#include "IPlanService.h"
#include "../../persistence/repositories/IPlanRepository.h"

class PlanService : public IPlanService {
public:
    explicit PlanService(IPlanRepository* planRepository);
    bool createPlan(const QString& name, double price, int durationMonths) override;

private:
    IPlanRepository* m_planRepository;
};
