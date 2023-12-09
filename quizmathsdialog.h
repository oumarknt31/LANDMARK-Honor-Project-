#ifndef QUIZMATHSDIALOG_H
#define QUIZMATHSDIALOG_H

#include <QDialog>

namespace Ui {
class quizmathsDialog;
}

class quizmathsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit quizmathsDialog(QWidget *parent = nullptr);
    ~quizmathsDialog();

private:
    Ui::quizmathsDialog *ui;
};

#endif // QUIZMATHSDIALOG_H
