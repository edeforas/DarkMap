#include "DialogOpen.h"
#include "ui_DialogOpen.h"

DialogOpen::DialogOpen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOpen)
{
    ui->setupUi(this);
}

DialogOpen::~DialogOpen()
{
    delete ui;
}

void DialogOpen::on_pushButton_clicked()
{

}

void DialogOpen::on_buttonBox_accepted()
{

}

void DialogOpen::on_buttonBox_rejected()
{

}

void DialogOpen::on_OpenCameraDevice_clicked()
{

}

void DialogOpen::on_OpenImageFolder_clicked()
{

}

void DialogOpen::on_OpenOneImage_clicked()
{

}

void DialogOpen::on_OpenVideoFile_clicked()
{

}
