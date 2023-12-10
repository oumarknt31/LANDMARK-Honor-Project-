#ifndef LEARNDIALOG_H
#define LEARNDIALOG_H

#include <QDialog>
#include "learncscdialog.h"

namespace Ui {
class LearnDialog;
}

class LearnDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LearnDialog(QWidget *parent = nullptr);
    ~LearnDialog();

private slots:


    void on_pushButton_clicked();

    void on_Csc_btn_clicked();

    void on_Maths_btn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_Csc111_btn_clicked();

    void on_IntroToIntgrl_btn_clicked();

    void on_Back2_btn_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_Back_btn_clicked();

    void on_Csc211_btn_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_Pointers_btn_111_clicked();

    void on_MoreResources_btn_clicked();

    void on_Loop_btn_clicked();

    void on_If_Else_btn_clicked();

    void on_Function_btn_clicked();

    void on_Class_btn_clicked();

    void on_Struct_btn_clicked();

    void on_Pointers_btn_clicked();

    void on_Inheritance_btn_clicked();

    void on_template_btn_clicked();

    void on_Recursion_btn_clicked();

    void on_Exception_btn_clicked();

    void on_FileInOut_btn_clicked();

    void on_TechOfIntgrl_btn_clicked();

    void on_ApplicIntgrl_btn_clicked();

    void on_SequSer_btn_clicked();

    void on_Limits_btn_clicked();

    void on_BasicDeriv_btn_clicked();

    void on_MoreDeriv_btn_clicked();

    void on_ApplicatDeriv_btn_clicked();

private:
    Ui::LearnDialog *ui;
    LearnCSCDialog *LearnCscComp;
};

#endif // LEARNDIALOG_H
