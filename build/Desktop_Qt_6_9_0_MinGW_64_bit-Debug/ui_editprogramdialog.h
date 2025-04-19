/********************************************************************************
** Form generated from reading UI file 'editprogramdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROGRAMDIALOG_H
#define UI_EDITPROGRAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditProgramDialog
{
public:
    QLineEdit *ProgramNameLine;
    QLabel *ProgramName;
    QLineEdit *ProgramCodeLine;
    QLabel *AddProgram;
    QLabel *ProgramCode;
    QLabel *CollegeCode;
    QPushButton *CancelProgram;
    QComboBox *CollegeCodeComboBox;
    QPushButton *UpdateProgram;

    void setupUi(QDialog *EditProgramDialog)
    {
        if (EditProgramDialog->objectName().isEmpty())
            EditProgramDialog->setObjectName("EditProgramDialog");
        EditProgramDialog->resize(243, 256);
        ProgramNameLine = new QLineEdit(EditProgramDialog);
        ProgramNameLine->setObjectName("ProgramNameLine");
        ProgramNameLine->setGeometry(QRect(20, 130, 191, 26));
        ProgramName = new QLabel(EditProgramDialog);
        ProgramName->setObjectName("ProgramName");
        ProgramName->setGeometry(QRect(20, 110, 121, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rockwell")});
        font.setBold(true);
        font.setItalic(false);
        ProgramName->setFont(font);
        ProgramCodeLine = new QLineEdit(EditProgramDialog);
        ProgramCodeLine->setObjectName("ProgramCodeLine");
        ProgramCodeLine->setGeometry(QRect(20, 80, 191, 26));
        AddProgram = new QLabel(EditProgramDialog);
        AddProgram->setObjectName("AddProgram");
        AddProgram->setGeometry(QRect(20, 20, 181, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setPointSize(12);
        font1.setBold(true);
        AddProgram->setFont(font1);
        AddProgram->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"    border: 2px solid #00674F;\n"
"    border-radius: 10px;\n"
"    padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: black;"));
        AddProgram->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ProgramCode = new QLabel(EditProgramDialog);
        ProgramCode->setObjectName("ProgramCode");
        ProgramCode->setGeometry(QRect(20, 60, 111, 20));
        ProgramCode->setFont(font);
        CollegeCode = new QLabel(EditProgramDialog);
        CollegeCode->setObjectName("CollegeCode");
        CollegeCode->setGeometry(QRect(20, 160, 111, 20));
        CollegeCode->setFont(font);
        CancelProgram = new QPushButton(EditProgramDialog);
        CancelProgram->setObjectName("CancelProgram");
        CancelProgram->setGeometry(QRect(20, 220, 91, 21));
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
        CollegeCodeComboBox = new QComboBox(EditProgramDialog);
        CollegeCodeComboBox->setObjectName("CollegeCodeComboBox");
        CollegeCodeComboBox->setGeometry(QRect(20, 180, 131, 26));
        UpdateProgram = new QPushButton(EditProgramDialog);
        UpdateProgram->setObjectName("UpdateProgram");
        UpdateProgram->setGeometry(QRect(120, 220, 91, 21));
        UpdateProgram->setMinimumSize(QSize(91, 20));
        UpdateProgram->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(EditProgramDialog);

        QMetaObject::connectSlotsByName(EditProgramDialog);
    } // setupUi

    void retranslateUi(QDialog *EditProgramDialog)
    {
        EditProgramDialog->setWindowTitle(QCoreApplication::translate("EditProgramDialog", "Dialog", nullptr));
        ProgramName->setText(QCoreApplication::translate("EditProgramDialog", "Program Name", nullptr));
        AddProgram->setText(QCoreApplication::translate("EditProgramDialog", "Program", nullptr));
        ProgramCode->setText(QCoreApplication::translate("EditProgramDialog", "Program Code", nullptr));
        CollegeCode->setText(QCoreApplication::translate("EditProgramDialog", "College Code", nullptr));
        CancelProgram->setText(QCoreApplication::translate("EditProgramDialog", "Cancel", nullptr));
        UpdateProgram->setText(QCoreApplication::translate("EditProgramDialog", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditProgramDialog: public Ui_EditProgramDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROGRAMDIALOG_H
