#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H

#include <QDialog>

namespace Ui {
class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudentDialog(QWidget *parent = nullptr);
    ~AddStudentDialog();

    QString getFirstName() const;
    QString getLastName() const;
    QString getID() const;
    QString getMiddleName() const;
    int getYearLevel() const;
    QString getGender() const;
    QString getProgramCode() const;


private slots:
    void on_AddDialog_clicked();

private:
    Ui::AddStudentDialog *ui;
};

#endif // ADDSTUDENTDIALOG_H
