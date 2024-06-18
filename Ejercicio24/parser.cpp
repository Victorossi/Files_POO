#include "parser.h"
#include <QDebug>
#include <QVBoxLayout>

Parser::Parser(QWidget *parent)
    : QWidget(parent)
{
    lURL = new QLabel("URL:", this);
    lURL->setFont(QFont("", 10, QFont::Bold, true));

    leURL = new QLineEdit(this);
    leURL->setFont(QFont("", 10));

    pbBuscar = new QPushButton("Guardar", this);
    pbBuscar->setFont(QFont("", 10));

    lGuardado = new QLabel("Direccion de la carpeta:", this);
    lGuardado->setFont(QFont("", 10, QFont::Bold, true));

    leGuardado = new QLineEdit(this);

    teHTML = new QTextEdit(this);
    teHTML->setFont(QFont("", 8));
    teHTML->setReadOnly(true);

    pbDibujar = new QPushButton("Dibujar una Imagen del Disco", this);
    pbDibujar->setFont(QFont("", 10));

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(lURL, 0, 0);
    layout->addWidget(leURL, 0, 1);
    layout->addWidget(pbBuscar, 0, 2);
    layout->addWidget(lGuardado, 1, 0);
    layout->addWidget(leGuardado, 1, 1, 1, 2);
    layout->addWidget(teHTML, 2, 0, 1, 3);
    layout->addWidget(pbDibujar, 3, 0, 1, 3);
    setLayout(layout);

    connect(pbBuscar, SIGNAL(clicked(bool)), this, SLOT(slot_descargar_html()));
    connect(this, SIGNAL(signal_HTML_descargado()), this, SLOT(slot_descargar_archivos()));
    connect(pbDibujar, SIGNAL(clicked(bool)), this, SLOT(slot_QDialog_img_disco()));
}

Parser::~Parser()
{
    delete css_list;
    delete js_list;
    delete img_list;
}

void Parser::getRecursos()
{
    qDebug() << "Buscando los Recursos...";
    qDebug() << "HTML es Vacio?" << html_storage.isEmpty();

    css_list = new QStringList();

    QRegularExpression cssRegex("<link\\s+.*?href=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator cssMatches = cssRegex.globalMatch(html_storage);
    while(cssMatches.hasNext())
    {
        qDebug() << "Adentro de CSS";
        QRegularExpressionMatch match = cssMatches.next();
        QString cssURL = match.captured(1);
        css_list->push_back(cssURL);
    }

    qDebug() << "CSS obtenido";

    js_list = new QStringList();

    QRegularExpression jsRegex("<script\\s+.*?src=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator jsMatches = jsRegex.globalMatch(html_storage);
    while(jsMatches.hasNext())
    {
        qDebug() << "Adentro de JS";
        QRegularExpressionMatch match = jsMatches.next();
        QString jsURL = match.captured(1);
        js_list->push_back(jsURL);
    }

    qDebug() << "JS obtenido";

    img_list = new QStringList();

    QRegularExpression imgRegex("<img\\s+.*?src=\"(.*?)\".*?>");
    QRegularExpressionMatchIterator imgMatches = imgRegex.globalMatch(html_storage);
    while(imgMatches.hasNext())
    {
        qDebug() << "Adentro de IMG";
        QRegularExpressionMatch match = imgMatches.next();
        QString imgURL = match.captured(1);
        img_list->push_back(imgURL);
    }

    qDebug() << "IMG obtenido";
    qDebug() << "Todos los Recursos Conseguidos...";
}

void Parser::slot_descargar_html()
{
    if (!(leURL->text().isEmpty()) && !(leGuardado->text().isEmpty()))
    {
        qDebug() << "Descargando HTML...";

        filePath = leGuardado->text();
        filePath += "/";
        qDebug() << "Direccion de Guardado:" << filePath;

        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_html_descargado(QNetworkReply * )));
        QNetworkRequest request(QUrl(leURL->text()));
        manager->get(request);
    } else {
        qDebug() << "Falta la URL y/o la Directorio de Guardado. Vuelva a Intentar";
    }
}

void Parser::slot_descargar_archivos()
{
    getRecursos();

    qDebug() << "Por descargar todos los Recursos...";

    css_list_pos = 0;
    connect(this, SIGNAL(signal_iniciar_descarga_css()), this, SLOT(slot_descargar_CSS()));
    emit signal_iniciar_descarga_css();

    js_list_pos = 0;
    connect(this, SIGNAL(signal_iniciar_descarga_js()), this, SLOT(slot_descargar_JS()));
    emit signal_iniciar_descarga_js();

    img_list_pos = 0;
    connect(this, SIGNAL(signal_iniciar_descarga_img()), this, SLOT(slot_descargar_IMG()));
    emit signal_iniciar_descarga_img();

    qDebug() << "Finalizado!";
}

void Parser::slot_html_descargado(QNetworkReply* reply)
{
    qDebug() << "Guardando HTML y Emitiendo SIGNAL...";
    html_storage = reply->readAll();

    QString fileName = "/html.txt";
    QFile file(filePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Se ha creado el Archivo HTML";
    }
    file.write(html_storage.toUtf8());

    teHTML->setText(html_storage);
    emit signal_HTML_descargado();
}

void Parser::slot_descargar_CSS()
{
    if (css_list->isEmpty() || css_list_pos == css_list->size())
    {
        return;
    } else {
        manager = new QNetworkAccessManager();
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_css_descargado(QNetworkReply *)));

        qDebug() << "Descargando CSS... Estoy en la Posicion" << css_list_pos << "| Size de Lista es:" << css_list->size();
        qDebug() << "URL en la Posicion Actual:" << css_list->at(css_list_pos);
        QNetworkRequest request(QUrl(css_list->at(css_list_pos)));
        manager->get(request);

        connect(this, SIGNAL(signal_CSS_descargado()), this, SLOT(slot_descargar_CSS()));
        css_list_pos++;
    }
}

void Parser::slot_descargar_JS()
{
    if (js_list->isEmpty() || js_list_pos == js_list->size())
    {
        return;
    } else {
        manager = new QNetworkAccessManager();
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_js_descargado(QNetworkReply *)));

        qDebug() << "Descargando JS... Estoy en la Posicion" << js_list_pos << "| Size de Lista es:" << js_list->size();
        qDebug() << "URL en la Posicion Actual:" << js_list->at(js_list_pos);
        QNetworkRequest request(QUrl(js_list->at(js_list_pos)));
        manager->get(request);

        connect(this, SIGNAL(signal_JS_descargado()), this, SLOT(slot_descargar_JS()));
        js_list_pos++;
    }
}

void Parser::slot_descargar_IMG()
{
    if (img_list->isEmpty() || img_list_pos == img_list->size())
    {
        return;
    } else {
        manager = new QNetworkAccessManager();
        connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(slot_img_descargado(QNetworkReply *)));

        qDebug() << "Descargando IMG... Estoy en la Posicion" << img_list_pos << "| Size de Lista es:" << img_list->size();
        qDebug() << "URL en la Posicion Actual:" << img_list->at(img_list_pos);
        QNetworkRequest request(QUrl(img_list->at(img_list_pos)));
        manager->get(request);

        connect(this, SIGNAL(signal_IMG_descargado()), this, SLOT(slot_descargar_IMG()));
        img_list_pos++;
    }
}

void Parser::slot_css_descargado(QNetworkReply* reply)
{
    QString fileName = "/estilo_" + QString::number(css_list_pos) + ".css";
    QFile file(filePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Archivo CSS Guardado";
    }
    file.write(reply->readAll());
    emit signal_CSS_descargado();
}

void Parser::slot_js_descargado(QNetworkReply* reply)
{
    QString fileName = "/js_" + QString::number(js_list_pos) + ".js";
    QFile file(filePath + fileName);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Archivo JS Guardado";
    }
    file.write(reply->readAll());
    emit signal_JS_descargado();
}

void Parser::slot_img_descargado(QNetworkReply* reply)
{
    QImage img;
    img.loadFromData(reply->readAll());
    QString fileName = "/img_" + QString::number(img_list_pos) + ".png";
    img.save(filePath + fileName);
    emit signal_IMG_descargado();
}

void Parser::slot_QDialog_img_disco()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
    slot_imagen_obtenida(fileName);
}

void Parser::slot_imagen_obtenida(QString fileName)
{
    img.load(fileName);
    repaint();
}

void Parser::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if (!img.isNull()) {
        qDebug() << "Pintando Imagen...";

        painter.setWindow(500, 500, 400, 300);
        painter.drawImage(0, 0, img);
    }
}
