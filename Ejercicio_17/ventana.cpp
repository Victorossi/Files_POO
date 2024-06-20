#include "ventana.h"
#include <QPainter>

Ventana::Ventana(QWidget *parent) : QWidget(parent)
{

    this->hide();

    Manager = new QNetworkAccessManager(this);

    connect(Manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(descargaFinalizada(QNetworkReply*)));

    QNetworkRequest request(QUrl("https://images7.alphacoders.com/133/1330715.png"));

    Manager->get(request);


}

void Ventana::paintEvent(QPaintEvent *event)
{
    QPainter painter( this );
        if (!img.isNull()) {
            painter.drawImage( 0, 0, img.scaled(this->size()));
        }

}

void Ventana::descargaFinalizada(QNetworkReply *reply)
{
    this->showFullScreen();
    img = QImage::fromData( reply->readAll() );
    this->repaint();
}
