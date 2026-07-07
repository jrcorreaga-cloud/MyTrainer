#include "User.h"

User::User(int id, const QString& email, const QString& passwordHash, Role role)
    : m_id(id), m_email(email), m_passwordHash(passwordHash), m_role(role) {}

int User::getId() const { return m_id; }
QString User::getEmail() const { return m_email; }
QString User::getPasswordHash() const { return m_passwordHash; }
Role User::getRole() const { return m_role; }
