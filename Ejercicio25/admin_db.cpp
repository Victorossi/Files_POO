#include "admin_db.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    initialize();
}

AdminDB& AdminDB::instance()
{
    static AdminDB instance;
    return instance;
}

void AdminDB::initialize()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/victx/Documents/TERCER_ANO/POO/NOTA_TRES/Ejercicio25/db.sqlite");

    if (!db.open()) {
        qDebug() << "Error: La conexion con la base de datos fallo";
    } else {
        qDebug() << "Base de datos: Conectada";
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS usuarios (id INTEGER PRIMARY KEY AUTOINCREMENT, usuario TEXT, clave TEXT)");
}

bool AdminDB::addUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO usuarios (usuario, clave) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    return query.exec();
}

bool AdminDB::authenticateUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE usuario = :username AND clave = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();
    return query.next();
}

QSqlQuery AdminDB::getAllUsers()
{
    QSqlQuery query;
    query.exec("SELECT * FROM usuarios");
    return query;
}
