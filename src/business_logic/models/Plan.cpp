#include "Plan.h"

Plan::Plan() : m_id(0), m_name(""), m_price(0.0), m_durationMonths(0) {}

Plan::Plan(int id, const QString& name, double price, int durationMonths)
    : m_id(id), m_name(name), m_price(price), m_durationMonths(durationMonths) {}

Plan::Plan(const Plan& other)
    : m_id(other.m_id), m_name(other.m_name), m_price(other.m_price), m_durationMonths(other.m_durationMonths) {}

Plan& Plan::operator=(const Plan& other) {
    if (this != &other) {
        m_id = other.m_id;
        m_name = other.m_name;
        m_price = other.m_price;
        m_durationMonths = other.m_durationMonths;
    }
    return *this;
}

Plan::~Plan() {}

int Plan::getId() const { return m_id; }
QString Plan::getName() const { return m_name; }
double Plan::getPrice() const { return m_price; }
int Plan::getDurationMonths() const { return m_durationMonths; }
