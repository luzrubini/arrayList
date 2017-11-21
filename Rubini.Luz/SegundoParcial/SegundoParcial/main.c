#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    system("color 0f");
    char seguir='s';
    int opcion;
    ArrayList* listaTareas=al_newArrayList();
    FILE* miArchivo=NULL;
    Tareas* auxTareas;
    int i;



    while(seguir=='s')
    {
        printf("1- Cargar lista de tareas\n");
        printf("2- Ordenar\n");
        printf("3- Particionar por prioridad\n");
        printf("4- Resolver tarea\n");
        printf("5- Generar\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);
        while(opcion<1 || opcion>7)
        {
            printf("Error! Ingrese una opcion valida: ");
            scanf("%d",&opcion);
        }


        switch(opcion)
        {
            case 1:
                parserTarea(miArchivo,listaTareas);
                break;
            case 2:
                printf("DESCRIPCION\tPRIORIDAD\tDEMORA(HS)\n");
                for(i=0;i<al_len(listaTareas);i++)
                {
                    al_sort(listaTareas,tarea_compare(),1);
                    auxTareas=al_get(listaTareas(),i);
                    tareas_print(auxTareas);
                }
                break;
            case 3:

                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
            seguir = 'n';
                break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
