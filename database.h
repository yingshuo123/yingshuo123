/*
 * @Author: yingshuo 2690374573@qq.com
 * @Date: 2025-11-07 20:15:07
 * @LastEditors: yingshuo 2690374573@qq.com
 * @LastEditTime: 2025-11-07 20:44:33
 * @FilePath: \QtTcp-master\database.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDebug>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    // 获取单例实例的静态方法
    static DatabaseManager* getInstance(QObject *parent = nullptr);
    ~DatabaseManager();

    // 初始化数据库
    bool initialize();
    
    // 验证用户登录
    bool validateUser(const QString &username, const QString &password);
    
    // 注册新用户
    bool registerUser(const QString &username, const QString &password);
    
    // 检查用户名是否已存在
    bool isUsernameExists(const QString &username);
    
    // 获取数据库连接状态
    bool isConnected() const;
    
private:
    // 私有构造函数，防止外部直接实例化
    explicit DatabaseManager(QObject *parent = nullptr);
    
    QSqlDatabase m_database;
    
    // 创建用户表（如果不存在）
    void createTables();
    
    // 添加默认用户（用于测试）
    void addDefaultUser();
    
    // 单例实例指针
    static DatabaseManager* m_instance;
};

#endif // DATABASE_H