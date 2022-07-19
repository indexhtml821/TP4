#ifndef DIALOGFORMADDPRODUCT_H
#define DIALOGFORMADDPRODUCT_H

#include <QDialog>
using namespace std;

namespace Ui {
class DialogformAddProduct;
}

class DialogformAddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit DialogformAddProduct(QWidget *parent = nullptr);
    ~DialogformAddProduct();

    void loadInformation(int id, string name, int amount);
    int getId();
    string getName();
    int getAmount();

private slots:


    void on_lineEditID_editingFinished();

    void on_lineEditAmount_editingFinished();

    void on_lineEditName_editingFinished();

private:
    Ui::DialogformAddProduct *ui;
    int productId;
    int amount;
    char prodName[20];


};

#endif // DIALOGFORMADDPRODUCT_H
