#include "questionquiz.h"

QuestionQuiz::QuestionQuiz() {}

QuestionQuiz::QuestionQuiz(const QString& question, const QVector<QString>& options, int correct) {
    questionText = question;
    this->options = options;
    correctOption = correct;
}
