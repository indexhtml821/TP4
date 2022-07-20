#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../.././library/local_store/store.h"
#include "dialogformaddproduct.h"

#include <string>
#include <fstream>
#include <sstream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_addProduct_clicked()
{
    DialogformAddProduct formAddProduct;
    formAddProduct.exec();


}

bool MainWindow::check_File(ifstream * stream){





      if (! stream->is_open())
      {
        return false;

      }else {
          return true;
      }
}


void MainWindow::on_loadStoreb_clicked()
{
    ifstream fileLoad;
    if(check_File(&fileLoad)){

    }else{
    fileLoad.open("test_file.dat", ios::in | ios::binary);
    this->store.loadFromBinaryFile(&fileLoad);
  }
}


void MainWindow::on_addProductB_clicked()
{
    DialogformAddProduct formAddProduct;


    int result = formAddProduct.exec();

    int prodId =formAddProduct.getId();
    int prodAmount =formAddProduct.getAmount();
    string prodName =formAddProduct.getName();


     if(store.idIstaken(prodId)){

         QMessageBox *msgbox = new QMessageBox(this);
               msgbox->setWindowTitle("Warning message");
               msgbox->setText("Id key is already under use");
               msgbox->open();

  } else if(store.productAlreadyExists(prodName)){

         QMessageBox *msgbox = new QMessageBox(this);
               msgbox->setWindowTitle("Warning Message");
               msgbox->setText("Product already exists");
               msgbox->open();

  }    else if (result == QDialog::Accepted){

      Product *product = new Product(prodId, prodAmount ,
                                        prodName);
      this->store.addProduct(product);
     // int listCount = this->ui->showProducts->count();
      ostringstream productInfo;
      productInfo <<product;
      string stringProductInfo = productInfo.str();
      QString qstringProductInfo = QString::fromStdString(stringProductInfo);

      QListWidgetItem *newItem = new QListWidgetItem(qstringProductInfo);
      newItem->setData(1, prodId);
      this->ui->showProducts->addItem(newItem);


      }




}


void MainWindow::on_deleteProductB_clicked()
{

    QListWidgetItem *selectedItem= this->ui->showProducts->currentItem();

       if (selectedItem == nullptr)
       {
           // no item has been selected
           QMessageBox *msgbox = new QMessageBox(this);
           msgbox->setWindowTitle("Warning message");
           msgbox->setText("No item has been selected from the products panel");
           msgbox->open();
       }else{

           QString productSelected = selectedItem->data(1).toString();
           int id = productSelected.toInt();
           this->store.deleteProduct(id);
           qDeleteAll(ui->showProducts->selectedItems());


       }

}
