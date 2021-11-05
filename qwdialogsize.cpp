#include "qwdialogsize.h"
#include "ui_qwdialogsize.h"
#include <QDebug>

QWDialogSize::QWDialogSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogSize)
{
    ui->setupUi(this);
    connect(ui->ok_butt, &QPushButton::clicked, this, &QWDialogSize::accept);
}

QWDialogSize::~QWDialogSize()
{
    qDebug()<<"QWDialogSize被删除";
    delete ui;
}

int QWDialogSize::get_row()
{
    qDebug()<<"row = "<<ui->rowSpinBox->value();
    return ui->rowSpinBox->value();
}

int QWDialogSize::get_col()
{
    qDebug()<<"col = "<<ui->colSpinBox->value();
    return ui->colSpinBox->value();
}

void QWDialogSize::set_rowClo(int row, int col)
{
    qDebug()<<"set行列值 "<< row << col;
    ui->rowSpinBox->setValue(row);
    ui->colSpinBox->setValue(col);
}

//void QWDialogSize::on_pushButton_clicked()
//{

//}

int QWDialogSize::on_ok_butt_clicked()
{
//    //获取输入的行列值
//    m_row = ui->rowSpinBox->value();
//    m_col = ui->colSpinBox->value();
//    qDebug()<<"输入行值"<<m_row<<m_col;
//    emit signal_sendRowCol(m_row, m_col);
//    return QDialog::Accepted; //不生效
}

void QWDialogSize::on_pushButton_2_clicked()
{
    this->close();
//    delete this;
}
