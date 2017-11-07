#define GENERO_ACCION 1
#define GENERO_AVENTURA 2
#define GENERO_TERROR 3
#define GENERO_DEPORTE 4
#define GENERO_LOGICA 5


typedef struct
{
    int Usuario;///     El IDENTIFICADOR NUMERICO DEL USUARIO.
    char Nick[20];///    EL NOMBRE DEL JUGADOR.
    char contrasena[30];///     LA CONTRASEÑA DEL JUGADOR.
    char E_mail[35];///     EL E-MAIL DEL JUGADOR.
}eJugador;

typedef struct
{
    int Usuario;///     El IDENTIFICADOR NUMERICO DEL USUARIO.
    int Juego;///       El IDENTIFICADOR NUMERICO DEL JUEGO.
    char Nombre[30];///     NOMBRE DEL VIDEOJUEGO.
    char Desarrolladora[20];///    EL NOMBRE DE LA DESARROLLADORA DEL VIDEOJUEGO.
    int Genero;///      TIPO DE VIDEOJUEGO.
    int Puntaje;///     PUNTAJE DADO POR JUGADOR/ES.
}eGame;


eJugador* new_jugador();

eGame* new_game();

void mostrarTodo(eJugador*,eGame*);

void menu();
