#include "PushNotifier.h"
#include <iostream>

void PushNotifier::update(const QString& message, const QString& userEmail) {
    // Simulates sending a push notification to an app
    std::cout << "[APP PUSH to " << userEmail.toStdString() << "]: " 
              << message.toStdString() << std::endl;
}
