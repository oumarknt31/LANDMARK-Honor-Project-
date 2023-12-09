#include "mathsquizdialog.h"
#include "ui_mathsquizdialog.h"
#include "questionquiz.h"
#include "cscquiz.h"
#include <QVector>
#include <QString>
#include <QList>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>


mathsquizDialog::mathsquizDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mathsquizDialog)
{
    ui->setupUi(this);

    // SET THE IMAGE OF MY DIFFERENT BACKGROUND
    QPixmap MathsQPic(":/img/MathsQuiz.jpeg");
    ui->MathsQuizPic->setPixmap(MathsQPic);

    QPixmap calc1QPic(":/img/CalculusI Quiz.jpeg");
    ui->calc1_Pic->setPixmap(calc1QPic);

    QPixmap calc2QPic(":/img/CalculusII Quiz.jpeg");
    ui->Cal2_Pic->setPixmap(calc2QPic);

    QPixmap backgrdQPic(":/img/Quiz Background.jpeg");
    ui->QuizCsc111Pic->setPixmap(backgrdQPic);

    QPixmap summaryQPic(":/img/Quiz Background.jpeg");
    ui->summaryPic->setPixmap(summaryQPic);


    QPixmap backgrdQPicII(":/img/Quiz Background.jpeg");
    ui->QuizCsc211Pic->setPixmap(backgrdQPicII);

    QPixmap summaryQPicII(":/img/Quiz Background.jpeg");
    ui->summaryPic_II->setPixmap(summaryQPicII);
}

mathsquizDialog::~mathsquizDialog()
{
    delete ui;
}

int mathsquizDialog::initializeQuestionsC(int index) {  // THIS FUNCTION LOAD THE QUIZ'S QUESTIONS
    QVector<QuestionQuiz> question; // This QVector will store the different question and then will be used as a parameter for the CscQuiz object

    // Question 1 ~Derivatives~
    QString questionText1 = "In physics, what does the derivative of position with respect to time represent?";
    QVector<QString> options1 = {"Velocity", "Acceleration", "Force", "Energy"};
    int correctOption1 = 1; // The correct option is the first one
    question.push_back(QuestionQuiz(questionText1, options1, correctOption1));

    // Question 2  ~~
    QString questionText2 = "What is the derivative of a function?";
    QVector<QString> options2 = {"Rate of changes", "Area under curve", "Integral of function", "Slope of tangent"};
    int correctOption2 = 4;
    question.push_back(QuestionQuiz(questionText2, options2, correctOption2));

    // Question 3  ~~
    QString questionText3 = "What does it mean if the limit of a function as x approaches a certain value is infinity?";
    QVector<QString> options3 = {"Becomes extremelly large", "Undefined", "Approaches zero", "Oscillates"};
    int correctOption3 = 1;
    question.push_back(QuestionQuiz(questionText3, options3, correctOption3));

    // Question 4  ~ ~
    QString questionText4 = "For what functions is the derivative not defined?";
    QVector<QString> options4 = {"Continuous", "Discontinuous", "Functions with corners", "All have defined derivatives"};
    int correctOption4 = 2;
    question.push_back(QuestionQuiz(questionText4, options4, correctOption4));

    // Question 5  ~ ~
    QString questionText5 = "What does the limit of a function describe?";
    QVector<QString> options5 = {"Value at a point", "Rate of change", "Approaching a value", "Integral"};
    int correctOption5 = 3;
    question.push_back(QuestionQuiz(questionText5, options5, correctOption5));

    // Question 6  ~ ~
    QString questionText6 = "What is the limit of a function as x approaches positive or negative infinity?";
    QVector<QString> options6 = {"Zero", "Undefined", "Infinity", "One"};
    int correctOption6 = 2;
    question.push_back(QuestionQuiz(questionText6, options6, correctOption6));

    // Question 7 ~ ~
    QString questionText7 = "For what functions is the derivative always zero?";
    QVector<QString> options7 = {"Constant functions", "Linear functions", "Quadratic functions", "Exponential functions"};
    int correctOption7 = 1;
    question.push_back(QuestionQuiz(questionText7, options7, correctOption7));

    // Question 8 ~ ~
    QString questionText8 = "What is the second derivative of a function?";
    QVector<QString> options8 = {"Slope of tangent", "Area under curve", "Rate of change of change", "Integral of function"};
    int correctOption8 = 3;
    question.push_back(QuestionQuiz(questionText8, options8, correctOption8));

    // Question 9 ~ ~
    QString questionText9 = "In economics, what does the marginal cost represent?";
    QVector<QString> options9 = {"Total cost", "Average Cost", "Cost of one unit", "Profit from one additional unit"};
    int correctOption9 = 2;
    question.push_back(QuestionQuiz(questionText9, options9, correctOption9));

    // Question 10 ~ ~
    QString questionText10 = "What is L'Hôpital's Rule used for in calculus?";
    QVector<QString> options10 = {"Evaluating indeterminate forms", "Integration", "Solving linear equations", "Graphing functions"};
    int correctOption10 = 1;
    question.push_back(QuestionQuiz(questionText10, options10, correctOption10));




    // Instantiate CscIquiz and set its properties
    CscQuiz csc111Quiz;
    csc111Quiz.setQuizName("Calculus I Quiz");
    csc111Quiz.setNumOfQuestions(10);
    csc111Quiz.setQuestionContainer(question);

    // Send the questions and options to my labels
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

int selectedOption, points=0, position = 0;

void mathsquizDialog::on_Ready_btn_clicked()
{
    ui->stackedWidgetMaths->setCurrentIndex(2);
    initializeQuestionsC(0);
    ui->pointsVal_lbl->setText(QString::number(points));
}


void mathsquizDialog::on_Exit_btn_clicked()
{
    ui->stackedWidgetMaths->setCurrentIndex(0);
}


void mathsquizDialog::on_Back_btn_clicked()
{
    ui->stackedWidgetMaths->setCurrentIndex(0);
}


void mathsquizDialog::on_Back2_btn_clicked()
{
    reject();
}


void mathsquizDialog::on_Csc111_btn_clicked()
{
    ui->stackedWidgetMaths->setCurrentIndex(1);
}


void mathsquizDialog::on_Csc211_btn_clicked()
{
    ui->stackedWidgetMaths->setCurrentIndex(3);
}


void mathsquizDialog::on_Confirm_btn_clicked()    // THIS BLOCK CHECK THE ANSWER ENTERED BY THE USER
{
    if (position >= 0 && position < 10) {
        int correctOption = initializeQuestionsC(position);
        if (correctOption != -1) { // Check for a valid return value
            if (selectedOption == correctOption) {
                points++;
                ui->pointsVal_lbl->setText(QString::number(points));
            }
            else {
                // Display a message or update UI to show the correct answer
                QString correctAnswer = "Correct Answer: Option " + QString::number(correctOption);
                // Show a QMessageBox with the correct answer
                QMessageBox::information(this, "Incorrect", correctAnswer);
            }

            position++;
            int correctOption2 = initializeQuestionsC(position);
            if (position == 10){
                if (selectedOption == correctOption2) {
                    points++;
                    ui->pointsVal_lbl->setText(QString::number(points));
                }
            }
        }

    }

    if (position==10){
        ui->stackedWidgetMaths->setCurrentIndex(6);
        ui->finalScore->setText(QString::number(points));
        if (points==10 || points==9){
            ui->Congrats_lbl->setText("WOW, YOU ACED IT!");
        }
        else if (points==8 || points == 7){
            ui->Congrats_lbl->setText("EXCELLENT WORK!");
        }
        else if(points==6 || points ==5){
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



void mathsquizDialog::on_option1_Rbtn_clicked()
{
    selectedOption = 1;
}


void mathsquizDialog::on_option2_Rbtn_clicked()
{
    selectedOption = 2;
}


void mathsquizDialog::on_option3_Rbtn_clicked()
{
    selectedOption = 3;
}


void mathsquizDialog::on_option4_Rbtn_clicked()
{
    selectedOption = 4;
}


void mathsquizDialog::on_Close_btn_clicked()
{
    close();
}



//CALCULUS II IMPLEMENTTATION

int mathsquizDialog::initializeQuestionsIIC(int index) { // THIS FUNCTION LOAD THE QUESTION FOR THE SECOND QUIZ CSC211
    QVector<QuestionQuiz> questionII;

    // Question 1 ~Integral~
    QString questionIIText1 = "What does the symbol ∫ represent in calculus?";
    QVector<QString> optionsII1 = {"Summation", "Limit", "Integral", "Derivative"};
    int correctOptionII1 = 3; // The correct option is the third one
    questionII.push_back(QuestionQuiz(questionIIText1, optionsII1, correctOptionII1));

    // Question 2  ~Techniques of integration~
    QString questionIIText2 = "Which method involves selecting a substitution to simplify an integral?";
    QVector<QString> optionsII2 = {"Trigonometric Substitution", "Partial Fractions", "Integration by Parts", "Power Reduction"};
    int correctOptionII2 = 1;
    questionII.push_back(QuestionQuiz(questionIIText2, optionsII2, correctOptionII2));

    // Question 3 ~Seies and sequences~
    QString questionIIText3 = "What type of series has a constant difference between consecutive terms?";
    QVector<QString> optionsII3 = {"Divergent Series", "Geometric Series", "Convergent Series", "Arithmetic Series"};
    int correctOptionII3 = 4;
    questionII.push_back(QuestionQuiz(questionIIText3, optionsII3, correctOptionII3));

    // Question 4  ~Integral~
    QString questionIIText4 = "What test can be used to determine the convergence of an infinite series with positive terms?";
    QVector<QString> optionsII4 = {"Integral Test", "Ratio Test", "Comparison Test", "Root Test"};
    int correctOptionII4 = 2;
    questionII.push_back(QuestionQuiz(questionIIText4, optionsII4, correctOptionII4));

    // Question 5  ~Seies and sequences~
    QString questionIIText5 = "What does a definite integral represent geometrically?";
    QVector<QString> optionsII5 = {"Area under a curve", "Slope of a tangent line", "Rate of change", "Volume of a solid"};
    int correctOptionII5 = 1;
    questionII.push_back(QuestionQuiz(questionIIText5, optionsII5, correctOptionII5));

    // Question 6  ~Techniques of integration~
    QString questionIIText6 = "Which method involves multiplying two functions to simplify an integral?";
    QVector<QString> optionsII6 = {"Power Reduction", "Partial Fractions", "U Substitution", "Integration by Parts"};
    int correctOptionII6 = 4;
    questionII.push_back(QuestionQuiz(questionIIText6, optionsII6, correctOptionII6));

    // Question 7 ~Integrals~
    QString questionIIText7 = "What is the fundamental concept in calculus that involves adding up infinitely small quantities?";
    QVector<QString> optionsII7 = {"Derivative", "Limit", "Integration", "Sequence"};
    int correctOptionII7 = 3;
    questionII.push_back(QuestionQuiz(questionIIText7, optionsII7, correctOptionII7));

    // Question 8 ~Integrals~
    QString questionIIText8 = "Which term describes the sum of the terms in a sequence or series?";
    QVector<QString> optionsII8 = {"Derivative", "Integral", "Limit", "Summation"};
    int correctOptionII8 = 4;
    questionII.push_back(QuestionQuiz(questionIIText8, optionsII8, correctOptionII8));

    // Question 9 ~Techniques of integration~
    QString questionTextII9 = "Which method involves breaking down a complex fraction into simpler fractions?";
    QVector<QString> optionsII9 = {"Partial Fractions", "Integration by Parts", "U Substitution", "Power Reduction"};
    int correctOptionII9 = 1;
    questionII.push_back(QuestionQuiz(questionTextII9, optionsII9, correctOptionII9));

    // Question 10 ~Inheritance~
    QString questionIIText10 = "What is the sum of an infinite geometric series with a common ratio r, where -1 < r < 1?";
    QVector<QString> optionsII10 = {"Infinite", "1/(1 - r)", "Undefined", "0"};
    int correctOptionII10 = 2;
    questionII.push_back(QuestionQuiz(questionIIText10, optionsII10, correctOptionII10));




    // Instantiate CscIquiz and set its properties
    CscQuiz csc211Quiz;
    csc211Quiz.setQuizName("Calculus II Quiz");
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


int selectedOptionII, pointsII=0, positionII = 0;


void mathsquizDialog::on_Close_btn_II_clicked()
{
    close();
}




void mathsquizDialog::on_option1_Rbtn_II_clicked()
{
    selectedOptionII = 1;
}


void mathsquizDialog::on_option2_Rbtn_II_clicked()
{
    selectedOptionII = 2;
}


void mathsquizDialog::on_option3_Rbtn_II_clicked()
{
    selectedOptionII = 3;
}



void mathsquizDialog::on_option4_Rbtn_II_clicked()
{
    selectedOptionII = 4;
}


void mathsquizDialog::on_Confirm_btn_II_clicked()   //THIS BLOCK CHECK THE ANSWER ENTERED BY THE USER
{
    if (positionII >= 0 && positionII < 10) {  // Make sure it is in the interval of question
        int correctOptionII = initializeQuestionsIIC(positionII);
        if (correctOptionII != -1) { // Check for a valid return value
            if (selectedOptionII == correctOptionII) {
                pointsII++;
                ui->pointsVal_lbl_II->setText(QString::number(pointsII));
            }

            else {
                    // Display a message or update UI to show the correct answer
                    QString correctAnswer = "Correct Answer: Option " + QString::number(correctOptionII);
                    // Show a QMessageBox with the correct answer
                    QMessageBox::information(this, "Incorrect", correctAnswer);

            }

            positionII++;
            int correctOptionII2 = initializeQuestionsIIC(positionII);
            if (positionII == 10){
                if (selectedOptionII == correctOptionII2) {
                    pointsII++;
                    ui->pointsVal_lbl_II->setText(QString::number(pointsII));
                }
            }
        }

    }

    if (positionII==10){    // QUIZ APPRECIATION ACCORDING TO THE SCORE
        ui->stackedWidgetMaths->setCurrentIndex(5);
        ui->finalScore_II->setText(QString::number(pointsII));
        if (pointsII==10 || pointsII==9){
            ui->Congrats_lbl_II->setText("WOW, YOU ACED IT!");
        }
        else if (pointsII==8 || pointsII == 7){
            ui->Congrats_lbl_II->setText("EXCELLENT WORK!");
        }
        else if(pointsII==6 || pointsII ==5){
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

void mathsquizDialog::on_Ready_btn_2_clicked()
{
    ui->stackedWidgetMaths->setCurrentIndex(4);
    initializeQuestionsIIC(0);
    ui->pointsVal_lbl_II->setText(QString::number(pointsII));
}

void mathsquizDialog::on_Back_btn_2_clicked()
{
    ui->stackedWidgetMaths->setCurrentIndex(0);
}




void mathsquizDialog::on_Exit_btn_II_clicked()
{
    ui->stackedWidgetMaths->setCurrentIndex(0);
}

