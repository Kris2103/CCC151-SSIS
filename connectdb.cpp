#include "connectdb.h"
#include <qdebug.h>
#include <QDebug>
#include <QSqlError>

connectdb::connectdb() {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/Kristelle/Documents/Database/CCC151_Database.db");
}

bool connectdb::Connect()
{
    if (database.open()) {
        qDebug() << "Connected to SQLite database.";
        return true;
    } else {
        qDebug() << "Failed to connect to database:" << database.lastError().text();
        return false;
    }
}

void connectdb::Disconnect()
{
    database.close();
    qDebug() << "🔌 Disconnected from database.";
}
