#include "editprogramdialog.h"
#include "ui_editprogramdialog.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QCompleter>

EditProgramDialog::EditProgramDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditProgramDialog)
{
    ui->setupUi(this);

    ui->ProgramCodeLine->setReadOnly(true);
    ui->ProgramCodeLine->setEnabled(false);

    connect(ui->UpdateProgram, &QPushButton::clicked, this, &EditProgramDialog::on_UpdateProgram_clicked);
    connect(ui->CancelProgram, &QPushButton::clicked, this, &QDialog::reject);

    QStringList collegeCodes;
    QSqlQuery query;
    if (!query.exec("SELECT COLLEGE_CODE FROM COLLEGE ORDER BY COLLEGE_CODE ASC")) {
        QMessageBox::critical(this, "Database Error", "Failed to load college codes:\n" + query.lastError().text());
        return;
    }

    while (query.next()) {
        collegeCodes << query.value(0).toString();
    }

    //ui->CollegeCodeComboBox->addItem("");
    ui->CollegeCodeComboBox->addItems(collegeCodes);
    ui->CollegeCodeComboBox->setEditable(true);

    QCompleter *completer = new QCompleter(collegeCodes, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains); // allows search anywhere in string
    ui->CollegeCodeComboBox->setCompleter(completer);

    if (collegeCodes.isEmpty()) {
        QMessageBox::warning(this, "No Colleges Found", "No college codes found in the database. Please add a college first.");
    }
}

EditProgramDialog::~EditProgramDialog()
{
    delete ui;
}

void EditProgramDialog::setProgramData(const QString &programCode, const QString &programName, const QString &collegeCode)
{
    ui->ProgramCodeLine->setText(programCode);
    //ui->ProgramCodeLine->setDisabled(false);  // Make Program Code non-editable
    ui->ProgramNameLine->setText(programName);
    ui->CollegeCodeComboBox->setCurrentText(collegeCode);
}

QString EditProgramDialog::getProgramCode() const
{
    return ui->ProgramCodeLine->text().trimmed();
}

QString EditProgramDialog::getProgramName() const
{
    return ui->ProgramNameLine->text().trimmed();
}

QString EditProgramDialog::getCollegeCode() const
{
    return ui->CollegeCodeComboBox->currentText().trimmed();
}

void EditProgramDialog::on_UpdateProgram_clicked()
{
    accept();
}
