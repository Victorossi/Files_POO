#ifndef BOTON_H
#define BOTON_H

#include <QWidget>

class Boton : public QWidget
{
    Q_OBJECT
public:
    enum Colores {Azul,Verde,Magenta};
    explicit Boton(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent *event);
    void colorear(Colores c);

signals:

};

#endif // BOTON_H
