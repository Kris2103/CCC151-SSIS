#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectdb.h"
#include <QDebug>
#include <QFileInfo>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString dbPath = "C:/Users/Kristelle/Documents/Database/CCC151_Database.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    QFileInfo fileInfo(dbPath);
    if (fileInfo.exists()) {
        qDebug() << "File exists at:" << dbPath;
        qDebug() << "Permissions:" << fileInfo.permissions();
    } else {
        qDebug() << "File does not exist at:" << dbPath;
    }

    connectdb con;
    if (con.Connect()) {
        qDebug() << "Database is Connected";
    } else {
        qDebug() << "Database is not connected";
    }

    //STUDENT table
    studentSqlModel = new QSqlTableModel(this, db);
    studentSqlModel->setTable("Students");
    studentSqlModel->select();
    studentSqlModel->setHeaderData(0, Qt::Horizontal, "I.D. Number");
    studentSqlModel->setHeaderData(1, Qt::Horizontal, "First Name");
    studentSqlModel->setHeaderData(2, Qt::Horizontal, "Middle Name");
    studentSqlModel->setHeaderData(3, Qt::Horizontal, "Last Name");
    studentSqlModel->setHeaderData(4, Qt::Horizontal, "Year Level");
    studentSqlModel->setHeaderData(5, Qt::Horizontal, "Gender");
    studentSqlModel->setHeaderData(6, Qt::Horizontal, "Program Code");

    ui->StudentTable->setModel(studentSqlModel);
    ui->StudentTable->setSortingEnabled(true);
    ui->StudentTable->horizontalHeader()->setSortIndicator(0, Qt::AscendingOrder);

    // PROGRAM TABLE
    programSqlModel = new QSqlTableModel(this, db);
    programSqlModel->setTable("Program");
    programSqlModel->select();
    programSqlModel->setHeaderData(0, Qt::Horizontal, "Program Code");
    programSqlModel->setHeaderData(1, Qt::Horizontal, "Program Name");
    programSqlModel->setHeaderData(2, Qt::Horizontal, "College Code");

    ui->ProgTable->setModel(programSqlModel);
    ui->ProgTable->setSortingEnabled(true);
    ui->ProgTable->horizontalHeader()->setSortIndicator(0, Qt::AscendingOrder);
    ui->ProgTable->setColumnWidth(0, 115);
    ui->ProgTable->setColumnWidth(2, 100);
    ui->ProgTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    // COLLEGE TABLE
    collegeSqlModel = new QSqlTableModel(this, db);
    collegeSqlModel->setTable("College");
    collegeSqlModel->select();
    collegeSqlModel->setHeaderData(0, Qt::Horizontal, "College Code");
    collegeSqlModel->setHeaderData(1, Qt::Horizontal, "College Name");

    ui->CollegeTable->setModel(collegeSqlModel);
    ui->CollegeTable->setSortingEnabled(true);
    ui->CollegeTable->horizontalHeader()->setSortIndicator(0, Qt::AscendingOrder);
    ui->CollegeTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->CollegeTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->CollegeTable->horizontalHeader()->setStretchLastSection(true);
    ui->CollegeTable->horizontalHeader()->setMinimumSectionSize(150);

    // ComboBoxes reset
    ui->CourseComboBox->setCurrentIndex(-1);
    ui->Genderline->setCurrentIndex(-1);
    ui->Yearlevelline->setCurrentIndex(-1);
    ui->CollegeCodeCombbox->setCurrentIndex(-1);

    // Tab setup
    connect(ui->TabTable, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));
    ui->TabTable->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
