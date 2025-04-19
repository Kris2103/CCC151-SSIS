/********************************************************************************
** Form generated from reading UI file 'editcollegedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCOLLEGEDIALOG_H
#define UI_EDITCOLLEGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditCollegeDialog
{
public:
    QLabel *AddCollege;
    QLineEdit *CollegeCodeLine;
    QLabel *FirstName_5;
    QLabel *FirstName_6;
    QPushButton *CancelCollege;
    QPushButton *UpdateCollege;
    QLineEdit *CollegeNameLine;

    void setupUi(QDialog *EditCollegeDialog)
    {
        if (EditCollegeDialog->objectName().isEmpty())
            EditCollegeDialog->setObjectName("EditCollegeDialog");
        EditCollegeDialog->resize(225, 208);
        AddCollege = new QLabel(EditCollegeDialog);
        AddCollege->setObjectName("AddCollege");
        AddCollege->setGeometry(QRect(20, 20, 181, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setPointSize(12);
        font.setBold(true);
        AddCollege->setFont(font);
        AddCollege->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"    border: 2px solid #00674F;\n"
"    border-radius: 10px;\n"
"    padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: black;"));
        AddCollege->setAlignment(Qt::AlignmentFlag::AlignCenter);
        CollegeCodeLine = new QLineEdit(EditCollegeDialog);
        CollegeCodeLine->setObjectName("CollegeCodeLine");
        CollegeCodeLine->setGeometry(QRect(20, 80, 181, 26));
        FirstName_5 = new QLabel(EditCollegeDialog);
        FirstName_5->setObjectName("FirstName_5");
        FirstName_5->setGeometry(QRect(20, 60, 111, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setBold(true);
        font1.setItalic(false);
        FirstName_5->setFont(font1);
        FirstName_6 = new QLabel(EditCollegeDialog);
        FirstName_6->setObjectName("FirstName_6");
        FirstName_6->setGeometry(QRect(20, 110, 111, 20));
        FirstName_6->setFont(font1);
        CancelCollege = new QPushButton(EditCollegeDialog);
        CancelCollege->setObjectName("CancelCollege");
        CancelCollege->setGeometry(QRect(20, 170, 91, 21));
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
        UpdateCollege = new QPushButton(EditCollegeDialog);
        UpdateCollege->setObjectName("UpdateCollege");
        UpdateCollege->setGeometry(QRect(120, 170, 91, 21));
        UpdateCollege->setMinimumSize(QSize(91, 20));
        UpdateCollege->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        CollegeNameLine = new QLineEdit(EditCollegeDialog);
        CollegeNameLine->setObjectName("CollegeNameLine");
        CollegeNameLine->setGeometry(QRect(20, 130, 181, 26));

        retranslateUi(EditCollegeDialog);

        QMetaObject::connectSlotsByName(EditCollegeDialog);
    } // setupUi

    void retranslateUi(QDialog *EditCollegeDialog)
    {
        EditCollegeDialog->setWindowTitle(QCoreApplication::translate("EditCollegeDialog", "Dialog", nullptr));
        AddCollege->setText(QCoreApplication::translate("EditCollegeDialog", "College", nullptr));
        FirstName_5->setText(QCoreApplication::translate("EditCollegeDialog", "College Code", nullptr));
        FirstName_6->setText(QCoreApplication::translate("EditCollegeDialog", "College Name", nullptr));
        CancelCollege->setText(QCoreApplication::translate("EditCollegeDialog", "Cancel", nullptr));
        UpdateCollege->setText(QCoreApplication::translate("EditCollegeDialog", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditCollegeDialog: public Ui_EditCollegeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCOLLEGEDIALOG_H
