/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *connectBtn;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *upBtn;
    QPushButton *leftBtn;
    QPushButton *downBtn;
    QPushButton *rightBtn;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(580, 379);
        connectBtn = new QPushButton(Widget);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));
        connectBtn->setGeometry(QRect(430, 70, 61, 31));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 351, 301));
        label->setFrameShape(QFrame::Box);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 40, 54, 12));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(410, 40, 113, 20));
        upBtn = new QPushButton(Widget);
        upBtn->setObjectName(QStringLiteral("upBtn"));
        upBtn->setGeometry(QRect(430, 140, 51, 23));
        leftBtn = new QPushButton(Widget);
        leftBtn->setObjectName(QStringLiteral("leftBtn"));
        leftBtn->setGeometry(QRect(380, 190, 51, 23));
        downBtn = new QPushButton(Widget);
        downBtn->setObjectName(QStringLiteral("downBtn"));
        downBtn->setGeometry(QRect(440, 240, 51, 23));
        rightBtn = new QPushButton(Widget);
        rightBtn->setObjectName(QStringLiteral("rightBtn"));
        rightBtn->setGeometry(QRect(500, 190, 51, 23));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(380, 280, 171, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        connectBtn->setText(QApplication::translate("Widget", "connect", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("Widget", "ip\357\274\232", 0));
        upBtn->setText(QApplication::translate("Widget", "up", 0));
        leftBtn->setText(QApplication::translate("Widget", "left", 0));
        downBtn->setText(QApplication::translate("Widget", "down", 0));
        rightBtn->setText(QApplication::translate("Widget", "right", 0));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
