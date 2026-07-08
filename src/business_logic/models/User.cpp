#include "User.h"

User::User() : m_id(0), m_email(""), m_passwordHash(""), m_role(Role::Student), m_specialties("") {}

User::User(int id, const QString& email, const QString& passwordHash, Role role, const QString& specialties)
    : m_id(id), m_email(email), m_passwordHash(passwordHash), m_role(role), m_specialties(specialties) {}

User::User(const User& other) 
    : m_id(other.m_id), m_email(other.m_email), 
      m_passwordHash(other.m_passwordHash), m_role(other.m_role), m_specialties(other.m_specialties) {}

User& User::operator=(const User& other) {
    if (this != &other) {
        m_id = other.m_id;
        m_email = other.m_email;
        m_passwordHash = other.m_passwordHash;
        m_role = other.m_role;
        m_specialties = other.m_specialties;
    }
    return *this;
}

User::~User() {}

int User::getId() const { return m_id; }
QString User::getEmail() const { return m_email; }
QString User::getPasswordHash() const { return m_passwordHash; }
Role User::getRole() const { return m_role; }
QString User::getSpecialties() const { return m_specialties; }
