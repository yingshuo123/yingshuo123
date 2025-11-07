#include "loginwindow.h"
#include "database.h"
#include "registerwindow.h"

#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent),
    dbManager(nullptr)
{
    setupUI();
    setWindowTitle("登录系统");
    setFixedSize(400, 300);
    
    // 使用单例模式获取数据库管理器实例
    dbManager = DatabaseManager::getInstance(this);
    if (!dbManager->initialize()) {
        QMessageBox::critical(this, "数据库错误", "无法初始化数据库，请检查应用程序权限。");
    }
}

LoginWindow::~LoginWindow()
{
    // 数据库管理器会在父对象销毁时自动释放
}

void LoginWindow::setupUI()
{
    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setContentsMargins(50, 30, 50, 30);
    mainLayout->setSpacing(20);

    // 添加Logo
    logoLabel = new QLabel(this);
    QPixmap logoPixmap("images/logo4.ico");
    if (!logoPixmap.isNull()) {
        logoPixmap = logoPixmap.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        logoLabel->setPixmap(logoPixmap);
    } else {
        logoLabel->setText("Logo");
        logoLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #1a73e8;");
    }
    logoLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(logoLabel);

    // 添加标题
    titleLabel = new QLabel("用户登录", this);
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // 用户名标签和输入框
    QLabel *usernameLabel = new QLabel("用户名:", this);
    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("请输入用户名");
    usernameEdit->setMinimumHeight(30);

    // 密码标签和输入框
    QLabel *passwordLabel = new QLabel("密码:", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("请输入密码");
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setMinimumHeight(30);
    
    // 添加输入框到布局
    inputLayout = new QVBoxLayout();
    inputLayout->addWidget(usernameLabel);
    inputLayout->addWidget(usernameEdit);
    inputLayout->addWidget(passwordLabel);
    inputLayout->addWidget(passwordEdit);

    inputLayout->setSpacing(10);
    mainLayout->addLayout(inputLayout);

    // 创建按钮布局
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(15);

    // 登录按钮
    loginButton = new QPushButton("登录", this);
    loginButton->setStyleSheet(
        "QPushButton { background-color: #1a73e8; color: white; border-radius: 4px; font-weight: bold; }"
        "QPushButton:hover { background-color: #1669d0; }"
        "QPushButton:pressed { background-color: #135ca7; }"
    );
    loginButton->setMinimumHeight(30);
    loginButton->setMinimumWidth(100);
    
    // 注册按钮
    registerButton = new QPushButton("注册", this);
    registerButton->setStyleSheet(
        "QPushButton { background-color: #2196F3; color: white; border-radius: 4px; font-weight: bold; }"
        "QPushButton:hover { background-color: #1976D2; }"
        "QPushButton:pressed { background-color: #0d47a1; }"
    );
    registerButton->setMinimumHeight(30);
    registerButton->setMinimumWidth(100);
    // 注册按钮始终可见，不需要默认隐藏

    // 取消按钮
    cancelButton = new QPushButton("取消", this);
    cancelButton->setStyleSheet(
        "QPushButton { background-color: #f1f3f4; color: #333; border-radius: 4px; }"
        "QPushButton:hover { background-color: #e8eaed; }"
        "QPushButton:pressed { background-color: #dadce0; }"
    );
    cancelButton->setMinimumHeight(30);
    cancelButton->setMinimumWidth(100);

    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(registerButton);
    buttonLayout->addWidget(cancelButton);
    mainLayout->addLayout(buttonLayout);
    
    // 移除模式切换按钮，使用直接的登录和注册按钮
    // 添加简单的提示标签
    QLabel *tipsLabel = new QLabel("请使用注册按钮创建新账号，登录按钮进行登录", this);
    tipsLabel->setStyleSheet("color: #666; font-size: 12px;");
    tipsLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(tipsLabel);

    // 连接信号和槽
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &LoginWindow::onCancelButtonClicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterButtonClicked);
    
    // 注册按钮已经在buttonLayout中添加，不需要单独添加到mainLayout

    // 设置窗口样式
    setStyleSheet("background-color: white;");
}

bool LoginWindow::validateInput()
{
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text();

    if (username.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请输入用户名");
        usernameEdit->setFocus();
        return false;
    }

    if (password.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请输入密码");
        passwordEdit->setFocus();
        return false;
    }

    return true;
}



void LoginWindow::onRegisterButtonClicked()
{
    // 打开独立的注册窗口
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->exec(); // 模态显示注册窗口
    
    // 注册窗口关闭后，清空登录窗口的输入并设置焦点
    usernameEdit->clear();
    passwordEdit->clear();
    usernameEdit->setFocus();
}

void LoginWindow::onLoginButtonClicked()
{
    if (validateInput()) {
        QString username = usernameEdit->text().trimmed();
        QString password = passwordEdit->text(); // 密码不需要去除空格，与注册逻辑保持一致

        // 使用数据库验证用户
        if (dbManager && dbManager->validateUser(username, password)) {
            QMessageBox::information(this, "登录成功", "欢迎回来！");
            // 登录成功后的处理逻辑
            accept(); // 如果是模态对话框，这里可以接受
        } else {
            QMessageBox::warning(this, "登录失败", "用户名或密码错误，请重试。");
            passwordEdit->clear();
            passwordEdit->setFocus();
        }
    }
}

void LoginWindow::onCancelButtonClicked()
{
    // 取消登录，关闭窗口
    reject(); // 如果是模态对话框，这里可以拒绝
    close();
}