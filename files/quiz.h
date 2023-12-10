/* Quiz class is an abstract class. It will be the base class for the different subject
I have in my quiz which are Computer Science, Maths and Physics.
Those classes willl have to override the pure virtual functions*/

#ifndef QUIZ_H
#define QUIZ_H

#include <QString>
#include <QVector>
#include "QuestionQuiz.h"

class Quiz {  // Abstract base class for my differents quiz classes (csc/maths/phy)
public://protected:
    QString name;
    int numOfQuestions;
    QVector<QuestionQuiz> questionContainer;

//public:
    Quiz();
    Quiz(const QString& quizName);
    virtual void setQuizName(const QString& name) = 0;   // Pure virtual function
    virtual void setNumOfQuestions(int num) = 0;        // Pure virtual function
    virtual void setQuestionContainer(const QVector<QuestionQuiz>& questions) = 0;  // Pure virtual function
};

#endif // QUIZ_H
