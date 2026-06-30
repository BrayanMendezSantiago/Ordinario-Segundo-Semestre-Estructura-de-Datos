#ifndef MOSTRAR_H
#define MOSTRAR_H

#include <stdio.h>

struct Alumno;
struct Persona;

/*Compara datosCompara dos cadenas de texto carácter por carácter para saber si son exactamente iguales.
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

void mostrarTodos(struct Persona *ptr);
void mostrarPorCarrera(struct Persona *ptr);
void mostrarPorSemestre(struct Persona *ptr);
void mostrarPorCarreraYSemestre(struct Persona *ptr);
void mostrarPorNombre(struct Persona *ptr);
void mostrarPorMatricula(struct Persona *ptr);

// 1. Mostrar todos
void mostrarTodos(struct Persona *ptr)
{
    if(ptr == NULL){
        printf("No hay registros.\n");
        return;
    }
    struct Persona *aux = ptr;

    while(aux != NULL){
        printf("\n--- Persona ---\n");
        printf("Nombre: %s\n", aux->Nombre);
        printf("Edad: %d\n", aux->Edad);
        printf("Genero: %c\n", aux->Genero);
        printf("Fecha de nacimiento: %s\n", aux->Fn);
        if(aux->PtrAlum != NULL){
            printf("--- Alumno ---\n");
            printf("Matricula: %s\n", aux->PtrAlum->Matricula);
            printf("Carrera: %s\n", aux->PtrAlum->Carrera);
            printf("Semestre: %d\n", aux->PtrAlum->Semestre);
            printf("Correo: %s\n", aux->PtrAlum->Correo);
            int i;
            for(i = 0; i < 5; i++){
                printf("Materia %d - Promedio: %.2f\n", i+1, aux->PtrAlum->Calif[i][4]);
            }
        }
        aux = aux->Ptrsig;
    }
}

// 2. Mostrar por carrera
void mostrarPorCarrera(struct Persona *ptr)
{
    if(ptr == NULL){ 
    printf("No hay registros.\n"); 
    return; 
    }
    char carrera[20];
    printf("Ingresa la carrera: ");
    scanf(" %19s", carrera);

    struct Persona *aux = ptr;
    int encontrado = 0;
    while(aux != NULL){
        if(aux->PtrAlum != NULL && sonIguales(aux->PtrAlum->Carrera, carrera)){
            printf("\nNombre: %s | Matricula: %s | Semestre: %d\n",
                aux->Nombre, aux->PtrAlum->Matricula, aux->PtrAlum->Semestre);
            int i;
            for(i = 0; i < 5; i++){
                printf("Materia %d - Promedio: %.2f\n", i+1, aux->PtrAlum->Calif[i][4]);
            }
            encontrado = 1;
        }
        aux = aux->Ptrsig;
    }
    if(!encontrado) printf("No se encontraron alumnos de esa carrera.\n");
}

// 3. Mostrar por semestre
void mostrarPorSemestre(struct Persona *ptr)
{
    if(ptr == NULL){
    printf("No hay registros.\n");
    return;
    }
    int semestre;
    printf("Ingresa el semestre: ");
    scanf(" %d", &semestre);

    struct Persona *aux = ptr;
    int encontrado = 0;
    while(aux != NULL){
        if(aux->PtrAlum != NULL && aux->PtrAlum->Semestre == semestre){
            printf("\nNombre: %s | Matricula: %s | Carrera: %s\n",
                aux->Nombre, aux->PtrAlum->Matricula, aux->PtrAlum->Carrera);
            int i;
            for(i = 0; i < 5; i++){
                printf("Materia %d - Promedio: %.2f\n", i+1, aux->PtrAlum->Calif[i][4]);
            }
            encontrado = 1;
        }
        aux = aux->Ptrsig;
    }
    if(!encontrado) printf("No se encontraron alumnos de ese semestre.\n");
}

// 4. Mostrar por carrera y semestre
void mostrarPorCarreraYSemestre(struct Persona *ptr)
{
    if(ptr == NULL){
    printf("No hay registros.\n"); 
    return; 
    }
    char carrera[20];
    int semestre;
    printf("Ingresa la carrera: ");
    scanf(" %19s", carrera);
    printf("Ingresa el semestre: ");
    scanf(" %d", &semestre);

    struct Persona *aux = ptr;
    int encontrado = 0;
    while(aux != NULL){
        if(aux->PtrAlum != NULL &&
           sonIguales(aux->PtrAlum->Carrera, carrera) &&
           aux->PtrAlum->Semestre == semestre){
            printf("\nNombre: %s | Matricula: %s\n",
                aux->Nombre, aux->PtrAlum->Matricula);
            int i;
            for(i = 0; i < 5; i++){
                printf("Materia %d - Promedio: %.2f\n", i+1, aux->PtrAlum->Calif[i][4]);
            }
            encontrado = 1;
        }
        aux = aux->Ptrsig;
    }
    if(!encontrado) printf("No se encontraron alumnos.\n");
}

// 5. Mostrar por nombre
void mostrarPorNombre(struct Persona *ptr)
{
    if(ptr == NULL){ 
    printf("No hay registros.\n");
    return;
    }
    char nombre[50];
    printf("Ingresa el nombre: ");
    scanf(" %49s", nombre);

    struct Persona *aux = ptr;
    int encontrado = 0;
    while(aux != NULL){
        if(sonIguales(aux->Nombre, nombre)){
            printf("\nNombre: %s | Edad: %d | Genero: %c\n",
                aux->Nombre, aux->Edad, aux->Genero);
            if(aux->PtrAlum != NULL){
                printf("Matricula: %s | Carrera: %s\n",
                    aux->PtrAlum->Matricula, aux->PtrAlum->Carrera);
                int i;
                for(i = 0; i < 5; i++){
                    printf("Materia %d - Promedio: %.2f\n", i+1, aux->PtrAlum->Calif[i][4]);
                }
            }
            encontrado = 1;
        }
        aux = aux->Ptrsig;
    }
    if(!encontrado) printf("No se encontro la persona.\n");
}

// 6. Mostrar por matricula
void mostrarPorMatricula(struct Persona *ptr)
{
    if(ptr == NULL){
    printf("No hay registros.\n");
    return;
    }
    char matricula[10];
    printf("Ingresa la matricula: ");
    scanf(" %9s", matricula);

    struct Persona *aux = ptr;
    int encontrado = 0;
    while(aux != NULL){
        if(aux->PtrAlum != NULL && sonIguales(aux->PtrAlum->Matricula, matricula)){
            printf("\nNombre: %s | Carrera: %s | Semestre: %d | Correo: %s\n",
                aux->Nombre, aux->PtrAlum->Carrera,
                aux->PtrAlum->Semestre, aux->PtrAlum->Correo);
            int i;
            for(i = 0; i < 5; i++){
                printf("Materia %d - Promedio: %.2f\n", i+1, aux->PtrAlum->Calif[i][4]);
            }
            encontrado = 1;
        }
        aux = aux->Ptrsig;
    }
    if(!encontrado) printf("No se encontro la matricula.\n");
}

#endif
