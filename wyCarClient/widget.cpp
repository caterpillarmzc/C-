#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setText("192.168.1.1");

    camSocket = new QTcpSocket(this);
    serSocket = new QTcpSocket(this);

    ui->connectBtn->setEnabled(true);
    ui->upBtn->setEnabled(false);
    ui->downBtn->setEnabled(false);
    ui->leftBtn->setEnabled(false);
    ui->rightBtn->setEnabled(false);

    connect(camSocket,SIGNAL(connected()),this,SLOT(camConnectedSlot()));
    connect(serSocket,SIGNAL(connected()),this,SLOT(serConnectedSlot()));

    connect(camSocket,SIGNAL(readyRead()),this,SLOT(recvImageSlot()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connectBtn_clicked()
{
    readFlag = true;
    //连接视频服务器
    camSocket->connectToHost(ui->lineEdit->text(),8888);
    //连接串口服务器
    serSocket->connectToHost(ui->lineEdit->text(),2001);
}

//连接摄像头服务器成功
void Widget::camConnectedSlot()
{
    ui->connectBtn->setEnabled(false);
}

//连接串口服务器成功
void Widget::serConnectedSlot()
{
    ui->upBtn->setEnabled(true);
    ui->downBtn->setEnabled(true);
    ui->leftBtn->setEnabled(true);
    ui->rightBtn->setEnabled(true);
}

//接收并显示图片
void Widget::recvImageSlot()
{
    qDebug() << "waiting..";
    if(true == readFlag)
    {
        char buf[10] = {0};
        camSocket->read(buf, 10);
        picSize = atoi(buf);
        readFlag = false;
    }
    else
    {
        if(camSocket->bytesAvailable() < picSize)
        {
            return;
        }
        char buf[1280*1024*3];
        camSocket->read(buf,picSize);
        QPixmap pix;
        pix.loadFromData((uchar *)buf, picSize, "JPEG");
        ui->label->setPixmap(pix);
        ui->label->setScaledContents(true);
        readFlag = true;
    }
}


void Widget::on_upBtn_pressed()
{
    char frontBuf[5] = {(char)0xff,(char)0,(char)1,(char)0,(char)0xff};
    serSocket->write(frontBuf,sizeof(frontBuf));
}


void Widget::on_upBtn_released()
{
    char stopBuf[5] = {(char)0xff,(char)0,(char)0,(char)0,(char)0xff};
    serSocket->write(stopBuf,sizeof(stopBuf));
}

void Widget::on_downBtn_pressed()
{
    char backBuf[5] = {(char)0xff,(char)0,(char)2,(char)0,(char)0xff};
    serSocket->write(backBuf,sizeof(backBuf));
}


void Widget::on_downBtn_released()
{
    char stopBuf1[5] = {(char)0xff,0,0,0,(char)0xff};
    serSocket->write(stopBuf1,sizeof(stopBuf1));
}

void Widget::on_leftBtn_pressed()
{
    char leftBuf[5] = {(char)0xff,0,3,0,(char)0xff};
    serSocket->write(leftBuf,sizeof(leftBuf));
}

void Widget::on_leftBtn_released()
{
    char stopBuf2[5] = {(char)0xff,0,0,0,(char)0xff};
    serSocket->write(stopBuf2,sizeof(stopBuf2));
}

void Widget::on_rightBtn_pressed()
{
    char rightBuf[5] = {(char)0xff,0,4,0,(char)0xff};
    serSocket->write(rightBuf,sizeof(rightBuf));
}

void Widget::on_rightBtn_released()
{
    char stopBuf3[5] = {(char)0xff,0,0,0,(char)0xff};
    serSocket->write(stopBuf3,sizeof(stopBuf3));
}
