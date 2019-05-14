#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include "Conexion.h"


//Abrimos la BD, si no existe se crea una nueva.
int main(int argc, char* argv[]) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	

	request = sqlite3_open("prog4db.db", &db);

	if (request) {
		fprintf(stderr, "No se puede abrir la BD %s\n", sqlite3_errmsg(db));
		return 0;
	}
	else {
		fprintf(stdout, "La BD se ha abierto correctamente.\n");
	}
	sqlite3_close(db);
	return 0;

}

static int llamada(void *NotUsed, int argc, char **argv, char **colName) {
	int i;
	for (i = 0; i < argc; i++){
		printf("%s = %s \n", colName[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

static int llamada2(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}
static void crearTablas(int request, char *sql) {
	
	//Crear tablas
	//sql = "CREATE TABLE PERSONAJE("
	//Ejecutar sentencia SQL
	request = sqlite3_exec(db, sql, llamada, 0, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL Error: &s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Tabla creada.\n");
	}
}

static void insertarDatos(int request, char *sql) {
	//sql = "INSERT INTO COMPANY ;
	request = sqlite3_exec(db, sql, llamada, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records created successfully\n");
	}

}

static void seleccionarDatos(int request, char *sql) {
	const char* data = "Funcion llamada iniciada.";
	sql = "SELECT * FROM PERSONAJE;";
	request = sqlite3_exec(db, sql, llamada2, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operacion terminada.\n");
	}

}
static void actualizarDatos(int request, char *sql) {
	const char* data = "Funcion llamada iniciada.";
	//sql = 
	request = sqlite3_exec(db, sql, llamada2, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operacion terminada.\n");
	}

}
static void borrarDatos(int request, char *sql) {
	const char* data = "Funcion llamada iniciada.";
	//sql = 
	request = sqlite3_exec(db, sql, llamada2, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operacion terminada.\n");
	}

}