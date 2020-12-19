#include "qcustomsystemtrayicon.h"
#include"QQCustomMenu.h"
#include<QAction>
#include<QMenu>
#include<QWidgetAction>
#include<QAction>
#include<QDebug>
#include<QSystemTrayIcon>

QCustomSystemTrayIcon::QCustomSystemTrayIcon(QObject *parent):QSystemTrayIcon(parent)
{
    m_widget =new QQCustomMenu;

    initWidget();

    initActions();

    initConnect();

    m_trayMenu= new QMenu();
}

void QCustomSystemTrayIcon::initActions()
{
    this->setToolTip(tr("Computer Manager"));
    this->setIcon(QIcon(":/Resources/lock.png"));
    m_trayMenu = new QMenu();

    this->setContextMenu(m_trayMenu);
}

void QCustomSystemTrayIcon::initConnect()
{
    connect(m_Action,&QAction::triggered,this,&QCustomSystemTrayIcon::OpenFileAction);
}

void QCustomSystemTrayIcon::initWidget()
{
    m_Action = new QWidgetAction(m_trayMenu);

    m_widget->addMenuItem(QIcon(":/Resources/busy.png"), "忙碌");



    m_Action->setDefaultWidget(m_widget);
}

void QCustomSystemTrayIcon::OpenFileAction()
{
    qDebug()<<"sdsdsds";
}

