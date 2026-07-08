#include "UserRepository.h"

UserRepository::UserRepository() : m_nextId(4) {
    m_mockUsers.push_back(User(1, "admin@mytrainer.com", "admin123", Role::Admin));
    m_mockUsers.push_back(User(2, "trainer@mytrainer.com", "trainer123", Role::Trainer, "Weightlifting"));
    m_mockUsers.push_back(User(3, "student@mytrainer.com", "student123", Role::Student));
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
    User newUser = user;
    // Overriding ID logic just for mock safety
    User toSave(m_nextId++, newUser.getEmail(), newUser.getPasswordHash(), newUser.getRole(), newUser.getSpecialties());
    m_mockUsers.push_back(toSave);
    return true;
}
