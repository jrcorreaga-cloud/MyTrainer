#include <QApplication>
#include <QStackedWidget>
#include "persistence/repositories/UserRepository.h"
#include "persistence/repositories/PlanRepository.h"
#include "persistence/repositories/ScheduleRepository.h"
#include "business_logic/services/AuthService.h"
#include "business_logic/services/AdminService.h"
#include "business_logic/services/UserService.h"
#include "business_logic/services/UserServiceProxy.h"
#include "business_logic/services/PlanService.h"
#include "business_logic/services/SchedulingService.h"
#include "business_logic/services/ReportService.h"
#include "business_logic/services/notifications/NotificationManager.h"
#include "business_logic/services/notifications/EmailNotifier.h"
#include "business_logic/services/notifications/PushNotifier.h"
#include "business_logic/services/notifications/UINotifier.h"
#include "presentation/views/LoginView.h"
#include "presentation/views/DashboardView.h"
#include "presentation/views/RegisterTrainerView.h"
#include "presentation/views/RegisterStudentView.h"
#include "presentation/views/CreatePlanView.h"
#include "presentation/views/ScheduleView.h"
#include "presentation/views/ReportView.h"
#include "presentation/views/BookClassView.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Dependency Injection
    UserRepository userRepository;
    PlanRepository planRepository;
    ScheduleRepository scheduleRepository;

    // Setup Notification System (Observer)
    auto notificationManager = std::make_shared<NotificationManager>();
    notificationManager->attach(std::make_shared<EmailNotifier>());
    notificationManager->attach(std::make_shared<PushNotifier>());
    notificationManager->attach(std::make_shared<UINotifier>());

    AuthService authService(&userRepository);
    AdminService adminService(&userRepository);

    // Setup Security Proxy
    auto baseUserService = std::make_shared<UserService>(&userRepository);
    UserServiceProxy userServiceProxy(baseUserService);

    PlanService planService(&planRepository);

    // Setup Scheduling with Notifications
    SchedulingService scheduleService(&scheduleRepository, notificationManager.get());
    ReportService reportService(&scheduleRepository, &userRepository, &planRepository);

    // UI Routing Setup
    QStackedWidget stackedWidget;
    stackedWidget.setWindowTitle("MyTrainer");
    stackedWidget.resize(800, 600);

    LoginView* loginView = new LoginView(&authService);
    stackedWidget.addWidget(loginView);

    RegisterTrainerView* registerTrainerView = new RegisterTrainerView(&userServiceProxy);
    stackedWidget.addWidget(registerTrainerView);

    RegisterStudentView* registerStudentView = new RegisterStudentView(&userServiceProxy);
    stackedWidget.addWidget(registerStudentView);

    CreatePlanView* createPlanView = new CreatePlanView(&planService);
    stackedWidget.addWidget(createPlanView);

    ScheduleView* scheduleView = new ScheduleView(&scheduleService);
    stackedWidget.addWidget(scheduleView);

    BookClassView* bookClassView = new BookClassView(&scheduleService);
    stackedWidget.addWidget(bookClassView);

    ReportView* reportView = new ReportView(&reportService);
    stackedWidget.addWidget(reportView);

    DashboardView* currentDashboard = nullptr;

    QObject::connect(loginView, &LoginView::loginSuccessful, [&](const User& user) {
        if (currentDashboard) {
            stackedWidget.removeWidget(currentDashboard);
            currentDashboard->deleteLater();
        }

        currentDashboard = new DashboardView(user);
        stackedWidget.addWidget(currentDashboard);

        QObject::connect(currentDashboard, &DashboardView::registerTrainerRequested, [&]() {
            stackedWidget.setCurrentWidget(registerTrainerView);
        });

        QObject::connect(currentDashboard, &DashboardView::registerStudentRequested, [&]() {
            stackedWidget.setCurrentWidget(registerStudentView);
        });

        QObject::connect(currentDashboard, &DashboardView::createPlanRequested, [&]() {
            stackedWidget.setCurrentWidget(createPlanView);
        });

        QObject::connect(currentDashboard, &DashboardView::viewScheduleRequested, [&]() {
            scheduleView->refreshSchedule(); // Refresh data before showing
            stackedWidget.setCurrentWidget(scheduleView);
        });

        QObject::connect(currentDashboard, &DashboardView::bookClassRequested, [&]() {
            bookClassView->setCurrentStudentId(user.getId());
            bookClassView->refreshAvailableSlots();
            stackedWidget.setCurrentWidget(bookClassView);
        });

        QObject::connect(currentDashboard, &DashboardView::viewKPIsRequested, [&]() {
            reportView->refreshReport(); // Refresh report data before showing
            stackedWidget.setCurrentWidget(reportView);
        });

        QObject::connect(currentDashboard, &DashboardView::logoutRequested, [&]() {
            stackedWidget.setCurrentWidget(loginView);
        });

        stackedWidget.setCurrentWidget(currentDashboard);
    });

    auto goBackToDashboard = [&]() {
        if (currentDashboard) {
            stackedWidget.setCurrentWidget(currentDashboard);
        }
    };

    QObject::connect(registerTrainerView, &RegisterTrainerView::backRequested, goBackToDashboard);
    QObject::connect(registerStudentView, &RegisterStudentView::backRequested, goBackToDashboard);
    QObject::connect(createPlanView, &CreatePlanView::backRequested, goBackToDashboard);
    QObject::connect(scheduleView, &ScheduleView::backRequested, goBackToDashboard);
    QObject::connect(bookClassView, &BookClassView::backRequested, goBackToDashboard);
    QObject::connect(reportView, &ReportView::backRequested, goBackToDashboard);

    stackedWidget.show();
    return app.exec();
}
