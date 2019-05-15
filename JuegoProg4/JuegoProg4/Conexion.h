typedef int(*sqlite3_callback)(
	void*, //Datos que se proporcionan al llamar a la funcion sqlite3_exec() en el 4º argumento.
	int, //nº de columnas en fila.
	char**, //array de strings representando campos en cada fila.
	char** //array de strings representando nombres de columnas.
);

static void iniciarBD(int argc, char* argv[]);
static int llamada(void *NotUsed, int argc, char **argv, char **colName);
static int llamada2(void *data, int argc, char **argv, char **azColName);
static void crearTablas(int request, char *sql);
static void insertarDatos(int request, char *sql);
static void seleccionarDatos(int request, char *sql);
static void actualizarDatos(int request, char *sql);
static void borrarDatos(int request, char *sql);
