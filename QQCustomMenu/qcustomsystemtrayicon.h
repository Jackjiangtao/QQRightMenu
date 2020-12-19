#ifndef QCUSTOMSYSTEMTRAYICON_H
#define QCUSTOMSYSTEMTRAYICON_H

#include<QSystemTrayIcon>

class QQCustomMenu ;
class QAction;
class QMenu;
class QWidgetAction;
class QCustomSystemTrayIcon : public QSystemTrayIcon
{
public:
    QCustomSystemTrayIcon(QObject *parent = nullptr);

    void initActions();

    void initConnect(); //初始化信号和槽的连接


    void initWidget();

 public slots:;
    void OpenFileAction();
private:
    QWidgetAction * m_Action;
    QQCustomMenu * m_widget;

    QMenu *m_trayMenu;
};

#endif // QCUSTOMSYSTEMTRAYICON_H
