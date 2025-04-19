#include "addcollegedialog.h"
#include "ui_addcollegedialog.h"

AddCollegeDialog::AddCollegeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCollegeDialog)
{
    ui->setupUi(this);

    connect(ui->AddCollege_2, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->CancelCollege, &QPushButton::clicked, this, &QDialog::reject);
}

AddCollegeDialog::~AddCollegeDialog()
{
    delete ui;
}
QString AddCollegeDialog::getCollegeCode() const
{
    return ui->CollegeCodeLine->text().trimmed();
}

QString AddCollegeDialog::getCollegeName() const
{
    return ui->CollegeNameLine->text().trimmed();
}
