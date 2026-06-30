#ifndef ESESPESIALES_H
#define ESESPESIALES_H

#include <stdio.h>

struct Persona;
struct Alumno;

i/*Compara datosCompara dos cadenas de texto carácter por carácter para saber si son exactamente iguales.
 Regresa 1 si son iguales y 0 si son diferentes.*/
int sonIguales(char *a, char *b)
{
    int i = 0;//Contador
    while(a[i] != '\0' && b[i] != '\0'){//El ciclo se repite mientras ninguna de las dos cadenas haya llegado a su fin\0 es nulo
        if(a[i] != b[i]) return 0;//compara el caracter i en todos los caracteres pera ver si son iguyales.
        i++;
    }
    return a[i] == b[i];// Resive 1 si son igules y 0n si no
}
struct Persona* buscarPorMatricula(struct Persona *ptr, char *matricula)
{
    struct Persona *aux = ptr;
    while(aux != NULL){
        if(aux->PtrAlum != NULL && sonIgualesEsp(aux->PtrAlum->Matricula, matricula)){
            return aux;
        }
        aux = aux->Ptrsig;
    }
    return NULL;
}

void modCalifPorParcial(struct Alumno *A)
{
    int parcial, i;
    printf("Que parcial deseas modificar (1,2,3, u Ordinario=4)?: ");
    scanf(" %d", &parcial);

    if(parcial < 1 || parcial > 4){
        printf("Parcial invalido.\n");
        return;
    }

    for(i = 0; i < 5; i++){
        printf("Materia %d - nueva calificacion: ", i+1);
        scanf(" %f", &A->Calif[i][parcial-1]);

        float promParciales = (A->Calif[i][0] + A->Calif[i][1] + A->Calif[i][2]) / 3;
        A->Calif[i][4] = (promParciales * 0.50) + (A->Calif[i][3] * 0.50);
    }
    printf("Calificaciones actualizadas.\n");
}

void modCalifPorMateria(struct Alumno *A)
{
    int materia;
    printf("Que materia deseas modificar (1-5)?: ");
    scanf(" %d", &materia);

    if(materia < 1 || materia > 5){
        printf("Materia invalida.\n");
        return;
    }
    materia--;

    printf("Parcial 1: ");
    scanf(" %f", &A->Calif[materia][0]);
    printf("Parcial 2: ");
    scanf(" %f", &A->Calif[materia][1]);
    printf("Parcial 3: ");
    scanf(" %f", &A->Calif[materia][2]);
    printf("Ordinario: ");
    scanf(" %f", &A->Calif[materia][3]);

    float promParciales = (A->Calif[materia][0] + A->Calif[materia][1] + A->Calif[materia][2]) / 3;
    A->Calif[materia][4] = (promParciales * 0.50) + (A->Calif[materia][3] * 0.50);

    printf("Materia actualizada. Promedio final: %.2f\n", A->Calif[materia][4]);
}

void modDatosPersona(struct Persona *P)
{
    printf("Nuevo nombre: ");
    scanf(" %49s", P->Nombre);
    printf("Nueva edad: ");
    scanf(" %d", &P->Edad);
    printf("Nuevo genero (M/F): ");
    scanf(" %c", &P->Genero);
    printf("Nueva fecha de nacimiento (DDMMAAAA): ");
    scanf(" %11s", P->Fn);
    printf("Datos de la persona actualizados.\n");
}

void modDatosAlumno(struct Alumno *A)
{
    printf("Nueva matricula: ");
    scanf(" %9s", A->Matricula);
    printf("Nueva carrera: ");
    scanf(" %10s", A->Carrera);
    printf("Nuevo semestre: ");
    scanf(" %d", &A->Semestre);
    printf("Nuevo correo: ");
    scanf(" %22s", A->Correo);
    printf("Datos del alumno actualizados.\n");
}

void menuModificarLogica(struct Persona *ptr)
{
    int Op5, Op6;
    struct Persona *p;
    char matricula[10];

    do{
        Op5 = menuModificar();
        switch(Op5){
        case 1: // Calificaciones de un alumno
            printf("Ingresa la matricula: ");
            scanf(" %9s", matricula);
            p = buscarPorMatricula(ptr, matricula);
            if(p == NULL){
                printf("No se encontro esa matricula.\n");
            } else {
                Op6 = menuModificarCalif();
                if(Op6 == 1) modCalifPorParcial(p->PtrAlum);
                else if(Op6 == 2) modCalifPorMateria(p->PtrAlum);
            }
            break;
        case 2: // Datos
            printf("Ingresa la matricula: ");
            scanf(" %9s", matricula);
            p = buscarPorMatricula(ptr, matricula);
            if(p == NULL){
                printf("No se encontro esa matricula.\n");
            } else {
                Op6 = menuModificarDatos();
                if(Op6 == 1) modDatosPersona(p);
                else if(Op6 == 2) modDatosAlumno(p->PtrAlum);
            }
            break;
        default:
            break;
        }
    }while(Op5 != 3);
}

#endif
