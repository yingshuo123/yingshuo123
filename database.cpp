#include "database.h"
#include <QCoreApplication>

// 初始化静态实例指针
DatabaseManager* DatabaseManager::m_instance = nullptr;

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
}

DatabaseManager::~DatabaseManager()
{
    if (m_database.isOpen()) {
        m_database.close();
    }
    // 清除单例实例
    m_instance = nullptr;
}

// 获取单例实例的静态方法
DatabaseManager* DatabaseManager::getInstance(QObject *parent)
{
    if (!m_instance) {
        m_instance = new DatabaseManager(parent);
    }
    return m_instance;
}

bool DatabaseManager::initialize()
{
    // 使用固定的连接名称，确保整个应用程序使用同一个数据库连接
    const QString connectionName = "mainDatabase";
    
    // 检查是否已经存在该连接
    if (QSqlDatabase::contains(connectionName)) {
        m_database = QSqlDatabase::database(connectionName);
    } else {
        // 创建新连接
        m_database = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        // 使用绝对路径确保数据库文件位置一致
        QString databasePath = QCoreApplication::applicationDirPath() + "/users.db";
        m_database.setDatabaseName(databasePath);
        qDebug() << "数据库文件路径: " << databasePath;
    }
    
    // 打开数据库
    if (!m_database.isOpen()) {
        if (!m_database.open()) {
            qDebug() << "无法打开数据库:" << m_database.lastError().text();
            return false;
        }
    }
    
    // 创建表和添加默认用户
    createTables();
    addDefaultUser();
    
    qDebug() << "数据库初始化成功";
    return true;
}

void DatabaseManager::createTables()
{
    QSqlQuery query;
    
    QString createTableQuery = 
    "CREATE TABLE IF NOT EXISTS users ("
    "    id INTEGER PRIMARY KEY AUTOINCREMENT,"
    "    username TEXT NOT NULL UNIQUE,"
    "    password TEXT NOT NULL,"
    "    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
    ");";
    
    if (!query.exec(createTableQuery)) {
        qDebug() << "创建用户表失败:" << query.lastError().text();
    }
}

void DatabaseManager::addDefaultUser()
{
    // 检查是否已有用户，如果没有则添加默认用户
    QSqlQuery checkQuery;
    checkQuery.exec("SELECT COUNT(*) FROM users");
    
    if (checkQuery.next() && checkQuery.value(0).toInt() == 0) {
        // 添加默认用户，用户名1，密码1（注意：实际应用中应该加密存储密码）
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
        insertQuery.bindValue(":username", "1");
        insertQuery.bindValue(":password", "1"); // 实际应用中应该使用哈希算法加密
        
        if (insertQuery.exec()) {
            qDebug() << "已添加默认用户: 用户名1，密码1";
        } else {
            qDebug() << "添加默认用户失败:" << insertQuery.lastError().text();
        }
    }
}

bool DatabaseManager::validateUser(const QString &username, const QString &password)
{
    if (!m_database.isOpen()) {
        qDebug() << "数据库未连接";
        return false;
    }
    
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password); // 实际应用中应该使用哈希算法验证
    
    if (!query.exec()) {
        qDebug() << "验证用户查询失败:" << query.lastError().text();
        return false;
    }
    
    // 如果查询返回结果，则用户验证成功
    return query.next();
}

bool DatabaseManager::registerUser(const QString &username, const QString &password)
{
    if (!m_database.isOpen()) {
        qDebug() << "数据库未连接";
        return false;
    }
    
    // 检查用户名是否已存在
    if (isUsernameExists(username)) {
        qDebug() << "用户名已存在";
        return false;
    }
    
    // 插入新用户
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password); // 实际应用中应该使用哈希算法加密
    
    if (!query.exec()) {
        qDebug() << "注册用户失败:" << query.lastError().text();
        return false;
    }
    
    qDebug() << "用户注册成功: " << username;
    return true;
}

bool DatabaseManager::isUsernameExists(const QString &username)
{
    if (!m_database.isOpen()) {
        qDebug() << "数据库未连接";
        return false;
    }
    
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username");
    query.bindValue(":username", username);
    
    if (!query.exec()) {
        qDebug() << "检查用户名失败:" << query.lastError().text();
        return false;
    }
    
    // 如果查询返回结果，则用户名已存在
    return query.next();
}

bool DatabaseManager::isConnected() const
{
    return m_database.isOpen();
}