/*
 * @Author: yingshuo 2690374573@qq.com
 * @Date: 2025-11-07 20:07:16
 * @LastEditors: yingshuo 2690374573@qq.com
 * @LastEditTime: 2025-11-07 20:07:21
 * @FilePath: \QtTcp-master\loginwindow.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QPixmap>
#include <QIcon>

class DatabaseManager;

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void onLoginButtonClicked();
    void onCancelButtonClicked();
    void onRegisterButtonClicked();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *cancelButton;
    QPushButton *registerButton; // 注册按钮(用于打开独立的注册窗口)
    QLabel *logoLabel; // Logo标签
    QLabel *titleLabel; // 标题标签
    QVBoxLayout *inputLayout; // 输入布局，作为成员变量以便在其他函数中访问
    DatabaseManager *dbManager; // 数据库管理器指针
    
    void setupUI();
    bool validateInput();
};

#endif // LOGINWINDOW_H