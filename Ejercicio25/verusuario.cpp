#include "verusuario.h"
#include "admin_db.h"
#include "login.h"

VerUsuarios::VerUsuarios(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    Arbol_usuario = new QTreeWidget(this);
    Arbol_usuario->setColumnCount(2);
    QStringList headers;
    headers << "Username" << "Password";
    Arbol_usuario->setHeaderLabels(headers);
    layout->addWidget(Arbol_usuario);

    boton_guardar = new QPushButton("Guardar cambios", this);
    layout->addWidget(boton_guardar);
    connect(boton_guardar, SIGNAL(clicked()), this, SLOT(guardar_button()));

    boton_borrar = new QPushButton("Borrar Usuario", this);
    layout->addWidget(boton_borrar);
    connect(boton_borrar, SIGNAL(clicked()), this, SLOT(borrar_button()));

    boton_volver = new QPushButton("Volver", this);
    layout->addWidget(boton_volver);
    connect(boton_volver, SIGNAL(clicked()), this, SLOT(volver_button()));

    setLayout(layout);

    agregar_usuario();
}

void VerUsuarios::agregar_usuario()
{
    QSqlQuery query = AdminDB::instance().getAllUsers();

    while (query.next()) {
        QTreeWidgetItem *item = new QTreeWidgetItem(Arbol_usuario);
        item->setText(0, query.value("usuario").toString());
        item->setText(1, query.value("clave").toString());
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
}

void VerUsuarios::guardar_button()
{
    for (int i = 0; i < Arbol_usuario->topLevelItemCount(); ++i) {
        QTreeWidgetItem *item = Arbol_usuario->topLevelItem(i);
        QString username = item->text(0);
        QString password = item->text(1);

        QSqlQuery query;
        query.prepare("UPDATE usuarios SET clave = :password WHERE usuario = :username");
        query.bindValue(":username", username);
        query.bindValue(":password", password);
        query.exec();
    }

    QMessageBox::information(this, "Guardar Cambios", "Todos los cambios se guardaron");
}

void VerUsuarios::volver_button()
{
    this->close();

    Login *loginWindow = new Login();
    loginWindow->show();

    loginWindow->limpiarCampos();
}

void VerUsuarios::borrar_button()
{
    QList<QTreeWidgetItem *> selectedItems = Arbol_usuario->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "No se seleccionó usuario", "Por favor seleccione un usuario.");
        return;
    }

    QString usernameToDelete = selectedItems.at(0)->text(0);
    int response = QMessageBox::question(this, "Confirmar eliminación", "¿Estás seguro que quieres eliminar al usuario '" + usernameToDelete + "'?", QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM usuarios WHERE usuario = :username");
        query.bindValue(":username", usernameToDelete);
        if (query.exec()) {
            QMessageBox::information(this, "Usuario eliminado", "Usuario '" + usernameToDelete + "' eliminado correctamente.");
            agregar_usuario(); // Recargar la lista de usuarios después de la eliminación
        } else {
            QMessageBox::critical(this, "Error", "Error al eliminar usuario.");
        }
    }
}
