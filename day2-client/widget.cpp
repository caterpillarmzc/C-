#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    _socket=new QTcpSocket;
    _socket->connectToHost("127.0.0.1",9988);

    connect(_socket,SIGNAL(readyRead()),this,SLOT(recv_info()));//接收
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()//发送
{
    QString str1;
    str1=ui->textEdit->toPlainText();

    ui->textBrowser->append("client:");
    ui->textBrowser->append(" "+str1);

    QByteArray buf=str1.toUtf8();
    _socket->write(buf);

    ui->textEdit->clear();
}

void Widget::on_pushButton_2_clicked()//退出
{
    this->close();
}

void Widget::recv_info()
{
    QString buf=_socket->readAll();
    
    ui->textBrowser->append("server:");
    ui->textBrowser->append(" "+buf);
}
