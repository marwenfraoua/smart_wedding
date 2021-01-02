#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "income.h"
#include "expenses.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_rechercher_clicked();

    void on_tridescendant_clicked();

    void on_pdf_clicked();

    void on_pdf_2_clicked();

    void on_pushButton_ajout_expense_clicked();

    void on_pushButton_suppression_expense_clicked();

    void on_pushButton_modifier_expense_clicked();

    void on_tridescendant_2_clicked();

private:
    Ui::MainWindow *ui;
    income tempIncome;
    expenses tempExpense;
};
#endif // MAINWINDOW_H
