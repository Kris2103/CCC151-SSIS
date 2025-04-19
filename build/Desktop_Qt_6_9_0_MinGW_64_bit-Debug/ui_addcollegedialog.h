/********************************************************************************
** Form generated from reading UI file 'addcollegedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOLLEGEDIALOG_H
#define UI_ADDCOLLEGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddCollegeDialog
{
public:
    QPushButton *AddCollege_2;
    QLabel *FirstName_5;
    QLabel *FirstName_6;
    QLineEdit *CollegeNameLine;
    QPushButton *CancelCollege;
    QLineEdit *CollegeCodeLine;
    QLabel *AddCollege;

    void setupUi(QDialog *AddCollegeDialog)
    {
        if (AddCollegeDialog->objectName().isEmpty())
            AddCollegeDialog->setObjectName("AddCollegeDialog");
        AddCollegeDialog->resize(241, 243);
        AddCollege_2 = new QPushButton(AddCollegeDialog);
        AddCollege_2->setObjectName("AddCollege_2");
        AddCollege_2->setGeometry(QRect(130, 170, 91, 21));
        AddCollege_2->setMinimumSize(QSize(91, 20));
        AddCollege_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00674F;\n"
"    color: white;\n"
"    border: 2px solid #000000;\n"
"    border-radius: 5px;\n"
"     padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: white; \n"
"}\n"
"\n"
"/ Hover effect for the button */\n"
"QPushButton:hover {\n"
"    background-color: #944E63;\n"
"    border: 2px solid #944E63;\n"
"}"));
        FirstName_5 = new QLabel(AddCollegeDialog);
        FirstName_5->setObjectName("FirstName_5");
        FirstName_5->setGeometry(QRect(30, 60, 111, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setBold(true);
        font.setItalic(false);
        FirstName_5->setFont(font);
        FirstName_6 = new QLabel(AddCollegeDialog);
        FirstName_6->setObjectName("FirstName_6");
        FirstName_6->setGeometry(QRect(30, 110, 111, 20));
        FirstName_6->setFont(font);
        CollegeNameLine = new QLineEdit(AddCollegeDialog);
        CollegeNameLine->setObjectName("CollegeNameLine");
        CollegeNameLine->setGeometry(QRect(30, 130, 181, 26));
        CancelCollege = new QPushButton(AddCollegeDialog);
        CancelCollege->setObjectName("CancelCollege");
        CancelCollege->setGeometry(QRect(30, 170, 91, 21));
        CancelCollege->setMinimumSize(QSize(91, 20));
        CancelCollege->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00674F;\n"
"    color: white;\n"
"    border: 2px solid #000000;\n"
"    border-radius: 5px;\n"
"     padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: white; \n"
"}\n"
"\n"
"/ Hover effect for the button */\n"
"QPushButton:hover {\n"
"    background-color: #944E63;\n"
"    border: 2px solid #944E63;\n"
"}"));
        CollegeCodeLine = new QLineEdit(AddCollegeDialog);
        CollegeCodeLine->setObjectName("CollegeCodeLine");
        CollegeCodeLine->setGeometry(QRect(30, 80, 181, 26));
        AddCollege = new QLabel(AddCollegeDialog);
        AddCollege->setObjectName("AddCollege");
        AddCollege->setGeometry(QRect(30, 20, 181, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setPointSize(12);
        font1.setBold(true);
        AddCollege->setFont(font1);
        AddCollege->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"    border: 2px solid #00674F;\n"
"    border-radius: 10px;\n"
"    padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: black;"));
        AddCollege->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(AddCollegeDialog);

        QMetaObject::connectSlotsByName(AddCollegeDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCollegeDialog)
    {
        AddCollegeDialog->setWindowTitle(QCoreApplication::translate("AddCollegeDialog", "Dialog", nullptr));
        AddCollege_2->setText(QCoreApplication::translate("AddCollegeDialog", "Add", nullptr));
        FirstName_5->setText(QCoreApplication::translate("AddCollegeDialog", "College Code", nullptr));
        FirstName_6->setText(QCoreApplication::translate("AddCollegeDialog", "College Name", nullptr));
        CancelCollege->setText(QCoreApplication::translate("AddCollegeDialog", "Cancel", nullptr));
        AddCollege->setText(QCoreApplication::translate("AddCollegeDialog", "College", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCollegeDialog: public Ui_AddCollegeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOLLEGEDIALOG_H
