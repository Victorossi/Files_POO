#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Ventana : public QWidget
{
    Q_OBJECT
public:
    explicit Ventana(QWidget *parent = nullptr);
    QNetworkAccessManager *Manager;
    QImage img;

private slots:
    void paintEvent(QPaintEvent *event);
    void descargaFinalizada(QNetworkReply *reply);

signals:

};

#endif // VENTANA_H
