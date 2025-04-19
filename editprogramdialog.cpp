#include "editprogramdialog.h"
#include "ui_editprogramdialog.h"

EditProgramDialog::EditProgramDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditProgramDialog)
{
    ui->setupUi(this);
}

EditProgramDialog::~EditProgramDialog()
{
    delete ui;
}

void EditProgramDialog::setProgramData(const QString &code, const QString &name, const QString &collegeCode)
{
    ui->ProgramCodeLine->setText(code);
    ui->ProgramCodeLine->setDisabled(true);

    ui->ProgramNameLine->setText(name);

    ui->CollegeCodeComboBox->setCurrentText(collegeCode);
}

QString EditProgramDialog::getProgramName() const
{
    return ui->ProgramNameLine->text().trimmed();
}

QString EditProgramDialog::getCollegeCode() const
{
    return ui->CollegeCodeComboBox->currentText().trimmed();
}
