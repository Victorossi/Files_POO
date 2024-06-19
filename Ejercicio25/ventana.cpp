#include "ventana.h"
#include "admin_db.h"
#include <QMessageBox>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *usernameLabel = new QLabel("Usuario:", this);
    usuarioEdit = new QLineEdit(this);
    layout->addWidget(usernameLabel);
    layout->addWidget(usuarioEdit);

    QLabel *passwordLabel = new QLabel("Clave:", this);
    claveEdit = new QLineEdit(this);
    claveEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordLabel);
    layout->addWidget(claveEdit);

    QPushButton *registerButton = new QPushButton("Registro", this);
    layout->addWidget(registerButton);
    connect(registerButton, SIGNAL(clicked()), this, SLOT(registrar_button()));

    setLayout(layout);
}

void Ventana::registrar_button()
{
    QString username = usuarioEdit->text();
    QString password = claveEdit->text();

    if (AdminDB::instance().addUser(username, password)) {
        QMessageBox::information(this, "Registro exitoso", "Usuario se registró correctamente");
        this->close();
    } else {
        QMessageBox::warning(this, "Registro fallido", "Usuario no se registró correctamente");
    }
}
