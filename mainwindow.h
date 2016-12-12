#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include "result.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_nextWordButton_clicked();

    void on_actionOpen_right_triggered();

    void on_actionShow_results_table_triggered();

private:
    unsigned int currentWordNumber;
    Ui::MainWindow *ui;
    QString path, wordStr, rightWordStr;
    QStringList words;
    QStringList rightWords;
    result resWidget;

};

#endif // MAINWINDOW_H
