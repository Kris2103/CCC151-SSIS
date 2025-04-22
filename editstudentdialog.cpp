#include "editstudentdialog.h"
#include "ui_editstudentdialog.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QCompleter>
#include "mainwindow.h"


EditStudentDialog::EditStudentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditStudentDialog)
{
    ui->setupUi(this);

    ui->IDline->setReadOnly(true);
    ui->IDline->setEnabled(false);

    connect(ui->UpdateStudent, &QPushButton::clicked, this, &EditStudentDialog::on_UpdateStudent_clicked);
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

EditStudentDialog::~EditStudentDialog()
{
    delete ui;
}

void EditStudentDialog::setStudentData(const QString &id, const QString &fname, const QString &mname, const QString &lname,
                                       int year, const QString &gender, const QString &course)
{
    ui->IDline->setText(id);
    ui->Firstnameline->setText(fname);
    ui->Middlenameline->setText(mname);
    ui->Lastnameline->setText(lname);
    ui->Yearlevelline->setCurrentText(QString::number(year));
    ui->Genderline->setCurrentText(gender);
    ui->CourseComboBox->setCurrentText(course);
}

QString EditStudentDialog::getID() const
{
    return ui->IDline->text().trimmed();
}

QString EditStudentDialog::getFirstName() const
{
    return ui->Firstnameline->text().trimmed();
}

QString EditStudentDialog::getMiddleName() const
{
    return ui->Middlenameline->text().trimmed();
}

QString EditStudentDialog::getLastName() const
{
    return ui->Lastnameline->text().trimmed();
}

int EditStudentDialog::getYearLevel() const
{
    return ui->Yearlevelline->currentText().toInt();
}

QString EditStudentDialog::getGender() const
{
    return ui->Genderline->currentText().trimmed();
}

QString EditStudentDialog::getProgramCode() const
{
    return ui->CourseComboBox->currentText().trimmed();
}

void EditStudentDialog::on_UpdateStudent_clicked()
{
    accept();
}
