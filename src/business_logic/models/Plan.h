#pragma once
#include <QString>

class PlanBody;

/**
 * @class Plan
 * @brief Handle class for Plan entity using Pimpl idiom.
 */
class Plan {
public:
    Plan();
    Plan(int id, const QString& name, double price, int durationMonths);
    Plan(const Plan& other);
    Plan& operator=(const Plan& other);
    ~Plan();

    int getId() const;
    QString getName() const;
    double getPrice() const;
    int getDurationMonths() const;

private:
    PlanBody* pImpl;
};
