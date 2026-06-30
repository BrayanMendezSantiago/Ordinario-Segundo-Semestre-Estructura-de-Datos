#ifndef ALTAS_H
#define ALTAS_H


#include <stdio.h>
#include <stdlib.h>


int Altas(struct Persona **);
struct Persona* nuevaPersona(void);
struct Alumno*  nuevoAlumno(void);


int Altas(struct Persona **ptr)
{

    struct Persona *P = NULL;
    struct Alumno *A = NULL;
    int b = 1;//Bandera

    P = nuevaPersona();

    if(P == NULL){

        b = 0;

    }else{
        A = nuevoAlumno();
        if(A == NULL){
            b = 0;
            free(P);
        } else {
        //Hace que se cree el dato y lo enlaza
        P->PtrAlum = A;
        P->Ptrsig = *ptr;
        *ptr = P;
        }
    }
    return b;
}

struct Persona* nuevaPersona(void)
{
    struct Persona *P = (struct Persona*)malloc(sizeof(struct Persona));
    if (P == NULL) 
        return NULL;

    P->Nombre = (char*)malloc(50 * sizeof(char));

    if(P->Nombre == NULL){ 
        free(P); 
        return NULL; }
    

    printf("Nombre: \n");
    scanf(" %49s", P->Nombre);
    printf("Edad: \n");
    scanf(" %d", &P->Edad);
    printf("Genero (M/F): \n");
    scanf(" %c", &P->Genero);
    printf("Fecha de nacimiento (DDMMAAAA): \n");
    scanf(" %11s", P->Fn);

    P->PtrAlum = NULL;
    P->Ptrsig  = NULL;

    return P;
}

struct Alumno* nuevoAlumno(void)
{
    struct Alumno *A = (struct Alumno*)malloc(sizeof(struct Alumno));
    if (A == NULL) 
    return NULL;

    printf("Matricula: \n");
    scanf(" %10s", A->Matricula);
    printf("Carrera |Software |Turismo |Forestal |Biologia |Ambientales :");
    scanf(" %11s", A->Carrera);
    printf("Semestre:(1,2,3,4,5,6,7,8,9,10)\n");
    scanf(" %d", &A->Semestre);
    printf("Correo institucional: \n");
    scanf(" %22s", A->Correo);
    int i;
    printf("Ingresa las calificaciones de 5 materias:\n");
    for(i = 0; i < 5; i++){
    printf("\nMateria %d:\n", i+1);
    printf("  Parcial 1:");
    scanf(" %f", &A->Calif[i][0]);
    printf("  Parcial 2: ");
    scanf(" %f", &A->Calif[i][1]);
    printf("  Parcial 3: ");
    scanf(" %f", &A->Calif[i][2]);
    printf("  Ordinario: ");
    scanf(" %f", &A->Calif[i][3]);

    // Calcula promedio automaticamente
    float promParciales = (A->Calif[i][0] + A->Calif[i][1] + A->Calif[i][2]) / 3;
    A->Calif[i][4] = (promParciales * 0.50) + (A->Calif[i][3] * 0.50);

    printf("  Promedio final: %.2f\n", A->Calif[i][4]);
}

    return A;
}

#endif
