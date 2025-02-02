#include <QApplication>
#include <QMainWindow>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString executablePath = QCoreApplication::applicationDirPath();

    QFile file(executablePath + "/style.qss");
    if (file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        QString style = stream.readAll();
        app.setStyleSheet(style);
    }
    else
    {
        qDebug() << "Impossibile aprire il file QSS:" << file.errorString();
    }

    // Window
    QMainWindow window;
    window.setWindowTitle("Test");
    window.resize(800, 400);

    window.show();
    return app.exec();
}