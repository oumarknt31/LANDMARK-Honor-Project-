#include "learndialog.h"
#include "ui_learndialog.h"
#include <QPixmap>
#include <QUrl>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFile>
#include <QString>o
//#include "mainwindow.h"

LearnDialog::LearnDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LearnDialog)
{

    // Set the images of the backgrounds
    ui->setupUi(this);
    QPixmap LearnImage(":/img/learn_Pic.jpeg");
    ui->learnCsc_Pic->setPixmap(LearnImage);

    QPixmap LearnMaths(":/img/LearnMaths.jpeg");
    ui->mathsLearn_Pic->setPixmap(LearnMaths);

    QPixmap LearnComputerSc(":/img/LearnCSC.jpeg");
    ui->cscLearn_Pic->setPixmap(LearnComputerSc);

    QPixmap LearnCalcII(":/img/CalculusII.jpeg");
    ui->CalcII_Pic->setPixmap(LearnCalcII);

    QPixmap LearnCalcI(":/img/CalculusI.jpeg");
    ui->CalcI_Pic->setPixmap(LearnCalcI);

    QPixmap MathsTxt(":/img/Quiz Background.jpeg");
    ui->MathsDisplay_pic->setPixmap(MathsTxt);

    QPixmap LearnCsc111(":/img/CSC111.jpeg");
    ui->Csc111Learn_Pic->setPixmap(LearnCsc111);

    QPixmap LearnCsc211(":/img/CSC211.jpeg");
    ui->Csc211Learn_Pic->setPixmap(LearnCsc211);

}

LearnDialog::~LearnDialog()
{
    delete ui;
}




void LearnDialog::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LearnDialog::on_Csc_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void LearnDialog::on_Maths_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void LearnDialog::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}



void LearnDialog::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}



void LearnDialog::on_Csc111_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

/* In this section, I used my push buttons to display the desired contents clicked by the user. When a button is clicked,
the text sent to the text label is read from the corresponding files (Each subject has its lists of topics, and each topics
has its own text files .txt After displaying the text which the user can learn from, the user will have the possibility to
go to a website realated to the topic if not satisfied with the previous content. The link will be stored in a QPushButton
so whenever the user click it she/he is redirect to a website */


void LearnDialog::on_IntroToIntgrl_btn_clicked()
{
    {
        // Reading from file by using Exception
        try {
            ui->stackedWidget->setCurrentIndex(5);

            QFile file(":/txt/Intro to integration.txt");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                throw QString("Error opening file");
            }

            QTextStream in(&file);
            QString content = in.readAll();

            ui->MathsDisplay_Txt->setPlainText(content);
            ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

            file.close();

            // Setting the external link (corrsponding website)
            QString websiteUrl = "https://math.libretexts.org/Courses/Monroe_Community_College/MTH_211_Calculus_II/Chapter_5%3A_Integration";
            ui->MoreResources_btn->setProperty("link12", QVariant(websiteUrl));

        } catch (const QString& errorMsg) {
            // Handle the exception
            QMessageBox::critical(this, "Error", errorMsg);
        }
    }
}




void LearnDialog::on_Back2_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LearnDialog::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void LearnDialog::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void LearnDialog::on_pushButton_4_clicked()
{
    reject();
}


void LearnDialog::on_Back_btn_clicked()
{
    reject();
}



void LearnDialog::on_Csc211_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void LearnDialog::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void LearnDialog::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void LearnDialog::on_Pointers_btn_111_clicked()
{

    {
        // USE OF FILE I/O and EXCEPTION HANDLING
        try {
            ui->stackedWidget->setCurrentIndex(5);

            QFile file(":/txt/Pointers in c++.txt");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                throw QString("Error opening file");
            }

            QTextStream in(&file);
            QString content = in.readAll();

            ui->MathsDisplay_Txt->setPlainText(content);
            ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

            file.close();

            QString websiteUrl = "https://www.programiz.com/cpp-programming/pointers";
            ui->MoreResources_btn->setProperty("link", QVariant(websiteUrl));

        } catch (const QString& errorMsg) {
            // Handle the exception
            QMessageBox::critical(this, "Error", errorMsg);
        }
    }
}


void LearnDialog::on_MoreResources_btn_clicked()  // This button check which link to send to the label according to user event
{
    // Retrieve the link set by Pointers_btn_111
    QVariant linkVariant = ui->MoreResources_btn->property("link");
    if (linkVariant.isValid()) {
        QString websiteUrl = linkVariant.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant1 = ui->MoreResources_btn->property("link1");
    if (linkVariant1.isValid()) {
        QString websiteUrl = linkVariant1.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant2 = ui->MoreResources_btn->property("link2");
    if (linkVariant2.isValid()) {
        QString websiteUrl = linkVariant2.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant3 = ui->MoreResources_btn->property("link3");
    if (linkVariant3.isValid()) {
        QString websiteUrl = linkVariant3.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant4 = ui->MoreResources_btn->property("link4");
    if (linkVariant4.isValid()) {
        QString websiteUrl = linkVariant4.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant5 = ui->MoreResources_btn->property("link5");
    if (linkVariant5.isValid()) {
        QString websiteUrl = linkVariant5.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant6 = ui->MoreResources_btn->property("link6");
    if (linkVariant6.isValid()) {
        QString websiteUrl = linkVariant6.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }


    QVariant linkVariant7 = ui->MoreResources_btn->property("link7");
    if (linkVariant7.isValid()) {
        QString websiteUrl = linkVariant7.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant8 = ui->MoreResources_btn->property("link8");
    if (linkVariant8.isValid()) {
        QString websiteUrl = linkVariant8.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant9 = ui->MoreResources_btn->property("link9");
    if (linkVariant9.isValid()) {
        QString websiteUrl = linkVariant9.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant10 = ui->MoreResources_btn->property("link10");
    if (linkVariant10.isValid()) {
        QString websiteUrl = linkVariant10.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant11 = ui->MoreResources_btn->property("link11");
    if (linkVariant11.isValid()) {
        QString websiteUrl = linkVariant11.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant12 = ui->MoreResources_btn->property("link12");
    if (linkVariant12.isValid()) {
        QString websiteUrl = linkVariant12.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant13 = ui->MoreResources_btn->property("link13");
    if (linkVariant13.isValid()) {
        QString websiteUrl = linkVariant13.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant14 = ui->MoreResources_btn->property("link14");
    if (linkVariant14.isValid()) {
        QString websiteUrl = linkVariant14.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant15 = ui->MoreResources_btn->property("link15");
    if (linkVariant15.isValid()) {
        QString websiteUrl = linkVariant15.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant16 = ui->MoreResources_btn->property("link16");
    if (linkVariant16.isValid()) {
        QString websiteUrl = linkVariant16.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant17 = ui->MoreResources_btn->property("link17");
    if (linkVariant17.isValid()) {
        QString websiteUrl = linkVariant17.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant18 = ui->MoreResources_btn->property("link18");
    if (linkVariant18.isValid()) {
        QString websiteUrl = linkVariant18.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }

    QVariant linkVariant19 = ui->MoreResources_btn->property("link19");
    if (linkVariant19.isValid()) {
        QString websiteUrl = linkVariant19.toString();
        QDesktopServices::openUrl(QUrl(websiteUrl));
    }
}


void LearnDialog::on_Loop_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Loop in c++.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/for-loop";
        ui->MoreResources_btn->setProperty("link1", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}



void LearnDialog::on_If_Else_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/If-else statement.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/if-else";
        ui->MoreResources_btn->setProperty("link2", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_Function_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Function in c++.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/function";
        ui->MoreResources_btn->setProperty("link3", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}




void LearnDialog::on_Class_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Class in c++.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/object-class";
        ui->MoreResources_btn->setProperty("link4", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}




void LearnDialog::on_Struct_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Structures in C++.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/structure";
        ui->MoreResources_btn->setProperty("link5", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_Pointers_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Pointers in c++.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/pointers";
        ui->MoreResources_btn->setProperty("link6", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_Inheritance_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Inheritance in c++.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/inheritance";
        ui->MoreResources_btn->setProperty("link7", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}



void LearnDialog::on_template_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Template in c++.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/class-templates";
        ui->MoreResources_btn->setProperty("link8", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_Recursion_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Recursion in c++.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/recursion";
        ui->MoreResources_btn->setProperty("link9", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_Exception_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Exception_txt.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/exception-handling";
        ui->MoreResources_btn->setProperty("link10", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_FileInOut_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/FIle InOut.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://www.programiz.com/cpp-programming/file-handling";
        ui->MoreResources_btn->setProperty("link11", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_TechOfIntgrl_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Techniques of integration.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://math.libretexts.org/Courses/Monroe_Community_College/MTH_211_Calculus_II/Chapter_7%3A_Techniques_of_Integration";
        ui->MoreResources_btn->setProperty("link13", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_ApplicIntgrl_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Application of integrals.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://math.libretexts.org/Courses/Monroe_Community_College/MTH_211_Calculus_II/Chapter_6%3A_Applications_of_Integration";
        ui->MoreResources_btn->setProperty("link14", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}




void LearnDialog::on_SequSer_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Series and sequencies.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://math.libretexts.org/Courses/Monroe_Community_College/MTH_211_Calculus_II/Chapter_9%3A_Sequences_and_Series";
        ui->MoreResources_btn->setProperty("link15", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_Limits_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Limits .txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://math.libretexts.org/Courses/Monroe_Community_College/MTH_210_Calculus_I_(Professor_Dean)/Chapter_2_Limits";
        ui->MoreResources_btn->setProperty("link16", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_BasicDeriv_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Basics Derivatives.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://math.libretexts.org/Courses/Monroe_Community_College/MTH_210_Calculus_I_(Professor_Dean)/Chapter_3%3A_Derivatives";
        ui->MoreResources_btn->setProperty("link17", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}



void LearnDialog::on_MoreDeriv_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/More Derivatives.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://math.libretexts.org/Courses/Monroe_Community_College/MTH_210_Calculus_I_(Professor_Dean)/Chapter_3%3A_Derivatives/3.5%3A_Derivatives_of_Trigonometric_Functions";
        ui->MoreResources_btn->setProperty("link18", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}


void LearnDialog::on_ApplicatDeriv_btn_clicked()
{
    try {
        ui->stackedWidget->setCurrentIndex(5);

        QFile file(":/txt/Application of derivatives.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            throw QString("Error opening file");
        }

        QTextStream in(&file);
        QString content = in.readAll();

        ui->MathsDisplay_Txt->setPlainText(content);
        ui->MathsDisplay_Txt->setStyleSheet("background: transparent;");

        file.close();

        QString websiteUrl = "https://math.libretexts.org/Courses/Monroe_Community_College/MTH_210_Calculus_I_(Professor_Dean)/Chapter_4%3A_Applications_of_Derivatives";
        ui->MoreResources_btn->setProperty("link19", QVariant(websiteUrl));

    } catch (const QString& errorMsg) {
        // Handle the exception
        QMessageBox::critical(this, "Error", errorMsg);
    }
}

