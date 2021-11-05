#include "qwdialogheaders.h"
#include "ui_qwdialogheaders.h"
#include <QDebug>

qwdialogHeaders::qwdialogHeaders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qwdialogHeaders)
{
    ui->setupUi(this);
    m_listModel = new QStringListModel();
    ui->listView->setModel(m_listModel);
    connect(ui->ok_pushButton, &QPushButton::clicked, this, &qwdialogHeaders::accept);
    connect(ui->cancle_pushButton, &QPushButton::clicked, this, &qwdialogHeaders::close);
}

qwdialogHeaders::~qwdialogHeaders()
{
    qDebug()<<"删除headersDialog";
    delete ui;
}

void qwdialogHeaders::setHeaderList(QStringList& headers)
{
    m_listModel->setStringList(headers);
}

QStringList qwdialogHeaders::getHeaderList()
{
    return m_listModel->stringList();
}
