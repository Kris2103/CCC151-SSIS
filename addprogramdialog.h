#ifndef ADDPROGRAMDIALOG_H
#define ADDPROGRAMDIALOG_H

#include <QDialog>

namespace Ui {
class AddProgramDialog;
}

class AddProgramDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProgramDialog(QWidget *parent = nullptr);
    ~AddProgramDialog();

    QString getProgramCode() const;
    QString getProgramName() const;
    QString getCollegeCode() const;

private:
    Ui::AddProgramDialog *ui;
};

#endif // ADDPROGRAMDIALOG_H
