/* The Cscquiz class is the derived class of Quiz class (abstract class) that will serve of the blueprint of my quiz question*/


#include "cscquiz.h"

void CscQuiz::setQuizName(const QString& subject) {
    name = subject;
}

void CscQuiz::setNumOfQuestions(int num) {
    numOfQuestions = num;
}

void CscQuiz::setQuestionContainer(const QVector<QuestionQuiz>& questions) {
    questionContainer = questions;
}

void CscQuiz::showCurrentQuest(int index) {
    // Implement this function to display the current question
    // use questionContainer.at(index) to get the current question
}
