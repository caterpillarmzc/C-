#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_connectBtn_clicked();
    void camConnectedSlot();
    void serConnectedSlot();
    void recvImageSlot();


    void on_upBtn_pressed();

    void on_downBtn_pressed();

    void on_upBtn_released();

    void on_downBtn_released();


    void on_leftBtn_pressed();

    void on_leftBtn_released();

    void on_rightBtn_pressed();

    void on_rightBtn_released();

private:
    Ui::Widget *ui;
    QTcpSocket *camSocket;
    QTcpSocket *serSocket;
    bool readFlag;
    int picSize;
};

#endif // WIDGET_H
