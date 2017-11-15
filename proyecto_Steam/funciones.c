#include "ArrayList.h"
#include "funciones.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


void new_jugador(ArrayList* lista)
{
    eJugador* jugador = NULL;
    int Usuario;
    char Nick[20];
    char contrasena[30];
    char E_mail[35];

        jugador = (eJugador*) malloc(sizeof(eJugador));

        if(jugador != NULL)
        {
            system("cls");
            printf("1. Ingrese su nombre de usuario: ");
            fflush(stdin);
            gets(Nick);
            printf("2. Ingrese su contraseña: ");
            fflush(stdin);
            gets(contrasena);
            printf("3. Ingrese su E-mail: ");
            fflush(stdin);
            gets(E_mail);
            Usuario = 1000+lista->len(lista);

            strcpy(jugador->Nick,Nick);
            strcpy(jugador->contrasena,contrasena);
            strcpy(jugador->E_mail,E_mail);
            jugador->Usuario = Usuario;

            al_add(lista,jugador);
        }
        else
        {
            free(jugador);
        }
}

void new_game(ArrayList* lista)
{
    eGame* videojuego = NULL;
    int Juego;
    char Nombre[30];
    char Desarrolladora[20];
    int Genero;
    char opcion;
    int ban = 0;

        videojuego = (eGame*) malloc(sizeof(eGame));

        if(videojuego != NULL)
        {

                system("cls");
                printf("1. Ingrese el nombre del juego: ");
                fflush(stdin);
                gets(Nombre);
                printf("2. Ingrese su Desarrolladora: ");
                fflush(stdin);
                gets(Desarrolladora);
            do
            {
                printf("3. Ingrese su Genero entre los siguentes\n\n");
                printf("  [1]ACCION  [2]AVENTURA  [3]TERROR  [4]DEPORTES  [5]LOGICA\n");
                printf("  ---------  -----------  ---------  -----------  ---------\n");
                printf("Ingrese la opcion deseada: ");
                fflush(stdin);
                opcion = getch();
                switch(opcion)
                {
                    case '1':
                        Genero = GENERO_ACCION;
                        ban = 1;
                        break;
                    case '2':
                        Genero = GENERO_AVENTURA;
                        ban = 1;
                        break;
                    case '3':
                        Genero = GENERO_TERROR;
                        ban = 1;
                        break;
                    case '4':
                        Genero = GENERO_DEPORTE;
                        ban = 1;
                        break;
                    case '5':
                        Genero = GENERO_LOGICA;
                        ban = 1;
                        break;
                    default:
                        printf("\n\nLa opcion ingresada no existe.\n--------> REINGRESE <--------\n");
                        system("pause");
                        system("cls");
                }
            }while(ban == 0);

            Juego = 100+lista->len(lista);

            strcpy(videojuego->Nombre,Nombre);
            strcpy(videojuego->Desarrolladora,Desarrolladora);
            videojuego->Genero = Genero;
            videojuego->Juego = Juego;

            al_add(lista,videojuego);
        }
        else
        {
            free(videojuego);
        }
}

void mostrarTodo(ArrayList* jugadores,ArrayList* juegos)
{
    char opcion;
    char seguir= 's';

    do
    {
        system("cls");
        printf("*****************************************************************\n");
        printf("*   1. [JUEGOS]X   2. [JUGADORES]X   3. [JUEGOS Y JUGADORES]    *\n");
        printf("*****************************************************************\n");
        printf("*       4. [JUGADOR/JUEGOS]         5. [JUEGO/JUGADORES]        *\n");
        printf("*****************************************************************\n");
        printf("*                         6. [SALIR]                            *\n");
        printf("*****************************************************************\n");
        printf("\nIngrese la opcion deseada: ");
        fflush(stdin);
        opcion = getche();

        switch(opcion)
        {
            case '1':
                Mostrar_Juegos(juegos);
                break;
            case '2':
                Mostrar_Jugadores(jugadores);
                break;
            case '3':
                Mostrar_Juegos_Jugadores(juegos,jugadores);
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                seguir = 'n';
                break;
            default:
              system("cls");
              printf("\n\nLa opcion ingresada es invalida\n------->REINGRESE<-------\n");
              system("pause");
        }

    }while(seguir == 's');

}

void menu()
{
    char opcion;
    char seguir = 's';
    //eJugador* gamer = NULL;
    //eGame* juego = NULL;

    ArrayList* lista_jugadores = al_newArrayList();
    ArrayList* lista_juegos = al_newArrayList();

    if(lista_juegos != NULL && lista_jugadores != NULL)
    {
        do
        {
            system("cls");
            printf("*************************************************************\n");
            printf("*      1. [CARGAR JUGADOR]X         2. [CARGAR JUEGO]X      *\n");
            printf("*************************************************************\n");
            printf("*      3. [MOSTRAR]                 4. [MODIFICAR]X         *\n");
            printf("*************************************************************\n");
            printf("*      5. [BAJAS]X                  6. [CARGAS]             *\n");
            printf("*************************************************************\n");
            printf("*                        7. [SALIR]                         *\n");
            printf("*************************************************************\n");
            printf("\nIngrese la opcion deseada: ");
            fflush(stdin);
            opcion = getche();

            switch(opcion)
            {
                    case '1':
                        new_jugador(lista_jugadores);
                        break;
                    case '2':
                        new_game(lista_juegos);
                        break;
                    case '3':
                        mostrarTodo(lista_jugadores,lista_juegos);
                        break;
                    case '4':
                        Modificar(lista_juegos,lista_jugadores);
                        break;
                    case '5':

                        break;
                    case '6':
                        Cargar_juego(lista_juegos,lista_jugadores);
                        break;
                    case '7':
                        free(lista_juegos);
                        free(lista_jugadores);
                        exit(1);
                        break;
                    default:
                    system("cls");
                    printf("\n\nLa opcion ingresada es invalida\n------->REINGRESE<-------\n");
                    system("pause");
                }
        }while(seguir == 's');
    }
    else
    {
        system("cls");
        printf("Lamentablemente hubo un Error,\nPor Favor Reintente mas tarde.\n\n");
        system("pause");
        exit(1);
    }

}

void Modificar(ArrayList* juego,ArrayList* gamer)
{
    int seguir = 1;
    char opcion;

        do
        {
            system("cls");
            printf("*************************************************************\n");
            printf("*    1. [MODIFICAR JUGADOR]   ***   2. [MODIFICAR JUEGO]    *\n");
            printf("*************************************************************\n");
            printf("*                        3. [SALIR]                         *\n");
            printf("*************************************************************\n");
            printf("\nIngrese una opcion: ");
            fflush(stdin);
            opcion = getch();

            switch(opcion)
            {
                case '1':
                    Modificar_jugador(gamer);
                    break;
                case '2':
                    Modificar_juego(juego);
                    break;
                case '3':
                    seguir = 0;
                    break;
                default:
                    system("cls");
                    printf("\n\nLa opcion ingresada es invalida\n------->REINGRESE<-------\n");
                    system("pause");
            }
        }while(seguir == 1);

}

void Modificar_juego(ArrayList* this)
{
    eGame* auxliar = NULL;
    eGame* Modificado;
    char opcion;
    int posicion;
    int i;

    char Nombre[30];
    char Desarrolladora[20];
    int Genero;

       if(al_isEmpty(this) == 0)
       {
            system("cls");
            printf("***************************************************\n");
            printf("***********------->   JUEGOS   <-------************\n\n");
            for(i=0; i<this->len(this) ;i++)
            {
                auxliar = (eGame*) al_get(this,i);
                printf("*  [ %d ] -------------> %s\n",i,(auxliar->Nombre+i));
            }

            printf("\nIngrese el NUMERO de la posicion del juego a modificar: ");
            scanf("%d",&posicion);

            Modificado = (eGame*) al_get(this,posicion);

            if(Modificado != NULL)
            {
                system("cls");
                printf("***************************************************\n");
                printf("*-------------> 1. Modificar Nombre <-------------*\n");
                printf("*-------------> 2. Modificar Desarrolladora <-----*\n");
                printf("*-------------> 3. Modificar Genero <-------------*\n");
                printf("***************************************************\n");
                printf("\nIngrese la opcion deseada: ");
                fflush(stdin);
                opcion = getch();

                switch(opcion)
                {
                    case '1':
                        system("cls");
                        printf("ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(Nombre);

                        strcpy(Modificado->Nombre,Nombre);

                        al_set(this,posicion,Modificado);
                        break;
                    case '2':
                        system("cls");
                        printf("ingrese nuevo desarrollador: ");
                        fflush(stdin);
                        gets(Desarrolladora);

                        strcpy(Modificado->Desarrolladora,Desarrolladora);

                        al_set(this,posicion,Modificado);
                        break;
                    case '3':
                        system("cls");
                        printf("\n\t\t  [1]ACCION  [2]AVENTURA  [3]TERROR  [4]DEPORTES  [5]LOGICA\n");
                        printf("ingrese nuevo Genero: ");

                        scanf("%d",&Genero);

                        switch(Genero)
                        {
                            case 1:
                                Modificado->Genero = GENERO_ACCION;
                                break;
                            case 2:
                                Modificado->Genero = GENERO_AVENTURA;
                                break;
                            case 3:
                                Modificado->Genero = GENERO_TERROR;
                                break;
                            case 4:
                                Modificado->Genero = GENERO_DEPORTE;
                                break;
                            case 5:
                                Modificado->Genero = GENERO_LOGICA;
                                break;
                        }

                        al_set(this,posicion,Modificado);
                        break;
                    default:
                        printf("\n\nLa opcion ingresada es invalida\n\n");
                        system("pause");
                }
            }
       }
       else
       {
           system("cls");
           printf("\n\nNo hay juegos ingresados para hacer alguna modificacion.\n\n");
           system("pause");
       }
}

void Modificar_jugador(ArrayList* this)
{
    eJugador* auxliar = NULL;
    eJugador* Modificado;
    char opcion;
    int posicion;
    int i;

    char Nick[20];
    char contrasena[30];
    char E_mail[35];

        if(al_isEmpty(this) == 0)
        {
                system("cls");
                printf("***************************************************\n");
                printf("********------->   JUGADORES   <-------************\n\n");
                for(i=0; i<this->len(this) ;i++)
                {
                    auxliar = (eJugador*) al_get(this,i);
                    printf("*  [ %d ] -------------> %s\n",i,(auxliar->Nick+i));
                }

                printf("\nIngrese el NUMERO de la posicion del Jugador a modificar: ");
                scanf("%d",&posicion);

                Modificado = (eJugador*) al_get(this,posicion);

                if(Modificado != NULL)
                {
                    system("cls");
                    printf("*************************************************\n");
                    printf("*-------------> 1. Modificar Nick <-------------*\n");
                    printf("*-------------> 2. Modificar Contrasena <-------*\n");
                    printf("*-------------> 3. Modificar E_mail <-----------*\n");
                    printf("*************************************************\n");
                    printf("\nIngrese la opcion deseada: ");
                    fflush(stdin);
                    opcion = getch();

                    switch(opcion)
                    {
                        case '1':
                            system("cls");
                            printf("ingrese nuevo Nick: ");
                            fflush(stdin);
                            gets(Nick);

                            strcpy(Modificado->Nick,Nick);

                            al_set(this,posicion,Modificado);
                            break;
                        case '2':
                            system("cls");
                            printf("ingrese nueva Contrasena: ");
                            fflush(stdin);
                            gets(contrasena);

                            strcpy(Modificado->contrasena,contrasena);

                            al_set(this,posicion,Modificado);
                            break;
                        case '3':
                            system("cls");
                            printf("ingrese nuevo E-Mail: ");
                            fflush(stdin);
                            gets(E_mail);

                            strcpy(Modificado->E_mail,E_mail);

                            al_set(this,posicion,Modificado);
                            break;
                        default:
                            printf("\n\nLa opcion ingresada es invalida\n\n");
                            system("pause");
                    }
                }
        }
        else
        {
            system("cls");
            printf("\n\nNo hay jugadores cargados para hacer ninguna modificacion.\n");
            system("pause");
        }

}

void Baja_Jugador(ArrayList* this)
{
    eJugador* jugador;
    int posicion;
    int i;
    char seguir;

        if(al_isEmpty(this) == 0)
        {
             system("cls");
                printf("***************************************************\n");
                printf("********------->   JUGADORES   <-------************\n\n");
                for(i=0; i<this->len(this) ;i++)
                {
                    jugador = (eJugador*) al_get(this,i);
                    printf("*  [ %d ] -------------> %s\n",i,(jugador->Nick+i));
                }

                printf("\nIngrese el NUMERO de la posicion del Jugador a dar de baja: ");
                scanf("%d",&posicion);

                if(al_contains(this,al_get(this,posicion)) == 1)
                {
                    jugador = (eJugador*) al_get(this,posicion);
                    system("cls");
                    printf("***************************************************\n");
                    printf("***** NICK ******* CONTRASENA ****** E-MAIL********\n");
                    printf("    %s      %s      %s\n\n",jugador->Nick,jugador->contrasena,jugador->E_mail);
                    printf("Desea dar de baja a este jugador? ( s / n ): ");
                    fflush(stdin);
                    seguir = tolower(getch());

                    if(seguir == 's')
                    {
                        al_remove(this,posicion);
                        system("cls");
                        printf("\n\nBaja Exitosa.\n->>>>>>>>>GAME OVER<<<<<<<<<-\n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("\n\nSe a cancelado la operacion.\n\n");
                        system("pause");
                    }

                }
        }
        else
        {
            system("cls");
            printf("\n\nNo hay jugadores cargados para dar ninguna baja.\n");
            system("pause");
        }
}

void Bajas(ArrayList* juegos,ArrayList* jugadores)
{
    char opcion;
    char seguir = 's';

      do
        {
            system("cls");
            printf("***********************************************************\n");
            printf("*       1. [BAJA JUGADOR]       2. [BAJA JUEGO]           *\n");
            printf("***********************************************************\n");
            printf("*       3. [BAJA JUGADORES]     4. [BAJA JUEGOS]          *\n");
            printf("***********************************************************\n");
            printf("*                      5. [SALIR]                         *\n");
            printf("***********************************************************\n");
            printf("\nIngrese la opcion deseada: ");
            fflush(stdin);
            opcion = getch();

            switch(opcion)
            {
                case '1':
                    Baja_Jugador(jugadores);
                    break;
                case '2':
                    Baja_Juego(juegos);
                    break;
                case '3':
                    Baja_Jugadores(jugadores);
                    break;
                case '4':
                    Baja_Juegos(juegos);
                    break;
                case '5':
                    seguir = 'n';
                    break;
                default:
                    printf("\n\nLa opcion ingresada es invalida\n\n");
                    system("pause");
            }

        }while(seguir == 's');

}

void Baja_Juego(ArrayList* this)
{
    eGame* juego;
    int posicion;
    int i;
    char seguir;

        if(al_isEmpty(this) == 0)
        {
             system("cls");
                printf("***************************************************\n");
                printf("***********------->   JUEGOS   <-------************\n\n");
                for(i=0; i<this->len(this) ;i++)
                {
                    juego = (eGame*) al_get(this,i);
                    printf("*  [ %d ] -------------> %s\n",i,(juego->Nombre+i));
                }

                printf("\nIngrese el NUMERO de la posicion del juego a dar de baja: ");
                scanf("%d",&posicion);

                if(al_contains(this,al_get(this,posicion)) == 1)
                {
                    juego = (eGame*) al_get(this,posicion);
                    system("cls");
                    printf("***************************************************\n");
                    printf("***** NOMBRE ******* DESARROLLADORA ****** GENERO********\n");
                    switch(juego->Genero)
                    {
                        case GENERO_ACCION:
                            printf("*      %s       %s      ACCION\n",juego->Nombre,juego->Desarrolladora);
                            break;
                        case GENERO_AVENTURA:
                            printf("*      %s       %s      AVENTURA\n",juego->Nombre,juego->Desarrolladora);
                            break;
                        case GENERO_TERROR:
                            printf("*      %s       %s      TERROR\n",juego->Nombre,juego->Desarrolladora);
                            break;
                        case GENERO_DEPORTE:
                            printf("*      %s       %s      DEPORTE\n",juego->Nombre,juego->Desarrolladora);
                            break;
                        case GENERO_LOGICA:
                            printf("*      %s       %s      LOGICA\n",juego->Nombre,juego->Desarrolladora);
                            break;
                    }
                    printf("\nDesea dar de baja a este Juego? ( s / n ): ");
                    fflush(stdin);
                    seguir = tolower(getch());

                    if(seguir == 's')
                    {
                        al_remove(this,posicion);
                        system("cls");
                        printf("\n\nBaja Exitosa.\n->>>>>>>>>GAME OVER<<<<<<<<<-\n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("\n\nSe a cancelado la operacion.\n\n");
                        system("pause");
                    }

                }
        }
        else
        {
            system("cls");
            printf("\n\nNo hay Juegos cargados para dar alguna baja.\n");
            system("pause");
        }
}

void Baja_Jugadores(ArrayList* this)
{
    eJugador* jugador;
    int i;
    char seguir;

        if(al_isEmpty(this) == 0)
        {
           system("cls");
           printf("*****************************************************\n");
           printf("************-------->JUGADORES<-------***************\n");
            for(i=0; i<this->len(this) ;i++)
            {
                jugador = (eJugador*) al_get(this,i);
                printf("*  [ %d ] -------------> %s\n",i,(jugador->Nick+i));
            }
            printf("\nDsea dar de baja a todos los jugadores? ( s / n ): ");
            fflush(stdin);
            seguir = tolower(getch());

            if(seguir == 's')
            {
                if(al_clear(this)==0)
                {
                   system("cls");
                   printf("Todos los jugadores an sido Eliminados con exito.\n\n");
                   system("pause");
                }
                else
                {
                    system("cls");
                    printf("Se a producido un Error y no se a podido efectuar la baja.\n\n");
                    system("pause");
                }

            }
        }
        else
        {
            system("cls");
            printf("\n\nNo hay jugadores cargados para dar los de baja.\n");
            system("pause");
        }
}

void Baja_Juegos(ArrayList* this)
{
    eGame* juego;
    int i;
    char seguir;

        if(al_isEmpty(this) == 0)
        {
           system("cls");
           printf("*****************************************************\n");
           printf("*************---------->JUEGOS<-------***************\n");
            for(i=0; i<this->len(this) ;i++)
            {
                juego = (eGame*) al_get(this,i);
                printf("*  [ %d ] -------------> %s\n",i,(juego->Nombre+i));
            }
            printf("\nDesea dar de baja a todos los juegos? ( s / n ): ");
            fflush(stdin);
            seguir = tolower(getch());

            if(seguir == 's')
            {
                if(al_clear(this)==0)
                {
                   system("cls");
                   printf("Todos los juegos an sido Eliminados con exito.\n\n");
                   system("pause");
                }
                else
                {
                    system("cls");
                    printf("Se a producido un Error y no se a podido efectuar la baja.\n\n");
                    system("pause");
                }

            }
        }
        else
        {
            system("cls");
            printf("\n\nNo hay juegos cargados para dar los de baja.\n");
            system("pause");
        }
}

int Orden_General()
{
    char Opcion;
    int retornado;
    char seguir = 's';

    do
    {
        system("cls");
        printf("************************************************\n");
        printf("************* [ Ingrese el Orden ] *************\n");
        printf("***** 1. [ Acendente ]    2. [ Decendente ] ****\n");
        fflush(stdin);
        Opcion = getch();

        switch(Opcion)
        {
            case '1':
                retornado = 1;
                seguir = 'n';
                break;
            case '2':
                retornado = 0;
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("Opcion ingresada incorecta\n---------> Reingrese<---------\n");
                system("pause");
        }
    }while(seguir == 's');

    return retornado;
}

void Mostrar_Juegos(ArrayList* this)
{
    int orden;
    eGame* juego;
    int i;
    if(this != NULL)
    {
         if(!al_isEmpty(this))
         {
           orden = Orden_General();

           if(!al_sort(this,Compara_juegos,orden))
           {
               system("cls");
               printf("*****************************************************\n");
               printf("*************---------->JUEGOS<-------***************\n\n");
               for(i=0; i<this->len(this) ;i++)
                {
                    juego = (eGame*) al_get(this,i);
                    printf("*  [ %d ] ------------> %s\n",i,juego->Nombre);
                }
               printf("*****************************************************\n");
               system("pause");
           }
         }
    }
}

int Compara_juegos(void* juegoX, void* juegoZ)
{
    int retorno = 0;

    if(juegoX != NULL && juegoZ != NULL)
    {
        if(strcmp(((eGame*)juegoX)->Nombre,((eGame*)juegoZ)->Nombre) > 0)
        {
            retorno = 1;
        }
        if(strcmp(((eGame*)juegoX)->Nombre,((eGame*)juegoZ)->Nombre) < 0)
        {
            retorno = -1;
        }
    }

    return retorno;
}

void Mostrar_Jugadores(ArrayList* this)
{
    int orden;
    eJugador* jugador;
    int i;
    if(this != NULL)
    {
         if(!al_isEmpty(this))
         {
           orden = Orden_General();

           if(!al_sort(this,Compara_jugadores,orden))
           {
               system("cls");
               printf("********************************************************\n");
               printf("*************---------->JUGADORES<-------***************\n\n");
               for(i=0; i<this->len(this) ;i++)
                {
                    jugador = (eJugador*) al_get(this,i);
                    printf("*  [ %d ] ------------> %s\n",i,jugador->Nick);
                }
               printf("*****************************************************\n");
               system("pause");
           }
         }
    }
}

int Compara_jugadores(void* jugadorX, void* jugadorZ)
{
    int retorno = 0;

    if(jugadorX != NULL && jugadorZ != NULL)
    {
        if(strcmp(((eJugador*)jugadorX)->Nick,((eJugador*)jugadorZ)->Nick) > 0)
        {
            retorno = 1;
        }
        if(strcmp(((eJugador*)jugadorX)->Nick,((eJugador*)jugadorZ)->Nick) < 0)
        {
            retorno = -1;
        }
    }

    return retorno;
}

void Cargar_juego(ArrayList* juegos,ArrayList* jugadores)
{
    int i;
    int posicion;
    int pos_Juego;
    int puntaje;
    char password[30];
    eJugador* auxiliar;
    eGame* juego;

       if(al_isEmpty(jugadores)== 0)
       {
            system("cls");
               printf("********************************************************\n");
               printf("*************---------->JUGADORES<-------***************\n\n");
               for(i=0; i<jugadores->len(jugadores) ;i++)
                {
                    auxiliar = (eJugador*) al_get(jugadores,i);
                    printf("*  [ %d ] ------------> %s\n",i,auxiliar->Nick);
                }
               printf("*****************************************************\n");

                printf("\nIngrese el NUMERO de la posicion del Jugador : ");
                scanf("%d",&posicion);

                auxiliar = (eJugador*) al_get(jugadores,posicion);

                printf("Ingrese su contrasena: ");
                fflush(stdin);
                gets(password);

                if(strcmp(auxiliar->contrasena,password)== 0)
                {
                    system("cls");
                    printf("*****************************************************\n");
                    printf("*************---------->JUEGOS<-------***************\n\n");
                    for(i=0; i<juegos->len(juegos) ;i++)
                    {
                        juego = (eGame*) al_get(juegos,i);
                        printf("*  [ %d ] ------------> %s\n",i,juego->Nombre);
                    }
                    printf("*****************************************************\n\n");

                    printf("Ingrese la posicion del juego elegido: ");
                    scanf("%d",&pos_Juego);

                    juego = (eGame*) al_get(juegos,pos_Juego);

                    printf("Ingrese un puntaje para el Juego; ");
                    scanf("%d",&puntaje);

                    juego->Puntaje = puntaje;
                    juego->Usuario = auxiliar->Usuario;
                }
       }
}

void Mostrar_Juegos_Jugadores(ArrayList* juego,ArrayList* jugador)
{
    int i,j;

    eGame* aux_juego;
    eJugador* aux_jugador;

    if(al_isEmpty(juego)== 0 && al_isEmpty(jugador)== 0)
    {
        system("cls");
        printf("*****************************************************\n");
        printf("*************---------->JUEGOS<-------***************\n\n");
        for(i=0;i<al_len(juego);i++)
        {
            aux_juego = (eGame*) al_get(juego,i);

            printf("%s\n",aux_juego->Nombre);
            printf("------------------------------------------------------\n\n");

            for(j=0;j<al_len(jugador);j++)
            {
                aux_jugador = (eJugador*) al_get(jugador,j);

                if(aux_juego->Usuario == aux_jugador->Usuario)
                {
                    printf("[%d]-->%s\t\t",j,aux_jugador->Nick);
                    if(!(j%3))
                    {
                        printf("\n\n");
                    }
                }
            }
            printf("\n********************************************************\n");
        }
    }
}
