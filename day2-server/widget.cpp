#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QDebug>
#include <QByteArray>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    _server=new QTcpServer;
    _server->listen(QHostAddress::Any,8888);

    connect(_server,SIGNAL(newConnection()),this,SLOT(slotconnect()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()//发送
{
    QString str1;
    str1=ui->textEdit->toPlainText();//获取文本内容

    ui->textBrowser->append("server:");
    ui->textBrowser->append(" "+str1);

    QByteArray buff=str1.toUtf8();
    _socket->write(buff);//发送数据

    ui->textEdit->clear();
}

void Widget::on_pushButton_2_clicked()//退出
{
    this->close();
}

void Widget::recv_info()
{
    QString buf=_socket->readAll();

    ui->textBrowser->append("client:");
    ui->textBrowser->append(" "+buf);
}

void Widget::slotconnect()
{
    while(_server->hasPendingConnections())
    {
        _socket=_server->nextPendingConnection();
        connect(_socket,SIGNAL(readyRead()),this,SLOT(recv_info()));
    }
}
