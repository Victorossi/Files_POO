#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

private slots:
    void registrar_button();

private:
    QLineEdit *usuarioEdit;
    QLineEdit *claveEdit;
};

#endif // VENTANA_H
