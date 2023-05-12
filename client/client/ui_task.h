/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QComboBox *comboBoxCategories;
    QPushButton *pushButtonGetTask;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTask;
    QLabel *label_Variant;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEditAnswer;

    void setupUi(QDialog *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName("Task");
        Task->resize(400, 300);
        comboBoxCategories = new QComboBox(Task);
        comboBoxCategories->setObjectName("comboBoxCategories");
        comboBoxCategories->setGeometry(QRect(20, 10, 181, 23));
        pushButtonGetTask = new QPushButton(Task);
        pushButtonGetTask->setObjectName("pushButtonGetTask");
        pushButtonGetTask->setGeometry(QRect(230, 10, 131, 22));
        layoutWidget = new QWidget(Task);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 50, 361, 231));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelTask = new QLabel(layoutWidget);
        labelTask->setObjectName("labelTask");

        verticalLayout->addWidget(labelTask);

        label_Variant = new QLabel(layoutWidget);
        label_Variant->setObjectName("label_Variant");

        verticalLayout->addWidget(label_Variant);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        lineEditAnswer = new QLineEdit(layoutWidget);
        lineEditAnswer->setObjectName("lineEditAnswer");

        horizontalLayout->addWidget(lineEditAnswer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Task);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Task, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Task, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QDialog *Task)
    {
        Task->setWindowTitle(QCoreApplication::translate("Task", "Dialog", nullptr));
        pushButtonGetTask->setText(QCoreApplication::translate("Task", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\320\275\320\270\320\265", nullptr));
        labelTask->setText(QString());
        label_Variant->setText(QString());
        label->setText(QCoreApplication::translate("Task", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
