#pragma once

#include <QString>

class IAdminService {
public:
    virtual ~IAdminService() = default;
    virtual bool registerTrainer(const QString& email, const QString& password, const QString& specialties) = 0;
    virtual bool registerStudent(const QString& email, const QString& password) = 0;
};
