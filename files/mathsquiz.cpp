#include "mathsquiz.h"

void mathsquiz::setQuizName(const QString& subject) {
    name = subject;
}

void mathsquiz::setNumOfQuestions(int num) {
    numOfQuestions = num;
}

void mathsquiz::setQuestionContainer(const QVector<QuestionQuiz>& questions) {
    questionContainer = questions;
}

void mathsquiz::showCurrentQuest(int index) {
    // I might need this function
}
