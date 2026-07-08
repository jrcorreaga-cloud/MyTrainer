#pragma once

#include <optional>
#include <QString>
#include "../../business_logic/models/User.h"

class IUserRepository {
public:
    virtual ~IUserRepository() = default;
    virtual std::optional<User> getUserByEmail(const QString& email) = 0;
    virtual bool addUser(const User& user) = 0;
};
