#include "EmailNotifier.h"
#include <iostream>

void EmailNotifier::update(const QString& message, const QString& userEmail) {
    // Simulates sending an email
    std::cout << "[EMAIL NOTIFICATION to " << userEmail.toStdString() << "]: " 
              << message.toStdString() << std::endl;
}
