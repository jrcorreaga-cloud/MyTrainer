#include <QApplication>
#include <QStackedWidget>
#include "persistence/repositories/UserRepository.h"
#include "business_logic/services/AuthService.h"
#include "business_logic/services/AdminService.h"
#include "presentation/views/LoginView.h"
#include "presentation/views/DashboardView.h"
#include "presentation/views/RegisterTrainerView.h"
#include "presentation/views/RegisterStudentView.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Dependency Injection
    UserRepository userRepository;
    AuthService authService(&userRepository);
    AdminService adminService(&userRepository);

    // UI Routing Setup
    QStackedWidget stackedWidget;
    stackedWidget.setWindowTitle("MyTrainer");
    stackedWidget.resize(800, 600);

    LoginView* loginView = new LoginView(&authService);
    stackedWidget.addWidget(loginView);

    RegisterTrainerView* registerTrainerView = new RegisterTrainerView(&adminService);
    stackedWidget.addWidget(registerTrainerView);

    RegisterStudentView* registerStudentView = new RegisterStudentView(&adminService);
    stackedWidget.addWidget(registerStudentView);

    QObject::connect(loginView, &LoginView::loginSuccessful, [&](const User& user) {
        DashboardView* dashboardView = new DashboardView(user);
        stackedWidget.addWidget(dashboardView);
        
        QObject::connect(dashboardView, &DashboardView::registerTrainerRequested, [&]() {
            stackedWidget.setCurrentWidget(registerTrainerView);
        });
        
        QObject::connect(dashboardView, &DashboardView::registerStudentRequested, [&]() {
            stackedWidget.setCurrentWidget(registerStudentView);
        });

        stackedWidget.setCurrentWidget(dashboardView);
    });

    QObject::connect(registerTrainerView, &RegisterTrainerView::backRequested, [&]() {
        // Find the dashboard view and go back to it
        for (int i = 0; i < stackedWidget.count(); ++i) {
            if (qobject_cast<DashboardView*>(stackedWidget.widget(i))) {
                stackedWidget.setCurrentIndex(i);
                break;
            }
        }
    });

    QObject::connect(registerStudentView, &RegisterStudentView::backRequested, [&]() {
        for (int i = 0; i < stackedWidget.count(); ++i) {
            if (qobject_cast<DashboardView*>(stackedWidget.widget(i))) {
                stackedWidget.setCurrentIndex(i);
                break;
            }
        }
    });

    stackedWidget.show();
    return app.exec();
}
