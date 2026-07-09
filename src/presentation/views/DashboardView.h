#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "../../business_logic/models/User.h"

class DashboardView : public QWidget {
    Q_OBJECT

public:
    explicit DashboardView(const User& user, QWidget *parent = nullptr);

signals:
    void registerTrainerRequested();
    void registerStudentRequested();
    void createPlanRequested();
    void viewScheduleRequested();
    void bookClassRequested();
    void logoutRequested();

private slots:
    void onRegisterTrainerClicked();
    void onRegisterStudentClicked();
    void onCreatePlanClicked();
    void onViewScheduleClicked();
    void onBookClassClicked();
    void onLogoutClicked();

private:
    void setupUi(const User& user);
    QString getRoleName(Role role) const;
};
