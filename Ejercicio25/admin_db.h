#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class AdminDB : public QObject
{
    Q_OBJECT

public:
    static AdminDB& instance();
    bool addUser(const QString& username, const QString& password);
    bool authenticateUser(const QString& username, const QString& password);
    QSqlQuery getAllUsers();

private:
    explicit AdminDB(QObject *parent = nullptr);
    void initialize();
    QSqlDatabase db;
};

#endif // ADMINDB_H
