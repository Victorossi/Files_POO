#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    layout = new QVBoxLayout(centralWidget);
    label = new QLabel("Ingresar la URL:", centralWidget);
    lineEdit = new QLineEdit(centralWidget);
    button = new QPushButton("Analizar web", centralWidget);
    saveButton = new QPushButton("Guardar HTML", centralWidget);
    saveCssButton = new QPushButton("Guardar CSS", centralWidget);

    connect(button, &QPushButton::clicked, this, &MainWindow::openWebsite);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveHtmlToFile);
    connect(saveCssButton, &QPushButton::clicked, this, &MainWindow::saveCssToFile);

    // Añadir widgets al layout
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    layout->addWidget(saveButton);
    layout->addWidget(saveCssButton);

    manager = new QNetworkAccessManager(this);

    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished);
}

MainWindow::~MainWindow() {}

void MainWindow::openWebsite()
{
    QString urlString = lineEdit->text();
    QUrl url(urlString);

    if (!url.isValid()) {
        QMessageBox::warning(this, "Error", "URL no válida");
        return;
    }

    QNetworkRequest request(url);
    manager->get(request);
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        QMessageBox::warning(this, "Error", "Error al obtener el contenido de la página");
        reply->deleteLater();
        return;
    }

    htmlContent = reply->readAll();

    reply->deleteLater();
}

void MainWindow::saveHtmlToFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Guardar HTML"), QDir::homePath(), tr("Archivos de texto (*.txt)"));

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escribir");
        return;
    }

    QTextStream out(&file);
    out << htmlContent;

    file.close();

    QMessageBox::information(this, "Éxito", "El HTML se ha guardado correctamente en el archivo");
}

void MainWindow::saveCssToFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Guardar CSS"), QDir::homePath(), tr("Archivos de texto (*.css)"));

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escribir");
        return;
    }

    QStringList cssBlocks = extractCssBlocks(htmlContent);

    QTextStream out(&file);
    for (const QString &cssBlock : cssBlocks)
    {
        out << cssBlock << "\n\n";
    }

    file.close();

    QMessageBox::information(this, "Éxito", "El CSS se ha guardado correctamente en el archivo");
}

QStringList MainWindow::extractCssBlocks(const QString &htmlContent)
{
    QRegExp cssRegex("\\{(.*?)\\}");
    QStringList cssBlocks;
    int pos = 0;

    while ((pos = cssRegex.indexIn(htmlContent, pos)) != -1)
    {
        cssBlocks << cssRegex.cap(1).trimmed();
        pos += cssRegex.matchedLength();
    }

    return cssBlocks;
}
