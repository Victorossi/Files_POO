#include <iostream>
#include <QString>
#include <QDebug>


namespace SCM {
    QString getVersion() {
        return ("v0.0.1 - 20240318");
    }
}

int main() {
    QString version = SCM::getVersion();
    qDebug() << version;
    return 0;
}
