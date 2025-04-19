#ifndef EDITCOLLEGEDIALOG_H
#define EDITCOLLEGEDIALOG_H

#include <QDialog>

namespace Ui {
class EditCollegeDialog;
}

class EditCollegeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCollegeDialog(QWidget *parent = nullptr);
    ~EditCollegeDialog();

    void setCollegeData(const QString &code, const QString &name);

    QString getCollegeName() const;
    QString getCollegeCode() const;

public slots:
    void on_UpdateCollege_clicked();


private:
    Ui::EditCollegeDialog *ui;
};

#endif // EDITCOLLEGEDIALOG_H
