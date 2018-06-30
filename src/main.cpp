#include <QApplication>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	
    QTextEdit w;
	w.setText("Hello World!");
    w.showMaximized();

    return app.exec();
}
