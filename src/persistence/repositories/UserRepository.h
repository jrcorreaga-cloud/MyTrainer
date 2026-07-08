#pragma once

#include <vector>
#include "IUserRepository.h"

class UserRepository : public IUserRepository {
public:
    UserRepository();
    std::optional<User> getUserByEmail(const QString& email) override;
    bool addUser(const User& user) override;

private:
    std::vector<User> m_mockUsers;
    int m_nextId;
};
