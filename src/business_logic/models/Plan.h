#pragma once
#include <QString>

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
    int m_id;
    QString m_name;
    double m_price;
    int m_durationMonths;
};
