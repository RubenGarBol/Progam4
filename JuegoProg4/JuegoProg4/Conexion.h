#include "sqlite3.h"
typedef int(*sqlite3_callback)(
	void*, //Datos que se proporcionan al llamar a la funcion sqlite3_exec() en el 4º argumento.
	int, //nº de columnas en fila.
	char**, //array de strings representando campos en cada fila.
	char** //array de strings representando nombres de columnas.
);

sqlite3* iniciarBD();
void crearTablas();
void insertarDatos();
void seleccionarDatos();
int llamada(void *NotUsed, int argc, char **argv, char **colName);
//void actualizarDatos();
//void borrarDatos();


