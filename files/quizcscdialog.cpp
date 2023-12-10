#include "quizcscdialog.h"
#include "ui_quizcscdialog.h"
#include "questionquiz.h"
#include "cscquiz.h"
#include "mainwindow.h"
#include <QVector>
#include <QString>
#include <QList>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>

QuizCscDialog::QuizCscDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuizCscDialog)
{
    ui->setupUi(this);

    QPixmap cscQPic(":/img/ComputerSc quiz.jpeg");
    ui->CscQuizPic->setPixmap(cscQPic);

    QPixmap csc111QPic(":/img/Csc111Quiz.jpeg");
    ui->CSC111_Pic->setPixmap(csc111QPic);

    QPixmap csc211Pic(":/img/Csc211Quiz.jpeg");
    ui->CSC211_Pic->setPixmap(csc211Pic);

    QPixmap backgrdQPic(":/img/Quiz Background.jpeg");
    ui->QuizCsc111Pic->setPixmap(backgrdQPic);

    QPixmap summaryQPic(":/img/Quiz Background.jpeg");
    ui->summaryPic->setPixmap(summaryQPic);


    QPixmap backgrdQPicII(":/img/Quiz Background.jpeg");
    ui->QuizCsc211Pic->setPixmap(backgrdQPicII);

    QPixmap summaryQPicII(":/img/Quiz Background.jpeg");
    ui->summaryPic_II->setPixmap(summaryQPicII);

    /*ui->option1_Rbtn->setChecked(false);
    ui->option2_Rbtn->setChecked(false);
    ui->option3_Rbtn->setChecked(false);
    ui->option4_Rbtn->setChecked(false);*/
}

QuizCscDialog::~QuizCscDialog()
{
    delete ui;
}

int QuizCscDialog::initializeQuestions(int index) {    // THIS FUNCTION LOAD THE QUIZ'S QUESTIONS
    QVector<QuestionQuiz> question;   // This QVector will store the different question and then will be used as a parameter for the CscQuiz object

    // Question 1 ~LOOP~
    QString questionText1 = "What is the main purpose of a loop?";
    QVector<QString> options1 = {"To repeat a block of code", "To define a new data type", "To store data in memory", "To handle exceptions"};
    int correctOption1 = 1; // The correct option is the first one
    question.push_back(QuestionQuiz(questionText1, options1, correctOption1));

    // Question 2  ~STRUCT~
    QString questionText2 = "What is the primary use of a struct in C++?";
    QVector<QString> options2 = {"To create objects", "To organize related data", "To handle exceptions", "To define functions"};
    int correctOption2 = 2;
    question.push_back(QuestionQuiz(questionText2, options2, correctOption2));

    // Question 3  ~ARRAY~
    QString questionText3 = "What does the [] operator do in C++ when used with an array?";
    QVector<QString> options3 = {"Loops through all elements", "Creates a new array", "Prints the entire array", "Accesses element at given index"};
    int correctOption3 = 4;
    question.push_back(QuestionQuiz(questionText3, options3, correctOption3));

    // Question 4  ~FILE I/O~
    QString questionText4 = "What does ofstream represent in file I/O?";
    QVector<QString> options4 = {"A file access mode", "An input stream object", "A file buffer", "An output stream object"};
    int correctOption4 = 4;
    question.push_back(QuestionQuiz(questionText4, options4, correctOption4));

    // Question 5  ~FUNCTION~
    QString questionText5 = "What happens when a function returns no value (void)?";
    QVector<QString> options5 = {"Returns 0 by default", "Doesn't return anything", "Program crashes", "Returns an empty array"};
    int correctOption5 = 2;
    question.push_back(QuestionQuiz(questionText5, options5, correctOption5));

    // Question 6  ~LOOP~
    QString questionText6 = "Which loop type is best suited for iterating over a fixed-size array?";
    QVector<QString> options6 = {"while loop", "do-while loop", "if statement", "for loop"};
    int correctOption6 = 4;
    question.push_back(QuestionQuiz(questionText6, options6, correctOption6));

    // Question 7 ~Value vs Reference~
    QString questionText7 = "Which data type is ALWAYS passed by reference in C++?";
    QVector<QString> options7 = {"int", "char", "array", "bool"};
    int correctOption7 = 3;
    question.push_back(QuestionQuiz(questionText7, options7, correctOption7));

    // Question 8 ~Class~
    QString questionText8 = "What is the key advantage of using classes in C++?";
    QVector<QString> options8 = {"Code reuse", "Data encapsulation", "Dynamic memory allocation", "Automatic type conversion"};
    int correctOption8 = 1;
    question.push_back(QuestionQuiz(questionText8, options8, correctOption8));

    // Question 9 ~If-Else statement~
    QString questionText9 = "What type of expression does an if statement evaluate in C++?";
    QVector<QString> options9 = {"Mathematical/Boolean", "Boolean Only", "Mathematical only", "Character string"};
    int correctOption9 = 1;
    question.push_back(QuestionQuiz(questionText9, options9, correctOption9));

    // Question 10 ~Pointer~
    QString questionText10 = "What does the '*' symbol represent in a pointer declaration?";
    QVector<QString> options10 = {"Dereference operator", "Multiplication operator", "Address-of operator", "Pointer type"};
    int correctOption10 = 3;
    question.push_back(QuestionQuiz(questionText10, options10, correctOption10));




    // Instantiate CscIquiz and set its properties
    CscQuiz csc111Quiz;
    csc111Quiz.setQuizName("Computer Science 111 Quiz");
    csc111Quiz.setNumOfQuestions(10);
    csc111Quiz.setQuestionContainer(question);


    if (index >= 0 && index < question.size()) {
        ui->questionTxt->setWordWrap(true);
        ui->questionTxt->setText(csc111Quiz.questionContainer.at(index).questionText);
        ui->option1_Rbtn->setText(csc111Quiz.questionContainer.at(index).options.at(0));
        ui->option2_Rbtn->setText(csc111Quiz.questionContainer.at(index).options.at(1));
        ui->option3_Rbtn->setText(csc111Quiz.questionContainer.at(index).options.at(2));
        ui->option4_Rbtn->setText(csc111Quiz.questionContainer.at(index).options.at(3));

        /*ui->option1_Rbtn->setChecked(false);
        ui->option2_Rbtn->setChecked(false);
        ui->option3_Rbtn->setChecked(false);
        ui->option4_Rbtn->setChecked(false);*/

        return csc111Quiz.questionContainer.at(index).correctOption;
    } else {
        qDebug() << "Invalid index in initializeQuestions.";
        return -1; // Indicate an error condition
    }

    return csc111Quiz.questionContainer.at(index).correctOption;

}

int mSelectedOption, mPoints=0, mPosition = 0;

void QuizCscDialog::on_Ready_btn_clicked()
{
    ui->stackedWidgetCSC->setCurrentIndex(2);
    initializeQuestions(0);
    ui->pointsVal_lbl->setText(QString::number(mPoints));
}


void QuizCscDialog::on_Exit_btn_clicked()
{
    ui->stackedWidgetCSC->setCurrentIndex(0);
}


void QuizCscDialog::on_Back_btn_clicked()
{
    ui->stackedWidgetCSC->setCurrentIndex(0);
}


void QuizCscDialog::on_Back2_btn_clicked()
{
    reject();
}


void QuizCscDialog::on_Csc111_btn_clicked()
{
    ui->stackedWidgetCSC->setCurrentIndex(1);
}


void QuizCscDialog::on_Csc211_btn_clicked()
{
    ui->stackedWidgetCSC->setCurrentIndex(3);
}


void QuizCscDialog::on_Confirm_btn_clicked()   //THIS BLOCK CHECK THE ANSWER ENTERED BY THE USER
{
    if (mPosition >= 0 && mPosition < 10) {
        int correctOption = initializeQuestions(mPosition);
        if (correctOption != -1) { // Check for a valid return value
            if (mSelectedOption == correctOption) {
                mPoints++;
                ui->pointsVal_lbl->setText(QString::number(mPoints));
            }
            else {
                // Display a message or update UI to show the correct answer
                QString mCorrectAnswer = "Correct Answer: Option " + QString::number(correctOption);
                // Show a QMessageBox with the correct answer
                QMessageBox::information(this, "Incorrect", mCorrectAnswer);
            }

            mPosition++;
            int correctOption2 = initializeQuestions(mPosition);
            if (mPosition == 10){
                    if (mSelectedOption == correctOption2) {
                        mPoints++;
                        ui->pointsVal_lbl->setText(QString::number(mPoints));
                    }
            }
        }

    }

    if (mPosition==10){
        ui->stackedWidgetCSC->setCurrentIndex(6);
            ui->finalScore->setText(QString::number(mPoints));
            if (mPoints==10 || mPoints==9){
                ui->Congrats_lbl->setText("WOW, YOU ACED IT!");
            }
            else if (mPoints==8 || mPoints == 7){
                ui->Congrats_lbl->setText("EXCELLENT WORK!");
            }
            else if(mPoints==6 || mPoints ==5){
                ui->Congrats_lbl->setText("HALFWAY TO PERFECT!");
            }
            else{
                    ui->Congrats_lbl->setText("DON'T GET DISCOURAGED!");
            }

    }
        else {
        qDebug() << "Invalid position in on_Confirm_btn_clicked.";
    }
}



void QuizCscDialog::on_option1_Rbtn_clicked()
{
    mSelectedOption = 1;
}


void QuizCscDialog::on_option2_Rbtn_clicked()
{
    mSelectedOption = 2;
}


void QuizCscDialog::on_option3_Rbtn_clicked()
{
    mSelectedOption = 3;
}


void QuizCscDialog::on_option4_Rbtn_clicked()
{
    mSelectedOption = 4;
}


void QuizCscDialog::on_Close_btn_clicked()
{
    close();
}

                                                    //COMPUTER SCIENCE 211 IMPLEMENTTATION

int QuizCscDialog::initializeQuestionsII(int index) {     // THIS FUNCTION LOAD THE SECOND QUIZ'S QUESTIONS
    QVector<QuestionQuiz> questionII;

    // Question 1 ~Pointer~
    QString questionIIText1 = "What allows you to dynamically allocate and access memory in C++?";
    QVector<QString> optionsII1 = {"Arrays", "Pointers", "References", "Loops"};
    int correctOptionII1 = 2; // The correct option is the first one
    questionII.push_back(QuestionQuiz(questionIIText1, optionsII1, correctOptionII1));

    // Question 2  ~Vector~
    QString questionIIText2 = "A ____ happens when dynamically allocated memory (using new) isn't properly deallocated";
    QVector<QString> optionsII2 = {"Memory corruption", "Stack overflow", "Memory leak", "Null pointer exception"};
    int correctOptionII2 = 3;
    questionII.push_back(QuestionQuiz(questionIIText2, optionsII2, correctOptionII2));

    // Question 3 ~Template~
    QString questionIIText3 = "When are templates usually instantiated?";
    QVector<QString> optionsII3 = {"At compile time", "At link time", "Load time", "At runtime"};
    int correctOptionII3 = 1;
    questionII.push_back(QuestionQuiz(questionIIText3, optionsII3, correctOptionII3));

    // Question 4  ~Inheritane~
    QString questionIIText4 = "How many classes can a single class inherited from?";
    QVector<QString> optionsII4 = {"infinte", "1", "2", "3"};
    int correctOptionII4 = 2;
    questionII.push_back(QuestionQuiz(questionIIText4, optionsII4, correctOptionII4));

    // Question 5  ~Abstract class~
    QString questionIIText5 = "A class containing a(n) _____ is an abstract class.";
    QVector<QString> optionsII5 = {"Recursive function", "Built-in Function", "Pure virtual function", "Overloaded function"};
    int correctOptionII5 = 3;
    questionII.push_back(QuestionQuiz(questionIIText5, optionsII5, correctOptionII5));

    // Question 6  ~Recursion~
    QString questionIIText6 = "What is recursion in C++?";
    QVector<QString> optionsII6 = {"A function that calls itself", "Dynamic size", "A Function", "A data type"};
    int correctOptionII6 = 1;
    questionII.push_back(QuestionQuiz(questionIIText6, optionsII6, correctOptionII6));

    // Question 7 ~Exception~
    QString questionIIText7 = "The main advantage of using _____ in C++ is to handle unexpected errors gracefully.";
    QVector<QString> optionsII7 = {"Template", "Class", "Struct", "Exception"};
    int correctOptionII7 = 4;
    questionII.push_back(QuestionQuiz(questionIIText7, optionsII7, correctOptionII7));

    // Question 8 ~Pointers~
    QString questionIIText8 = "What does the '->' operator represent in a pointer-to-member?";
    QVector<QString> optionsII8 = {"Pointer declaration", "Dereference operator", "Dynamic size", "Access member through pointer"};
    int correctOptionII8 = 4;
    questionII.push_back(QuestionQuiz(questionIIText8, optionsII8, correctOptionII8));

    // Question 9 ~Array~
    QString questionTextII9 = "What is the correct syntax for accessing an element in a two-dimensional array?";
    QVector<QString> optionsII9 = {"arr[2,3]", "arr[2][3]", "arr(2,3)", "arr[2]{3}"};
    int correctOptionII9 = 2;
    questionII.push_back(QuestionQuiz(questionTextII9, optionsII9, correctOptionII9));

    // Question 10 ~Inheritance~
    QString questionIIText10 = "what do you use to inherit another class?";
    QVector<QString> optionsII10 = {"(:) Colon", "(*) Asterisk", "(;) Semi-colon", "([]) Brackets"};
    int correctOptionII10 = 1;
    questionII.push_back(QuestionQuiz(questionIIText10, optionsII10, correctOptionII10));




    // Instantiate CscIquiz and set its properties
    CscQuiz csc211Quiz;
    csc211Quiz.setQuizName("Computer Science 211 Quiz");
    csc211Quiz.setNumOfQuestions(10);
    csc211Quiz.setQuestionContainer(questionII);


    if (index >= 0 && index < questionII.size()) {
        ui->questionTxt_II->setWordWrap(true);
        ui->questionTxt_II->setText(csc211Quiz.questionContainer.at(index).questionText);
        ui->option1_Rbtn_II->setText(csc211Quiz.questionContainer.at(index).options.at(0));
        ui->option2_Rbtn_II->setText(csc211Quiz.questionContainer.at(index).options.at(1));
        ui->option3_Rbtn_II->setText(csc211Quiz.questionContainer.at(index).options.at(2));
        ui->option4_Rbtn_II->setText(csc211Quiz.questionContainer.at(index).options.at(3));

        /*ui->option1_Rbtn->setChecked(false);
        ui->option2_Rbtn->setChecked(false);
        ui->option3_Rbtn->setChecked(false);
        ui->option4_Rbtn->setChecked(false);*/

        return csc211Quiz.questionContainer.at(index).correctOption;
    } else {
        qDebug() << "Invalid index in initializeQuestionsII.";
        return -1; // Indicate an error condition
    }

    return csc211Quiz.questionContainer.at(index).correctOption;

}


int mSelectedOptionII, mPointsII=0, mPositionII = 0;


void QuizCscDialog::on_Close_btn_II_clicked()
{
    close();
}




void QuizCscDialog::on_option1_Rbtn_II_clicked()
{
    mSelectedOptionII = 1;
}


void QuizCscDialog::on_option2_Rbtn_II_clicked()
{
    mSelectedOptionII = 2;
}


void QuizCscDialog::on_option3_Rbtn_II_clicked()
{
    mSelectedOptionII = 3;
}



void QuizCscDialog::on_option4_Rbtn_II_clicked()
{
    mSelectedOptionII = 4;
}


void QuizCscDialog::on_Confirm_btn_II_clicked()    //THIS BLOCK CHECK THE ANSWER ENTERED BY THE USER
{
    if (mPositionII >= 0 && mPositionII < 10) {
        int correctOptionII = initializeQuestionsII(mPositionII);
        if (correctOptionII != -1) { // Check for a valid return value
            if (mSelectedOptionII == correctOptionII) {
            mPointsII++;
            ui->pointsVal_lbl_II->setText(QString::number(mPointsII));

            /*ui->option1_Rbtn->setChecked(false);
            ui->option2_Rbtn->setChecked(false);
            ui->option3_Rbtn->setChecked(false);
            ui->option4_Rbtn->setChecked(false);*/
            }

            else {
            // Display a message or update UI to show the correct answer
            QString mCorrectAnswer1 = "Correct Answer: Option " + QString::number(correctOptionII);
            // Show a QMessageBox with the correct answer
            QMessageBox::information(this, "Incorrect", mCorrectAnswer1);
            }

            mPositionII++;
            int correctOptionII2 = initializeQuestionsII(mPositionII);
                if (mPositionII == 10){
                    if (mSelectedOptionII == correctOptionII2) {
                        mPointsII++;
                        ui->pointsVal_lbl_II->setText(QString::number(mPointsII));
                    }
                }
        }

    }

    if (mPositionII==10){                          // QUIZ APPRECIATION ACCORDING TO THE SCORE
        ui->stackedWidgetCSC->setCurrentIndex(5);
        ui->finalScore_II->setText(QString::number(mPointsII));
        if (mPointsII==10 || mPointsII==9){
            ui->Congrats_lbl_II->setText("WOW, YOU ACED IT!");
        }
        else if (mPointsII==8 || mPointsII == 7){
            ui->Congrats_lbl_II->setText("EXCELLENT WORK!");
        }
        else if(mPointsII==6 || mPointsII ==5){
            ui->Congrats_lbl_II->setText("HALFWAY TO PERFECT!");
        }
        else{
            ui->Congrats_lbl_II->setText("DON'T GET DISCOURAGED!");
        }

    }
    else {
        qDebug() << "Invalid position in on_Confirm_btn_clicked_211.";
    }
}

void QuizCscDialog::on_Ready_btn_2_clicked()
{
    ui->stackedWidgetCSC->setCurrentIndex(4);
    initializeQuestionsII(0);
    ui->pointsVal_lbl_II->setText(QString::number(mPointsII));
}

void QuizCscDialog::on_Back_btn_2_clicked()
{
    ui->stackedWidgetCSC->setCurrentIndex(0);
}


void QuizCscDialog::on_Exit_btn_II_clicked()
{
    reject();
}

