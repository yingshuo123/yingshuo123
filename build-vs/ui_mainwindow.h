/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *btnOpen;
    QLabel *label_2;
    QComboBox *cbLocalIP;
    QLabel *label_7;
    QCheckBox *ckTimestamp;
    QLineEdit *txtInterval;
    QCheckBox *ckSendTimer;
    QCheckBox *ckRecvHex;
    QPushButton *btnClearRecv;
    QPushButton *btnClearSend;
    QCheckBox *chSendHex;
    QCheckBox *chSendNewline;
    QPlainTextEdit *txtSend;
    QPlainTextEdit *txtRecv;
    QComboBox *cbLocalPort;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *cbRemoteIP;
    QComboBox *cbRemotePort;
    QPushButton *btnSend;
    QPushButton *btnConnect;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(741, 523);
        MainWindow->setMinimumSize(QSize(0, 0));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(11, 4, 66, 16));
        btnOpen = new QPushButton(centralwidget);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setGeometry(QRect(9, 126, 103, 37));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(11, 44, 66, 16));
        cbLocalIP = new QComboBox(centralwidget);
        cbLocalIP->setObjectName(QString::fromUtf8("cbLocalIP"));
        cbLocalIP->setGeometry(QRect(10, 22, 181, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbLocalIP->sizePolicy().hasHeightForWidth());
        cbLocalIP->setSizePolicy(sizePolicy);
        cbLocalIP->setEditable(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 394, 81, 16));
        ckTimestamp = new QCheckBox(centralwidget);
        ckTimestamp->setObjectName(QString::fromUtf8("ckTimestamp"));
        ckTimestamp->setGeometry(QRect(10, 105, 81, 16));
        txtInterval = new QLineEdit(centralwidget);
        txtInterval->setObjectName(QString::fromUtf8("txtInterval"));
        txtInterval->setGeometry(QRect(80, 390, 81, 19));
        ckSendTimer = new QCheckBox(centralwidget);
        ckSendTimer->setObjectName(QString::fromUtf8("ckSendTimer"));
        ckSendTimer->setGeometry(QRect(10, 374, 131, 16));
        ckRecvHex = new QCheckBox(centralwidget);
        ckRecvHex->setObjectName(QString::fromUtf8("ckRecvHex"));
        ckRecvHex->setGeometry(QRect(10, 87, 131, 16));
        btnClearRecv = new QPushButton(centralwidget);
        btnClearRecv->setObjectName(QString::fromUtf8("btnClearRecv"));
        btnClearRecv->setGeometry(QRect(483, 289, 71, 23));
        btnClearSend = new QPushButton(centralwidget);
        btnClearSend->setObjectName(QString::fromUtf8("btnClearSend"));
        btnClearSend->setGeometry(QRect(563, 288, 72, 23));
        chSendHex = new QCheckBox(centralwidget);
        chSendHex->setObjectName(QString::fromUtf8("chSendHex"));
        chSendHex->setGeometry(QRect(10, 334, 171, 16));
        chSendNewline = new QCheckBox(centralwidget);
        chSendNewline->setObjectName(QString::fromUtf8("chSendNewline"));
        chSendNewline->setGeometry(QRect(10, 354, 141, 16));
        txtSend = new QPlainTextEdit(centralwidget);
        txtSend->setObjectName(QString::fromUtf8("txtSend"));
        txtSend->setGeometry(QRect(200, 320, 515, 148));
        txtRecv = new QPlainTextEdit(centralwidget);
        txtRecv->setObjectName(QString::fromUtf8("txtRecv"));
        txtRecv->setGeometry(QRect(200, 0, 514, 281));
        cbLocalPort = new QComboBox(centralwidget);
        cbLocalPort->setObjectName(QString::fromUtf8("cbLocalPort"));
        cbLocalPort->setGeometry(QRect(11, 62, 181, 20));
        sizePolicy.setHeightForWidth(cbLocalPort->sizePolicy().hasHeightForWidth());
        cbLocalPort->setSizePolicy(sizePolicy);
        cbLocalPort->setEditable(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(11, 195, 101, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(11, 236, 66, 16));
        cbRemoteIP = new QComboBox(centralwidget);
        cbRemoteIP->setObjectName(QString::fromUtf8("cbRemoteIP"));
        cbRemoteIP->setGeometry(QRect(10, 214, 181, 20));
        sizePolicy.setHeightForWidth(cbRemoteIP->sizePolicy().hasHeightForWidth());
        cbRemoteIP->setSizePolicy(sizePolicy);
        cbRemoteIP->setEditable(true);
        cbRemotePort = new QComboBox(centralwidget);
        cbRemotePort->setObjectName(QString::fromUtf8("cbRemotePort"));
        cbRemotePort->setGeometry(QRect(10, 254, 181, 20));
        sizePolicy.setHeightForWidth(cbRemotePort->sizePolicy().hasHeightForWidth());
        cbRemotePort->setSizePolicy(sizePolicy);
        cbRemotePort->setEditable(true);
        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(10, 426, 103, 39));
        btnConnect = new QPushButton(centralwidget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(10, 280, 103, 39));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 741, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        action->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\351\200\211\344\270\262\345\217\243\351\234\200\350\246\201\351\207\215\346\226\260\346\211\223\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260\344\270\273\346\234\272IP", nullptr));
        btnOpen->setText(QCoreApplication::translate("MainWindow", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243", nullptr));
#if QT_CONFIG(tooltip)
        label_7->setToolTip(QCoreApplication::translate("MainWindow", "\346\233\264\346\224\271\345\221\250\346\234\237\345\220\216\351\234\200\350\246\201\351\207\215\346\226\260\345\217\221\351\200\201", nullptr));
#endif // QT_CONFIG(tooltip)
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\221\250\346\234\237(ms)", nullptr));
        ckTimestamp->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\210\263", nullptr));
#if QT_CONFIG(tooltip)
        ckSendTimer->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        ckSendTimer->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        ckRecvHex->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        btnClearRecv->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        btnClearSend->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201", nullptr));
        chSendHex->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        chSendNewline->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\233\236\350\275\246\346\215\242\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        label_3->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\351\200\211\344\270\262\345\217\243\351\234\200\350\246\201\351\207\215\346\226\260\346\211\223\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\277\234\347\250\213\344\270\273\346\234\272IP", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        btnConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
