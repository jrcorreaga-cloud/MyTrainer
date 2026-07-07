#include <QApplication>
#include <QStackedWidget>
#include "persistence/repositories/UserRepository.h"
#include "business_logic/services/AuthService.h"
#include "presentation/views/LoginView.h"
#include "presentation/views/DashboardView.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Dependency Injection
    UserRepository userRepository;
    AuthService authService(&userRepository);

    // UI Routing Setup
    QStackedWidget stackedWidget;
    stackedWidget.setWindowTitle("MyTrainer");
    stackedWidget.resize(800, 600);

    LoginView* loginView = new LoginView(&authService);
    stackedWidget.addWidget(loginView);

    QObject::connect(loginView, &LoginView::loginSuccessful, [&](const User& user) {
        DashboardView* dashboardView = new DashboardView(user);
        stackedWidget.addWidget(dashboardView);
        stackedWidget.setCurrentWidget(dashboardView);
    });

    stackedWidget.show();
    return app.exec();
}
