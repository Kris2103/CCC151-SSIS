#include "addprogramdialog.h"
#include "ui_addprogramdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QCompleter>

AddProgramDialog::AddProgramDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddProgramDialog)
{
    ui->setupUi(this);
    connect(ui->AddProgram_2, &QPushButton::clicked, this, &QDialog::accept);
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

    ui->CollegeCodeComboBox->addItems(collegeCodes);

    ui->CollegeCodeComboBox->setEditable(true);
    QCompleter *completer = new QCompleter(collegeCodes, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains); // allows search anywhere in string
    ui->CollegeCodeComboBox->setCompleter(completer);
     ui->CollegeCodeComboBox->setCurrentIndex(-1);

    if (collegeCodes.isEmpty()) {
        QMessageBox::warning(this, "No Colleges Found", "No college codes found in the database. Please add a college first.");
    }
}

AddProgramDialog::~AddProgramDialog()
{
    delete ui;
}
QString AddProgramDialog::getProgramCode() const
{
    return ui->ProgramCodeLine->text().trimmed();
}

QString AddProgramDialog::getProgramName() const
{
    return ui->ProgramNameLine->text().trimmed();
}

QString AddProgramDialog::getCollegeCode() const
{
    return ui->CollegeCodeComboBox->currentText().trimmed();
}
