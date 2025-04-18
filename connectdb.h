#ifndef CONNECTDB_H
#define CONNECTDB_H
#include <QSqlDatabase>

class connectdb
{
private:
    QSqlDatabase database;

public:
    connectdb();
    bool Connect();
    void Disconnect();
};

#endif // CONNECTDB_H
