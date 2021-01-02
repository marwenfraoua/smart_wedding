#include "expenses.h"

expenses::expenses()
{
    this->ide=0;
    this->expense=0;
    this->datee="";
}

expenses::expenses(int ide,int expense,QString datee,QString description)
{
    this->ide=ide;
    this->expense=expense;
    this->datee=datee;
    this->description=description;
}

bool expenses::ajouterExpense(){

    QSqlQuery query;

    query.prepare("insert into expenses (ide,expense,datee,description)"
                  "values(:ide,:expense,:datee,:description)");
    QString ids=QString::number(ide);
    QString expenses_t=QString::number(expense);


    query.bindValue(":ide",ids);
    query.bindValue(":expense",expenses_t);
    query.bindValue(":datee",datee);
    query.bindValue(":description",description);

    return query.exec();
}

QSqlQueryModel * expenses::afficherExpense(){

    QSqlQueryModel * query = new QSqlQueryModel();

    query->setQuery("select * from expenses");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("IDe"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("description"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("expenses"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("date"));
    return query;

}

bool expenses::supprimerExpense(int idd)
{
    QSqlQuery query;

    query.prepare("Delete from expenses where ide=:ide");
    QString idds=QString::number(idd);
    query.bindValue(":ide",idds);
    return query.exec();

}

bool expenses::modifierExpense(int ide,int expense,QString datee,QString description)
{
    QSqlQuery query;

    query.prepare("UPDATE expenses  SET  expense=:expense , datee = :datee , description=:description WHERE ide = :ide");

    query.bindValue(":ide",ide);
    query.bindValue(":expense",expense);
    query.bindValue(":datee",datee);
    query.bindValue(":description",description);

    return query.exec();

}

QSqlQueryModel * expenses::afficher_tri_descexpense(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from expenses ORDER BY description");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("IDe"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("description"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("expenses"));
    query->setHeaderData(3,Qt::Horizontal,QObject::tr("date"));
    return query;

}
