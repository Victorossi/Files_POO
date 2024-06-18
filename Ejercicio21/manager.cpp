#include "manager.h"

Manager::Manager()
{
    QObject::connect(&login, SIGNAL(loginSuccessful()), this, SLOT(showVentana()));
    QObject::connect(&ventana, SIGNAL(backToLogin()), this, SLOT(showLogin()));

    login.show();
}

void Manager::showVentana()
{
    login.hide();
    ventana.show();
}

void Manager::showLogin()
{
    ventana.hide();
    login.show();
    login.borrarCampos();
}
