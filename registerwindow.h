#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

// 前向声明
class DatabaseManager;

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void onRegisterButtonClicked();
    void onCancelButtonClicked();

private:
    void setupUI();
    bool validateRegisterInput();

    // UI 组件
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmPasswordEdit;
    QPushButton *registerButton;
    QPushButton *cancelButton;
    QLabel *logoLabel;
    QLabel *titleLabel;
    QVBoxLayout *mainLayout;
    QVBoxLayout *inputLayout;
    QHBoxLayout *buttonLayout;

    // 数据库管理器
    DatabaseManager *dbManager;
};

#endif // REGISTERWINDOW_H