#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../.././library/local_store/store.h"
#include "../.././library/local_store/exceptionIdNotAllowed.h""
#include "../.././library/local_store/exceptionProductNameIsTaken.h".h""
#include "dialogformaddproduct.h"

#include <string>
#include <fstream>
#include <sstream>
#include <QMessageBox>
#include <QFileDialog>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditStoreName->setMaxLength(15);
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

    QString fileName = QFileDialog::getSaveFileName(this,
              "Load data file", "",
              tr("data file (*.dat);;All Files (*)"));
    vector<Product*> listOfProducts;

   if(fileName != ""){
     string name = fileName.toStdString();

    ifstream fileLoad;
    fileLoad.open(name, ios::in | ios::binary);
    if (!fileLoad.is_open())
       {

        QMessageBox *msgbox = new QMessageBox(this);
              msgbox->setWindowTitle("Warning message");
              msgbox->setText("file couldnt be opened");
              msgbox->open();

       }else{

     ui->showProducts->clear();
     this->store.cleanStoreStock();
     this->store.loadFromBinaryFile(&fileLoad);
     fileLoad.close();


     this->ui->lineEditStoreName->setText(this->store.storeName);
     this->ui->lineEditInternetAdress->setText(this->store.internetAddress);
     this->ui->lineEditLocation->setText(this->store.location);
     this->ui->lineEditPhoneNumber->setText(this->store.phoneNumber);

     listOfProducts = this->store.listProducts();

     for (Product *productRead : listOfProducts)
       {

         ostringstream productInfo;
         productInfo <<productRead;
         string stringProductInfo = productInfo.str();
         QString qstringProductInfo = QString::fromStdString(stringProductInfo);

         QListWidgetItem *newItem = new QListWidgetItem(qstringProductInfo);
         newItem->setData(1, productRead->getId());
         this->ui->showProducts->addItem(newItem);
       }


    }

   }
}

void MainWindow::on_saveStoreB_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this,
               "Guardar archivo de datos", "",
               tr("data file (*.dat);;All Files (*)"));
    string name = fileName.toStdString();

    if (fileName != "")
       {
        ofstream storageFile;
        storageFile.open(name, ios::in | ios::binary);
        if (!storageFile.is_open())
           {

            QMessageBox *msgbox = new QMessageBox(this);
                  msgbox->setWindowTitle("Warning message");
                  msgbox->setText("file couldnt be opened");
                  msgbox->open();

           }else{
            /*
            string ip,
            string location,
            string phoneNumber*/
            string storeName = this->ui->lineEditStoreName->text().toStdString();
            string storeInternetAddress = this->ui->lineEditInternetAdress->text().toStdString();
            string storeLocation = this->ui->lineEditLocation->text().toStdString();
            string storePhoneNumber = this->ui->lineEditPhoneNumber->text().toStdString();

            this->store.modifyStoreInfo(storeName,storeInternetAddress,storeLocation,storePhoneNumber);

            this->store.storetoBinaryFile(&storageFile);
            storageFile.close();

        }


    }

}

void MainWindow::on_addProductB_clicked()
{
    DialogformAddProduct formAddProduct;
    int result = formAddProduct.exec();

    int prodId =formAddProduct.getId();
    int prodAmount =formAddProduct.getAmount();
    string prodName =formAddProduct.getName();
    int validate =0;


  if (result == QDialog::Accepted){

      Product *product = new Product(prodId, prodAmount ,
                                        prodName);
      try{
      this->store.addProduct(product);
      }catch (ExceptionIdNotAllowed &e){

                validate = 1;
          QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Warning message");
                msgbox->setText("Id key is already under use or is negative id");
                msgbox->open();


      }catch(ExceptionProductNameIsTaken &e){

                validate = 1;
          QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Warning Message");
                msgbox->setText("Product already exists");
                msgbox->open();
      }

      if(validate ==0){
      ostringstream productInfo;
      productInfo <<product;
      string stringProductInfo = productInfo.str();
      QString qstringProductInfo = QString::fromStdString(stringProductInfo);

      QListWidgetItem *newItem = new QListWidgetItem(qstringProductInfo);
      newItem->setData(1, prodId);
      this->ui->showProducts->addItem(newItem);
      }


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


void MainWindow::on_modifyProductB_clicked()
{
    QListWidgetItem *selectedItem= this->ui->showProducts->currentItem();

    DialogformAddProduct formAddProduct;


       if (selectedItem == nullptr)
       {
           // no item has been selected
           QMessageBox *msgbox = new QMessageBox(this);
           msgbox->setWindowTitle("Warning message");
           msgbox->setText("No item has been selected from the products panel");
           msgbox->open();
       }else {

           QString productSelected = selectedItem->data(1).toString();
           int id = productSelected.toInt();
           string name = this->store.getProductName(id);
           int amount = this->store.getProductAmount(id);


           formAddProduct.loadInformation(id,name,amount);

           int result =formAddProduct.exec();

           string prodName =formAddProduct.getName();
           int prodAmount =formAddProduct.getAmount();

           if(result == QDialog::Accepted){

             try{
               this->store.modifyProductName(id,prodName);
               }catch(ExceptionProductNameIsTaken &e){

                   QMessageBox *msgbox = new QMessageBox(this);
                   msgbox->setWindowTitle("Warning message");
                   msgbox->setText("Product already exists");
                   msgbox->open();

               }
               this->store.modifyProductAmount(id,prodAmount);
               QString modifiedInfo = QString::fromStdString(this->store.getProductInfo(id));

               selectedItem->setText(modifiedInfo);

           }




       }
}



