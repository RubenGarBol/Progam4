#include "sqlite3.h"

typedef int(*sqlite3_callback)(
	void*, //Datos que se proporcionan al llamar a la funcion sqlite3_exec() en el 4º argumento.
	int, //nº de columnas en fila.
	char**, //array de strings representando campos en cada fila.
	char** //array de strings representando nombres de columnas.
);
class Conexion {
public:
	//Variables
	sqlite3 *db;
	char *zErrMsg = 0;
	int request;
	const char *sql;

	//Funciones
	void iniciarBD(int argc, char* argv[]);
	void crearTablas();
	void insertarDatos();
	void seleccionarDatos();
	void actualizarDatos();
	void borrarDatos();
};

//Funciones externas
int llamada(void *NotUsed, int argc, char **argv, char **colName);
int llamada2(void *data, int argc, char **argv, char **azColName);

