#ifndef DIALOGSETOUTPUT_H
#define DIALOGSETOUTPUT_H

#include <QDialog>

class ImageConsumer;

namespace Ui {
class DialogSetOutput;
}

class DialogSetOutput : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSetOutput(QWidget *parent = 0);
    ~DialogSetOutput();

    ImageConsumer* get_consumer(); // return the selected consumer or 0 if Cancelled , must be deleted by the caller


private:
    Ui::DialogSetOutput *ui;
    ImageConsumer* _pImConsumer;
};

#endif // DIALOGSETOUTPUT_H
