#include <sqlite3.h>
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

class Database
{
    public:
        void init();
        void insert(string message);
        void select();
        void update(string message);
        void remove(string message);
        void close();
        int getConnection();
        static int callback(void *NotUsed, int argc, char **argv, char **azColName);
        void createBaseTables();
    private:
        sqlite3 *db;
        char *zErrMsg = 0;
        int rc;
        const char *sql;
        const char* data = "Callback function called";
};