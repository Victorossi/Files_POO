#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QPainter>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    Manager = new QNetworkAccessManager(this);

    connect(ui->pbIngresar,SIGNAL(pressed()),this,SLOT(slot_validarUsaurio()));

    connect(Manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(descargaFinalizada(QNetworkReply*)));

    QNetworkRequest request(QUrl("https://i.pinimg.com/236x/88/71/53/8871538c3798cf8315c17e2415e55a5a.jpg"));

    Manager->get(request);


}

Login::~Login()
{
    delete ui;
}


void Login::slot_validarUsaurio()
{
    if (ui->leUsuario->text() == "admin" && ui->leClave->text() == "1111") {
        this->hide();
        ventana = new Ventana;
    } else {
        ui->leClave->clear();
    }
}

void Login::paintEvent(QPaintEvent *event)
{
    QPainter painter( this );
        if (!img.isNull()) {
            painter.drawImage( 0, 0, img.scaled(this->size()));
        }
}

void Login::descargaFinalizada(QNetworkReply *reply)
{
    img = QImage::fromData( reply->readAll() );
    this->repaint();
}
