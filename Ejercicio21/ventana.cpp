#include "ventana.h"
#include <QVBoxLayout>

Ventana::Ventana(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    backButton = new QPushButton("Volver", this);
    mainLayout->addWidget(backButton);

    connect(backButton, SIGNAL(clicked()), this, SIGNAL(backToLogin()));

    resize(400, 300);
}

Ventana::~Ventana() {}
