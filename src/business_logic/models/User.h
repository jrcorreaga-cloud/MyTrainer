#pragma once

#include <QString>
#include "Role.h"

class User {
public:
    User(); //default
    User(int id, const QString& email, const QString& passwordHash, Role role);
    User(const User& other); //copy
    User& operator=(const User& other); //Assignment
    ~User();

    int getId() const;
    QString getEmail() const;
    QString getPasswordHash() const;
    Role getRole() const;

private:
    int m_id;
    QString m_email;
    QString m_passwordHash;
    Role m_role;
};
