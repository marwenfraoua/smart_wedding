#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::ouvrirConnexion()
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("marwen");
    db.setPassword("marwen");


    if(db.open())
        return true;
    return false;

}
void Connexion::fermerConnexion()
{db.close();}
