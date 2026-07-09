/**
 * @file DashboardView.h
 * @brief Core functionality for DashboardView
 */

#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "../../business_logic/models/User.h"

/**
 * @class DashboardView
 * @brief Main class for DashboardView
 */
class DashboardView : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief Executes DashboardView operation.
     * @return Result of the operation.
     */
    explicit DashboardView(const User& user, QWidget *parent = nullptr);

signals:
    /**
     * @brief Executes registerTrainerRequested operation.
     * @return Result of the operation.
     */
    void registerTrainerRequested();
    /**
     * @brief Executes registerStudentRequested operation.
     * @return Result of the operation.
     */
    void registerStudentRequested();
    /**
     * @brief Executes createPlanRequested operation.
     * @return Result of the operation.
     */
    void createPlanRequested();
    /**
     * @brief Executes viewScheduleRequested operation.
     * @return Result of the operation.
     */
    void viewScheduleRequested();
    /**
     * @brief Executes bookClassRequested operation.
     * @return Result of the operation.
     */
    void bookClassRequested();
    /**
     * @brief Executes logoutRequested operation.
     * @return Result of the operation.
     */
    void logoutRequested();

private slots:
    /**
     * @brief Executes onRegisterTrainerClicked operation.
     * @return Result of the operation.
     */
    void onRegisterTrainerClicked();
    /**
     * @brief Executes onRegisterStudentClicked operation.
     * @return Result of the operation.
     */
    void onRegisterStudentClicked();
    /**
     * @brief Executes onCreatePlanClicked operation.
     * @return Result of the operation.
     */
    void onCreatePlanClicked();
    /**
     * @brief Executes onViewScheduleClicked operation.
     * @return Result of the operation.
     */
    void onViewScheduleClicked();
    /**
     * @brief Executes onBookClassClicked operation.
     * @return Result of the operation.
     */
    void onBookClassClicked();
    /**
     * @brief Executes onLogoutClicked operation.
     * @return Result of the operation.
     */
    void onLogoutClicked();

private:
    /**
     * @brief Executes setupUi operation.
     * @return Result of the operation.
     */
    void setupUi(const User& user);
    /**
     * @brief Executes getRoleName operation.
     * @return Result of the operation.
     */
    QString getRoleName(Role role) const;
};
