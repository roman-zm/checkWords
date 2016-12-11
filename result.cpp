#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
}

void result::getWords(QStringList inpt)
{
    words = inpt;
    for(size_t i=0; i<words.size(); i++){
        ui->tableWidget->insertRow(i);
    }
}

void result::getRightWords(QStringList inpt)
{
    rightWords = inpt;
    for(size_t i=0; i<rightWords.size(); i++){
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(rightWords[i]));
    }
}

void result::addWord(QString word, unsigned int number)
{
    ui->tableWidget->setItem(number, 0, new QTableWidgetItem(word));
    if(!QString::localeAwareCompare(word, rightWords[number]))
        ui->tableWidget->item(number, 0)->setBackground(QBrush(Qt::darkGreen));
    else
        ui->tableWidget->item(number, 0)->setBackground(QBrush(Qt::red));
}

void result::clearTable()
{
    ui->tableWidget->clear();
//    if(ui->tableWidget->rowCount()!=0)
//        for(int i=ui->tableWidget->rowCount(); i<=0; i--)
//            ui->tableWidget->removeRow(i);
    ui->tableWidget->setRowCount(0);
}

result::~result()
{
    delete ui;
}

void result::on_pushButton_clicked()
{
    ui->tableWidget->item(3, 1)->setBackgroundColor(Qt::blue);
}
