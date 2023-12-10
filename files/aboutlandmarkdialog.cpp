#include "aboutlandmarkdialog.h"
#include "ui_aboutlandmarkdialog.h"
#include <QPixmap>
#include <QFile>

AboutLandmarkDialog::AboutLandmarkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutLandmarkDialog)
{
    ui->setupUi(this);

    QPixmap aboutLM(":/img/AboutLandmark.jpeg");
    ui->About_Pic->setPixmap(aboutLM);

    QFile file(":/txt/About Landmark.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // if File opened successfully, proceed with reading
        QTextStream in(&file);
        QString content = in.readAll();
        file.close();

        // Set the plain text
        ui->AboutLM_Txt->setPlainText(content);
        ui->AboutLM_Txt->setStyleSheet("background: transparent;");
    } else {
        // Handle the case when the file couldn't be opened
        qDebug() << "Error opening file:" << file.errorString();
        ui->AboutLM_Txt->setPlainText("Error loading content. Please check the resource file.");
        ui->AboutLM_Txt->setStyleSheet("background: transparent;");
    }
}

AboutLandmarkDialog::~AboutLandmarkDialog()
{
    delete ui;
}

void AboutLandmarkDialog::on_Back_btn_clicked()
{
    reject();
}

