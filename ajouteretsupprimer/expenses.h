#ifndef EXPENSES_H
#define EXPENSES_H

#include <QString>
#include <QLineEdit>
#include <QSqlQuery>
#include <QSqlQueryModel>
class expenses
{
public:
    expenses();
    expenses(int,int,QString,QString);


    int getIDE(){return ide;}
    int getExpenses(){return expense;}
    QString getDatee(){return datee;}
    QString getDescription(){return description;}

    bool ajouterExpense();
    QSqlQueryModel * afficherExpense();
    bool supprimerExpense(int);
    bool modifierExpense(int,int,QString,QString);
    QSqlQueryModel * afficher_tri_descexpense();

private:
    int ide,expense;
    QString datee,description;
};

#endif // EXPENSES_H
