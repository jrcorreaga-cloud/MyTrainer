#include "AuthService.h"

AuthService::AuthService(IUserRepository* userRepository)
    : m_userRepository(userRepository) {}

std::optional<User> AuthService::login(const QString& email, const QString& password) {
    auto userOpt = m_userRepository->getUserByEmail(email);
    if (userOpt.has_value()) {
        if (userOpt.value().getPasswordHash() == password) {
            return userOpt.value();
        }
    }
    return std::nullopt;
}
