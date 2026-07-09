#include "AdminService.h"
#include "../models/User.h"
#include "../models/ModelFactory.h"

AdminService::AdminService(IUserRepository* userRepository) : m_userRepository(userRepository) {}

bool AdminService::registerTrainer(const QString& email, const QString& password, const QString& specialties) {
    if (email.isEmpty() || password.isEmpty()) return false;
    
    User newUser = ModelFactory::createUser(0, email, password, Role::Trainer, specialties);
    return m_userRepository->addUser(newUser);
}

bool AdminService::registerStudent(const QString& email, const QString& password) {
    if (email.isEmpty() || password.isEmpty()) return false;

    User newUser = ModelFactory::createUser(0, email, password, Role::Student, "");
    return m_userRepository->addUser(newUser);
}
