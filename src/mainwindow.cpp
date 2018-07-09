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
}

MainWindow::~MainWindow()
{
    delete ui;
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
        //todo

    }
}
