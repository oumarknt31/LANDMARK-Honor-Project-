#include "quizdialog.h"
#include "ui_quizdialog.h"
#include "quizcscdialog.h"
#include "mathsquizdialog.h"

QuizDialog::QuizDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuizDialog)
{
    ui->setupUi(this);
    QPixmap QuizImage(":/img/quizPic.jpeg");
    ui->QuizImage->setPixmap(QuizImage);
}

QuizDialog::~QuizDialog()
{
    delete ui;
}

void QuizDialog::on_GoBack_clicked()
{
    hide();
    reject();
}


void QuizDialog::on_CSC_learn_btn_clicked()
{
    QuizCscDialog CscQuizComp;
    CscQuizComp.setModal(true);
    CscQuizComp.exec();

}


void QuizDialog::on_MATHS_quiz_btn_clicked()
{
    mathsquizDialog mathQuizComp;
    mathQuizComp.setModal(true);
    mathQuizComp.exec();
}

