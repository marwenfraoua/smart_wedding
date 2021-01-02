#include "income.h"


income::income()
{
    this->id=0;
    this->income_i=0;
    this->date="";
}
income::income(int id,QString date,int income_i){

    this->id=id;
    this->income_i=income_i;
    this->date=date;
}
bool income::ajouter(){

    QSqlQuery query;

    query.prepare("insert into income (id,income_i,date_i)"
                  "values(:id,:income_i,:date)");
    QString ids=QString::number(id);
    QString income_t=QString::number(income_i);


    query.bindValue(":id",ids);
    query.bindValue(":income_i",income_t);
    query.bindValue(":date",date);

    return query.exec();
}

QSqlQueryModel * income::afficher(){

    QSqlQueryModel * query = new QSqlQueryModel();


    query->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Income"));
        query->setQuery("select * from income");
    return query;

}


bool income::supprimer(int idd)
{
    QSqlQuery query;

    query.prepare("Delete from income where id=:id");
    QString idds=QString::number(idd);
    query.bindValue(":id",idds);
    return query.exec();

}
bool income::modifier(int id, QString date, int income_i)
{
    QSqlQuery query;

    query.prepare("UPDATE income SET date_i = :date,income_i = :income_i WHERE id = :id");

    query.bindValue(":id",id);
    query.bindValue(":date",date);
    query.bindValue(":income_i",income_i);

    return query.exec();

}

QSqlQueryModel * income::afficher_tri_alphabetique(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from income ORDER BY income_i");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Income"));
    return query;

}
QSqlQueryModel * income::afficher_tri_desc(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from income ORDER BY income_i DESC");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("Income"));
    return query;

}


