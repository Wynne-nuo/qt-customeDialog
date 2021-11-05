#ifndef QWDIALOGHEADERS_H
#define QWDIALOGHEADERS_H

#include <QDialog>
#include <QStringListModel>
#include <QStringList>

namespace Ui {
class qwdialogHeaders;
}

class qwdialogHeaders : public QDialog
{
    Q_OBJECT

public:
    explicit qwdialogHeaders(QWidget *parent = nullptr);
    ~qwdialogHeaders();
    QStringListModel *m_listModel;
    QStringList headerList;
    void setHeaderList(QStringList&);
    QStringList getHeaderList();


private:
    Ui::qwdialogHeaders *ui;
};

#endif // QWDIALOGHEADERS_H
