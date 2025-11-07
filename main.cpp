/*
 * @Author: yingshuo 2690374573@qq.com
 * @Date: 2025-04-20 21:29:00
 * @LastEditors: yingshuo 2690374573@qq.com
 * @LastEditTime: 2025-11-07 20:09:49
 * @FilePath: \QtTcp-master\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // 首先显示登录窗口
    LoginWindow loginWindow;
    if (loginWindow.exec() == QDialog::Accepted) {
        // 登录成功，显示主窗口
        MainWindow w;
        w.show();
        return a.exec();
    }
    
    return 0;
}
