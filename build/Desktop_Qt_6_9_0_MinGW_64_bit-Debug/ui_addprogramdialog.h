/********************************************************************************
** Form generated from reading UI file 'addprogramdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPROGRAMDIALOG_H
#define UI_ADDPROGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddProgramDialog
{
public:
    QLabel *AddProgram;
    QLabel *CollegeCode;
    QPushButton *AddProgram_2;
    QPushButton *CancelProgram;
    QLineEdit *ProgramCodeLine;
    QLineEdit *ProgramNameLine;
    QLabel *ProgramName;
    QComboBox *CollegeCodeComboBox;
    QLabel *ProgramCode;

    void setupUi(QDialog *AddProgramDialog)
    {
        if (AddProgramDialog->objectName().isEmpty())
            AddProgramDialog->setObjectName("AddProgramDialog");
        AddProgramDialog->resize(227, 245);
        AddProgram = new QLabel(AddProgramDialog);
        AddProgram->setObjectName("AddProgram");
        AddProgram->setGeometry(QRect(20, 10, 181, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setPointSize(12);
        font.setBold(true);
        AddProgram->setFont(font);
        AddProgram->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"    border: 2px solid #00674F;\n"
"    border-radius: 10px;\n"
"    padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: black;"));
        AddProgram->setAlignment(Qt::AlignmentFlag::AlignCenter);
        CollegeCode = new QLabel(AddProgramDialog);
        CollegeCode->setObjectName("CollegeCode");
        CollegeCode->setGeometry(QRect(20, 150, 111, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setBold(true);
        font1.setItalic(false);
        CollegeCode->setFont(font1);
        AddProgram_2 = new QPushButton(AddProgramDialog);
        AddProgram_2->setObjectName("AddProgram_2");
        AddProgram_2->setGeometry(QRect(120, 210, 91, 21));
        AddProgram_2->setMinimumSize(QSize(91, 20));
        AddProgram_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        CancelProgram = new QPushButton(AddProgramDialog);
        CancelProgram->setObjectName("CancelProgram");
        CancelProgram->setGeometry(QRect(20, 210, 91, 21));
        CancelProgram->setMinimumSize(QSize(91, 20));
        CancelProgram->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        ProgramCodeLine = new QLineEdit(AddProgramDialog);
        ProgramCodeLine->setObjectName("ProgramCodeLine");
        ProgramCodeLine->setGeometry(QRect(20, 70, 191, 26));
        ProgramNameLine = new QLineEdit(AddProgramDialog);
        ProgramNameLine->setObjectName("ProgramNameLine");
        ProgramNameLine->setGeometry(QRect(20, 120, 191, 26));
        ProgramName = new QLabel(AddProgramDialog);
        ProgramName->setObjectName("ProgramName");
        ProgramName->setGeometry(QRect(20, 100, 121, 20));
        ProgramName->setFont(font1);
        CollegeCodeComboBox = new QComboBox(AddProgramDialog);
        CollegeCodeComboBox->setObjectName("CollegeCodeComboBox");
        CollegeCodeComboBox->setGeometry(QRect(20, 170, 131, 26));
        ProgramCode = new QLabel(AddProgramDialog);
        ProgramCode->setObjectName("ProgramCode");
        ProgramCode->setGeometry(QRect(20, 50, 111, 20));
        ProgramCode->setFont(font1);

        retranslateUi(AddProgramDialog);

        QMetaObject::connectSlotsByName(AddProgramDialog);
    } // setupUi

    void retranslateUi(QDialog *AddProgramDialog)
    {
        AddProgramDialog->setWindowTitle(QCoreApplication::translate("AddProgramDialog", "Dialog", nullptr));
        AddProgram->setText(QCoreApplication::translate("AddProgramDialog", "Program", nullptr));
        CollegeCode->setText(QCoreApplication::translate("AddProgramDialog", "College Code", nullptr));
        AddProgram_2->setText(QCoreApplication::translate("AddProgramDialog", "Add", nullptr));
        CancelProgram->setText(QCoreApplication::translate("AddProgramDialog", "Cancel", nullptr));
        ProgramName->setText(QCoreApplication::translate("AddProgramDialog", "Program Name", nullptr));
        ProgramCode->setText(QCoreApplication::translate("AddProgramDialog", "Program Code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddProgramDialog: public Ui_AddProgramDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPROGRAMDIALOG_H
