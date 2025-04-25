/********************************************************************************
** Form generated from reading UI file 'addstudentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENTDIALOG_H
#define UI_ADDSTUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddStudentDialog
{
public:
    QLabel *IDnumber;
    QLabel *StudentProfile;
    QLabel *MiddleName;
    QPushButton *CancelStudent;
    QLabel *YearLevel;
    QLabel *LastName;
    QLineEdit *Middlenameline;
    QPushButton *AddStudent;
    QComboBox *Yearlevelline;
    QLineEdit *IDline;
    QLabel *Gender;
    QLabel *FirstName;
    QLabel *CourseCode;
    QComboBox *Genderline;
    QLineEdit *Firstnameline;
    QLineEdit *Lastnameline;
    QComboBox *CourseComboBox;

    void setupUi(QDialog *AddStudentDialog)
    {
        if (AddStudentDialog->objectName().isEmpty())
            AddStudentDialog->setObjectName("AddStudentDialog");
        AddStudentDialog->resize(359, 343);
        IDnumber = new QLabel(AddStudentDialog);
        IDnumber->setObjectName("IDnumber");
        IDnumber->setGeometry(QRect(190, 210, 141, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setBold(true);
        IDnumber->setFont(font);
        StudentProfile = new QLabel(AddStudentDialog);
        StudentProfile->setObjectName("StudentProfile");
        StudentProfile->setGeometry(QRect(30, 20, 301, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setPointSize(20);
        font1.setBold(true);
        StudentProfile->setFont(font1);
        StudentProfile->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"    border: 2px solid #00674F;\n"
"    border-radius: 10px;\n"
"    padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: black;"));
        StudentProfile->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MiddleName = new QLabel(AddStudentDialog);
        MiddleName->setObjectName("MiddleName");
        MiddleName->setGeometry(QRect(30, 110, 181, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rockwell")});
        font2.setBold(true);
        font2.setItalic(false);
        MiddleName->setFont(font2);
        CancelStudent = new QPushButton(AddStudentDialog);
        CancelStudent->setObjectName("CancelStudent");
        CancelStudent->setGeometry(QRect(140, 310, 91, 21));
        CancelStudent->setMinimumSize(QSize(91, 20));
        CancelStudent->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        YearLevel = new QLabel(AddStudentDialog);
        YearLevel->setObjectName("YearLevel");
        YearLevel->setGeometry(QRect(190, 260, 141, 20));
        YearLevel->setFont(font);
        LastName = new QLabel(AddStudentDialog);
        LastName->setObjectName("LastName");
        LastName->setGeometry(QRect(30, 160, 181, 20));
        LastName->setFont(font);
        Middlenameline = new QLineEdit(AddStudentDialog);
        Middlenameline->setObjectName("Middlenameline");
        Middlenameline->setGeometry(QRect(30, 130, 301, 21));
        Middlenameline->setMinimumSize(QSize(301, 21));
        Middlenameline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        AddStudent = new QPushButton(AddStudentDialog);
        AddStudent->setObjectName("AddStudent");
        AddStudent->setGeometry(QRect(240, 310, 91, 21));
        AddStudent->setMinimumSize(QSize(91, 20));
        AddStudent->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Yearlevelline = new QComboBox(AddStudentDialog);
        Yearlevelline->addItem(QString());
        Yearlevelline->addItem(QString());
        Yearlevelline->addItem(QString());
        Yearlevelline->addItem(QString());
        Yearlevelline->setObjectName("Yearlevelline");
        Yearlevelline->setGeometry(QRect(190, 280, 141, 21));
        Yearlevelline->setMinimumSize(QSize(141, 21));
        Yearlevelline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        IDline = new QLineEdit(AddStudentDialog);
        IDline->setObjectName("IDline");
        IDline->setGeometry(QRect(190, 230, 141, 21));
        IDline->setMinimumSize(QSize(141, 21));
        IDline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        Gender = new QLabel(AddStudentDialog);
        Gender->setObjectName("Gender");
        Gender->setGeometry(QRect(30, 210, 141, 20));
        Gender->setFont(font);
        FirstName = new QLabel(AddStudentDialog);
        FirstName->setObjectName("FirstName");
        FirstName->setGeometry(QRect(30, 60, 181, 20));
        FirstName->setFont(font2);
        CourseCode = new QLabel(AddStudentDialog);
        CourseCode->setObjectName("CourseCode");
        CourseCode->setGeometry(QRect(30, 260, 141, 20));
        CourseCode->setFont(font);
        Genderline = new QComboBox(AddStudentDialog);
        Genderline->addItem(QString());
        Genderline->addItem(QString());
        Genderline->setObjectName("Genderline");
        Genderline->setGeometry(QRect(30, 230, 141, 21));
        Genderline->setMinimumSize(QSize(141, 21));
        Genderline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        Firstnameline = new QLineEdit(AddStudentDialog);
        Firstnameline->setObjectName("Firstnameline");
        Firstnameline->setGeometry(QRect(30, 80, 301, 21));
        Firstnameline->setMinimumSize(QSize(301, 21));
        Firstnameline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        Lastnameline = new QLineEdit(AddStudentDialog);
        Lastnameline->setObjectName("Lastnameline");
        Lastnameline->setGeometry(QRect(30, 180, 301, 21));
        Lastnameline->setMinimumSize(QSize(301, 21));
        Lastnameline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        CourseComboBox = new QComboBox(AddStudentDialog);
        CourseComboBox->setObjectName("CourseComboBox");
        CourseComboBox->setGeometry(QRect(30, 280, 141, 21));
        CourseComboBox->setMinimumSize(QSize(141, 21));
        CourseComboBox->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));

        retranslateUi(AddStudentDialog);

        QMetaObject::connectSlotsByName(AddStudentDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStudentDialog)
    {
        AddStudentDialog->setWindowTitle(QCoreApplication::translate("AddStudentDialog", "Dialog", nullptr));
        IDnumber->setText(QCoreApplication::translate("AddStudentDialog", "I.D. Number", nullptr));
        StudentProfile->setText(QCoreApplication::translate("AddStudentDialog", "Student Profile", nullptr));
        MiddleName->setText(QCoreApplication::translate("AddStudentDialog", "Middle Name", nullptr));
        CancelStudent->setText(QCoreApplication::translate("AddStudentDialog", "Cancel", nullptr));
        YearLevel->setText(QCoreApplication::translate("AddStudentDialog", "Year Level", nullptr));
        LastName->setText(QCoreApplication::translate("AddStudentDialog", "Last Name", nullptr));
        AddStudent->setText(QCoreApplication::translate("AddStudentDialog", "Add", nullptr));
        Yearlevelline->setItemText(0, QCoreApplication::translate("AddStudentDialog", "1", nullptr));
        Yearlevelline->setItemText(1, QCoreApplication::translate("AddStudentDialog", "2", nullptr));
        Yearlevelline->setItemText(2, QCoreApplication::translate("AddStudentDialog", "3", nullptr));
        Yearlevelline->setItemText(3, QCoreApplication::translate("AddStudentDialog", "4", nullptr));

        IDline->setPlaceholderText(QCoreApplication::translate("AddStudentDialog", "e.g. 2000-0000", nullptr));
        Gender->setText(QCoreApplication::translate("AddStudentDialog", "Gender", nullptr));
        FirstName->setText(QCoreApplication::translate("AddStudentDialog", "First Name", nullptr));
        CourseCode->setText(QCoreApplication::translate("AddStudentDialog", "Course Code", nullptr));
        Genderline->setItemText(0, QCoreApplication::translate("AddStudentDialog", "Female", nullptr));
        Genderline->setItemText(1, QCoreApplication::translate("AddStudentDialog", "Male", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AddStudentDialog: public Ui_AddStudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENTDIALOG_H
