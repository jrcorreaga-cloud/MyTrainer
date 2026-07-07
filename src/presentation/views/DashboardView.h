#pragma once

#include <QWidget>
#include <QLabel>
#include "../../business_logic/models/User.h"

class DashboardView : public QWidget {
    Q_OBJECT

public:
    explicit DashboardView(const User& user, QWidget *parent = nullptr);

private:
    void setupUi(const User& user);
    QString getRoleName(Role role) const;
};
