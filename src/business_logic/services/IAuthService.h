#pragma once

#include <optional>
#include <QString>
#include "../models/User.h"

class IAuthService {
public:
    virtual ~IAuthService() = default;
    virtual std::optional<User> login(const QString& email, const QString& password) = 0;
};
