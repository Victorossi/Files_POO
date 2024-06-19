#include "mapa.h"

void Mapa:: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawLine(0,0, this->width(), this->height());
    QImage im("C:/Users/victx/Pictures/cats 1.jpg");
        painter.drawImage(0,0,im);
    //painter.drawImage();
}
