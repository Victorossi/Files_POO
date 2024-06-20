#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "ventana.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    QNetworkAccessManager *Manager;
    QImage img;
    Ventana *ventana;



private slots:
    void slot_validarUsaurio();
    void paintEvent(QPaintEvent *event);
    void descargaFinalizada(QNetworkReply *reply);


private:
    Ui::Login *ui;
};
#endif // LOGIN_H
