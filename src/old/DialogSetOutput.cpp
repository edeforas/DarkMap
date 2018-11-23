#include "DialogSetOutput.h"
#include "ui_DialogSetOutput.h"

DialogSetOutput::DialogSetOutput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSetOutput)
{
    ui->setupUi(this);
    _pImConsumer=0;
}

DialogSetOutput::~DialogSetOutput()
{
    delete ui;
}

ImageConsumer* DialogSetOutput::get_consumer() // return the selected consumer or 0 if Cancelled
{
    return _pImConsumer;
}
