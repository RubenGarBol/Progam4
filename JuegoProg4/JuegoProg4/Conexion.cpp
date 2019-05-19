
#include <stdio.h>
#include "sqlite3.h"
#include <stdlib.h>
#include "Conexion.h"

using namespace std;

//Abrimos la BD, si no existe se crea una nueva.
sqlite3* iniciarBD() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	request = sqlite3_open("prog4db.db", &db);

	if (request) {
		fprintf(stderr, "No se puede abrir la BD %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stdout, "La BD se ha abierto correctamente.\n");
	}
	return db;
}

int llamada(void *NotUsed, int argc, char **argv, char **colName) {
	int i;
	for (i = 0; i < argc; i++){
		printf("%s = %s \n", colName[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

static int callBack(void *data, int argc, char **argv, char **azColName) {
	id = atoi(argv[0]);
	return 0;
}


void crearTablas() {
	
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	const char *sql;

	db = iniciarBD();

	//Crear tablas
	sql = "CREATE TABLE PERSONAJE("  \
		"ID INT PRIMARY KEY     NOT NULL," \
		"NAME           TEXT    NOT NULL," \
		"MONEDAS_RECOGIDAS            INT     NOT NULL," \
		"ENEMIGOS_ELIMINADOS         INT NOT NULL );";


	//Ejecutar sentencia SQL
	request = sqlite3_exec(db, sql, llamada, 0, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL Error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Tabla creada.\n");
	}
	sqlite3_close(db);
}

void insertarDatos() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	const char *sql;

	db = iniciarBD();

	sql = "INSERT INTO PERSONAJE (ID,NAME,MONEDAS_RECOGIDAS,ENEMIGOS_ELIMINADOS)" \
		"VALUES (4, 'Eneko', 25, 4);";


	request = sqlite3_exec(db, sql, llamada, 0, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s \n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Los datos se han introducido correctamente\n");
	}
	sqlite3_close(db);
}

void seleccionarDatos() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	const char *sql;
	const char* data = "Funcion Llamada iniciada.";

	db = iniciarBD();

	sql = "SELECT * FROM PERSONAJE";

	request = sqlite3_exec(db, sql, llamada, (void*)data, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s \n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operacion terminada.\n");
	}
	sqlite3_close(db);

}

void guardarPuntuacion(int nEnemigos,int nMonedas) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	char *sqlstatement = (char*)malloc(sizeof(char) * 1000);
	int x = sprintf(sqlstatement,"INSERT INTO PERSONAJE (ID,NAME,MONEDAS_RECOGIDAS,ENEMIGOS_ELIMINADOS) VALUES (%i, 'Usuario', %i, %i); ",id + 1, nEnemigos, nMonedas);
	db = iniciarBD();
	request = sqlite3_exec(db, sqlstatement, llamada, 0, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s \n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Los datos se han introducido correctamente\n");
	}
	sqlite3_close(db);
}
void conseguirID() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	const char *sqlstatement = "SELECT MAX(ID) FROM PERSONAJE;";
	db = iniciarBD();

	request = sqlite3_exec(db, sqlstatement, callBack, 0, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s \n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Los datos se han introducido correctamente\n");
	}
	sqlite3_close(db);
}
int printId() {
	return id;
}

/*void actualizarDatos() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	const char *sql;
	const char* data = "Funcion llamada iniciada.";
	//sql = 

	db = iniciarBD();

	request = sqlite3_exec(db, sql, llamada2, (void*)data, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operacion terminada.\n");
	}
	sqlite3_close(db);
}
void borrarDatos() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	const char *sql;
	const char* data = "Funcion llamada iniciada.";
	//sql = 

	db = iniciarBD();

	request = sqlite3_exec(db, sql, llamada2, (void*)data, &zErrMsg);

	if (request != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operacion terminada.\n");
	}
	sqlite3_close(db);
}*/