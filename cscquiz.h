#ifndef CSCIQUIZ_H
#define CSCIQUIZ_H

#include "quiz.h"
#include "QuestionQuiz.h"

class CscQuiz : public Quiz {    // INHERITANCE
public:
    void setQuizName(const QString& subject) override;
    void setNumOfQuestions(int num) override;
    void setQuestionContainer(const QVector<QuestionQuiz>& questions) override;
    void showCurrentQuest(int index);
};

#endif // CSCIQUIZ_H
