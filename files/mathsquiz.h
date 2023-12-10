#ifndef MATHSQUIZ_H
#define MATHSQUIZ_H

#include "quiz.h"
#include "QuestionQuiz.h"

class mathsquiz : public Quiz // INHERIT FROM QUIZ
{
public:
    void setQuizName(const QString& subject) override; //Override my pure virtual functions
    void setNumOfQuestions(int num) override;
    void setQuestionContainer(const QVector<QuestionQuiz>& questions) override;
    void showCurrentQuest(int index);
};

#endif // MATHSQUIZ_H
