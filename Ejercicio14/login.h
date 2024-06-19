#ifndef LOGIN_H
#define LOGIN_H
#endif // LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "mapa.h"
using namespace std;

class Login : public QWidget
{
private:
    QLabel * Usuario, *Clave;
    QLineEdit *leUsuario, *leClave;
    QPushButton *pbEntrar;
    QGridLayout *layout;
    Mapa *mapa;
private slots:
    void slot_validarUsuario();

public:
    Login();
};

