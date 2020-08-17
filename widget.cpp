#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    enabled(false, false, false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::enabled(bool b_coffee, bool b_tea, bool b_milk){
    ui->pbCoffee->setEnabled(b_coffee);
    ui->pbTea->setEnabled(b_tea);
    ui->pbMilk->setEnabled(b_milk);
}

void Widget::changeMoney(int diff){ // enabled or disabled coffe/tea/milk
    if(money>=-diff){
        money+=diff;
        if(money>=200){
            enabled(true, true, true);
        }else if(money>=150){
            enabled(true, true, false);
        }else if(money>=100){
            enabled(true, false, false);
        }else {
            enabled(false, false, false);
        }
    }
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);

}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    m.information(nullptr, "change", QString::number(money));
    money=0;
    ui->lcdNumber->display(money);
    enabled(false, false, false);
}
