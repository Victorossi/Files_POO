#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    virtual void login() = 0;

protected:
    QLineEdit *userLineEdit;
    QLineEdit *passwordLineEdit;
};

#endif // MAINWINDOW_H
