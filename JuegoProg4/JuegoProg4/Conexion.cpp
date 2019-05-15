#include <stdio.h>
#include "sqlite3.h"
#include <stdlib.h>
#include "Conexion.h"

//Variables
sqlite3 *db;
char *zErrMsg = 0;
int request;
const char *sql;

//Abrimos la BD, si no existe se crea una nueva.
static void iniciarBD(int argc, char* argv[]) {
	
	request = sqlite3_open("prog4db.db", &db);

	if (request) {
		fprintf(stderr, "No se puede abrir la BD %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stdout, "La BD se ha abierto correctamente.\n");
	}
	//sqlite3_close(db);

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
static void crearTablas() {
	//Crear tablas
	sql = "CREATE TABLE PERSONAJE("  \
		"ID INT PRIMARY KEY NOT NULL," \
		"NAME TEXT NOT NULL," \
		"ENEMIGOS_ELIMINADOS INT NOT NULL," \
		"MONEDAS_RECOGIDAS INT NOT NULL);";

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

static void insertarDatos() {
	sql = "INSERT INTO PERSONAJE (ID,NAME,ENEMIGOS_ELIMINADOS,MONEDAS_RECOGIDAS) " \
		"VALUES(1, 'P1', 3, 16);";

	request = sqlite3_exec(db, sql, llamada, 0, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Los datos se han introducido correctamente\n");
	}

}

static void seleccionarDatos() {
	const char* data = "Funcion Llamada iniciada.";
	sql = "SELECT * FROM PERSONAJE;";
	request = sqlite3_exec(db, sql, llamada2, (void*)data, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operacion terminada.\n");
	}

}
static void actualizarDatos() {
	const char* data = "Funcion llamada iniciada.";
	//sql = 
	request = sqlite3_exec(db, sql, llamada2, (void*)data, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operacion terminada.\n");
	}

}
static void borrarDatos() {
	const char* data = "Funcion llamada iniciada.";
	//sql = 
	request = sqlite3_exec(db, sql, llamada2, (void*)data, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operacion terminada.\n");
	}

}