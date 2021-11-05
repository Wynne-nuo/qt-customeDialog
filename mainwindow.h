#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <manager.h>
#include "qwdialogsize.h"
#include "qwdialogheaders.h"
#include "qwdialoglocate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStandardItemModel *itemModel;
    QItemSelectionModel *selectModel;
//    manager *m_manager;
    void setCellText(int, int, QString);
    void setLocateEnable(bool);
    void setDlgLocateNull();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

    qwdialogHeaders *m_headers = NULL;
    qwdialogLocate *m_locate = NULL;

};
#endif // MAINWINDOW_H
