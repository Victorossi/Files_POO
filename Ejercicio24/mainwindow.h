#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QUrl>
#include <QDesktopServices>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QXmlStreamReader>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QRegExp>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openWebsite();
    void replyFinished(QNetworkReply *reply);
    void saveHtmlToFile();
    void saveCssToFile();

private:
    QVBoxLayout *layout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *button;
    QPushButton *saveButton;
    QPushButton *saveCssButton;
    QNetworkAccessManager *manager;
    QString htmlContent;

    QStringList extractCssBlocks(const QString &htmlContent);
};

#endif // MAINWINDOW_H
