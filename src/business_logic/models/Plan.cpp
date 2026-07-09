#include "Plan.h"

class PlanBody {
public:
    int id;
    QString name;
    double price;
    int durationMonths;

    PlanBody() : id(0), price(0.0), durationMonths(0) {}
    PlanBody(int i, QString n, double p, int d) : id(i), name(n), price(p), durationMonths(d) {}
    PlanBody* clone() const { return new PlanBody(*this); }
};

Plan::Plan() : pImpl(new PlanBody()) {}

Plan::Plan(int id, const QString& name, double price, int durationMonths)
    : pImpl(new PlanBody(id, name, price, durationMonths)) {}

Plan::Plan(const Plan& other) : pImpl(other.pImpl ? other.pImpl->clone() : nullptr) {}

Plan& Plan::operator=(const Plan& other) {
    if (this != &other) {
        delete pImpl;
        pImpl = other.pImpl ? other.pImpl->clone() : nullptr;
    }
    return *this;
}

Plan::~Plan() {
    delete pImpl;
}

int Plan::getId() const { return pImpl->id; }
QString Plan::getName() const { return pImpl->name; }
double Plan::getPrice() const { return pImpl->price; }
int Plan::getDurationMonths() const { return pImpl->durationMonths; }
