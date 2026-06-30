#include <stdio.h>
#include <stdlib.h>

//Librerias propias.
#include "menu.h"

struct Alumno{
    char Matricula[10];
    char Carrera[11];//puede ser apuntador
    int Semestre;
    char Correo[23];
    float Calif[5][5];
};
struct Persona{
    char *Nombre;
    int Edad;
    char Genero;
    char Fn[11];// fecha de nacimiento
    struct Alumno *PtrAlum;
    struct Persona *Ptrsig;
};

//Llmada a libreras propias, en este punto porque el codigo lee de abajo a rriva 
#include "altas.h"
#include "Mostrar.h"
#include "Bajas.h"
#include "FunEspl.h"

int main(void){

    int Op,Op2,Op3,Op4,Op5,Op6;
    struct Persona *ptr = NULL;
    struct Persona *p = NULL;
    char matricula[10];
    
    do {
        Op = menuPrincipal();

        switch (Op)
        {
        case 1:
            //
            Altas(&ptr);
            break;
        case 2:
            do{
                Op2 = menuMostrar();

                switch (Op2)
                {
                case 1:
                   mostrarTodos(ptr);
                    break;
                case 2:
                    mostrarPorCarrera(ptr);
                    break;
                case 3:
                    mostrarPorSemestre(ptr);
                    break;
                case 4:
                    mostrarPorCarreraYSemestre(ptr);
                    break;
                case 5:
                    mostrarPorNombre(ptr);
                    break;
                case 6:
                    mostrarPorMatricula(ptr);
                    break;
                default:
                    break;
                }

            }while (Op2 != 7);
            //
            break;
        case 3:
            do{
                Op3 = menuBajas();

                switch (Op3)
                {
                case 1:
                      bajaUna(&ptr);
                 break;
                case 2:
                     bajaVarias(&ptr);
                 break;
                case 3:
                     bajaTodas(&ptr);
                 break;
                default:
                 break;
              }
            }while (Op3 != 4);
                break;
        case 4:
            
            printf("saliendo....");

            break;
        default:
            break;
        }

    } while (Op != 5);
    
    return 0;
}
