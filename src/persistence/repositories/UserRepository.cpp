#include "UserRepository.h"
#include "../../business_logic/models/ModelFactory.h"

UserRepository::UserRepository() : m_nextId(1) {
    // Mock users
    m_mockUsers.push_back(ModelFactory::createUser(m_nextId++, "admin@mytrainer.com", "admin123", Role::Admin));
    m_mockUsers.push_back(ModelFactory::createUser(m_nextId++, "trainer@mytrainer.com", "trainer123", Role::Trainer, "Weightlifting"));
    m_mockUsers.push_back(ModelFactory::createUser(m_nextId++, "student@mytrainer.com", "student123", Role::Student));
}

std::optional<User> UserRepository::getUserByEmail(const QString& email) {
    for (const auto& user : m_mockUsers) {
        if (user.getEmail() == email) {
            return user;
        }
    }
    return std::nullopt;
}
bool UserRepository::addUser(const User& user) {
    for (const auto& existingUser : m_mockUsers) {
        if (existingUser.getEmail() == user.getEmail()) {
            return false; // Email already exists
        }
    }
    User toSave = ModelFactory::createUser(m_nextId++, user.getEmail(), user.getPasswordHash(), user.getRole(), user.getSpecialties());
    m_mockUsers.push_back(toSave);
    return true;
}
