#include "editcollegedialog.h"
#include "ui_editcollegedialog.h"
#include "mainwindow.h"
#include <QMessageBox>

EditCollegeDialog::EditCollegeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditCollegeDialog)
{
    ui->setupUi(this);
}

EditCollegeDialog::~EditCollegeDialog()
{
    delete ui;
}

void EditCollegeDialog::setCollegeData(const QString &collegeCode, const QString &collegeName)
{
    ui->CollegeCodeLine->setText(collegeCode);
    ui->CollegeCodeLine->setDisabled(true);  // Make it read-only
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
    QString code = getCollegeCode();
    QString name = getCollegeName();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "College name cannot be empty.");
        return;
    }

    MainWindow *mainWindow = qobject_cast<MainWindow *>(parent());
    if (mainWindow) {
        mainWindow->updateCollegeInDatabase(code, name);
    }

    accept(); // Close the dialog
}
