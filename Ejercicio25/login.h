#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    void limpiarCampos();

private slots:
    void registrar_usuario();
    void login_usuario();

private:
    QLabel *labelRegistro;
    QLineEdit *usuarioEdit;
    QLineEdit *claveEdit;
};

#endif // LOGIN_H
