#include "addstudentdialog.h"
#include "ui_addstudentdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QCompleter>

AddStudentDialog::AddStudentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStudentDialog)
{
    ui->setupUi(this);

    connect(ui->AddStudent, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->CancelStudent, &QPushButton::clicked, this, &QDialog::reject);

    QSqlQuery query;
    if (!query.exec("SELECT PROGRAM_CODE FROM PROGRAM ORDER BY PROGRAM_CODE ASC")) {
        QMessageBox::critical(this, "Database Error", "Failed to load program codes:\n" + query.lastError().text());
        return;
    }

    QStringList programCodes;
    while (query.next()) {
        QString programCode = query.value(0).toString();
        programCodes << programCode;
    }

    ui->CourseComboBox->setEditable(true);
    QCompleter *completer = new QCompleter(programCodes, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    ui->CourseComboBox->setCompleter(completer);

    ui->CourseComboBox->addItems(programCodes);
    ui->CourseComboBox->setCurrentIndex(-1);
}

AddStudentDialog::~AddStudentDialog()
{
    delete ui;
}

QString AddStudentDialog::getFirstName() const
{
    return ui->Firstnameline->text().trimmed();
}

QString AddStudentDialog::getMiddleName() const
{
    return ui->Middlenameline->text().trimmed();
}

QString AddStudentDialog::getLastName() const
{
    return ui->Lastnameline->text().trimmed();
}

QString AddStudentDialog::getID() const
{
    return ui->IDline->text().trimmed();
}

int AddStudentDialog::getYearLevel() const
{
    return ui->Yearlevelline->currentText().toInt();
}

QString AddStudentDialog::getGender() const
{
    return ui->Genderline->currentText().trimmed();
}

QString AddStudentDialog::getProgramCode() const
{
    return ui->CourseComboBox->currentText().trimmed();
}

void AddStudentDialog::on_AddDialog_clicked()
{

}

