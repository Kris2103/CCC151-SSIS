#ifndef EDITSTUDENTDIALOG_H
#define EDITSTUDENTDIALOG_H
#include "mainwindow.h"


#include <QDialog>

namespace Ui {
class EditStudentDialog;
}

class EditStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditStudentDialog(QWidget *parent = nullptr);
    ~EditStudentDialog();

    void setStudentData(const QString &id, const QString &fname, const QString &mname, const QString &lname,
                   int year, const QString &gender, const QString &course);

    QString getID() const;
    QString getFirstName() const;
    QString getMiddleName() const;
    QString getLastName() const;
    int getYearLevel() const;
    QString getGender() const;
    QString getProgramCode() const;

private slots:
    void on_UpdateStudent_clicked();

private:
    Ui::EditStudentDialog *ui;
    MainWindow *mainWindow;
};

#endif // EDITSTUDENTDIALOG_H
