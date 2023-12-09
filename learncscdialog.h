#ifndef LEARNCSCDIALOG_H
#define LEARNCSCDIALOG_H

#include <QDialog>


namespace Ui {
class LearnCSCDialog;
}

class LearnCSCDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LearnCSCDialog(QWidget *parent = nullptr);
    ~LearnCSCDialog();

private slots:


    //void on_GoBack_clicked();

    void on_Pointers_btn_4_clicked();

    //void on_GoBack_4_clicked();

    void on_GoBack_4_clicked();

    void on_GoBack_5_clicked();

    void on_GoBack_13_clicked();

    void on_GoBack_12_clicked();

    void on_GoBack_11_clicked();

    void on_GoBack_10_clicked();

    void on_GoBack_9_clicked();

    void on_GoBack_8_clicked();

    void on_GoBack_7_clicked();

    void on_GoBack_6_clicked();


    void on_Vectors_btn_4_clicked();

    void on_Execption_btn_4_clicked();

    //void on_Array_btn_4_clicked();

private:
    Ui::LearnCSCDialog *ui;
};

#endif // LEARNCSCDIALOG_H
