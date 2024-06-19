#ifndef VERUSUARIO_H
#define VERUSUARIO_H

#include <QWidget>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

class VerUsuarios : public QWidget
{
    Q_OBJECT

public:
    explicit VerUsuarios(QWidget *parent = nullptr);

signals:
    void backToLogin();

private slots:
    void agregar_usuario();
    void guardar_button();
    void volver_button();
    void borrar_button();

private:
    QTreeWidget *Arbol_usuario;
    QPushButton *boton_guardar;
    QPushButton *boton_volver;
    QPushButton *boton_borrar;
};

#endif // VERUSUARIO_H
