#include "Database.hpp"

void Database::init()
{
    int rc = sqlite3_open("gateway-cfg.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
        this->rc = rc;
    }

    sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, this->callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }

    sqlite3_close(db);
}

int Database::getConnection()
{
    return this->rc;
}

int Database::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i = 0; i<argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void Database::createBaseTables()
{
    ifstream inputFile("../baseTables/tbl_lora_devices.sql"); 
  
    // Check if the file is successfully opened 
    if (!inputFile.is_open()) { 
        cerr << "Error opening the file!" << endl; 
        return;
        //return 1; 
    } 
  
    string line; // Declare a string variable to store each 
                 // line of the file 
  
    // Read each line of the file and print it to the 
    // standard output stream 
    cout << "File Content: " << endl; 
    while (getline(inputFile, line)) { 
        cout << line << endl; // Print the current line 
    } 
  
    // Close the file 
    inputFile.close(); 
}