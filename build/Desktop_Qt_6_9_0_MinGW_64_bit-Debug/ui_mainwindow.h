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
    QFrame *frame;
    QLineEdit *SearchLine;
    QPushButton *Search;
    QTabWidget *TabTable;
    QWidget *tab;
    QTableView *StudentTable;
    QPushButton *btnNextStudent;
    QPushButton *btnPrevStudent;
    QWidget *tab_3;
    QTableView *ProgTable;
    QPushButton *btnNextProgram;
    QPushButton *btnPrevProgram;
    QWidget *tab_2;
    QTableView *CollegeTable;
    QPushButton *btnNextCollege;
    QPushButton *btnPrevCollege;
    QPushButton *DeleteButton;
    QComboBox *Searchby;
    QPushButton *Add;
    QPushButton *Edit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(824, 735);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 20, 771, 621));
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
        TabTable->setGeometry(QRect(10, 50, 761, 571));
        TabTable->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        StudentTable = new QTableView(tab);
        StudentTable->setObjectName("StudentTable");
        StudentTable->setGeometry(QRect(10, 10, 741, 491));
        btnNextStudent = new QPushButton(tab);
        btnNextStudent->setObjectName("btnNextStudent");
        btnNextStudent->setGeometry(QRect(660, 500, 91, 29));
        btnPrevStudent = new QPushButton(tab);
        btnPrevStudent->setObjectName("btnPrevStudent");
        btnPrevStudent->setGeometry(QRect(570, 500, 91, 29));
        TabTable->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        ProgTable = new QTableView(tab_3);
        ProgTable->setObjectName("ProgTable");
        ProgTable->setGeometry(QRect(10, 10, 741, 491));
        btnNextProgram = new QPushButton(tab_3);
        btnNextProgram->setObjectName("btnNextProgram");
        btnNextProgram->setGeometry(QRect(660, 500, 91, 29));
        btnPrevProgram = new QPushButton(tab_3);
        btnPrevProgram->setObjectName("btnPrevProgram");
        btnPrevProgram->setGeometry(QRect(570, 500, 91, 29));
        TabTable->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        CollegeTable = new QTableView(tab_2);
        CollegeTable->setObjectName("CollegeTable");
        CollegeTable->setGeometry(QRect(10, 10, 741, 491));
        btnNextCollege = new QPushButton(tab_2);
        btnNextCollege->setObjectName("btnNextCollege");
        btnNextCollege->setGeometry(QRect(660, 500, 91, 29));
        btnPrevCollege = new QPushButton(tab_2);
        btnPrevCollege->setObjectName("btnPrevCollege");
        btnPrevCollege->setGeometry(QRect(570, 500, 91, 29));
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
        Add = new QPushButton(centralwidget);
        Add->setObjectName("Add");
        Add->setGeometry(QRect(700, 650, 91, 21));
        Add->setMinimumSize(QSize(91, 20));
        Add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Edit = new QPushButton(centralwidget);
        Edit->setObjectName("Edit");
        Edit->setGeometry(QRect(600, 650, 91, 21));
        Edit->setMinimumSize(QSize(91, 20));
        Edit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 824, 26));
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
        Search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        btnNextStudent->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        btnPrevStudent->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        TabTable->setTabText(TabTable->indexOf(tab), QCoreApplication::translate("MainWindow", "Students", nullptr));
        btnNextProgram->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        btnPrevProgram->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        TabTable->setTabText(TabTable->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Program", nullptr));
        btnNextCollege->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        btnPrevCollege->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        TabTable->setTabText(TabTable->indexOf(tab_2), QCoreApplication::translate("MainWindow", "College", nullptr));
        DeleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        Add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        Edit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
