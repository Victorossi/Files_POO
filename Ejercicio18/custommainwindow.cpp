#include "CustomMainWindow.h"

CustomMainWindow::CustomMainWindow(QWidget *parent) : MainWindow(parent) {}

void CustomMainWindow::login()
{

    QString username = "admin";
    QString password = "1234";
    if (userLineEdit->text() == username && passwordLineEdit->text() == password)
    {

        QTextEdit *htmlTextEdit = new QTextEdit;
        QLineEdit *urlLineEdit = new QLineEdit;
        connect(urlLineEdit, &QLineEdit::returnPressed, this, [this, htmlTextEdit, urlLineEdit]()
        {

            QUrl url(urlLineEdit->text());
            QNetworkAccessManager *manager = new QNetworkAccessManager(this);
            connect(manager, &QNetworkAccessManager::finished, this, [htmlTextEdit](QNetworkReply *reply)
            {
                if (reply->error() == QNetworkReply::NoError) {
                    QString html = QString::fromUtf8(reply->readAll());
                    htmlTextEdit->setPlainText(html);
                } else {
                    htmlTextEdit->setPlainText("Error al obtener el HTML: " + reply->errorString());
                }
                reply->deleteLater();
            });
            manager->get(QNetworkRequest(url));
        });

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(new QLabel("Ingrese la URL:"));
        layout->addWidget(urlLineEdit);
        layout->addWidget(new QLabel("HTML obtenido:"));
        layout->addWidget(htmlTextEdit);

        QDialog *dialog = new QDialog(this);
        dialog->setLayout(layout);
        dialog->exec();
    } else {
        QMessageBox::warning(this, "Error", "Credenciales incorrectas");
    }
}
