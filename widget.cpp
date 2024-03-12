#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeMoney(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 200);
    ui->pbTang->setEnabled(money >= 300);
    ui->pbReset->setEnabled(money > 0);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}



void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    QString text;

    int fiveHundred=0;
    int hundred=0;
    int fifty=0;
    int ten=0;
    fiveHundred = money / 500;
    text = QString::number(fiveHundred);

    if (money % 500) {
        fiveHundred = money / 500;
        money %= 500;
    } if (money % 100) {
        hundred = money / 100;
        money %= 100;
    } if (money % 50) {
        fifty = money / 50;
        money %= 50;
    } if (money != 0) {
        ten = money / 10;
        money %= 10;
    }


    text = "500 won = " + QString::number(fiveHundred)
           + " / 100 won = " + QString::number(hundred)
           + " / 50 won = " + QString::number(fifty)
           + " / 10 won = " + QString::number(ten);
    changeMoney(0);

    mb.information(nullptr, "Reset", text);
}











