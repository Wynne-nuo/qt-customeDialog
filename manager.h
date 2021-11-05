#ifndef MANAGER_H
#define MANAGER_H
#include <QObject>
#include "qwdialogsize.h"

class manager : public QObject
{
    Q_OBJECT
public:
    manager();
    virtual ~manager(){}

    QWDialogSize *m_size;

signals:
//    void signal_sendRowCol(int, int);
public slots:
//    void slot_getRowCol(int, int);
};


#endif // MANAGER_H
