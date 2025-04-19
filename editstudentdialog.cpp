#include "editstudentdialog.h"
#include "ui_editstudentdialog.h"
#include <QMessageBox>
#include "mainwindow.h"


EditStudentDialog::EditStudentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditStudentDialog)
{
    ui->setupUi(this);
    ui->IDline->setReadOnly(true);

    connect(ui->UpdateStudent, &QPushButton::clicked, this, &EditStudentDialog::on_UpdateStudent_clicked);

}

EditStudentDialog::~EditStudentDialog()
{
    delete ui;
}

void EditStudentDialog::setStudentData(const QString &id, const QString &fname, const QString &mname, const QString &lname,
                                       int year, const QString &gender, const QString &course)
{
    ui->IDline->setText(id);
    ui->IDline->setDisabled(true);

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
    QString id = getID();
    QString fname = getFirstName();
    QString mname = getMiddleName();
    QString lname = getLastName();
    int year = getYearLevel();
    QString gender = getGender();
    QString course = getProgramCode();

    MainWindow *mainWindow = qobject_cast<MainWindow *>(parent());
    if (mainWindow) {
        mainWindow->updateStudentInDatabase(id, fname, mname, lname, year, gender, course);
    } else {
        QMessageBox::warning(this, "Error", "Unable to access MainWindow.");
    }

    accept();
}
