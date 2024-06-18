#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "login.h"
#include "ventana.h"

class Manager : public QObject
{
    Q_OBJECT

public:
    Manager();

private slots:
    void showVentana();
    void showLogin();

private:
    Login login;
    Ventana ventana;
};

#endif // MANAGER_H
