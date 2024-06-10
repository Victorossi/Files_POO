#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear un objeto QLabel
    QLabel label;

    // Cargar la imagen desde un archivo JPG en el disco duro
    QPixmap imagen("C:/Users/victx/Pictures/desktop/download.jpg");

    // Establecer la imagen en el QLabel
    label.setPixmap(imagen.scaled(label.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Mostrar el QLabel maximizado
    label.showMaximized();

    // Crear un temporizador para cerrar la aplicación después de 3 segundos
    QTimer::singleShot(3000, [&](){
        label.close();
        app.quit();
    });

    return app.exec();
}
