#include "qwdialoglocate.h"
#include "ui_qwdialoglocate.h"
#include "mainwindow.h"

qwdialogLocate::qwdialogLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qwdialogLocate)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &qwdialogLocate::close);
}

qwdialogLocate::~qwdialogLocate()
{
    delete ui;
}

void qwdialogLocate::setSpinRange(int row, int col)
{
    ui->spinBoxRow->setMaximum(row);
    ui->spinBoxCol->setMaximum(col);
}

void qwdialogLocate::setSpinCount(int row, int col)
{
    ui->spinBoxRow->setValue(row);
    ui->spinBoxCol->setValue(col);
}

//点击设定文字
void qwdialogLocate::on_pushButton_clicked()
{
    int row = ui->spinBoxRow->value();
    int col = ui->spinBoxCol->value();

    MainWindow *parWindow = (MainWindow*)parentWidget(); //获取主窗口
    parWindow->setCellText(row, col, ui->lineEdit->text());

    if(ui->checkBoxRow->isChecked()){
        ui->spinBoxRow->setValue(1 + ui->spinBoxRow->value());
    }
    if(ui->checkBoxCol->isChecked()){
        ui->spinBoxCol->setValue(1 + ui->spinBoxCol->value());
    }
}

void qwdialogLocate::closeEvent(QCloseEvent *e)
{
    MainWindow *parWind = (MainWindow*)parentWidget();
    parWind->setLocateEnable(true);
    parWind->setDlgLocateNull();
}
