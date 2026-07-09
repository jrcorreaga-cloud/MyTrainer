#pragma once

#include "IAdminService.h"
#include "../../persistence/repositories/IUserRepository.h"

class AdminService : public IAdminService {
public:
    explicit AdminService(IUserRepository* userRepository);

    bool registerTrainer(const QString& email, const QString& password, const QString& specialties) override;
    bool registerStudent(const QString& email, const QString& password) override;

private:
    IUserRepository* m_userRepository;
};
