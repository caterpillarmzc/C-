#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void InitTimer();

private slots:
    void on_pushButton_clicked();
    void Timeout();

private:
    Ui::Widget *ui;
    QTimer timer;
    QString imgs[15];
    int i;
};

#endif // WIDGET_H
