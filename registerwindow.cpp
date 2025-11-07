#include "registerwindow.h"
#include "database.h"

#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QIcon>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent),
    dbManager(nullptr)
{
    setupUI();
    
    // 使用单例模式获取数据库管理器实例
    dbManager = DatabaseManager::getInstance(this);
    // 必须调用initialize()方法来初始化和打开数据库
    if (!dbManager->initialize()) {
        QMessageBox::warning(this, "数据库连接失败", "无法连接到数据库，请检查配置。");
    }
}

RegisterWindow::~RegisterWindow()
{
    // 由于使用单例模式，不需要在析构函数中删除dbManager
    // 单例实例会在应用程序结束时释放
}

void RegisterWindow::setupUI()
{
    // 设置窗口标题和尺寸
    setWindowTitle("用户注册");
    setMinimumSize(400, 300);
    
    // 创建UI组件
    logoLabel = new QLabel("用户注册");
    logoLabel->setAlignment(Qt::AlignCenter);
    logoLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #1976D2;");
    
    titleLabel = new QLabel("请输入注册信息");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("color: #555;");
    
    // 用户名输入
    QLabel *usernameLabel = new QLabel("用户名:");
    usernameEdit = new QLineEdit();
    usernameEdit->setMaxLength(20);
    usernameEdit->setPlaceholderText("请输入用户名");
    
    // 密码输入
    QLabel *passwordLabel = new QLabel("密码:");
    passwordEdit = new QLineEdit();
    passwordEdit->setMaxLength(20);
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setPlaceholderText("请输入密码");
    
    // 确认密码输入
    QLabel *confirmLabel = new QLabel("确认密码:");
    confirmPasswordEdit = new QLineEdit();
    confirmPasswordEdit->setMaxLength(20);
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordEdit->setPlaceholderText("请再次输入密码");
    
    // 按钮
    registerButton = new QPushButton("注册");
    registerButton->setMinimumHeight(30);
    registerButton->setStyleSheet("background-color: #1976D2; color: white; border-radius: 4px;");
    
    cancelButton = new QPushButton("取消");
    cancelButton->setMinimumHeight(30);
    
    // 创建布局
    mainLayout = new QVBoxLayout(this);
    inputLayout = new QVBoxLayout();
    buttonLayout = new QHBoxLayout();
    
    // 添加输入控件到输入布局
    inputLayout->addWidget(usernameLabel);
    inputLayout->addWidget(usernameEdit);
    inputLayout->addSpacing(10);
    inputLayout->addWidget(passwordLabel);
    inputLayout->addWidget(passwordEdit);
    inputLayout->addSpacing(10);
    inputLayout->addWidget(confirmLabel);
    inputLayout->addWidget(confirmPasswordEdit);
    
    // 添加按钮到按钮布局
    buttonLayout->addWidget(registerButton);
    buttonLayout->addWidget(cancelButton);
    
    // 设置间距
    inputLayout->addSpacing(20);
    
    // 添加到主布局
    mainLayout->addWidget(logoLabel);
    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    
    // 设置布局边距
    mainLayout->setContentsMargins(40, 30, 40, 30);
    
    // 连接信号和槽
    connect(registerButton, &QPushButton::clicked, this, &RegisterWindow::onRegisterButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &RegisterWindow::onCancelButtonClicked);
    
    // 设置焦点
    usernameEdit->setFocus();
}

bool RegisterWindow::validateRegisterInput()
{
    // 获取输入内容
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text();
    QString confirmPassword = confirmPasswordEdit->text();
    
    // 验证用户名不为空
    if (username.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "用户名不能为空！");
        usernameEdit->setFocus();
        return false;
    }
    
    // 验证密码长度至少为1位
    if (password.length() < 1) {
        QMessageBox::warning(this, "输入错误", "密码长度不能小于1位！");
        passwordEdit->setFocus();
        return false;
    }
    
    // 验证两次输入的密码是否一致
    if (password != confirmPassword) {
        QMessageBox::warning(this, "输入错误", "两次输入的密码不一致！");
        confirmPasswordEdit->setFocus();
        return false;
    }
    
    return true;
}

void RegisterWindow::onRegisterButtonClicked()
{
    // 验证注册输入
    if (!validateRegisterInput()) {
        return;
    }
    
    // 获取用户名和密码
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text();
    
    // 使用数据库注册用户
    if (dbManager && dbManager->registerUser(username, password)) {
        // 注册成功
        QMessageBox::information(this, "注册成功", "用户注册成功！您可以使用新账号进行登录了。");
        // 注册成功后关闭注册窗口
        accept();
    } else {
        // 注册失败（可能是用户名已存在）
        if (dbManager && dbManager->isUsernameExists(username)) {
            QMessageBox::warning(this, "注册失败", "用户名已存在，请更换用户名重试。");
        } else {
            QMessageBox::warning(this, "注册失败", "注册失败，请稍后重试。");
        }
        usernameEdit->setFocus();
    }
}

void RegisterWindow::onCancelButtonClicked()
{
    // 取消注册，关闭窗口
    reject();
    close();
}