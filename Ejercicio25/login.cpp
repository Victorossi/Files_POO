#include "login.h"
#include "ventana.h"
#include "admin_db.h"
#include "verusuario.h"
#include <QDebug>

Login::Login(QWidget *parent)
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

    QPushButton *loginButton = new QPushButton("Validar", this);
    layout->addWidget(loginButton);
    connect(loginButton, SIGNAL(clicked()), this, SLOT(login_usuario()));
    connect(claveEdit, SIGNAL(returnPressed()), this, SLOT(login_usuario()));

    labelRegistro = new QLabel("<a href=\"#\">Registrarse</a>", this);
    labelRegistro->setTextInteractionFlags(Qt::TextBrowserInteraction);
    labelRegistro->setOpenExternalLinks(false);
    layout->addWidget(labelRegistro);
    connect(labelRegistro, SIGNAL(linkActivated(QString)), this, SLOT(registrar_usuario()));

    setLayout(layout);
}

void Login::registrar_usuario()
{
    qDebug() << "registrar_usuario called";
    Ventana *ventana = new Ventana();
    ventana->show();
}

void Login::login_usuario()
{
    QString username = usuarioEdit->text();
    QString password = claveEdit->text();

    if (AdminDB::instance().authenticateUser(username, password)) {
        QMessageBox::information(this, "Valido", "Usuario Valido");
        VerUsuarios *verUsuarios = new VerUsuarios();
        verUsuarios->show();
        limpiarCampos(); // Limpiar los campos de entrada después de iniciar sesión
        this->close();
    } else {
        QMessageBox::warning(this, "Invalido", "Usuario o clave invalido");
    }
}

void Login::limpiarCampos()
{
    usuarioEdit->clear();
    claveEdit->clear();
}
