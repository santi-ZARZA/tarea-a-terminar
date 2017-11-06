
typedef struct
{
    int Usuario;///     El IDENTIFICADOR NUMERICO DEL USUARIO.
    int Juego;///       El IDENTIFICADOR NUMERICO DEL JUEGO.
    char Nick[20];///    EL NOMBRE DEL JUGADOR.
    char contrasena[30];///     LA CONTRASEÑA DEL JUGADOR.
    char E_mail[35];///     EL E-MAIL DEL JUGADOR.
}eJugador;

typedef struct
{
    int Usuario;///     El IDENTIFICADOR NUMERICO DEL USUARIO.
    int Juego;///       El IDENTIFICADOR NUMERICO DEL JUEGO.
    char Nombre;///     NOMBRE DEL VIDEOJUEGO.
    char Desarrolladora[20];///    EL NOMBRE DE LA DESARROLLADORA DEL VIDEOJUEGO.
    int Genero;///      TIPO DE VIDEOJUEGO.
    int Puntaje;///     PUNTAJE DADO POR JUGADOR/ES.
}eJugador;


