#pragma once

#include "IAuthService.h"
#include "../../persistence/repositories/IUserRepository.h"

class AuthService : public IAuthService {
public:
    explicit AuthService(IUserRepository* userRepository);
    std::optional<User> login(const QString& email, const QString& password) override;

private:
    IUserRepository* m_userRepository;
};
