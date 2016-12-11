#ifndef RESULT_H
#define RESULT_H

#include <QWidget>

namespace Ui {
class result;
}

class result : public QWidget
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();

public slots:
    void getWords(QStringList inpt);
    void getRightWords(QStringList inpt);
    void addWord(QString word, unsigned int number);
    void clearTable();

private slots:
    void on_pushButton_clicked();

private:
    Ui::result *ui;
    QStringList words, rightWords;
};

#endif // RESULT_H
