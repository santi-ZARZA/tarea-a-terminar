#include "funciones.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


eJugador* new_jugador()
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
            Usuario = 1000;

            strcpy(jugador->Nick,Nick);
            strcpy(jugador->contrasena,contrasena);
            strcpy(jugador->E_mail,E_mail);
            jugador->Usuario = Usuario;
        }

    return jugador;
}

eGame* new_game()
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
                printf("       [1]ACCION       [2]AVENTURA      [3]TERROR      [4]DEPORTES      [5]LOGICA\n");
                printf("       ---------       -----------      ---------      -----------      ---------\n");
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

            Juego = 100;

            strcpy(videojuego->Nombre,Nombre);
            strcpy(videojuego->Desarrolladora,Desarrolladora);
            videojuego->Genero = Genero;
            videojuego->Juego = Juego;
        }

    return videojuego;
}

void mostrarTodo(eJugador* jugadores,eGame* juegos)
{
    if(jugadores != NULL && juegos != NULL)
    {
        system("cls");
        printf("                JUGADORES<<<<<|||||||>>>>>JUEGOS\n");
        printf("-------------------------------------------------\n");
        printf("                %s <<<<<|||||||>>>>>%s\n\n",jugadores->Nick,juegos->Nombre);
        system("pause");
    }
}

void menu()
{
    char opcion;
    char seguir = 's';
    eJugador* gamer = NULL;
    eGame* juego = NULL;

    do
    {
        system("cls");
        printf("*************************************************************\n");
        printf("*        1. [CARGAR JUGADOR]   ***   2. [CARGAR JUEGO]      *\n");
        printf("*************************************************************\n");
        printf("*        3. [MOSTRAR]                                       *\n");
        printf("\nIngrese la opcion deseada: ");
        fflush(stdin);
        opcion = getch();

        switch(opcion)
        {
            case '1':
                gamer = new_jugador();
                break;
            case '2':
                juego = new_game();
                break;
            case '3':
                mostrarTodo(gamer,juego);
                break;
            default:
                system("cls");
                printf("\n\nLa opcion ingresada es invalida\n------->REINGRESE<-------\n");
                system("pause");
        }
    }while(seguir == 's');



}
