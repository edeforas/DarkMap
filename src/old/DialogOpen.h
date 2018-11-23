#ifndef DIALOGOPEN_H
#define DIALOGOPEN_H

#include <QDialog>

class ImageProducer;

namespace Ui {
class DialogOpen;
}

class DialogOpen : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOpen(QWidget *parent = 0);
    ~DialogOpen();

    ImageProducer* get_producer(); // return the selected producer or 0 if Cancelled , must be deleted by the caller

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_OpenCameraDevice_clicked();

    void on_OpenImageFolder_clicked();

    void on_OpenOneImage_clicked();

    void on_OpenVideoFile_clicked();

private:
    Ui::DialogOpen *ui;
    ImageProducer* _imProducer;
};

#endif // DIALOGOPEN_H
