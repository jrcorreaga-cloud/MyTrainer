#include "AdminService.h"
#include "../models/User.h"
#include "../models/ModelFactory.h"

AdminService::AdminService(IUserRepository* userRepository) : m_userRepository(userRepository) {}
