#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear objetos de las clases QLabel, QWidget, QPushButton y QLineEdit
    QLabel label("Etiqueta");
    QWidget widget;
    QPushButton button("Botón");
    QLineEdit lineEdit;

    // Mostrar cada objeto
    label.show();
    widget.show();
    button.show();
    lineEdit.show();

    return app.exec();
}
