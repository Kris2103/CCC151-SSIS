#ifndef EDITPROGRAMDIALOG_H
#define EDITPROGRAMDIALOG_H

#include <QDialog>

namespace Ui {
class EditProgramDialog;
}

class EditProgramDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditProgramDialog(QWidget *parent = nullptr);
    ~EditProgramDialog();

    void setProgramData(const QString &code, const QString &name, const QString &collegeCode);

    QString getProgramCode() const;
    QString getProgramName() const;
    QString getCollegeCode() const;


private slots:
    void on_UpdateProgram_clicked();

private:
    Ui::EditProgramDialog *ui;
};

#endif // EDITPROGRAMDIALOG_H
