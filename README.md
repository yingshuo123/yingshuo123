# QtTcp 项目

## 项目概述
这是一个基于Qt框架开发的TCP通信应用程序，提供用户登录、注册功能，并使用SQLite数据库存储用户信息。

## 功能特点
- 用户登录与注册
- 基于SQLite的本地数据存储
- TCP网络通信功能
- 友好的图形界面

## 技术栈
- C++
- Qt 5.x 框架
- SQLite 数据库
- TCP/IP 网络通信

## 环境要求
- Qt 5.x 开发环境
- MinGW 编译器 (Windows)
- SQLite 支持库

## 安装与构建

### 1. 环境准备
确保已安装Qt开发环境，可从[Qt官网](https://www.qt.io/)下载安装。

### 2. 打开项目
使用Qt Creator打开项目根目录下的`QTcp.pro`文件。

### 3. 构建项目
```bash
# 在Windows上使用MinGW构建
cd build-vs
mingw32-make -f Makefile.Debug clean
mingw32-make -f Makefile.Debug -j16
```

## 使用方法

### 运行程序
构建完成后，可在`build-vs/debug`目录下找到`QTcp.exe`可执行文件并运行。

### 用户操作
1. **注册新用户**：点击注册按钮，输入用户名和密码完成注册
2. **用户登录**：输入已注册的用户名和密码进行登录
3. **主界面**：登录成功后进入主界面，可进行TCP通信相关操作

## 项目结构
```
QtTcp-master/
├── database.cpp      # 数据库操作相关代码
├── database.h        # 数据库类定义
├── loginwindow.cpp   # 登录窗口实现
├── loginwindow.h     # 登录窗口类定义
├── registerwindow.cpp # 注册窗口实现
├── registerwindow.h   # 注册窗口类定义
├── mainwindow.cpp    # 主窗口实现
├── mainwindow.h      # 主窗口类定义
├── main.cpp          # 程序入口
├── images/           # 图片资源文件夹
└── build-vs/         # 构建输出目录
```

## 数据库说明
- 使用SQLite数据库存储用户信息
- 数据库文件位于程序运行目录下的`users.db`
- 主要存储用户名和密码信息

## 注意事项
1. 程序首次运行时会自动创建数据库文件和表结构
2. 为了安全考虑，建议在实际应用中对密码进行加密存储
3. 确保程序有足够的权限读写数据库文件

## 许可证
[MIT License](LICENSE)

## 联系方式
如有问题或建议，请联系项目维护者。