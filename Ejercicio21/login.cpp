#include "login.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

Login::Login(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Usuario");
    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Clave");
    passwordEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login", this);
    statusLabel = new QLabel(this);

    mainLayout->addWidget(usernameEdit);
    mainLayout->addWidget(passwordEdit);
    mainLayout->addWidget(loginButton);
    mainLayout->addWidget(statusLabel);

    connect(loginButton, SIGNAL(clicked()), this, SLOT(validateLogin()));
    connect(usernameEdit, SIGNAL(returnPressed()), this, SLOT(validateLogin()));
    connect(passwordEdit, SIGNAL(returnPressed()), this, SLOT(validateLogin()));

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/victx/Documents/TERCER_ANO/POO/NOTA_TRES/Ejercicio21/db.sqlite");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
    }

    resize(400, 300);
}

Login::~Login()
{
    db.close();
}

void Login::validateLogin()
{
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE usuario = :username AND clave = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        emit loginSuccessful();
    } else {
        statusLabel->setText("Usuario o Clave invalido");
    }
}

void Login::borrarCampos()
{
    usernameEdit->clear();
    passwordEdit->clear();
    statusLabel->clear();
}
