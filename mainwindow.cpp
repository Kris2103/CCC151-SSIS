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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadStudentPage(int page) {
    int limit = 15;
    int offset = page * limit;
    studentQueryModel = new QSqlQueryModel(this);

    QStringList columns = {"ID", "FIRST_NAME", "MIDDLE_NAME", "LAST_NAME", "YEAR_LEVEL", "GENDER", "PROGRAM_CODE"};

    QString query = QString("SELECT ID, FIRST_NAME, MIDDLE_NAME, LAST_NAME, YEAR_LEVEL, GENDER, PROGRAM_CODE "
                            "FROM Students "
                            "ORDER BY %1 %2 "
                            "LIMIT %3 OFFSET %4")
                        .arg(columns.value(studentSortColumn, "ID"))  // Sorting column
                        .arg(studentSortOrder == Qt::AscendingOrder ? "ASC" : "DESC")  // Sorting order
                        .arg(rowsPerPage)  // Number of rows per page
                        .arg(offset);  // Pagination offset

    studentQueryModel->setQuery(query, db);
    if (studentQueryModel->lastError().isValid()) {
        qDebug() << "Query Error: " << studentQueryModel->lastError().text();
    }

    studentQueryModel->setHeaderData(0, Qt::Horizontal, "I.D. Number");
    studentQueryModel->setHeaderData(1, Qt::Horizontal, "First Name");
    studentQueryModel->setHeaderData(2, Qt::Horizontal, "Middle Name");
    studentQueryModel->setHeaderData(3, Qt::Horizontal, "Last Name");
    studentQueryModel->setHeaderData(4, Qt::Horizontal, "Year Level");
    studentQueryModel->setHeaderData(5, Qt::Horizontal, "Gender");
    studentQueryModel->setHeaderData(6, Qt::Horizontal, "Program Code");

    if (studentQueryModel->rowCount() > 0) {
        ui->StudentTable->setModel(studentQueryModel);
        ui->StudentTable->setSortingEnabled(true);
        ui->StudentTable->horizontalHeader()->setSortIndicator(studentSortColumn, studentSortOrder); // Enable sorting on the header
    } else {
        qDebug() << "No data to display in the Student table.";
    }
}


void MainWindow::loadProgramPage(int page) {
    int offset = page * rowsPerPage;
    programQueryModel = new QSqlQueryModel(this);

    QStringList columns = {"CODE", "NAME", "COLLEGE_CODE"};
    QString orderBy = columns.value(programSortColumn, "CODE");
    QString order = (programSortOrder == Qt::AscendingOrder) ? "ASC" : "DESC";

    QString query = QString("SELECT CODE, NAME, COLLEGE_CODE FROM PROGRAM ORDER BY %1 %2 LIMIT %3 OFFSET %4")
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
}

void MainWindow::loadCollegePage(int page) {
    int offset = page * rowsPerPage;
    collegeQueryModel = new QSqlQueryModel(this);

    QStringList columns = {"CODE", "NAME"};
    QString orderBy = columns.value(collegeSortColumn, "CODE");
    QString order = (collegeSortOrder == Qt::AscendingOrder) ? "ASC" : "DESC";

    QString query = QString("SELECT CODE, NAME FROM COLLEGE ORDER BY %1 %2 LIMIT %3 OFFSET %4")
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
    checkProgram.prepare("SELECT COUNT(*) FROM PROGRAM WHERE CODE = :code");
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
        INSERT INTO Students (ID, FIRST_NAME, MIDDLE_NAME, LAST_NAME, YEAR_LEVEL, GENDER, PROGRAM_CODE)
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
    studentSortOrder = Qt::AscendingOrder;
    loadStudentPage(currentStudentPage);

    QMessageBox::information(this, "Success", "Student successfully added.");
}



void MainWindow::insertProgramToDatabase(const QString &code, const QString &name, const QString &collegeCode)
{
    QSqlQuery checkCollege(db);
    checkCollege.prepare("SELECT COUNT(*) FROM COLLEGE WHERE CODE = :collegeCode");
    checkCollege.bindValue(":collegeCode", collegeCode);
    if (!checkCollege.exec() || !checkCollege.next() || checkCollege.value(0).toInt() == 0) {
        QMessageBox::critical(this, "Invalid College Code", "Selected college code does not exist.");
        return;
    }

    QSqlQuery checkProgram(db);
    checkProgram.prepare("SELECT COUNT(*) FROM PROGRAM WHERE CODE = :code");
    checkProgram.bindValue(":code", code);
    if (!checkProgram.exec() || !checkProgram.next() || checkProgram.value(0).toInt() > 0) {
        QMessageBox::critical(this, "Duplicate Program", "A program with this code already exists.");
        return;
    }

    // Insert program
    QSqlQuery insert(db);
    insert.prepare(R"(
        INSERT INTO PROGRAM (CODE, NAME, COLLEGE_CODE)
        VALUES (:code, :name, :collegeCode)
    )");
    insert.bindValue(":code", code);
    insert.bindValue(":name", name);
    insert.bindValue(":collegeCode", collegeCode);

    if (!insert.exec()) {
        QMessageBox::critical(this, "Insertion Error", insert.lastError().text());
        return;
    }

    currentProgramPage = 0;
    programSortColumn = 0;
    programSortOrder = Qt::AscendingOrder;
    loadProgramPage(currentProgramPage);

    QMessageBox::information(this, "Success", "Program added successfully.");
}


void MainWindow::insertCollegeToDatabase(const QString &code, const QString &name)
{
    QSqlQuery checkCollege(db);
    checkCollege.prepare("SELECT COUNT(*) FROM COLLEGE WHERE CODE = :code");
    checkCollege.bindValue(":code", code);
    if (!checkCollege.exec() || !checkCollege.next() || checkCollege.value(0).toInt() > 0) {
        QMessageBox::critical(this, "Duplicate College", "A college with this code already exists.");
        return;
    }

    // Insert
    QSqlQuery insert(db);
    insert.prepare(R"(
        INSERT INTO COLLEGE (CODE, NAME)
        VALUES (:code, :name)
    )");
    insert.bindValue(":code", code);
    insert.bindValue(":name", name);

    if (!insert.exec()) {
        QMessageBox::critical(this, "Insertion Error", insert.lastError().text());
        return;
    }

    currentCollegePage = 0;
    collegeSortColumn = 0;
    collegeSortOrder = Qt::AscendingOrder;
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

        // Retrieve the student data from the table
        QString id = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 0)).toString(); // ID (column 0)
        QString fname = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 1)).toString(); // First Name
        QString mname = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 2)).toString(); // Middle Name
        QString lname = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 3)).toString(); // Last Name
        int year = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 4)).toInt(); // Year Level
        QString gender = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 5)).toString(); // Gender
        QString course = ui->StudentTable->model()->data(ui->StudentTable->model()->index(selectedRow, 6)).toString(); // Program Code

        // Open Edit Student Dialog
        EditStudentDialog dialog(this);
        dialog.setStudentData(id, fname, mname, lname, year, gender, course);

        if (dialog.exec() == QDialog::Accepted) {
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

        // Retrieve the program data from the table
        QString code = ui->ProgTable->model()->data(ui->ProgTable->model()->index(selectedRow, 0)).toString(); // Program Code (column 0)
        QString name = ui->ProgTable->model()->data(ui->ProgTable->model()->index(selectedRow, 1)).toString(); // Program Name
        QString collegeCode = ui->ProgTable->model()->data(ui->ProgTable->model()->index(selectedRow, 2)).toString(); // College Code

        // Open Edit Program Dialog
        EditProgramDialog dialog(this);
        dialog.setProgramData(code, name, collegeCode);

        if (dialog.exec() == QDialog::Accepted) {
            QString newName = dialog.getProgramName();
            QString newCollegeCode = dialog.getCollegeCode();

            updateProgramInDatabase(code, newName, newCollegeCode);
        }
    }
    else if (currentTab == 2) {  // College tab
        int selectedRow = ui->CollegeTable->selectionModel()->currentIndex().row();
        if (selectedRow < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a college to edit.");
            return;
        }

        // Retrieve the college data from the table
        QString code = ui->CollegeTable->model()->data(ui->CollegeTable->model()->index(selectedRow, 0)).toString(); // College Code (column 0)
        QString name = ui->CollegeTable->model()->data(ui->CollegeTable->model()->index(selectedRow, 1)).toString(); // College Name

        // Open Edit College Dialog
        EditCollegeDialog dialog(this);
        dialog.setCollegeData(code, name);

        if (dialog.exec() == QDialog::Accepted) {
            QString newName = dialog.getCollegeName();

            updateCollegeInDatabase(code, newName);
        }
    }
}

void MainWindow::updateStudentInDatabase(const QString &id, const QString &fname, const QString &mname, const QString &lname,
                                         int year, const QString &gender, const QString &course)
{
    QSqlQuery query;
    query.prepare("UPDATE students SET first_name = :fname, middle_name = :mname, last_name = :lname, year_level = :year, gender = :gender, program_code = :course WHERE id = :id");
    query.bindValue(":fname", fname);
    query.bindValue(":mname", mname);
    query.bindValue(":lname", lname);
    query.bindValue(":year", year);
    query.bindValue(":gender", gender);
    query.bindValue(":course", course);
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::warning(this, "Update Error", "Failed to update student in database: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Student updated successfully!");
    }
}


void MainWindow::updateProgramInDatabase(const QString &programCode, const QString &programName, const QString &collegeCode)
{
    QSqlQuery update(db);
    update.prepare(R"(
        UPDATE Programs
        SET PROGRAM_NAME = :pname,
            COLLEGE_CODE = :ccode
        WHERE PROGRAM_CODE = :pcode
    )");

    update.bindValue(":pname", programName);
    update.bindValue(":ccode", collegeCode);
    update.bindValue(":pcode", programCode);

    if (!update.exec()) {
        QMessageBox::critical(this, "Update Error", update.lastError().text());
        return;
    }

    loadProgramPage(currentProgramPage);
    QMessageBox::information(this, "Success", "Program record updated.");
}
void MainWindow::updateCollegeInDatabase(const QString &collegeCode, const QString &collegeName)
{
    QSqlQuery update(db);
    update.prepare(R"(
        UPDATE Colleges
        SET COLLEGE_NAME = :cname
        WHERE COLLEGE_CODE = :ccode
    )");

    update.bindValue(":cname", collegeName);
    update.bindValue(":ccode", collegeCode);

    if (!update.exec()) {
        QMessageBox::critical(this, "Update Error", update.lastError().text());
        return;
    }

    loadCollegePage(currentCollegePage);
    QMessageBox::information(this, "Success", "College record updated.");
}

