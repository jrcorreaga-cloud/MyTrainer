#include "User.h"

// The Body class defined only in the CPP file
class UserBody {
public:
    int id;
    QString email;
    QString passwordHash;
    Role role;
    QString specialties;

    UserBody() : id(0), role(Role::Student) {}
    UserBody(int i, QString e, QString p, Role r, QString s)
        : id(i), email(e), passwordHash(p), role(r), specialties(s) {}
    UserBody* clone() const { return new UserBody(*this); }
};

User::User() : pImpl(new UserBody()) {}

User::User(int id, const QString& email, const QString& passwordHash, Role role, const QString& specialties)
    : pImpl(new UserBody(id, email, passwordHash, role, specialties)) {}

User::User(const User& other) : pImpl(other.pImpl ? other.pImpl->clone() : nullptr) {}

User& User::operator=(const User& other) {
    if (this != &other) {
        delete pImpl;
        pImpl = other.pImpl ? other.pImpl->clone() : nullptr;
    }
    return *this;
}

User::~User() {
    delete pImpl;
}

int User::getId() const { return pImpl->id; }
QString User::getEmail() const { return pImpl->email; }
QString User::getPasswordHash() const { return pImpl->passwordHash; }
Role User::getRole() const { return pImpl->role; }
QString User::getSpecialties() const { return pImpl->specialties; }
