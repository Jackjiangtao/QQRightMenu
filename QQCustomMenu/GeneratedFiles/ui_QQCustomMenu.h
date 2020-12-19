/********************************************************************************
** Form generated from reading UI file 'QQCustomMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQCUSTOMMENU_H
#define UI_QQCUSTOMMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QQCustomMenuClass
{
public:

    void setupUi(QWidget *QQCustomMenuClass)
    {
        if (QQCustomMenuClass->objectName().isEmpty())
            QQCustomMenuClass->setObjectName(QString::fromUtf8("QQCustomMenuClass"));
        QQCustomMenuClass->resize(600, 400);

        retranslateUi(QQCustomMenuClass);

        QMetaObject::connectSlotsByName(QQCustomMenuClass);
    } // setupUi

    void retranslateUi(QWidget *QQCustomMenuClass)
    {
        QQCustomMenuClass->setWindowTitle(QCoreApplication::translate("QQCustomMenuClass", "QQCustomMenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QQCustomMenuClass: public Ui_QQCustomMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQCUSTOMMENU_H
