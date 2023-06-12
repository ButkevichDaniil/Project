/********************************************************************************
** Form generated from reading UI file 'extrafunction.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRAFUNCTION_H
#define UI_EXTRAFUNCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExtraFunction
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *Login;
    QLabel *label_3;
    QLineEdit *Password;

    void setupUi(QDialog *ExtraFunction)
    {
        if (ExtraFunction->objectName().isEmpty())
            ExtraFunction->setObjectName("ExtraFunction");
        ExtraFunction->resize(452, 300);
        gridLayout = new QGridLayout(ExtraFunction);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(ExtraFunction);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(ExtraFunction);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(ExtraFunction);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        Login = new QLineEdit(groupBox);
        Login->setObjectName("Login");

        formLayout->setWidget(0, QFormLayout::FieldRole, Login);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        Password = new QLineEdit(groupBox);
        Password->setObjectName("Password");
        Password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, Password);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        QWidget::setTabOrder(Login, Password);
        QWidget::setTabOrder(Password, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(ExtraFunction);

        QMetaObject::connectSlotsByName(ExtraFunction);
    } // setupUi

    void retranslateUi(QDialog *ExtraFunction)
    {
        ExtraFunction->setWindowTitle(QCoreApplication::translate("ExtraFunction", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ExtraFunction", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ExtraFunction", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ExtraFunction", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("ExtraFunction", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("ExtraFunction", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExtraFunction: public Ui_ExtraFunction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRAFUNCTION_H
