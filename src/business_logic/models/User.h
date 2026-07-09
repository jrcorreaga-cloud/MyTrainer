#pragma once
#include <QString>

/**
 * @enum Role
 * @brief Defines the access level of a User in the system.
 */
enum class Role {
    Admin,
    Trainer,
    Student
};

class UserBody; // Forward declaration for Handle-Body (Pimpl) idiom

/**
 * @class User
 * @brief Handle class for User entity using the Bridge/Pimpl pattern.
 */
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
    UserBody* pImpl; // Pointer to implementation (Body)
};
