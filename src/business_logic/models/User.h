#pragma once

#include <QString>
#include "Role.h"

class User {
public:
    User();
    User(int id, const QString& email, const QString& passwordHash, Role role, const QString& specialties = "");
    User(const User& other);
    User& operator=(const User& other);
    ~User();

    int getId() const;
    QString getEmail() const;
    QString getPasswordHash() const;
    Role getRole() const;
    QString getSpecialties() const;

private:
    int m_id;
    QString m_email;
    QString m_passwordHash;
    Role m_role;
    QString m_specialties;
};
