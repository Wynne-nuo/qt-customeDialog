#ifndef QWDIALOGLOCATE_H
#define QWDIALOGLOCATE_H

#include <QDialog>

namespace Ui {
class qwdialogLocate;
}

class qwdialogLocate : public QDialog
{
    Q_OBJECT

public:
    explicit qwdialogLocate(QWidget *parent = nullptr);
    ~qwdialogLocate();

    void setSpinRange(int, int);
    void setSpinCount(int, int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::qwdialogLocate *ui;
    void closeEvent(QCloseEvent *e);
};

#endif // QWDIALOGLOCATE_H
