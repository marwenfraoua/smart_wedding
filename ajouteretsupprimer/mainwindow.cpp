#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "income.h"
#include "expenses.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QStringList>

#include <QPrinter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempIncome.afficher());
    ui->tableView_3->setModel(tempExpense.afficherExpense());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Ajouter_clicked()
{
    int idi=ui->lineEdit_ID->text().toInt();
    QString datei=ui->lineEdit_Nom->text();

    int income_i=ui->lineEdit_Prnom->text().toInt();
    income e(idi,datei,income_i);
    bool test=e.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout Income"),
                                 QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempIncome.afficher());
        ui->lineEdit_Nom->clear();
        ui->lineEdit_ID->clear();
        ui->lineEdit_Prnom->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout Income"),
                                 QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_Supprimer_clicked()
{
    int ide=ui->lineEdit_ID_Suppr->text().toInt();
    bool test=tempIncome.supprimer(ide);
    if(test){
        QMessageBox::information(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempIncome.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression etudiant"),
                                 QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_modifier_clicked()
{
    int idi=ui->lineEdit_ID_MOD->text().toInt();
    QString datei=ui->lineEdit_NOM_MOD->text();

    int income_i=ui->lineEdit_P_MOD->text().toInt();
    bool test=tempIncome.modifier(idi,datei,income_i);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modification etudiant"),
                                 QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempIncome.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification etudiant"),
                                 QObject::tr("modification échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_tri_clicked()
{
    ui->tableView->setModel(tempIncome.afficher_tri_alphabetique());
}

void MainWindow::on_pushButton_rechercher_clicked()
{
    QSqlQueryModel * model = new QSqlQueryModel();
            QSqlQuery query1;
            int ide=ui->lineEdit_r->text().toInt();
            query1.prepare("select * from income where id=:id");
            QString idds=QString::number(ide);
            query1.bindValue(":id",idds);
            query1.exec();
            model->setQuery(query1);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("Income"));
            ui->tableView_2->setModel(model);
            ui->lineEdit_r->clear();

}

void MainWindow::on_tridescendant_clicked()
{ui->tableView->setModel(tempIncome.afficher_tri_desc());
}

void MainWindow::on_pdf_clicked()
{

    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();
        for(int column = 0;column < columnCount; column++)
            if(!ui->tableView->isColumnHidden(column))
                out <<QString("<td>%1</td>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        for(int row = 0;row < rowCount; row++)
        {
            out <<"<tr>";
            for(int column = 0 ;column < columnCount ; column++)
            {
                if(!ui->tableView->isColumnHidden(column))
                {
                    QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);
        QPrinter printer;
        QPrintDialog *daddy = new QPrintDialog(&printer , NULL);
        if(daddy->exec() == QDialog::Accepted){
            document->print(&printer);
        }
        delete document;
}

void MainWindow::on_pdf_2_clicked()
{
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();
        for(int column = 0;column < columnCount; column++)
            if(!ui->tableView->isColumnHidden(column))
                out <<QString("<td>%1</td>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        for(int row = 0;row < rowCount; row++)
        {
            out <<"<tr>";
            for(int column = 0 ;column < columnCount ; column++)
            {
                if(!ui->tableView->isColumnHidden(column))
                {
                    QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
        }
        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);
        QPrinter printer;
        QPrintDialog *daddy = new QPrintDialog(&printer , NULL);
        if(daddy->exec() == QDialog::Accepted){
            document->print(&printer);
        }
        delete document;
}

void MainWindow::on_pushButton_ajout_expense_clicked()
{
    int ide=ui->lineEdit->text().toInt();
    int expensee=ui->lineEdit_4->text().toInt();
    QString datee=ui->lineEdit_2->text();
    QString description=ui->lineEdit_3->text();

    expenses e(ide,expensee,datee,description);
    bool test=e.ajouterExpense();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout Expense"),
                                 QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(tempExpense.afficherExpense());
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
         ui->lineEdit_4->clear();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout Expense"),
                                 QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pushButton_suppression_expense_clicked()
{
    int ide=ui->lineEdit_5->text().toInt();
    bool test=tempExpense.supprimerExpense(ide);
    if(test){
        QMessageBox::information(nullptr, QObject::tr("suppression expense"),
                                 QObject::tr("suppression avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(tempExpense.afficherExpense());
         ui->lineEdit_5->clear();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression expense"),
                                 QObject::tr("suppression échouée.\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_modifier_expense_clicked()
{
    int ide=ui->lineEdit_6->text().toInt();
    int expensee=ui->lineEdit_9->text().toInt();
    QString datee=ui->lineEdit_7->text();
    QString description=ui->lineEdit_8->text();

    bool test=tempExpense.modifierExpense(ide,expensee,datee,description);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modification etudiant"),
                                 QObject::tr("modification avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_3->setModel(tempExpense.afficherExpense());
        ui->lineEdit_6->clear();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification etudiant"),
                                 QObject::tr("modification échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tridescendant_2_clicked()
{
    ui->tableView_3->setModel(tempExpense.afficher_tri_descexpense());
}
