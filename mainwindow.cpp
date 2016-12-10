#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    currentWordNumber = 1;
//    path = QFileDialog::getOpenFileName(0, tr("Open file"), "", "*.txt");
//    QFile opndFile(path);
//    QTextStream in(&opndFile);
//    wordStr = in.readAll();
//    ui->textEdit->setText(wordStr);

    QString fileName = QFileDialog::getOpenFileName(0, tr("Open file"), "", "*.txt");
    if(fileName != ""){
        QFile inputFile(fileName);
        if(!inputFile.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this,tr("Error"),"",tr("Can notopen file"));
        } else {
           // QString buffer;
            QTextStream in(&inputFile);
            wordStr = in.readAll();
            inputFile.close();
           // ui->textEdit->setPlainText(wordStr);
            //while(true){
                words = wordStr.split(',');
            //}

            currentWordNumber = 1;
            ui->wordsQuantity->setText('/'+QString::number(words.size()));
            ui->currentWord->setText(QString::number(currentWordNumber));
            ui->wordLabel->setText(words[currentWordNumber-1]);

            resWidget.getWords(words);

            this->on_actionOpen_right_triggered();

        }
    }
}

void MainWindow::on_actionOpen_right_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(0, tr("Open file"), "", "*.txt");
    if(fileName != ""){
        QFile inputFile(fileName);
        if(!inputFile.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this,tr("Error"),"",tr("Can notopen file"));
        } else {
           // QString buffer;
            QTextStream in(&inputFile);
            rightWordStr = in.readAll();
            inputFile.close();
           // ui->textEdit->setPlainText(wordStr);
            //while(true){
                rightWords = rightWordStr.split(',');
            //}
            ui->nextWordButton->setEnabled(true);
            resWidget.getRightWords(rightWords);
        }
    }

}

void MainWindow::on_nextWordButton_clicked()
{
    resWidget.addWord(ui->lineEdit->text(), currentWordNumber-1);
    if(currentWordNumber<words.size()){
        currentWordNumber++;
        ui->currentWord->setText(QString::number(currentWordNumber));
        ui->wordLabel->setText(words[currentWordNumber-1]);
    } else {
        ui->nextWordButton->setEnabled(false);
        resWidget.show();
    }
}

