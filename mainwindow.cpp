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
    connect(ui->lineEdit, SIGNAL(returnPressed()), ui->nextWordButton, SLOT(click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
   // words.clear();
    rightWords.clear();

    currentWordNumber = 1;
    resWidget.clearTable();

    QString fileName = QFileDialog::getOpenFileName(0, tr("Open file"), "", "*.txt");
    if(fileName != ""){
        QFile inputFile(fileName);
        if(!inputFile.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this,tr("Error"),"",tr("Can notopen file"));
        } else {
            QTextStream in(&inputFile);
            wordStr = in.readAll();
            inputFile.close();

            words = wordStr.split(',');

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
            QTextStream in(&inputFile);
            rightWordStr = in.readAll();
            inputFile.close();
            rightWords = rightWordStr.split(',');

            ui->nextWordButton->setEnabled(true);
            resWidget.getRightWords(rightWords);
        }
    }

}

void MainWindow::on_nextWordButton_clicked()
{
    resWidget.addWord(ui->lineEdit->text(), currentWordNumber-1);
    ui->lineEdit->clear();
    if(currentWordNumber<words.size()){
        currentWordNumber++;
        ui->currentWord->setText(QString::number(currentWordNumber));
        ui->wordLabel->setText(words[currentWordNumber-1]);
    } else {
        ui->nextWordButton->setEnabled(false);
        resWidget.show();
    }
}

