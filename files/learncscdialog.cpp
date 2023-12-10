#include "learncscdialog.h"
#include "ui_learncscdialog.h"
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

LearnCSCDialog::LearnCSCDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LearnCSCDialog)
{
    ui->setupUi(this);
    QPixmap backgrd(":/img/ReadingPic.jpeg");
    ui->backgroundPic_4->setPixmap(backgrd);

}

LearnCSCDialog::~LearnCSCDialog()
{
    delete ui;

}



/*void LearnCSCDialog::on_GoBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}*/


void LearnCSCDialog::on_Pointers_btn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QFile file(":/txt/Pointers in c++.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Read the content
        QTextStream in(&file);
        QString content = in.readAll();

        ui->Pointers_txt->setPlainText(content);

        QFont font("Arial", 26);  // Change "Arial" to the desired font family and 12 to the desired font size
        QPalette palette;
        palette.setColor(QPalette::Text, Qt::white);  // Change Qt::blue to the desired text color

        ui->Pointers_txt->setFont(font);
        ui->Pointers_txt->setPalette(palette);
        ui->Pointers_txt->setPlainText(content);

        // Show the content in a message box
        //QMessageBox::information(this, "CSC - 201 ", content);

        // Close the file
        file.close();
    }
}





void LearnCSCDialog::on_GoBack_4_clicked()
{
    reject();

}


void LearnCSCDialog::on_GoBack_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void LearnCSCDialog::on_GoBack_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void LearnCSCDialog::on_GoBack_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LearnCSCDialog::on_GoBack_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LearnCSCDialog::on_GoBack_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LearnCSCDialog::on_GoBack_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LearnCSCDialog::on_GoBack_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LearnCSCDialog::on_GoBack_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void LearnCSCDialog::on_GoBack_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void LearnCSCDialog::on_Vectors_btn_4_clicked()
{

}


void LearnCSCDialog::on_Execption_btn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    QFile file(":/txt/Exception_txt.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Read the content
        QTextStream in(&file);
        QString content = in.readAll();

        ui->Execption_txt->setPlainText(content);

        QFont font("Arial", 26);  // Change "Arial" to the desired font family and 12 to the desired font size
        QPalette palette;
        palette.setColor(QPalette::Text, Qt::white);  // Change Qt::blue to the desired text color

        ui->Execption_txt->setFont(font);
        ui->Execption_txt->setPalette(palette);
        ui->Execption_txt->setPlainText(content);

        // Show the content in a message box
        //QMessageBox::information(this, "CSC - 201 ", content);

        // Close the file
        file.close();
    }
}

