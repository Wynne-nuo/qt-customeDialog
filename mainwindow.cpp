#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "qwdialogsize.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    itemModel = new QStandardItemModel(this);
    ui->tableView->setModel(itemModel);
    selectModel = new QItemSelectionModel(itemModel);
    ui->tableView->setSelectionModel(selectModel);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::close);
//    m_manager = new manager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCellText(int row, int col, QString text)
{
    qDebug()<<"收到文字"<< text;
    QModelIndex index = itemModel->index(row,col);
    selectModel->clearSelection();
    selectModel->setCurrentIndex(index,QItemSelectionModel::Select);
    itemModel->setData(index, text, Qt::DisplayRole);
}

void MainWindow::setLocateEnable(bool enable)
{
    //定位单元格窗口退出后，将按钮置回可以点击
    ui->pushButton_3->setEnabled(enable);
}

void MainWindow::setDlgLocateNull()
{
    m_locate = NULL; // 将定位单元格的指针指回空，因为此时窗口已经被关闭
}

//点击设置行数列数
void MainWindow::on_pushButton_clicked()
{
    QWDialogSize *size = new QWDialogSize(this);
//    connect(size, SIGNAL(signal_sendRowCol(int,int)), this, SLOT(slot_getRowCol(int,int)));
    size->set_rowClo(itemModel->rowCount(), itemModel->columnCount());
    int ret = size->exec();
    if(ret == QDialog::Accepted){
        int row = size->get_row();
        int col = size->get_col();
        itemModel->setColumnCount(col);
        itemModel->setRowCount(row);
        qDebug()<<"点击确定"<<"row = "<<row<<"col = "<<row;
    }
    delete size;
}

//点击设置表头标题
void MainWindow::on_pushButton_2_clicked()
{
    m_headers = new qwdialogHeaders(this);
    //获取现有标题
    if(m_headers->getHeaderList().count() != itemModel->columnCount()){
        QStringList strlist;
        for(int i=0; i<itemModel->columnCount(); i++){
            strlist.append(itemModel->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
            m_headers->setHeaderList(strlist);
        }
    }
    int ret = m_headers->exec();
    //点击确定按钮，改变标题
    if(ret == QDialog::Accepted){
        QStringList list = m_headers->getHeaderList();
        itemModel->setHorizontalHeaderLabels(list);
    }
}

//点击单元格定位与文字设置
void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setEnabled(false);
    m_locate = new qwdialogLocate(this);
    m_locate->setAttribute(Qt::WA_DeleteOnClose);  //对话框关闭时自动删除组
    Qt::WindowFlags flags = m_locate->windowFlags();
    m_locate->setWindowFlags(flags | Qt::WindowStaysOnTopHint); //置顶

    m_locate->setSpinRange(itemModel->rowCount(), itemModel->columnCount());
    QModelIndex curIndex = selectModel->currentIndex();
    if(curIndex.isValid()){
        m_locate->setSpinCount(curIndex.row(), curIndex.column());
    }
    m_locate->show();
}
