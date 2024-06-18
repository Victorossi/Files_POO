#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QPushButton>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

signals:
    void backToLogin();

private:
    QPushButton *backButton;
};

#endif // VENTANA_H
