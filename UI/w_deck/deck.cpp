#include "deck.h"
#include "ui_deck.h"
#include <UI/w_cell/cell.h>
#include <QString>
<<<<<<< HEAD
#include <UI/w_login/loginwindow.h>
=======
#include <iostream>
#include <string>
#include <Qt>

>>>>>>> 93f530dfc291f046bc819d2cc51d6fdd8c31b4e9

Deck::Deck(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Deck)
{
    ui->setupUi(this);
    addTab("YourNewColumn");

}

Deck::~Deck()
{
    delete ui;
}

void Deck::setInfoLabels(QString Name, QString Type, QString Owners)
{
    ui->Name_label->setText(Name);
    ui->Type_label->setText(Type);
    ui->Owners_label->setText(Owners);
}

void Deck::addTab(QString TabName)
{
    NewTab *NewTabPtr = new NewTab(this);
    ui->tabWidget->addTab(NewTabPtr, TabName);
    NewTabPtr->setAttribute(Qt::WA_DeleteOnClose, true);

    allTabPtrs.append(NewTabPtr);
}

void Deck::on_btn_add_column_clicked()
{
    addTab(QString("Tab %0").arg(ui->tabWidget->count()+1));

}

void Deck::on_tabWidget_tabCloseRequested(int index)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Delete This Tab?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes){
        qDebug()<<"Removing tab of index:"<<index;
        allTabPtrs[index]->close();
        ui->tabWidget->removeTab(index);

        allTabPtrs.remove(index);
    }

    if(allTabPtrs.length()==0){
        addTab("Default");
        ui->statusBar->showMessage("Added Default Tab",3000);
    }
}

void Deck::on_btn_back_clicked()
{
    close();
    LoginWindow::WindowList->show();
}


void Deck::on_btn_add_owner_clicked()
{

    std::cout << jsnBoard["Name"] << std::endl;
}


