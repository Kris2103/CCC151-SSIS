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
#include "addstudentdialog.h"
#include "addprogramdialog.h"
#include "addcollegedialog.h"
#include "editstudentdialog.h"
#include "editprogramdialog.h"
#include "editcollegedialog.h"
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QStandardItem>
#include <iostream>

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

        QSqlQuery pragmaQuery("PRAGMA foreign_keys = ON;", db);
        if (!pragmaQuery.exec()) {
            qDebug() << "Failed to enable foreign keys:" << pragmaQuery.lastError();
        } else {
            qDebug() << "Foreign keys enabled!";
        }

        } else {
        qDebug() << "Database is not connected";
    }

    // STUDENT table with pagination
    currentStudentPage = 0;
    currentProgramPage = 0;
    currentCollegePage = 0;
    rowsPerPage = 15;
    studentSortColumn = 0;
    studentSortOrder = Qt::AscendingOrder;
    programSortColumn = 0;
    programSortOrder = Qt::AscendingOrder;
    collegeSortColumn = 0;
    collegeSortOrder = Qt::AscendingOrder;
    loadStudentPage(currentStudentPage);
    loadProgramPage(currentProgramPage);
    loadCollegePage(currentCollegePage);

    // Sorting connections
    connect(ui->StudentTable->horizontalHeader(), &QHeaderView::sectionClicked, this, [=](int logicalIndex){
        studentSortColumn = logicalIndex;
        studentSortOrder = (studentSortOrder == Qt::AscendingOrder) ? Qt::DescendingOrder : Qt::AscendingOrder;
        loadStudentPage(currentStudentPage);
    });
    connect(ui->ProgTable->horizontalHeader(), &QHeaderView::sectionClicked, this, [=](int logicalIndex){
        programSortColumn = logicalIndex;
        programSortOrder = (programSortOrder == Qt::AscendingOrder) ? Qt::DescendingOrder : Qt::AscendingOrder;
        loadProgramPage(currentProgramPage);
    });
    connect(ui->CollegeTable->horizontalHeader(), &QHeaderView::sectionClicked, this, [=](int logicalIndex){
        collegeSortColumn = logicalIndex;
        collegeSortOrder = (collegeSortOrder == Qt::AscendingOrder) ? Qt::DescendingOrder : Qt::AscendingOrder;
        loadCollegePage(currentCollegePage);
    });

    // Tab setup
    connect(ui->TabTable, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));
    ui->TabTable->setCurrentIndex(0);

    connect(ui->btnNextStudent, &QPushButton::clicked, this, &MainWindow::nextStudentPage);
    connect(ui->btnPrevStudent, &QPushButton::clicked, this, &MainWindow::prevStudentPage);

    connect(ui->btnNextProgram, &QPushButton::clicked, this, &MainWindow::nextProgramPage);
    connect(ui->btnPrevProgram, &QPushButton::clicked, this, &MainWindow::prevProgramPage);

    connect(ui->btnNextCollege, &QPushButton::clicked, this, &MainWindow::nextCollegePage);
    connect(ui->btnPrevCollege, &QPushButton::clicked, this, &MainWindow::prevCollegePage);

    connect(ui->TabTable, &QTabWidget::currentChanged, this, &MainWindow::on_TabTable_currentChanged);

    ui->TabTable->setCurrentIndex(0);
    ui->StudentTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->StudentTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    on_TabTable_currentChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadStudentPage(int page) {
    QSqlQuery countQuery("SELECT COUNT(*) FROM STUDENTS", db);
    int totalStudents = 0;
    if (countQuery.next()) {
        totalStudents = countQuery.value(0).toInt();
    }

    int maxPage = (totalStudents + rowsPerPage - 1) / rowsPerPage - 1;
    if (page > maxPage) {
        page = maxPage;
    }
    currentStudentPage = page;

    int offset = page * rowsPerPage;

    studentQueryModel = new QSqlQueryModel(this);

    QStringList columns = {"ID", "FIRST_NAME", "MIDDLE_NAME", "LAST_NAME", "YEAR_LEVEL", "GENDER", "PROGRAM_CODE"};
    QString query = QString("SELECT ID, FIRST_NAME, MIDDLE_NAME, LAST_NAME, YEAR_LEVEL, GENDER, "
                            "IFNULL(PROGRAM_CODE, 'Unenrolled') AS PROGRAM_CODE "
                            "FROM STUDENTS "
                            "ORDER BY %1 %2 "
                            "LIMIT %3 OFFSET %4")
                        .arg(columns.value(studentSortColumn, "ID"))
                        .arg(studentSortOrder == Qt::AscendingOrder ? "ASC" : "DESC")
                        .arg(rowsPerPage)
                        .arg(offset);

    studentQueryModel->setQuery(query, db);

    if (studentQueryModel->lastError().isValid()) {
        qDebug() << "Query Error: " << studentQueryModel->lastError().text();
    }

    studentQueryModel->setHeaderData(0, Qt::Horizontal, "ID");
    studentQueryModel->setHeaderData(1, Qt::Horizontal, "First Name");
    studentQueryModel->setHeaderData(2, Qt::Horizontal, "Middle Name");
    studentQueryModel->setHeaderData(3, Qt::Horizontal, "Last Name");
    studentQueryModel->setHeaderData(4, Qt::Horizontal, "Year Level");
    studentQueryModel->setHeaderData(5, Qt::Horizontal, "Gender");
    studentQueryModel->setHeaderData(6, Qt::Horizontal, "Program Code");

    ui->StudentTable->setModel(studentQueryModel);
    ui->StudentTable->setSortingEnabled(true);
    ui->StudentTable->horizontalHeader()->setSortIndicator(studentSortColumn, studentSortOrder);
    ui->StudentTable->verticalHeader()->setVisible(false);

    int start = offset + 1;
    int end = offset + studentQueryModel->rowCount();

    if (end > totalStudents) {
        end = totalStudents;
    }
    ui->pageLabel->setText(QString("Page %1: %2 - %3").arg(page + 1).arg(start).arg(end));

    ui->btnPrevStudent->setEnabled(currentStudentPage > 0);
    ui->btnNextStudent->setEnabled(studentQueryModel->rowCount() == rowsPerPage);
}

void MainWindow::loadProgramPage(int page) {
    QSqlQuery countQuery("SELECT COUNT(*) FROM PROGRAM", db);
    int totalPrograms = 0;
    if (countQuery.next()) {
        totalPrograms = countQuery.value(0).toInt();
    }

    int maxPage = (totalPrograms + rowsPerPage - 1) / rowsPerPage - 1;
    if (page > maxPage) {
        page = maxPage;
    }
    currentProgramPage = page;

    int offset = page * rowsPerPage;
    programQueryModel = new QSqlQueryModel(this);

    QStringList columns = {"PROGRAM_CODE", "PROGRAM_NAME", "COLLEGE_CODE"};
    QString orderBy = columns.value(programSortColumn, "CODE");
    QString order = (programSortOrder == Qt::AscendingOrder) ? "ASC" : "DESC";

    QString query = QString("SELECT PROGRAM_CODE, PROGRAM_NAME, IFNULL(COLLEGE_CODE, 'Null') AS COLLEGE_CODE "
                            "FROM PROGRAM "
                            "ORDER BY %1 %2 "
                            "LIMIT %3 OFFSET %4"
                            )
                            .arg(orderBy)
                            .arg(order)
                            .arg(rowsPerPage)
                            .arg(offset);

    programQueryModel->setQuery(query, db);
    programQueryModel->setHeaderData(0, Qt::Horizontal, "Program Code");
    programQueryModel->setHeaderData(1, Qt::Horizontal, "Program Name");
    programQueryModel->setHeaderData(2, Qt::Horizontal, "College Code");

    ui->ProgTable->setModel(programQueryModel);
    ui->ProgTable->setSortingEnabled(true);
    ui->ProgTable->horizontalHeader()->setSortIndicator(programSortColumn, programSortOrder);
    ui->ProgTable->setColumnWidth(0, 115);
    ui->ProgTable->setColumnWidth(2, 100);
    ui->ProgTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->ProgTable->verticalHeader()->setVisible(false);

    int start = offset + 1;
    int end = offset + programQueryModel->rowCount();

    if (end > totalPrograms) {
        end = totalPrograms;
    }

    ui->pageLabel_2->setText(QString("Page %1: %2 - %3").arg(page + 1).arg(start).arg(end));

    ui->btnPrevProgram->setEnabled(currentProgramPage > 0);
    ui->btnNextProgram->setEnabled(programQueryModel->rowCount() == rowsPerPage);
}

void MainWindow::loadCollegePage(int page) {
    QSqlQuery countQuery("SELECT COUNT(*) FROM COLLEGE", db);
    int totalColleges = 0;
    if (countQuery.next()) {
        totalColleges = countQuery.value(0).toInt();
    }

    // Calculate the maximum page
    int maxPage = (totalColleges + rowsPerPage - 1) / rowsPerPage - 1;
    if (page > maxPage) {
        page = maxPage;
    }
    currentCollegePage = page;

    int offset = page * rowsPerPage;
    collegeQueryModel = new QSqlQueryModel(this);

    QStringList columns = {"COLLEGE_CODE", "COLLEGE_NAME"};
    QString orderBy = columns.value(collegeSortColumn, "CODE");
    QString order = (collegeSortOrder == Qt::AscendingOrder) ? "ASC" : "DESC";

    QString query = QString("SELECT COLLEGE_CODE, COLLEGE_NAME FROM COLLEGE ORDER BY %1 %2 LIMIT %3 OFFSET %4")
                        .arg(orderBy)
                        .arg(order)
                        .arg(rowsPerPage)
                        .arg(offset);

    collegeQueryModel->setQuery(query, db);
    collegeQueryModel->setHeaderData(0, Qt::Horizontal, "College Code");
    collegeQueryModel->setHeaderData(1, Qt::Horizontal, "College Name");

    ui->CollegeTable->setModel(collegeQueryModel);
    ui->CollegeTable->setSortingEnabled(true);
    ui->CollegeTable->horizontalHeader()->setSortIndicator(collegeSortColumn, collegeSortOrder);
    ui->CollegeTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->CollegeTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->CollegeTable->horizontalHeader()->setStretchLastSection(true);
    ui->CollegeTable->horizontalHeader()->setMinimumSectionSize(150);
    ui->CollegeTable->verticalHeader()->setVisible(false);

    int start = offset + 1;
    int end = offset + collegeQueryModel->rowCount();

    if (end > totalColleges) {
        end = totalColleges;
    }

    ui->pageLabel_3->setText(QString("Page %1: %2 - %3").arg(page + 1).arg(start).arg(end));

    ui->btnPrevCollege->setEnabled(currentCollegePage > 0);
    ui->btnNextCollege->setEnabled(collegeQueryModel->rowCount() == rowsPerPage);
}

void MainWindow::nextStudentPage() {
    currentStudentPage++;
    loadStudentPage(currentStudentPage);
}

void MainWindow::prevStudentPage() {
    if (currentStudentPage > 0) {
        currentStudentPage--;
        loadStudentPage(currentStudentPage);
    }
}

void MainWindow::nextProgramPage() {
    currentProgramPage++;
    loadProgramPage(currentProgramPage);
}

void MainWindow::prevProgramPage() {
    if (currentProgramPage > 0) {
        currentProgramPage--;
        loadProgramPage(currentProgramPage);
    }
}

void MainWindow::nextCollegePage() {
    currentCollegePage++;
    loadCollegePage(currentCollegePage);
}

void MainWindow::prevCollegePage() {
    if (currentCollegePage > 0) {
        currentCollegePage--;
        loadCollegePage(currentCollegePage);
    }
}

void MainWindow::insertStudentToDatabase(const QString &id, const QString &fname, const QString &mname,
                                         const QString &lname, int year, const QString &gender, const QString &course)
{
    static const QRegularExpression idRegex(R"(^\d{4}-\d{4}$)");

    if (fname.trimmed().isEmpty() || lname.trimmed().isEmpty() || year == 0 || course.trimmed().isEmpty() || gender.trimmed().isEmpty()) {
        QMessageBox::critical(this, "Validation Error", "Please fill out all required fields (ID, First Name, Last Name, Year Level, Course Code, Gender).");
        return;
    }
    if (!idRegex.match(id).hasMatch()) {
        QMessageBox::critical(this, "ID Format Error", "ID must follow the format YYYY-NNNN.");
        return;
    }

    // Check if course exists
    QSqlQuery checkProgram(db);
    checkProgram.prepare("SELECT COUNT(*) FROM PROGRAM WHERE PROGRAM_CODE = :code");
    checkProgram.bindValue(":code", course);
    if (!checkProgram.exec() || !checkProgram.next() || checkProgram.value(0).toInt() == 0) {
        QMessageBox::critical(this, "Invalid Program", "The selected program does not exist.");
        return;
    }

    // Check for duplicate ID
    QSqlQuery checkStudent(db);
    checkStudent.prepare("SELECT COUNT(*) FROM STUDENTS WHERE ID = :id");
    checkStudent.bindValue(":id", id);
    if (!checkStudent.exec() || !checkStudent.next()) {
        QMessageBox::critical(this, "Error", "Failed to check for existing ID.");
        return;
    }
    if (checkStudent.value(0).toInt() > 0) {
        QMessageBox::critical(this, "Duplicate ID", "A student with this ID already exists.");
        return;
    }

    QSqlQuery insert(db);
    insert.prepare(R"(
        INSERT INTO STUDENTS (ID, FIRST_NAME, MIDDLE_NAME, LAST_NAME, YEAR_LEVEL, GENDER, PROGRAM_CODE)
        VALUES (:id, :fname, :mname, :lname, :year, :gender, :course)
    )");
    insert.bindValue(":id", id);
    insert.bindValue(":fname", fname);
    insert.bindValue(":mname", mname);
    insert.bindValue(":lname", lname);
    insert.bindValue(":year", year);
    insert.bindValue(":gender", gender);
    insert.bindValue(":course", course);

    if (!insert.exec()) {
        QMessageBox::critical(this, "Insertion Error", insert.lastError().text());
        return;
    }

    currentStudentPage = 0;
    studentSortColumn = 0;
    studentSortOrder = Qt::DescendingOrder;
    loadStudentPage(currentStudentPage);

    QMessageBox::information(this, "Success", "Student successfully added.");
}

void MainWindow::insertProgramToDatabase(const QString &programCode, const QString &programName, const QString &collegeCode)
{
    // Check if the college code exists
    QSqlQuery checkCollege(db);
    checkCollege.prepare("SELECT COUNT(*) FROM COLLEGE WHERE COLLEGE_CODE = :collegeCode");
    checkCollege.bindValue(":collegeCode", collegeCode);  // Binding the collegeCode here
    if (!checkCollege.exec() || !checkCollege.next() || checkCollege.value(0).toInt() == 0) {
        QMessageBox::critical(this, "Invalid College Code", "Selected college code does not exist.");
        return;
    }

    // Check if the program code already exists
    QSqlQuery checkProgram(db);
    checkProgram.prepare("SELECT COUNT(*) FROM PROGRAM WHERE PROGRAM_CODE = :programCode");
    checkProgram.bindValue(":programCode", programCode);  // Binding the programCode here
    if (!checkProgram.exec() || !checkProgram.next() || checkProgram.value(0).toInt() > 0) {
        QMessageBox::critical(this, "Duplicate Program", "A program with this code already exists.");
        return;
    }

    // Insert program into the PROGRAM table
    QSqlQuery insert(db);
    insert.prepare(R"(
        INSERT INTO PROGRAM (PROGRAM_CODE, PROGRAM_NAME, COLLEGE_CODE)
        VALUES (:programCode, :programName, :collegeCode)
    )");
    insert.bindValue(":programCode", programCode);  // Bind programCode correctly
    insert.bindValue(":programName", programName);  // Bind programName correctly
    insert.bindValue(":collegeCode", collegeCode);  // Bind collegeCode correctly

    if (!insert.exec()) {
        QMessageBox::critical(this, "Insertion Error", insert.lastError().text());
        return;
    }

    // After insertion, load the program page again
    currentProgramPage = 0;
    programSortColumn = 0;
    programSortOrder = Qt::DescendingOrder;
    loadProgramPage(currentProgramPage);

    QMessageBox::information(this, "Success", "Program added successfully.");
}


void MainWindow::insertCollegeToDatabase(const QString &code, const QString &name)
{
    QSqlQuery checkCollege(db);
    checkCollege.prepare("SELECT COUNT(*) FROM COLLEGE WHERE COLLEGE_CODE = :collegeCode");
    checkCollege.bindValue(":collegeCode", code);

    if (!checkCollege.exec() || !checkCollege.next() || checkCollege.value(0).toInt() > 0) {
        QMessageBox::critical(this, "Duplicate College", "A college with this code already exists.");
        return;
    }

    QSqlQuery insert(db);
    insert.prepare(R"(
        INSERT INTO COLLEGE (COLLEGE_CODE, COLLEGE_NAME)
        VALUES (:collegeCode, :collegeName)
    )");
    insert.bindValue(":collegeCode", code);
    insert.bindValue(":collegeName", name);

    if (!insert.exec()) {
        QMessageBox::critical(this, "Insertion Error", insert.lastError().text());
        return;
    }

    currentCollegePage = 0;
    collegeSortColumn = 0;
    collegeSortOrder = Qt::DescendingOrder;
    loadCollegePage(currentCollegePage);

    QMessageBox::information(this, "Success", "College added successfully.");
}


void MainWindow::refreshStudentTable()
{
    studentQueryModel->setQuery(studentQueryModel->query().lastQuery(), db); // Reload the data from the database into the model
}


void MainWindow::refreshProgramTable()
{
    programQueryModel->setQuery(programQueryModel->query().lastQuery(), db); // Refresh the Program table data
}


void MainWindow::refreshCollegeTable()
{
    collegeQueryModel->setQuery(collegeQueryModel->query().lastQuery(), db); // Refresh the College table data
}

void MainWindow::on_Add_clicked()
{
    int currentTab = ui->TabTable->currentIndex();

    if (currentTab == 0) {  // Student tab
        AddStudentDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QString id = dialog.getID();
            QString fname = dialog.getFirstName();
            QString mname = dialog.getMiddleName();
            QString lname = dialog.getLastName();
            int year = dialog.getYearLevel();
            QString gender = dialog.getGender();
            QString course = dialog.getProgramCode();

            insertStudentToDatabase(id, fname, mname, lname, year, gender, course);
        }
    }
    else if (currentTab == 1) {  // Program tab
        AddProgramDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QString code = dialog.getProgramCode();
            QString name = dialog.getProgramName();
            QString collegeCode = dialog.getCollegeCode();
            std::cout<< "Add Program works.";
            insertProgramToDatabase(code, name, collegeCode);
        }
    }
    else if (currentTab == 2) {  // College tab
        AddCollegeDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QString code = dialog.getCollegeCode();
            QString name = dialog.getCollegeName();

            insertCollegeToDatabase(code, name);
        }
    }
}

void MainWindow::on_Edit_clicked()
{
    int currentTab = ui->TabTable->currentIndex();

    if (currentTab == 0) {  // Student tab
        int selectedRow = ui->StudentTable->selectionModel()->currentIndex().row();
        if (selectedRow < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a student to edit.");
            return;
        }

        QString id = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 0)).toString(); // ID (column 0)
        QString fname = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 1)).toString(); // First Name
        QString mname = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 2)).toString(); // Middle Name
        QString lname = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 3)).toString(); // Last Name
        int year = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 4)).toInt(); // Year Level
        QString gender = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 5)).toString(); // Gender
        QString course = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 6)).toString(); // Program Code

        EditStudentDialog dialog(this);
        dialog.setStudentData(id, fname, mname, lname, year, gender, course);

        if (dialog.exec() == QDialog::Accepted) {
            //QString newID = dialog.getID();
            QString newFname = dialog.getFirstName();
            QString newMname = dialog.getMiddleName();
            QString newLname = dialog.getLastName();
            int newYear = dialog.getYearLevel();
            QString newGender = dialog.getGender();
            QString newCourse = dialog.getProgramCode();

            updateStudentInDatabase(id, newFname, newMname, newLname, newYear, newGender, newCourse);
        }
    }
    else if (currentTab == 1) {  // Program tab
        int selectedRow = ui->ProgTable->selectionModel()->currentIndex().row();
        if (selectedRow < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a program to edit.");
            return;
        }

        QString code = ui->ProgTable->model()->data(ui->ProgTable->model()->index(selectedRow, 0)).toString(); // Program Code (column 0)
        QString name = ui->ProgTable->model()->data(ui->ProgTable->model()->index(selectedRow, 1)).toString(); // Program Name
        QString collegeCode = ui->ProgTable->model()->data(ui->ProgTable->model()->index(selectedRow, 2)).toString(); // College Code

        EditProgramDialog dialog(this);
        dialog.setProgramData(code, name, collegeCode);

        if (dialog.exec() == QDialog::Accepted) {
            QString newCode = dialog.getProgramCode();
            QString newName = dialog.getProgramName();
            QString newCollegeCode = dialog.getCollegeCode();

            updateProgramInDatabase(newCode, newName, newCollegeCode);
        }
    }
    else if (currentTab == 2) {  // College tab
        int selectedRow = ui->CollegeTable->selectionModel()->currentIndex().row();
        if (selectedRow < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a college to edit.");
            return;
        }

        QString code = ui->CollegeTable->model()->data(ui->CollegeTable->model()->index(selectedRow, 0)).toString(); // College Code (column 0)
        QString name = ui->CollegeTable->model()->data(ui->CollegeTable->model()->index(selectedRow, 1)).toString(); // College Name

        EditCollegeDialog dialog(this);
        dialog.setCollegeData(code, name);

        if (dialog.exec() == QDialog::Accepted) {
            QString newCode = dialog.getCollegeCode();
            QString newName = dialog.getCollegeName();

            updateCollegeInDatabase(newCode, newName);
        }
    }
}

void MainWindow::updateStudentInDatabase(const QString &id, const QString &fname, const QString &mname, const QString &lname,
                                         int year, const QString &gender, const QString &programCode)
{
    if (fname.isEmpty() || mname.isEmpty() || lname.isEmpty() || gender.isEmpty() || programCode.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please fill in all fields before updating.");
        return;
    }

    QSqlQuery update(db);
    update.prepare(R"(
        UPDATE STUDENTS
        SET
            FIRST_NAME = :fname,
            MIDDLE_NAME = :mname,
            LAST_NAME = :lname,
            YEAR_LEVEL = :year,
            GENDER = :gender,
            PROGRAM_CODE = :programCode
        WHERE ID = :id
    )");

    update.bindValue(":id", id);
    update.bindValue(":fname", fname);
    update.bindValue(":mname", mname);
    update.bindValue(":lname", lname);
    update.bindValue(":year", year);
    update.bindValue(":gender", gender);
    update.bindValue(":programCode", programCode);

    if (!update.exec()) {
        QMessageBox::critical(this, "Update Error", update.lastError().text());
        qDebug() << "Update error:" << update.lastError().text();
        return;
    }

    db.commit();

    loadStudentPage(currentStudentPage);
    QMessageBox::information(this, "Success", "Student record updated.");
}


void MainWindow::updateProgramInDatabase(const QString &programCode, const QString &programName, const QString &collegeCode)
{
    if (programName.isEmpty() || collegeCode.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please fill in all fields before updating.");
        return;
    }

    QSqlQuery update(db);
    update.prepare(R"(
        UPDATE PROGRAM
        SET PROGRAM_NAME = :programName, COLLEGE_CODE = :collegeCode
        WHERE PROGRAM_CODE = :programCode
    )");

    update.bindValue(":programName", programName);
    update.bindValue(":collegeCode", collegeCode);
    update.bindValue(":programCode", programCode);

    // Execute the query
    if (!update.exec()) {
        qDebug() << "Update error (PROGRAM):" << update.lastError().text();
        QMessageBox::critical(this, "Update Error", "Failed to update the program record.\n" + update.lastError().text());
        // Rollback the transaction if an error occurs
        db.rollback();
        return;
    }

    db.commit();

    loadProgramPage(currentProgramPage);
    QMessageBox::information(this, "Success", "Program record updated.");
}

void MainWindow::updateCollegeInDatabase(const QString &collegeCode, const QString &collegeName)
{
    if (collegeName.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid College Name.");
        return;
    }

    QSqlQuery update(db);
    update.prepare(R"(
        UPDATE COLLEGE
        SET COLLEGE_NAME = :collegeName
        WHERE COLLEGE_CODE = :collegeCode
    )");

    update.bindValue(":collegeName", collegeName);
    update.bindValue(":collegeCode", collegeCode);

    if (!update.exec()) {
        QMessageBox::critical(this, "Update Error", update.lastError().text());
        qDebug() << "Update error (COLLEGE):" << update.lastError().text();
        return;
    }

    db.commit();

    loadCollegePage(currentCollegePage);
    QMessageBox::information(this, "Success", "College record updated.");
}

void MainWindow::on_DeleteButton_clicked()
{
    int currentTab = ui->TabTable->currentIndex();  // Get the current tab

    if (currentTab == 0) {  // Student tab
        int selectedRow = ui->StudentTable->selectionModel()->currentIndex().row();
        if (selectedRow < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a student to delete.");
            return;
        }

        QString studentId = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 0)).toString();

        if (QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to delete this student?",
                                  QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            deleteStudentFromDatabase(studentId);
            refreshAllTables();  // Helper to reload all tables
        }
    }
    else if (currentTab == 1) {  // Program tab
        int selectedRow = ui->ProgTable->selectionModel()->currentIndex().row();
        if (selectedRow < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a program to delete.");
            return;
        }

        QString programCode = ui->ProgTable->model()->data(ui->ProgTable->model()->index(selectedRow, 0)).toString();

        if (QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to delete this program?",
                                  QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            deleteProgramFromDatabase(programCode);
            refreshAllTables();
        }
    }
    else if (currentTab == 2) {  // College tab
        int selectedRow = ui->CollegeTable->selectionModel()->currentIndex().row();
        if (selectedRow < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a college to delete.");
            return;
        }

        QString collegeCode = ui->CollegeTable->model()->data(ui->CollegeTable->model()->index(selectedRow, 0)).toString();

        if (QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to delete this college?",
                                  QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            deleteCollegeFromDatabase(collegeCode);
            refreshAllTables();
        }
    }
}

void MainWindow::deleteStudentFromDatabase(const QString &id)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    QSqlQuery deleteQuery(db);
    deleteQuery.prepare("DELETE FROM STUDENTS WHERE ID = :id");
    deleteQuery.bindValue(":id", id);

    if (!deleteQuery.exec()) {
        qDebug() << "Delete error (STUDENTS):" << deleteQuery.lastError().text();
        QMessageBox::critical(this, "Delete Error", "Failed to delete the student record.");
        return;
    }
    loadStudentPage(currentStudentPage);
    loadProgramPage(currentProgramPage);

    db.commit();
}

void MainWindow::deleteProgramFromDatabase(const QString &code)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    QSqlQuery deleteQuery(db);
    deleteQuery.prepare("DELETE FROM PROGRAM WHERE PROGRAM_CODE = :code");
    deleteQuery.bindValue(":code", code);

    if (!deleteQuery.exec()) {
        qDebug() << "Delete error (PROGRAM):" << deleteQuery.lastError().text();
        db.rollback();  // Rollback if the deletion fails
        QMessageBox::critical(this, "Delete Error", "Failed to delete the program record.");
        return;
    }
    loadStudentPage(currentStudentPage);
    loadProgramPage(currentProgramPage);

    db.commit();
}


void MainWindow::deleteCollegeFromDatabase(const QString &code)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database not open!";
        return;
    }

    QSqlQuery deleteQuery(db);
    deleteQuery.prepare("DELETE FROM COLLEGE WHERE COLLEGE_CODE = :code");
    deleteQuery.bindValue(":code", code);

    if (!deleteQuery.exec()) {
        qDebug() << "Delete error (COLLEGE):" << deleteQuery.lastError().text();
        QMessageBox::critical(this, "Delete Error", "Failed to delete the college record.");
        return;
    }
    loadProgramPage(currentProgramPage);

    db.commit();
}

void MainWindow::refreshAllTables()
{
    loadStudentPage(currentStudentPage);
    loadProgramPage(currentProgramPage);
    loadCollegePage(currentCollegePage);
}


void MainWindow::replaceNullsInModel(QSqlQueryModel *model, const QString &replaceText)
{
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QVariant cellData = model->data(model->index(row, col));

            if (cellData.isNull() || cellData.toString().isEmpty()) {
                model->setData(model->index(row, col), replaceText);
            }
        }
    }
}

void MainWindow::on_Search_clicked()
{
    QString searchTerm = ui->SearchLine->text().trimmed();
    QString searchField = ui->Searchby->currentText();

    if (searchTerm.isEmpty()) {
        loadStudentPage(0);  // Reload all student data
        loadProgramPage(0);  // Reload all program data
        loadCollegePage(0);  // Reload all college data

        ui->StudentTable->setModel(studentQueryModel);
        ui->ProgTable->setModel(programQueryModel);
        ui->CollegeTable->setModel(collegeQueryModel);

        QMessageBox::information(this, "Search Reset", "All data has been reloaded.");
        return;
    }

    bool found = false;
    QSqlQuery query;
    QString sqlQuery;

    int currentTabIndex = ui->TabTable->currentIndex();

    if (currentTabIndex == 0) {  // Student Tab
        if (searchField == "All Fields") {
            sqlQuery = "SELECT * FROM STUDENTS WHERE ID LIKE :searchTerm "
                       "OR FIRST_NAME LIKE :searchTerm "
                       "OR MIDDLE_NAME LIKE :searchTerm "
                       "OR LAST_NAME LIKE :searchTerm "
                       "OR YEAR_LEVEL LIKE :searchTerm "
                       "OR GENDER LIKE :searchTerm "
                       "OR PROGRAM_CODE LIKE :searchTerm";
        } else if (searchField == "ID") {
            sqlQuery = "SELECT * FROM STUDENTS WHERE ID LIKE :searchTerm";
        } else if (searchField == "First Name") {
            sqlQuery = "SELECT * FROM STUDENTS WHERE FIRST_NAME LIKE :searchTerm";
        } else if (searchField == "Middle Name") {
            sqlQuery = "SELECT * FROM STUDENTS WHERE MIDDLE_NAME LIKE :searchTerm";
        } else if (searchField == "Last Name") {
            sqlQuery = "SELECT * FROM STUDENTS WHERE LAST_NAME LIKE :searchTerm";
        } else if (searchField == "Year Level") {
            sqlQuery = "SELECT * FROM STUDENTS WHERE YEAR_LEVEL LIKE :searchTerm";
        } else if (searchField == "Gender") {
            sqlQuery = "SELECT * FROM STUDENTS WHERE GENDER LIKE :searchTerm";
        } else if (searchField == "Program Code") {
            sqlQuery = "SELECT * FROM STUDENTS WHERE PROGRAM_CODE LIKE :searchTerm";
        }
    }
    else if (currentTabIndex == 1) {  // Program Tab
        if (searchField == "All Fields") {
            sqlQuery = "SELECT * FROM PROGRAM WHERE PROGRAM_CODE LIKE :searchTerm "
                       "OR PROGRAM_NAME LIKE :searchTerm "
                       "OR COLLEGE_CODE LIKE :searchTerm";
        } else if (searchField == "Program Code") {
            sqlQuery = "SELECT * FROM PROGRAM WHERE PROGRAM_CODE LIKE :searchTerm";
        } else if (searchField == "Program Name") {
            sqlQuery = "SELECT * FROM PROGRAM WHERE PROGRAM_NAME LIKE :searchTerm";
        } else if (searchField == "College Code") {
            sqlQuery = "SELECT * FROM PROGRAM WHERE COLLEGE_CODE LIKE :searchTerm";
        }
    }
    else if (currentTabIndex == 2) {  // College Tab
        if (searchField == "All Fields") {
            sqlQuery = "SELECT * FROM COLLEGE WHERE COLLEGE_CODE LIKE :searchTerm "
                       "OR COLLEGE_NAME LIKE :searchTerm";
        } else if (searchField == "College Code") {
            sqlQuery = "SELECT * FROM COLLEGE WHERE COLLEGE_CODE LIKE :searchTerm";
        } else if (searchField == "College Name") {
            sqlQuery = "SELECT * FROM COLLEGE WHERE COLLEGE_NAME LIKE :searchTerm";
        }
    }

    query.prepare(sqlQuery);
    query.bindValue(":searchTerm", "%" + searchTerm + "%");

    if (query.exec()) {
        found = true;

        QStandardItemModel *model = new QStandardItemModel(this);
        QSqlRecord record = query.record();
        int columnCount = record.count();
        model->setColumnCount(columnCount);

        for (int i = 0; i < columnCount; ++i) {
            model->setHeaderData(i, Qt::Horizontal, record.fieldName(i));
        }

        while (query.next()) {
            QList<QStandardItem*> rowItems;
            for (int i = 0; i < columnCount; ++i) {
                QStandardItem *item = new QStandardItem(query.value(i).toString());
                rowItems.append(item);
            }
            model->appendRow(rowItems);
        }

        if (currentTabIndex == 0) {
            ui->StudentTable->setModel(model);
        } else if (currentTabIndex == 1) {
            ui->ProgTable->setModel(model);
        } else if (currentTabIndex == 2) {
            ui->CollegeTable->setModel(model);
        }
    } else {
        QMessageBox::warning(this, "Search", "Failed to execute search query: " + query.lastError().text());
    }

    if (!found) {
        QMessageBox::information(this, "Search", "No matching records found based on the selected search field.");
    }
}

void MainWindow::on_TabTable_currentChanged(int index)
{
    ui->Searchby->clear();

    if (index == 0) { // Student Tab
        ui->Searchby->addItems({
            "All Fields", "ID", "First Name", "Middle Name",
            "Last Name", "Year Level", "Gender", "Program Code"
        });
    }
    else if (index == 1) { // Program Tab
        ui->Searchby->addItems({
            "All Fields", "Program Code", "Program Name", "College Code"
        });
    }
    else if (index == 2) { // College Tab
        ui->Searchby->addItems({
            "All Fields", "College Code", "College Name"
        });
    }
    ui->Searchby->setCurrentIndex(0);
}

void MainWindow::on_RefreshButton_clicked()
{
    loadStudentPage(currentStudentPage);
    loadProgramPage(currentProgramPage);
    loadCollegePage(currentCollegePage);

    ui->SearchLine->clear();
}
