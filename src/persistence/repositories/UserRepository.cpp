#include "UserRepository.h"

UserRepository::UserRepository() {
    m_mockUsers.push_back(User(1, "admin@mytrainer.com", "admin123", Role::Admin));
    m_mockUsers.push_back(User(2, "trainer@mytrainer.com", "trainer123", Role::Trainer));
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
