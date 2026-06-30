#ifndef BAJAS_H
#define BAJAS_H

#include <stdio.h>
#include <stdlib.h>

void bajaUna(struct Persona **ptr);
void bajaVarias(struct Persona **ptr);
void bajaTodas(struct Persona **ptr);

//Elimina la primera persona
void bajaUna(struct Persona **ptr)
{
    if(*ptr == NULL){
        printf("No hay registros.\n");
        return;
    }
    struct Persona *temp = *ptr;
    *ptr = (*ptr)->Ptrsig;

    if(temp->PtrAlum != NULL){
        free(temp->PtrAlum);
    }
    free(temp->Nombre);
    free(temp);
    printf("Persona eliminada.\n");
}

//Elimina varias una por una
void bajaVarias(struct Persona **ptr)
{
    if(*ptr == NULL){
        printf("No hay registros.\n");
        return;
    }
    char op;
    do {
        if(*ptr == NULL){
            printf("Ya no hay mas registros.\n");
            break;
        }
        printf("\nPersona a eliminar: %s\n", (*ptr)->Nombre);
        printf("Desea eliminarla? (S/N): ");
        scanf(" %c", &op);

        if(op == 'S' || op == 's'){
            bajaUna(ptr);
        }

        if(*ptr != NULL){
            printf("Desea continuar eliminando? (S/N): ");
            scanf(" %c", &op);
        }

    } while((op == 'S' || op == 's') && *ptr != NULL);
}

// 3. Elimina todas
void bajaTodas(struct Persona **ptr)
{
    if(*ptr == NULL){
        printf("No hay registros.\n");
        return;
    }
    while(*ptr != NULL){
        bajaUna(ptr);
    }
    printf("Todos los registros eliminados.\n");
}

#endif
