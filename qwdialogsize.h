#ifndef QWDIALOGSIZE_H
#define QWDIALOGSIZE_H

#include <QDialog>

namespace Ui {
class QWDialogSize;
}

class QWDialogSize : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogSize(QWidget *parent = nullptr);
    ~QWDialogSize();

    int get_row();
    int get_col();
    void set_rowClo(int, int);
    int m_row;
    int m_col;

private slots:
    void on_pushButton_clicked(){}

    int on_ok_butt_clicked();
    void on_pushButton_2_clicked();

signals:
    void signal_sendRowCol(int, int);
private:
    Ui::QWDialogSize *ui;
};

#endif // QWDIALOGSIZE_H
