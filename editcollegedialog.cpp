#include "editcollegedialog.h"
#include "ui_editcollegedialog.h"
#include "mainwindow.h"
#include <QMessageBox>

EditCollegeDialog::EditCollegeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditCollegeDialog)
{
    ui->setupUi(this);

    ui->CollegeCodeLine->setReadOnly(true);
    ui->CollegeCodeLine->setEnabled(false);

    connect(ui->UpdateCollege, &QPushButton::clicked, this, &EditCollegeDialog::on_UpdateCollege_clicked);
    connect(ui->CancelCollege, &QPushButton::clicked, this, &QDialog::reject);
}

EditCollegeDialog::~EditCollegeDialog()
{
    delete ui;
}

void EditCollegeDialog::setCollegeData(const QString &collegeCode, const QString &collegeName)
{
    ui->CollegeCodeLine->setText(collegeCode);
    ui->CollegeNameLine->setText(collegeName);
}

QString EditCollegeDialog::getCollegeCode() const
{
    return ui->CollegeCodeLine->text().trimmed();
}

QString EditCollegeDialog::getCollegeName() const
{
    return ui->CollegeNameLine->text().trimmed();
}

void EditCollegeDialog::on_UpdateCollege_clicked()
{
    accept();
}
