#include "CreatePlanView.h"
#include <QVBoxLayout>
#include <QFormLayout>

CreatePlanView::CreatePlanView(IPlanService* planService, QWidget *parent)
    : QWidget(parent), m_planService(planService) {
    setupUi();
}

void CreatePlanView::setupUi() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("Create Fitness Plan", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; margin-bottom: 20px;");
    mainLayout->addWidget(titleLabel);

    QFormLayout* formLayout = new QFormLayout();

    m_nameInput = new QLineEdit(this);
    formLayout->addRow("Plan Name (e.g., Monthly):", m_nameInput);

    m_priceInput = new QLineEdit(this);
    formLayout->addRow("Price ($):", m_priceInput);

    m_durationInput = new QLineEdit(this);
    formLayout->addRow("Duration (Months):", m_durationInput);

    mainLayout->addLayout(formLayout);

    m_statusLabel = new QLabel("", this);
    m_statusLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(m_statusLabel);

    m_createButton = new QPushButton("Create Plan", this);
    mainLayout->addWidget(m_createButton);

    m_backButton = new QPushButton("Back to Dashboard", this);
    mainLayout->addWidget(m_backButton);

    connect(m_createButton, &QPushButton::clicked, this, &CreatePlanView::onCreateClicked);
    connect(m_backButton, &QPushButton::clicked, this, &CreatePlanView::onBackClicked);
}

void CreatePlanView::onCreateClicked() {
    QString name = m_nameInput->text();
    double price = m_priceInput->text().toDouble();
    int duration = m_durationInput->text().toInt();

    if (m_planService->createPlan(name, price, duration)) {
        m_statusLabel->setStyleSheet("color: green;");
        m_statusLabel->setText("Plan created successfully!");
        m_nameInput->clear();
        m_priceInput->clear();
        m_durationInput->clear();
    } else {
        m_statusLabel->setStyleSheet("color: red;");
        m_statusLabel->setText("Failed to create plan. Check your inputs.");
    }
}

void CreatePlanView::onBackClicked() {
    emit backRequested();
}
