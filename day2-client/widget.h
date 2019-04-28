#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void recv_info();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
