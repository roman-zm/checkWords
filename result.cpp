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
//        ui->tableWidget->setItem(i,1, new QTableWidgetItem(words[i]));
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
    if(word == rightWords[number])
        ui->tableWidget->itemAt(number, 0)->setBackgroundColor(Qt::green);
    else
        ui->tableWidget->itemAt(number, 0)->setBackgroundColor(Qt::red);
}

result::~result()
{
    delete ui;
}
