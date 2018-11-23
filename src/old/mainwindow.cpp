#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ImageCamera.h"
#include "ImageVideoReader.h"
#include "ImageCamera.h"

#include "DialogOpen.h"
#include "DialogSetOutput.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	_pImProd=0;
    _pImOut=0;
}

MainWindow::~MainWindow()
{
    delete ui;
	delete _pImProd;
    delete _pImOut;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionOpen_triggered()
{
    DialogOpen dlgOpen;
    if(dlgOpen.exec())
    {
		delete _pImProd;
        _pImProd=dlgOpen.get_producer();
    }
	//todo open?
}

void MainWindow::on_actionSetOutput_triggered()
{
    DialogSetOutput dlgSO;
    if(dlgSO.exec())
    {
        delete _pImOut;
        _pImOut=dlgSO.get_consumer();
    }
    //todo open?
}

void MainWindow::on_actionView_Frames_triggered()
{
    //identity computation

    if(!_pImProd) //todo better error msg
        return;

    if(!_pImOut)  //todo better error msg
        return;

    //...
}

void MainWindow::on_actionGetGoodFrames_triggered()
{
    if(!_pImProd)  //todo better error msg
        return;

    if(!_pImOut)  //todo better error msg
        return;

    //...
}

void MainWindow::on_actionStabilize_triggered()
{
    if(!_pImProd) //todo better error msg
        return;


    if(!_pImOut) //todo better error msg
        return;

//...
}

void MainWindow::on_actionMap_Panorama_triggered()
{
    if(!_pImProd)  //todo better error msg
        return;

    if(!_pImOut)  //todo better error msg
        return;

//...
}
