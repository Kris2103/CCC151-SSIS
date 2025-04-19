#ifndef ADDCOLLEGEDIALOG_H
#define ADDCOLLEGEDIALOG_H

#include <QDialog>

namespace Ui {
class AddCollegeDialog;
}

class AddCollegeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCollegeDialog(QWidget *parent = nullptr);
    ~AddCollegeDialog();

    QString getCollegeCode() const;
    QString getCollegeName() const;

private:
    Ui::AddCollegeDialog *ui;
};

#endif // ADDCOLLEGEDIALOG_H
