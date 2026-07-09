#include "AdminService.h"
#include "../models/User.h"

AdminService::AdminService(IUserRepository* userRepository)
    : m_userRepository(userRepository) {}

bool AdminService::registerTrainer(const QString& email, const QString& password, const QString& specialties) {
    if (email.isEmpty() || password.isEmpty() || specialties.isEmpty()) {
        return false;
    }
    User newTrainer(0, email, password, Role::Trainer, specialties);
    return m_userRepository->addUser(newTrainer);
}

bool AdminService::registerStudent(const QString& email, const QString& password) {
    if (email.isEmpty() || password.isEmpty()) {
        return false;
    }
    User newStudent(0, email, password, Role::Student);
    return m_userRepository->addUser(newStudent);
}
