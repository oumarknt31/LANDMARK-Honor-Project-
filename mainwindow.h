#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "learndialog.h"
#include "quizdialog.h"
#include "aboutlandmarkdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_Learn_BTN_clicked();

    void on_Quiz_BTN_clicked();

    void on_About_BTN_clicked();

private:
    Ui::MainWindow *ui;
    LearnDialog *learnComp;
    QuizDialog *quizComp;
    AboutLandmarkDialog *aboutComp;
};
#endif // MAINWINDOW_H
