#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ImageCamera.h"
#include "ImageVideoReader.h"
#include "ImageCamera.h"

#include "DialogOpen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	_pImProd=0;
}

MainWindow::~MainWindow()
{
    delete ui;
	delete _pImProd;
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
