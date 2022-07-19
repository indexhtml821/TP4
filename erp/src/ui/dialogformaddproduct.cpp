#include "dialogformaddproduct.h"
#include "ui_dialogformaddproduct.h"
#include <QPushButton>

DialogformAddProduct::DialogformAddProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogformAddProduct)
{
    ui->setupUi(this);
    ui->lineEditName->setMaxLength(20);
    ui->lineEditID->setText("Write an Id(number) not used");
    ui->lineEditAmount->setText("Only numbers are admitted");
    ui->lineEditName->setText("Write the product name");
}

DialogformAddProduct::~DialogformAddProduct()
{
    delete ui;

}


void DialogformAddProduct::loadInformation(int id, string name, int amount){


}
int DialogformAddProduct::getId(){

 QString stringId = this->ui->lineEditID->text();
 int id = stringId.toInt();
 return id;

}
string DialogformAddProduct::getName(){

    QString stringName = this->ui->lineEditName->text();
    string name = stringName.toStdString();
    return name;
}
int DialogformAddProduct::getAmount(){
    QString stringAmount = this->ui->lineEditAmount->text();
    int amount = stringAmount.toInt();
    return amount;
}

void DialogformAddProduct::on_lineEditID_editingFinished()
{
    QString stringCheck = this->ui->lineEditID->text();
    bool ok = false;
    stringCheck.toInt(&ok);

    if(!ok){
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }else{
         ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}


void DialogformAddProduct::on_lineEditAmount_editingFinished()
{
    QString stringCheck = this->ui->lineEditAmount->text();
    bool ok = false;
    stringCheck.toInt(&ok);

    if(!ok){
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }else{
         ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}


void DialogformAddProduct::on_lineEditName_editingFinished()
{
    QString stringCheck = this->ui->lineEditName->text();

    if(stringCheck.trimmed().isEmpty()){

        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }else{

        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

