#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QString strHello = "Hello, World!";
    qDebug() << strHello;

    return a.exec();
}
