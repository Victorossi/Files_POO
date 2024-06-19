#include "login.h"

Login :: Login()
{
    Usuario = new QLabel("Usuario");
    Clave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit();
    pbEntrar = new QPushButton ("Entrar");
    mapa = new Mapa;

    layout = new QGridLayout;
    layout->addWidget(Usuario, 0, 0, 1, 1);
    layout->addWidget(Clave, 1, 0, 1, 1);
    layout->addWidget(leUsuario, 0 , 1, 1, 2);
    layout->addWidget(leClave, 1, 1, 1, 2);
    layout->addWidget(pbEntrar, 2, 1, 1, 1);

    this-> setLayout(layout);

    connect(pbEntrar, SIGNAL(pressed()), this, SLOT (slot_validarUsuario()));
    }

    void Login::slot_validarUsuario()
    {
        if (leUsuario -> text() == "admin" && leClave -> text() == "1234"){
            mapa->show();
            this->hide();
        }
        else
        {
            leClave->clear();
        }

}
