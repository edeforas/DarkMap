#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ImageProducer.h"
#include "ImageConsumer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_actionSetOutput_triggered();

    void on_actionView_Frames_triggered();

    void on_actionGetGoodFrames_triggered();

    void on_actionStabilize_triggered();

    void on_actionMap_Panorama_triggered();

private:
    Ui::MainWindow *ui;
	ImageProducer* _pImProd;
    ImageConsumer* _pImOut;
};

#endif // MAINWINDOW_H
