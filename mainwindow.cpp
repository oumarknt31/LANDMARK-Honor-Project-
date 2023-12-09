// OUMAR KANTE
// 12-07-2023
// CSC 211H
// Dr Azhar

/* This project is by the name of 'Landmark' because it is a reference point for people willing to
 learn and test what they learned. It will be composed of 2 parts.

-Learn: Where user will be provided with neccesary resources and content for learning
-Quiz: Where user will be able to test what they learned*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap MainPic(":/img/mainPic.jpeg");
    ui->MainImage->setPixmap(MainPic);
    QPixmap logoPic(":/img/logo.jpg");
    ui->logo->setPixmap(logoPic);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_Learn_BTN_clicked()   //Display Learn components
{
    //hide();
    LearnDialog learnDialog(this);
    /*int result =*/ learnDialog.exec();

}





void MainWindow::on_Quiz_BTN_clicked()  //Display quiz components
{
    QuizDialog quizDialog(this);
    /*int result =*/ quizDialog.exec();
}


void MainWindow::on_About_BTN_clicked() //Display Abouy landmark components
{
    AboutLandmarkDialog aboutDialog(this);
    aboutDialog.exec();
}

