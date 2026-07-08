#include "DashboardView.h"
#include <QVBoxLayout>

DashboardView::DashboardView(const User& user, QWidget *parent)
    : QWidget(parent) {
    setupUi(user);
}

void DashboardView::setupUi(const User& user) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* welcomeLabel = new QLabel(QString("Welcome, %1!").arg(user.getEmail()), this);
    welcomeLabel->setStyleSheet("font-size: 20px; font-weight: bold;");
    layout->addWidget(welcomeLabel);

    QLabel* roleLabel = new QLabel(QString("Your Role: %1").arg(getRoleName(user.getRole())), this);
    layout->addWidget(roleLabel);

    if (user.getRole() == Role::Admin) {
        QLabel* adminPanel = new QLabel("--- Admin Dashboard ---\nManage Trainers and Plans here.", this);
        layout->addWidget(adminPanel);
        
        QPushButton* registerTrainerBtn = new QPushButton("Register Personal Trainer", this);
        QPushButton* registerStudentBtn = new QPushButton("Register Student", this);
        
        layout->addWidget(registerTrainerBtn);
        layout->addWidget(registerStudentBtn);
        
        connect(registerTrainerBtn, &QPushButton::clicked, this, &DashboardView::onRegisterTrainerClicked);
        connect(registerStudentBtn, &QPushButton::clicked, this, &DashboardView::onRegisterStudentClicked);

    } else if (user.getRole() == Role::Trainer) {
        QLabel* trainerPanel = new QLabel("--- Trainer Dashboard ---\nManage your schedule here.", this);
        layout->addWidget(trainerPanel);
    } else {
        QLabel* studentPanel = new QLabel("--- Student Dashboard ---\nBook classes and view your plan here.", this);
        layout->addWidget(studentPanel);
    }

    layout->addStretch();
}

void DashboardView::onRegisterTrainerClicked() {
    emit registerTrainerRequested();
}

void DashboardView::onRegisterStudentClicked() {
    emit registerStudentRequested();
}

QString DashboardView::getRoleName(Role role) const {
    switch (role) {
        case Role::Admin: return "Administrator";
        case Role::Trainer: return "Personal Trainer";
        case Role::Student: return "Student";
        default: return "Unknown";
    }
}
