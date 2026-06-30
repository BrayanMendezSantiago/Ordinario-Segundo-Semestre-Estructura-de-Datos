#include <stdio.h>

int menuPrincipal(void);
int menuBajas(void);
int menuMostrar(void);
int funcionesEspeciales(void); 


int menuPrincipal(void){
    int op;
    printf("***MENU***\n");
    printf("[1]...Crear datos.\n");
    printf("[2]...Mostrar.\n");
    printf("[3]...Dar de baja usuarios.\n");
    printf("[4]...Funciones Especiales.\n");
    printf("[5]...Salir.\n");
    scanf("%d",&op);
    
    return op;
}

int menuBajas(void){
    int op;
    printf("***MENU_BAJAS***\n");
    printf("[1]...Dar de baja a una persona.\n");
    printf("[2]...Dar a vairas personas.\n");
    printf("[3]....Dar de baja a todos los usuarios.\n");
    printf("[4]...regresar.\n");
    scanf("%d",&op);
    
    return op;
    
}

int menuMostrar(void){
    int op;
    printf("***MENU_MOSTRAR***\n");
    printf("[1]...Moatrar todos los usuarios.\n");
    printf("[2]...Mostrar alumnos de la carrera seleccionada.\n");
    printf("[3]...Mostrar alumnos de el semestre seleccionado.\n");
    printf("[4]...Mostrar alumnos de el semestre y carrera seleccionado.\n");
    printf("[5]...Mostrar alumnos por nombre.\n");
    printf("[6]...Mostrar alumnos por maticula.\n");
    printf("[7]...Regresar.\n");
    scanf("%d",&op);
    
    return op;

}

//MENUS DE FUNVIONES ESPECIALES 

int menuEspeciales(void){
    int op;
    printf("***FUNCIONES_ESPECIALES***\n");
    printf("[1]...Modificar.\n");
    printf("[3]...Regresar.\n");
    scanf("%d",&op);
    return op;
}

int menuModificar(void){
    int op;
    printf("***MODIFICAR***\n");
    printf("[1]...Calificaciones de un alumno.\n");
    printf("[2]...Datos.\n");
    printf("[3]...Regresar.\n");
    scanf("%d",&op);
    return op;
}

int menuModificarCalif(void){
    int op;
    printf("***MODIFICAR_CALIFICACIONES***\n");
    printf("[1]...Por parcial.\n");
    printf("[2]...Por materia.\n");
    printf("[3]...Regresar.\n");
    scanf("%d",&op);
    return op;
}

int menuModificarDatos(void){
    int op;
    printf("***MODIFICAR_DATOS***\n");
    printf("[1]...Datos de la persona.\n");
    printf("[2]...Datos del alumno.\n");
    printf("[3]...Regresar.\n");
    scanf("%d",&op);
    return op;
}
