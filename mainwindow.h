#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void insertStudentToDatabase(const QString &id, const QString &firstName, const QString &middleName,
                                 const QString &lastName, int yearLevel, const QString &gender,
                                 const QString &programCode);  // Declare the function

    void insertProgramToDatabase(const QString &programCode, const QString &programName, const QString &collegeCode);

    void insertCollegeToDatabase(const QString &collegeCode, const QString &collegeName);

    void updateStudentInDatabase(const QString &id, const QString &fname, const QString &mname, const QString &lname,
                                 int year, const QString &gender, const QString &course);

    void updateProgramInDatabase(const QString &programCode, const QString &programName, const QString &collegeCode);

    void updateCollegeInDatabase(const QString &collegeCode, const QString &collegeName);

private slots:
    void refreshStudentTable();
    void refreshProgramTable();
    void refreshCollegeTable();
    void on_Add_clicked();

    void nextStudentPage();
    void prevStudentPage();
    void nextProgramPage();
    void prevProgramPage();
    void nextCollegePage();
    void prevCollegePage();

    void on_Edit_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;

    QSqlQueryModel *studentQueryModel;
    QSqlQueryModel *programQueryModel;
    QSqlQueryModel *collegeQueryModel;

    // Pagination variables
    int currentStudentPage;
    int currentProgramPage;
    int currentCollegePage;
    int rowsPerPage;

    int studentSortColumn;
    int programSortColumn;
    int collegeSortColumn;

    Qt::SortOrder studentSortOrder;
    Qt::SortOrder programSortOrder;
    Qt::SortOrder collegeSortOrder;

    void loadStudentPage(int page);
    void loadProgramPage(int page);
    void loadCollegePage(int page);

};
#endif // MAINWINDOW_H
