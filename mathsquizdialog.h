#ifndef MATHSQUIZDIALOG_H
#define MATHSQUIZDIALOG_H

#include <QDialog>

namespace Ui {
class mathsquizDialog;
}

class mathsquizDialog : public QDialog
{
    Q_OBJECT

public:
    explicit mathsquizDialog(QWidget *parent = nullptr);
    ~mathsquizDialog();
    int initializeQuestionsC(int index);
    int initializeQuestionsIIC(int index);

private slots:
    void on_Ready_btn_clicked();

    void on_Exit_btn_clicked();

    void on_Back_btn_clicked();

    void on_Back2_btn_clicked();

    void on_Csc111_btn_clicked();

    void on_Csc211_btn_clicked();

    void on_Ready_btn_2_clicked();

    void on_Confirm_btn_clicked();

    void on_option1_Rbtn_clicked();

    void on_option2_Rbtn_clicked();

    void on_option3_Rbtn_clicked();

    void on_option4_Rbtn_clicked();

    void on_Close_btn_clicked();

    void on_Close_btn_II_clicked();

    void on_option1_Rbtn_II_clicked();

    void on_option2_Rbtn_II_clicked();

    void on_option3_Rbtn_II_clicked();

    void on_option4_Rbtn_II_clicked();

    void on_Confirm_btn_II_clicked();

    void on_Back_btn_2_clicked();



    //void on_Csc211_btn_clicked();

    void on_Exit_btn_II_clicked();

private:
    Ui::mathsquizDialog *ui;
};

#endif // MATHSQUIZDIALOG_H
