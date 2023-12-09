/* QuizCscDialog is a class that will be use to load all the questions of my quiz by using some user defined functions*/

#ifndef QUIZCSCDIALOG_H
#define QUIZCSCDIALOG_H

#include <QDialog>

namespace Ui {
class QuizCscDialog;
}

class QuizCscDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuizCscDialog(QWidget *parent = nullptr);
    ~QuizCscDialog();
    int initializeQuestions(int index);
    int initializeQuestionsII(int index);

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

private:
    Ui::QuizCscDialog *ui;
};

#endif // QUIZCSCDIALOG_H
