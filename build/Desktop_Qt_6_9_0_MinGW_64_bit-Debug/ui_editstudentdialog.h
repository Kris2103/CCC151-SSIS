/********************************************************************************
** Form generated from reading UI file 'editstudentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSTUDENTDIALOG_H
#define UI_EDITSTUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditStudentDialog
{
public:
    QLabel *LastName;
    QLineEdit *Middlenameline;
    QLineEdit *IDline;
    QLabel *FirstName;
    QLabel *Gender;
    QComboBox *Yearlevelline;
    QPushButton *CancelStudent;
    QLabel *MiddleName;
    QComboBox *Genderline;
    QLineEdit *Firstnameline;
    QLabel *IDnumber;
    QPushButton *UpdateStudent;
    QLabel *CourseCode;
    QLineEdit *Lastnameline;
    QLabel *StudentProfile;
    QLabel *YearLevel;
    QComboBox *CourseComboBox;

    void setupUi(QDialog *EditStudentDialog)
    {
        if (EditStudentDialog->objectName().isEmpty())
            EditStudentDialog->setObjectName("EditStudentDialog");
        EditStudentDialog->resize(333, 345);
        LastName = new QLabel(EditStudentDialog);
        LastName->setObjectName("LastName");
        LastName->setGeometry(QRect(20, 160, 181, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setBold(true);
        LastName->setFont(font);
        Middlenameline = new QLineEdit(EditStudentDialog);
        Middlenameline->setObjectName("Middlenameline");
        Middlenameline->setGeometry(QRect(20, 130, 301, 21));
        Middlenameline->setMinimumSize(QSize(301, 21));
        Middlenameline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        IDline = new QLineEdit(EditStudentDialog);
        IDline->setObjectName("IDline");
        IDline->setGeometry(QRect(180, 230, 141, 21));
        IDline->setMinimumSize(QSize(141, 21));
        IDline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        FirstName = new QLabel(EditStudentDialog);
        FirstName->setObjectName("FirstName");
        FirstName->setGeometry(QRect(20, 60, 181, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setBold(true);
        font1.setItalic(false);
        FirstName->setFont(font1);
        Gender = new QLabel(EditStudentDialog);
        Gender->setObjectName("Gender");
        Gender->setGeometry(QRect(20, 210, 141, 20));
        Gender->setFont(font);
        Yearlevelline = new QComboBox(EditStudentDialog);
        Yearlevelline->addItem(QString());
        Yearlevelline->addItem(QString());
        Yearlevelline->addItem(QString());
        Yearlevelline->addItem(QString());
        Yearlevelline->setObjectName("Yearlevelline");
        Yearlevelline->setGeometry(QRect(180, 280, 141, 21));
        Yearlevelline->setMinimumSize(QSize(141, 21));
        Yearlevelline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        CancelStudent = new QPushButton(EditStudentDialog);
        CancelStudent->setObjectName("CancelStudent");
        CancelStudent->setGeometry(QRect(130, 310, 91, 21));
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
        MiddleName = new QLabel(EditStudentDialog);
        MiddleName->setObjectName("MiddleName");
        MiddleName->setGeometry(QRect(20, 110, 181, 20));
        MiddleName->setFont(font1);
        Genderline = new QComboBox(EditStudentDialog);
        Genderline->addItem(QString());
        Genderline->addItem(QString());
        Genderline->setObjectName("Genderline");
        Genderline->setGeometry(QRect(20, 230, 141, 21));
        Genderline->setMinimumSize(QSize(141, 21));
        Genderline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        Firstnameline = new QLineEdit(EditStudentDialog);
        Firstnameline->setObjectName("Firstnameline");
        Firstnameline->setGeometry(QRect(20, 80, 301, 21));
        Firstnameline->setMinimumSize(QSize(301, 21));
        Firstnameline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        IDnumber = new QLabel(EditStudentDialog);
        IDnumber->setObjectName("IDnumber");
        IDnumber->setGeometry(QRect(180, 210, 141, 20));
        IDnumber->setFont(font);
        UpdateStudent = new QPushButton(EditStudentDialog);
        UpdateStudent->setObjectName("UpdateStudent");
        UpdateStudent->setGeometry(QRect(230, 310, 91, 21));
        UpdateStudent->setMinimumSize(QSize(91, 20));
        UpdateStudent->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        CourseCode = new QLabel(EditStudentDialog);
        CourseCode->setObjectName("CourseCode");
        CourseCode->setGeometry(QRect(20, 260, 141, 20));
        CourseCode->setFont(font);
        Lastnameline = new QLineEdit(EditStudentDialog);
        Lastnameline->setObjectName("Lastnameline");
        Lastnameline->setGeometry(QRect(20, 180, 301, 21));
        Lastnameline->setMinimumSize(QSize(301, 21));
        Lastnameline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        StudentProfile = new QLabel(EditStudentDialog);
        StudentProfile->setObjectName("StudentProfile");
        StudentProfile->setGeometry(QRect(20, 20, 301, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rockwell")});
        font2.setPointSize(20);
        font2.setBold(true);
        StudentProfile->setFont(font2);
        StudentProfile->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"    border: 2px solid #00674F;\n"
"    border-radius: 10px;\n"
"    padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: black;"));
        StudentProfile->setAlignment(Qt::AlignmentFlag::AlignCenter);
        YearLevel = new QLabel(EditStudentDialog);
        YearLevel->setObjectName("YearLevel");
        YearLevel->setGeometry(QRect(180, 260, 141, 20));
        YearLevel->setFont(font);
        CourseComboBox = new QComboBox(EditStudentDialog);
        CourseComboBox->setObjectName("CourseComboBox");
        CourseComboBox->setGeometry(QRect(20, 280, 141, 21));
        CourseComboBox->setMinimumSize(QSize(141, 21));
        CourseComboBox->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));

        retranslateUi(EditStudentDialog);

        QMetaObject::connectSlotsByName(EditStudentDialog);
    } // setupUi

    void retranslateUi(QDialog *EditStudentDialog)
    {
        EditStudentDialog->setWindowTitle(QCoreApplication::translate("EditStudentDialog", "Dialog", nullptr));
        LastName->setText(QCoreApplication::translate("EditStudentDialog", "Last Name", nullptr));
        IDline->setPlaceholderText(QCoreApplication::translate("EditStudentDialog", "e.g. 2000-0000", nullptr));
        FirstName->setText(QCoreApplication::translate("EditStudentDialog", "First Name", nullptr));
        Gender->setText(QCoreApplication::translate("EditStudentDialog", "Gender", nullptr));
        Yearlevelline->setItemText(0, QCoreApplication::translate("EditStudentDialog", "1", nullptr));
        Yearlevelline->setItemText(1, QCoreApplication::translate("EditStudentDialog", "2", nullptr));
        Yearlevelline->setItemText(2, QCoreApplication::translate("EditStudentDialog", "3", nullptr));
        Yearlevelline->setItemText(3, QCoreApplication::translate("EditStudentDialog", "4", nullptr));

        CancelStudent->setText(QCoreApplication::translate("EditStudentDialog", "Cancel", nullptr));
        MiddleName->setText(QCoreApplication::translate("EditStudentDialog", "Middle Name", nullptr));
        Genderline->setItemText(0, QCoreApplication::translate("EditStudentDialog", "Female", nullptr));
        Genderline->setItemText(1, QCoreApplication::translate("EditStudentDialog", "Male", nullptr));

        IDnumber->setText(QCoreApplication::translate("EditStudentDialog", "I.D. Number", nullptr));
        UpdateStudent->setText(QCoreApplication::translate("EditStudentDialog", "Update", nullptr));
        CourseCode->setText(QCoreApplication::translate("EditStudentDialog", "Course Code", nullptr));
        StudentProfile->setText(QCoreApplication::translate("EditStudentDialog", "Student Profile", nullptr));
        YearLevel->setText(QCoreApplication::translate("EditStudentDialog", "Year Level", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditStudentDialog: public Ui_EditStudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSTUDENTDIALOG_H
