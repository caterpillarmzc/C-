#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QImage>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    imgs[0]="images/1.jpg";
    imgs[1]="images/2.jpg";
    imgs[2]="images/3.jpg";
    imgs[3]="images/4.jpg";
    imgs[4]="images/5.jpg";
    imgs[5]="images/6.jpg";
    imgs[6]="images/7.jpg";
    imgs[7]="images/8.jpg";
    imgs[8]="images/9.jpg";
    imgs[9]="images/10.jpg";
    imgs[10]="images/11.jpg";
    imgs[11]="images/12.jpg";
    imgs[12]="images/13.jpg";
    imgs[13]="images/14.jpg";
    imgs[14]="images/15.jpg";
    i=0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::InitTimer()
{
    connect(&timer,SIGNAL(timeout()),this,SLOT(Timeout()));
}
void Widget::Timeout()
{
    if(15==i)
    {
        i=0;
    }
    QImage img;
    img.load(imgs[i]);
    i++;
    QPixmap map=QPixmap::fromImage(img);
    ui->label->setPixmap(map);
    ui->label->setScaledContents(true);
}

void Widget::on_pushButton_clicked()
{
    if("start"==ui->pushButton->text())
    {
        timer.start(0.1);
        ui->pushButton->setText("stop");
    }
    else
    {
        timer.stop();
        ui->pushButton->setText("start");
    }
}
