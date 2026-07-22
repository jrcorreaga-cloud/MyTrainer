#pragma once

#include "IObserver.h"
#include <QMessageBox>
#include <QString>

/**
 * @brief Concrete observer that shows a pop-up window in the UI.
 */
class UINotifier : public IObserver {
public:
    void update(const QString& message, const QString& userEmail) override {
        // Muestra una ventana de alerta emergente en la interfaz gráfica
        QString fullMessage = message + "\n\nEnviado a: " + userEmail;
        QMessageBox::information(nullptr, "Nueva Notificación - MyTrainer", fullMessage);
    }
};
