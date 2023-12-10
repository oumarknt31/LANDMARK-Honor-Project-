#ifndef QUIZDIALOG_H
#define QUIZDIALOG_H

#include <QDialog>

namespace Ui {
class QuizDialog;
}

class QuizDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuizDialog(QWidget *parent = nullptr);
    ~QuizDialog();

private slots:
    void on_GoBack_clicked();

    void on_CSC_learn_btn_clicked();

    void on_MATHS_quiz_btn_clicked();

private:
    Ui::QuizDialog *ui;
};

#endif // QUIZDIALOG_H
