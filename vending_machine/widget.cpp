#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbIceTea->setEnabled(false);
    ui->pbGongCha->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money+=n;

    ui->lcdNumber->display(QString::number(money));
    if(money >= 200){
        ui->pbCoffee->setEnabled(true);
        ui->pbIceTea->setEnabled(true);
        ui->pbGongCha->setEnabled(true);
    }
    else if(money >= 150){
        ui->pbCoffee->setEnabled(true);
        ui->pbIceTea->setEnabled(true);
        ui->pbGongCha->setEnabled(false);
    }
    else if(money >= 100){
        ui->pbCoffee->setEnabled(true);
        ui->pbIceTea->setEnabled(false);
        ui->pbGongCha->setEnabled(false);
    }
    else{
        ui->pbCoffee->setEnabled(false);
        ui->pbIceTea->setEnabled(false);
        ui->pbGongCha->setEnabled(false);
    }
}

void Widget::on_pb10_clicked(){
    changeMoney(10);
}

void Widget::on_pb50_clicked(){
    changeMoney(50);
}

void Widget::on_pb100_clicked(){
    changeMoney(100);
}

void Widget::on_pb500_clicked(){
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbIceTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbGongCha_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReturnCoin_clicked()
{
    QString returnCoin = "";
    returnCoin += ((money/500) != 0 ? "500 : " + QString::number(money/500) + "\n" : "");
    money%=500;
    returnCoin += ((money/100) != 0 ? "100 : " + QString::number(money/100) + "\n" : "");
    money%=100;
    returnCoin += ((money/50) != 0 ? " 50 : " + QString::number(money/50) + "\n" : "");
    money%=50;
    returnCoin += ((money/10) != 0 ? " 10 : " + QString::number(money/10) + "\n" : "");
    money%=10;

    changeMoney(0);
    QMessageBox msg;
    msg.information(nullptr, "Return Coin", returnCoin);
}
