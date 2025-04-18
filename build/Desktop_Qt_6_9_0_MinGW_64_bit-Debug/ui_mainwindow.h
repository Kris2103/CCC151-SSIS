/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *EditProg;
    QComboBox *Genderline;
    QPushButton *AddProgram_2;
    QLabel *AddCollege;
    QLineEdit *CollegeNameLine;
    QLineEdit *ProgramName_2;
    QLabel *ProgramName;
    QLineEdit *Lastnameline;
    QLabel *AddProgram;
    QLabel *Gender;
    QPushButton *SaveStudent;
    QLabel *FirstName;
    QPushButton *EditCollege;
    QPushButton *AddCollege_2;
    QLabel *ProgramCode;
    QFrame *frame;
    QLineEdit *SearchLine;
    QPushButton *Search;
    QTabWidget *TabTable;
    QWidget *tab;
    QTableView *StudentTable;
    QWidget *tab_3;
    QTableView *ProgTable;
    QWidget *tab_2;
    QTableView *CollegeTable;
    QPushButton *DeleteButton;
    QComboBox *Searchby;
    QLabel *FirstName_5;
    QPushButton *AddStudent;
    QComboBox *Yearlevelline;
    QLabel *CollegeCode;
    QLineEdit *Firstnameline;
    QLineEdit *Middlenameline;
    QLabel *StudentProfile;
    QLineEdit *IDline;
    QLabel *MiddleName;
    QPushButton *SaveCollege;
    QLabel *CourseCode;
    QPushButton *EditStudent;
    QLineEdit *ProgramCode_2;
    QComboBox *CourseComboBox;
    QPushButton *SaveProg;
    QLabel *FirstName_6;
    QComboBox *CollegeCodeCombbox;
    QLabel *YearLevel;
    QLabel *LastName;
    QLineEdit *CollegeCodeLine;
    QLabel *IDnumber;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1219, 710);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        EditProg = new QPushButton(centralwidget);
        EditProg->setObjectName("EditProg");
        EditProg->setGeometry(QRect(30, 600, 91, 21));
        EditProg->setMinimumSize(QSize(91, 20));
        EditProg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Genderline = new QComboBox(centralwidget);
        Genderline->addItem(QString());
        Genderline->addItem(QString());
        Genderline->setObjectName("Genderline");
        Genderline->setGeometry(QRect(80, 260, 141, 21));
        Genderline->setMinimumSize(QSize(141, 21));
        Genderline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        AddProgram_2 = new QPushButton(centralwidget);
        AddProgram_2->setObjectName("AddProgram_2");
        AddProgram_2->setGeometry(QRect(130, 600, 91, 21));
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
        AddCollege = new QLabel(centralwidget);
        AddCollege->setObjectName("AddCollege");
        AddCollege->setGeometry(QRect(240, 400, 181, 31));
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
        CollegeNameLine = new QLineEdit(centralwidget);
        CollegeNameLine->setObjectName("CollegeNameLine");
        CollegeNameLine->setGeometry(QRect(240, 510, 181, 26));
        ProgramName_2 = new QLineEdit(centralwidget);
        ProgramName_2->setObjectName("ProgramName_2");
        ProgramName_2->setGeometry(QRect(30, 510, 191, 26));
        ProgramName = new QLabel(centralwidget);
        ProgramName->setObjectName("ProgramName");
        ProgramName->setGeometry(QRect(30, 490, 121, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        font1.setBold(true);
        font1.setItalic(false);
        ProgramName->setFont(font1);
        Lastnameline = new QLineEdit(centralwidget);
        Lastnameline->setObjectName("Lastnameline");
        Lastnameline->setGeometry(QRect(80, 210, 301, 21));
        Lastnameline->setMinimumSize(QSize(301, 21));
        Lastnameline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        AddProgram = new QLabel(centralwidget);
        AddProgram->setObjectName("AddProgram");
        AddProgram->setGeometry(QRect(30, 400, 181, 31));
        AddProgram->setFont(font);
        AddProgram->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"    border: 2px solid #00674F;\n"
"    border-radius: 10px;\n"
"    padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: black;"));
        AddProgram->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Gender = new QLabel(centralwidget);
        Gender->setObjectName("Gender");
        Gender->setGeometry(QRect(80, 240, 141, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rockwell")});
        font2.setBold(true);
        Gender->setFont(font2);
        SaveStudent = new QPushButton(centralwidget);
        SaveStudent->setObjectName("SaveStudent");
        SaveStudent->setGeometry(QRect(110, 370, 91, 21));
        SaveStudent->setStyleSheet(QString::fromUtf8("\n"
"QPushButton:hover {\n"
"    background-color: #808080;\n"
"    border: 2px solid #2980b9;\n"
"}"));
        FirstName = new QLabel(centralwidget);
        FirstName->setObjectName("FirstName");
        FirstName->setGeometry(QRect(80, 90, 181, 20));
        FirstName->setFont(font1);
        EditCollege = new QPushButton(centralwidget);
        EditCollege->setObjectName("EditCollege");
        EditCollege->setGeometry(QRect(240, 550, 91, 21));
        EditCollege->setMinimumSize(QSize(91, 20));
        EditCollege->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        AddCollege_2 = new QPushButton(centralwidget);
        AddCollege_2->setObjectName("AddCollege_2");
        AddCollege_2->setGeometry(QRect(340, 550, 91, 21));
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
        ProgramCode = new QLabel(centralwidget);
        ProgramCode->setObjectName("ProgramCode");
        ProgramCode->setGeometry(QRect(30, 440, 111, 20));
        ProgramCode->setFont(font1);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(430, 40, 771, 621));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        SearchLine = new QLineEdit(frame);
        SearchLine->setObjectName("SearchLine");
        SearchLine->setGeometry(QRect(260, 30, 301, 21));
        SearchLine->setMinimumSize(QSize(301, 21));
        SearchLine->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        Search = new QPushButton(frame);
        Search->setObjectName("Search");
        Search->setGeometry(QRect(570, 30, 91, 20));
        Search->setMinimumSize(QSize(91, 20));
        Search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        TabTable = new QTabWidget(frame);
        TabTable->setObjectName("TabTable");
        TabTable->setGeometry(QRect(10, 50, 761, 561));
        TabTable->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        StudentTable = new QTableView(tab);
        StudentTable->setObjectName("StudentTable");
        StudentTable->setGeometry(QRect(10, 10, 741, 511));
        TabTable->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        ProgTable = new QTableView(tab_3);
        ProgTable->setObjectName("ProgTable");
        ProgTable->setGeometry(QRect(10, 10, 741, 511));
        TabTable->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        CollegeTable = new QTableView(tab_2);
        CollegeTable->setObjectName("CollegeTable");
        CollegeTable->setGeometry(QRect(10, 10, 741, 511));
        TabTable->addTab(tab_2, QString());
        DeleteButton = new QPushButton(frame);
        DeleteButton->setObjectName("DeleteButton");
        DeleteButton->setGeometry(QRect(670, 30, 91, 21));
        DeleteButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"    background-color: #c70000 ;\n"
"    color: white;\n"
"    border: 2px solid #000000;\n"
"    border-radius: 5px;\n"
"     padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: white; \n"
"}"));
        Searchby = new QComboBox(frame);
        Searchby->setObjectName("Searchby");
        Searchby->setGeometry(QRect(145, 30, 111, 20));
        FirstName_5 = new QLabel(centralwidget);
        FirstName_5->setObjectName("FirstName_5");
        FirstName_5->setGeometry(QRect(240, 440, 111, 20));
        FirstName_5->setFont(font1);
        AddStudent = new QPushButton(centralwidget);
        AddStudent->setObjectName("AddStudent");
        AddStudent->setGeometry(QRect(260, 340, 91, 21));
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
        Yearlevelline = new QComboBox(centralwidget);
        Yearlevelline->addItem(QString());
        Yearlevelline->addItem(QString());
        Yearlevelline->addItem(QString());
        Yearlevelline->addItem(QString());
        Yearlevelline->setObjectName("Yearlevelline");
        Yearlevelline->setGeometry(QRect(240, 310, 141, 21));
        Yearlevelline->setMinimumSize(QSize(141, 21));
        Yearlevelline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        CollegeCode = new QLabel(centralwidget);
        CollegeCode->setObjectName("CollegeCode");
        CollegeCode->setGeometry(QRect(30, 540, 111, 20));
        CollegeCode->setFont(font1);
        Firstnameline = new QLineEdit(centralwidget);
        Firstnameline->setObjectName("Firstnameline");
        Firstnameline->setGeometry(QRect(80, 110, 301, 21));
        Firstnameline->setMinimumSize(QSize(301, 21));
        Firstnameline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        Middlenameline = new QLineEdit(centralwidget);
        Middlenameline->setObjectName("Middlenameline");
        Middlenameline->setGeometry(QRect(80, 160, 301, 21));
        Middlenameline->setMinimumSize(QSize(301, 21));
        Middlenameline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        StudentProfile = new QLabel(centralwidget);
        StudentProfile->setObjectName("StudentProfile");
        StudentProfile->setGeometry(QRect(80, 50, 301, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Rockwell")});
        font3.setPointSize(20);
        font3.setBold(true);
        StudentProfile->setFont(font3);
        StudentProfile->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"    border: 2px solid #00674F;\n"
"    border-radius: 10px;\n"
"    padding: 1px;\n"
"    box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);\n"
"    color: black;"));
        StudentProfile->setAlignment(Qt::AlignmentFlag::AlignCenter);
        IDline = new QLineEdit(centralwidget);
        IDline->setObjectName("IDline");
        IDline->setGeometry(QRect(240, 260, 141, 21));
        IDline->setMinimumSize(QSize(141, 21));
        IDline->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        MiddleName = new QLabel(centralwidget);
        MiddleName->setObjectName("MiddleName");
        MiddleName->setGeometry(QRect(80, 140, 181, 20));
        MiddleName->setFont(font1);
        SaveCollege = new QPushButton(centralwidget);
        SaveCollege->setObjectName("SaveCollege");
        SaveCollege->setGeometry(QRect(240, 580, 91, 21));
        SaveCollege->setStyleSheet(QString::fromUtf8("\n"
"QPushButton:hover {\n"
"    background-color: #808080;\n"
"    border: 2px solid #2980b9;\n"
"}"));
        CourseCode = new QLabel(centralwidget);
        CourseCode->setObjectName("CourseCode");
        CourseCode->setGeometry(QRect(80, 290, 141, 20));
        CourseCode->setFont(font2);
        EditStudent = new QPushButton(centralwidget);
        EditStudent->setObjectName("EditStudent");
        EditStudent->setGeometry(QRect(110, 340, 91, 21));
        EditStudent->setMinimumSize(QSize(91, 20));
        EditStudent->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        ProgramCode_2 = new QLineEdit(centralwidget);
        ProgramCode_2->setObjectName("ProgramCode_2");
        ProgramCode_2->setGeometry(QRect(30, 460, 191, 26));
        CourseComboBox = new QComboBox(centralwidget);
        CourseComboBox->setObjectName("CourseComboBox");
        CourseComboBox->setGeometry(QRect(80, 310, 141, 21));
        CourseComboBox->setMinimumSize(QSize(141, 21));
        CourseComboBox->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"	border: 2px solid #000000;\n"
"	border-radius: 5px;\n"
"	padding: 1px;\n"
"	box-shadow: 0 0 10px rgba(0,0,05);"));
        SaveProg = new QPushButton(centralwidget);
        SaveProg->setObjectName("SaveProg");
        SaveProg->setGeometry(QRect(30, 630, 81, 21));
        SaveProg->setStyleSheet(QString::fromUtf8("\n"
"QPushButton:hover {\n"
"    background-color: #808080;\n"
"    border: 2px solid #2980b9;\n"
"}"));
        FirstName_6 = new QLabel(centralwidget);
        FirstName_6->setObjectName("FirstName_6");
        FirstName_6->setGeometry(QRect(240, 490, 111, 20));
        FirstName_6->setFont(font1);
        CollegeCodeCombbox = new QComboBox(centralwidget);
        CollegeCodeCombbox->setObjectName("CollegeCodeCombbox");
        CollegeCodeCombbox->setGeometry(QRect(30, 560, 131, 26));
        YearLevel = new QLabel(centralwidget);
        YearLevel->setObjectName("YearLevel");
        YearLevel->setGeometry(QRect(240, 290, 141, 20));
        YearLevel->setFont(font2);
        LastName = new QLabel(centralwidget);
        LastName->setObjectName("LastName");
        LastName->setGeometry(QRect(80, 190, 181, 20));
        LastName->setFont(font2);
        CollegeCodeLine = new QLineEdit(centralwidget);
        CollegeCodeLine->setObjectName("CollegeCodeLine");
        CollegeCodeLine->setGeometry(QRect(240, 460, 181, 26));
        IDnumber = new QLabel(centralwidget);
        IDnumber->setObjectName("IDnumber");
        IDnumber->setGeometry(QRect(240, 240, 141, 20));
        IDnumber->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1219, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        TabTable->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        EditProg->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        Genderline->setItemText(0, QCoreApplication::translate("MainWindow", "Female", nullptr));
        Genderline->setItemText(1, QCoreApplication::translate("MainWindow", "Male", nullptr));

        AddProgram_2->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        AddCollege->setText(QCoreApplication::translate("MainWindow", "College", nullptr));
        ProgramName->setText(QCoreApplication::translate("MainWindow", "Program Name", nullptr));
        AddProgram->setText(QCoreApplication::translate("MainWindow", "Program", nullptr));
        Gender->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        SaveStudent->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        FirstName->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        EditCollege->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        AddCollege_2->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        ProgramCode->setText(QCoreApplication::translate("MainWindow", "Program Code", nullptr));
        Search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        TabTable->setTabText(TabTable->indexOf(tab), QCoreApplication::translate("MainWindow", "Students", nullptr));
        TabTable->setTabText(TabTable->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Program", nullptr));
        TabTable->setTabText(TabTable->indexOf(tab_2), QCoreApplication::translate("MainWindow", "College", nullptr));
        DeleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        FirstName_5->setText(QCoreApplication::translate("MainWindow", "College Code", nullptr));
        AddStudent->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        Yearlevelline->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        Yearlevelline->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        Yearlevelline->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        Yearlevelline->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));

        CollegeCode->setText(QCoreApplication::translate("MainWindow", "College Code", nullptr));
        StudentProfile->setText(QCoreApplication::translate("MainWindow", "Student Profile", nullptr));
        IDline->setPlaceholderText(QCoreApplication::translate("MainWindow", "e.g. 2000-0000", nullptr));
        MiddleName->setText(QCoreApplication::translate("MainWindow", "Middle Name", nullptr));
        SaveCollege->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        CourseCode->setText(QCoreApplication::translate("MainWindow", "Course Code", nullptr));
        EditStudent->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        SaveProg->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        FirstName_6->setText(QCoreApplication::translate("MainWindow", "College Name", nullptr));
        YearLevel->setText(QCoreApplication::translate("MainWindow", "Year Level", nullptr));
        LastName->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        IDnumber->setText(QCoreApplication::translate("MainWindow", "I.D. Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
