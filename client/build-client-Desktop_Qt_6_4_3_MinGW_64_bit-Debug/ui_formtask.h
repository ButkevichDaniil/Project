/********************************************************************************
** Form generated from reading UI file 'formtask.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTASK_H
#define UI_FORMTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormTask
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *FormTask)
    {
        if (FormTask->objectName().isEmpty())
            FormTask->setObjectName("FormTask");
        FormTask->resize(400, 300);
        label = new QLabel(FormTask);
        label->setObjectName("label");
        label->setGeometry(QRect(22, 19, 361, 171));
        label_2 = new QLabel(FormTask);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 210, 63, 20));
        lineEdit = new QLineEdit(FormTask);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 240, 113, 25));
        pushButton = new QPushButton(FormTask);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 240, 93, 29));
        pushButton_2 = new QPushButton(FormTask);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 180, 93, 29));

        retranslateUi(FormTask);

        QMetaObject::connectSlotsByName(FormTask);
    } // setupUi

    void retranslateUi(QWidget *FormTask)
    {
        FormTask->setWindowTitle(QCoreApplication::translate("FormTask", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormTask", "text for task", nullptr));
        label_2->setText(QCoreApplication::translate("FormTask", "variant", nullptr));
        lineEdit->setText(QCoreApplication::translate("FormTask", "answer", nullptr));
        pushButton->setText(QCoreApplication::translate("FormTask", "send", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FormTask", "canc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTask: public Ui_FormTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTASK_H
