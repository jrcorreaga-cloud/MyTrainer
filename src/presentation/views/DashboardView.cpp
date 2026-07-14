#include "DashboardView.h"
#include <QVBoxLayout>
#include <QApplication>

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
        QPushButton* createPlanBtn = new QPushButton("Create Fitness Plan", this);
        QPushButton* viewKPIsBtn = new QPushButton("View KPI Reports", this);
        
        layout->addWidget(registerTrainerBtn);
        layout->addWidget(registerStudentBtn);
        layout->addWidget(createPlanBtn);
        layout->addWidget(viewKPIsBtn);
        
        connect(registerTrainerBtn, &QPushButton::clicked, this, &DashboardView::onRegisterTrainerClicked);
        connect(registerStudentBtn, &QPushButton::clicked, this, &DashboardView::onRegisterStudentClicked);
        connect(createPlanBtn, &QPushButton::clicked, this, &DashboardView::onCreatePlanClicked);
        connect(viewKPIsBtn, &QPushButton::clicked, this, &DashboardView::onViewKPIsClicked);

    } else if (user.getRole() == Role::Trainer) {
        QLabel* trainerPanel = new QLabel("--- Trainer Dashboard ---\nManage your schedule here.", this);
        layout->addWidget(trainerPanel);
        
        QPushButton* viewScheduleBtn = new QPushButton("View My Schedule", this);
        layout->addWidget(viewScheduleBtn);
        connect(viewScheduleBtn, &QPushButton::clicked, this, &DashboardView::onViewScheduleClicked);
        
    } else {
        QLabel* studentPanel = new QLabel("--- Student Dashboard ---\nBook classes and view your plan here.", this);
        layout->addWidget(studentPanel);
        
        QPushButton* viewScheduleBtnS = new QPushButton("View Available Classes", this);
        layout->addWidget(viewScheduleBtnS);
        connect(viewScheduleBtnS, &QPushButton::clicked, this, &DashboardView::onViewScheduleClicked);
        
        QPushButton* bookClassBtnS = new QPushButton("Book a Class", this);
        layout->addWidget(bookClassBtnS);
        connect(bookClassBtnS, &QPushButton::clicked, this, &DashboardView::onBookClassClicked);
    }
    
    QPushButton* logoutBtn = new QPushButton("Logout", this);
    logoutBtn->setStyleSheet("color: red; font-weight: bold; margin-top: 15px;");
    layout->addWidget(logoutBtn);
    connect(logoutBtn, &QPushButton::clicked, this, &DashboardView::onLogoutClicked);
    
    QPushButton* exitBtn = new QPushButton("Exit Program", this);
    exitBtn->setStyleSheet("background-color: darkred; color: white; font-weight: bold; margin-top: 5px;");
    layout->addWidget(exitBtn);
    connect(exitBtn, &QPushButton::clicked, qApp, &QApplication::quit);

    layout->addStretch();
}

void DashboardView::onRegisterTrainerClicked() {
    emit registerTrainerRequested();
}

void DashboardView::onRegisterStudentClicked() {
    emit registerStudentRequested();
}

void DashboardView::onCreatePlanClicked() {
    emit createPlanRequested();
}

void DashboardView::onViewScheduleClicked() {
    emit viewScheduleRequested();
}

void DashboardView::onBookClassClicked() {
    emit bookClassRequested();
}

void DashboardView::onLogoutClicked() {
    emit logoutRequested();
}

void DashboardView::onViewKPIsClicked() {
    emit viewKPIsRequested();
}

QString DashboardView::getRoleName(Role role) const {
    switch (role) {
        case Role::Admin: return "Administrator";
        case Role::Trainer: return "Personal Trainer";
        case Role::Student: return "Student";
        default: return "Unknown";
    }
}