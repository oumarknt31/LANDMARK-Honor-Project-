#ifndef ABOUTLANDMARKDIALOG_H
#define ABOUTLANDMARKDIALOG_H

#include <QDialog>

namespace Ui {
class AboutLandmarkDialog;
}

class AboutLandmarkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutLandmarkDialog(QWidget *parent = nullptr);
    ~AboutLandmarkDialog();

private slots:
    void on_Back_btn_clicked();

private:
    Ui::AboutLandmarkDialog *ui;
};

#endif // ABOUTLANDMARKDIALOG_H
