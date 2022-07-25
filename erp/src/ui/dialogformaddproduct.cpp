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

    QString stringId = QString::number(id);
    this->ui->lineEditID->setReadOnly(true);
    this->ui->lineEditID->setText(stringId);

    QString stringName = QString::fromStdString(name);
    this->ui->lineEditName->setText(stringName);

    QString stringAmount = QString::number(amount);
    this->ui->lineEditAmount->setText(stringAmount);



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
    QString stringCheckId = this->ui->lineEditID->text();
    QString stringCheckAmount = this->ui->lineEditAmount->text();
    QString stringCheckName = this->ui->lineEditName->text();
    bool ok = false;
    bool ok1 = false;
    stringCheckId.toInt(&ok);
    stringCheckAmount.toInt(&ok1);

    checkLines( ok, ok1 , stringCheckName.trimmed().isEmpty());
}


void DialogformAddProduct::on_lineEditAmount_editingFinished()
{
    QString stringCheckId = this->ui->lineEditID->text();
    QString stringCheckAmount = this->ui->lineEditAmount->text();
    QString stringCheckName = this->ui->lineEditName->text();
    bool ok = false;
    bool ok1 = false;
    stringCheckId.toInt(&ok);
    stringCheckAmount.toInt(&ok1);

    checkLines( ok, ok1 , stringCheckName.trimmed().isEmpty());
}




void DialogformAddProduct::on_lineEditName_editingFinished()
{
    QString stringCheckId = this->ui->lineEditID->text();
    QString stringCheckAmount = this->ui->lineEditAmount->text();
    QString stringCheckName = this->ui->lineEditName->text();
    bool ok = false;
    bool ok1 = false;
    stringCheckId.toInt(&ok);
    stringCheckAmount.toInt(&ok1);

    checkLines( ok, ok1 , stringCheckName.trimmed().isEmpty());
}

void DialogformAddProduct:: checkLines(bool isInt, bool isInt2,bool filled){


    if(!isInt || !isInt2 || filled){
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }else{
         ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }

}
