#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void showSQLError(unsigned int handleType, const SQLHANDLE& handle);
int initBD();
SQLDisconnect(SQLConnectionHandle);
SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);