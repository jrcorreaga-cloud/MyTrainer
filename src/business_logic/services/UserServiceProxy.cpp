#include "UserServiceProxy.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <iostream>

UserServiceProxy::UserServiceProxy(std::shared_ptr<IUserService> realService)
    : m_realService(realService) {}

void UserServiceProxy::logOperation(const QString& operation, const QString& details) {
    QFile file("audit.log");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        out << "[" << timestamp << "] [AUDIT] " << operation << " - " << details << "\n";
        file.close();
    } else {
        std::cerr << "Failed to open audit.log for writing." << std::endl;
    }
}

bool UserServiceProxy::registerTrainer(const QString& email, const QString& password, const QString& specialties) {
    logOperation("REGISTER_TRAINER_ATTEMPT", "Email: " + email);

    // Delegate to real service
    bool success = m_realService->registerTrainer(email, password, specialties);

    if (success) {
        logOperation("REGISTER_TRAINER_SUCCESS", "Trainer registered successfully.");
    } else {
        logOperation("REGISTER_TRAINER_FAILURE", "Failed to register trainer.");
    }

    return success;
}

bool UserServiceProxy::registerStudent(const QString& email, const QString& password) {
    logOperation("REGISTER_STUDENT_ATTEMPT", "Email: " + email);

    // Delegate to real service
    bool success = m_realService->registerStudent(email, password);

    if (success) {
        logOperation("REGISTER_STUDENT_SUCCESS", "Student registered successfully.");
    } else {
        logOperation("REGISTER_STUDENT_FAILURE", "Failed to register student.");
    }

    return success;
}
