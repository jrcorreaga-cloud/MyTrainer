#include <QApplication>
#include <QStackedWidget>
#include "persistence/repositories/UserRepository.h"
#include "persistence/repositories/PlanRepository.h"
#include "persistence/repositories/ScheduleRepository.h"
#include "business_logic/services/AuthService.h"
#include "business_logic/services/AdminService.h"
#include "business_logic/services/UserService.h"
#include "business_logic/services/PlanService.h"
#include "business_logic/services/SchedulingService.h"
#include "business_logic/services/ReportService.h"
#include "presentation/views/LoginView.h"
#include "presentation/views/DashboardView.h"
#include "presentation/views/RegisterTrainerView.h"
#include "presentation/views/RegisterStudentView.h"
#include "presentation/views/CreatePlanView.h"
#include "presentation/views/ScheduleView.h"
#include "presentation/views/ReportView.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Dependency Injection
    UserRepository userRepository;
    PlanRepository planRepository;
    ScheduleRepository scheduleRepository;

    AuthService authService(&userRepository);
    AdminService adminService(&userRepository);
    UserService userService(&userRepository);
    PlanService planService(&planRepository);
    SchedulingService scheduleService(&scheduleRepository);
    ReportService reportService(&scheduleRepository, &userRepository, &planRepository);

    // UI Routing Setup
    QStackedWidget stackedWidget;
    stackedWidget.setWindowTitle("MyTrainer");
    stackedWidget.resize(800, 600);

    LoginView* loginView = new LoginView(&authService);
    stackedWidget.addWidget(loginView);

    RegisterTrainerView* registerTrainerView = new RegisterTrainerView(&userService);
    stackedWidget.addWidget(registerTrainerView);

    RegisterStudentView* registerStudentView = new RegisterStudentView(&userService);
    stackedWidget.addWidget(registerStudentView);

    CreatePlanView* createPlanView = new CreatePlanView(&planService);
    stackedWidget.addWidget(createPlanView);

    ScheduleView* scheduleView = new ScheduleView(&scheduleService);
    stackedWidget.addWidget(scheduleView);

    ReportView* reportView = new ReportView(&reportService);
    stackedWidget.addWidget(reportView);

    QObject::connect(loginView, &LoginView::loginSuccessful, [&](const User& user) {
        DashboardView* dashboardView = new DashboardView(user);
        stackedWidget.addWidget(dashboardView);

        QObject::connect(dashboardView, &DashboardView::registerTrainerRequested, [&]() {
            stackedWidget.setCurrentWidget(registerTrainerView);
        });

        QObject::connect(dashboardView, &DashboardView::registerStudentRequested, [&]() {
            stackedWidget.setCurrentWidget(registerStudentView);
        });

        QObject::connect(dashboardView, &DashboardView::createPlanRequested, [&]() {
            stackedWidget.setCurrentWidget(createPlanView);
        });

        QObject::connect(dashboardView, &DashboardView::viewScheduleRequested, [&]() {
            scheduleView->refreshSchedule(); // Refresh data before showing
            stackedWidget.setCurrentWidget(scheduleView);
        });

        QObject::connect(dashboardView, &DashboardView::viewKPIsRequested, [&]() {
            reportView->refreshReport(); // Refresh report data before showing
            stackedWidget.setCurrentWidget(reportView);
        });

        stackedWidget.setCurrentWidget(dashboardView);
    });

    auto goBackToDashboard = [&]() {
        for (int i = 0; i < stackedWidget.count(); ++i) {
            if (qobject_cast<DashboardView*>(stackedWidget.widget(i))) {
                stackedWidget.setCurrentIndex(i);
                break;
            }
        }
    };

    QObject::connect(registerTrainerView, &RegisterTrainerView::backRequested, goBackToDashboard);
    QObject::connect(registerStudentView, &RegisterStudentView::backRequested, goBackToDashboard);
    QObject::connect(createPlanView, &CreatePlanView::backRequested, goBackToDashboard);
    QObject::connect(scheduleView, &ScheduleView::backRequested, goBackToDashboard);
    QObject::connect(reportView, &ReportView::backRequested, goBackToDashboard);

    stackedWidget.show();
    return app.exec();
}
