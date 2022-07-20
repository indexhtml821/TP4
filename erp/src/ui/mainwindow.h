#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../.././library/local_store/store.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_addProduct_clicked();

    void on_loadStoreb_clicked();

    void on_addProductB_clicked();

    void on_deleteProductB_clicked();

    void on_modifyProductB_clicked();

    void on_saveStoreB_clicked();

private:
    Ui::MainWindow *ui;
    Store store;
    bool check_File(ifstream * stream);

};
#endif // MAINWINDOW_H
