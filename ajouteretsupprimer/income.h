#ifndef INCOME_H
#define INCOME_H
#include <QString>
#include <QLineEdit>
#include <QSqlQuery>
#include <QSqlQueryModel>
class income
{
public:
    income();
    income(int,QString,int);


    int getID(){return id;}
    int getIncome(){return income_i;}
    QString getDate(){return date;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,int);
    QSqlQueryModel * afficher_tri_alphabetique();
    QSqlQueryModel * afficher_tri_desc();

private:
    int id;
    QString date;
    int income_i;
};

#endif // INCOME_H
