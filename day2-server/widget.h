#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QtNetwork>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QTcpSocket *_socket;
    QTcpServer *_server;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void recv_info();
    void slotconnect();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
