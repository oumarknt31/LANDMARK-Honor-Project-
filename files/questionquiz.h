/* QuestionQuiz is a class that I will use in my Quiz class (aggregation) for a better implementation and comprehension*/


#ifndef QUESTIONQUIZ_H
#define QUESTIONQUIZ_H


#include <QString>
#include <QVector>

class QuestionQuiz {
public:
    QString questionText;  // This variable will store the question
    QVector<QString> options;  // This Qvector array will store the different options
    int correctOption;         // This int variable will store the index of the correct option

    // Constructors
    QuestionQuiz();
    QuestionQuiz(const QString& question, const QVector<QString>& options, int correct);
};

#endif // QUESTIONQUIZ_H
