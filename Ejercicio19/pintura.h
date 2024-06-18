#ifndef Pintura_H
#define Pintura_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QWheelEvent>
#include <QTimer>

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Pintura;
}
QT_END_NAMESPACE

struct Pintura_Data {
    QPoint position;
    int paintSize;
    int currentColor;
};

class Pintura : public QWidget
{
    Q_OBJECT

    public:
        Pintura(QWidget *parent = nullptr);
        ~Pintura();

    protected:
        void paintEvent(QPaintEvent *event);

        virtual void mousePressEvent( QMouseEvent * event );
        virtual void mouseReleaseEvent( QMouseEvent * event );
        virtual void mouseMoveEvent(QMouseEvent *event);
        virtual void keyPressEvent( QKeyEvent * event );
        virtual void wheelEvent(QWheelEvent * event);

    private:
        Ui::Pintura *ui;
        QPoint position;
        int paintSize;
        int currentColor; // 0 = R (RED), 1 = G (GREEN), 2 = B (BLUE)
        QTimer* repaintTimer;
        bool eraseCheck; // 0 = No Borrando, 1 = Borrando
        QVector<Pintura_Data> allDrawings;

    private slots:
        void slot_keep_painting();
};
#endif // Pintura_H
