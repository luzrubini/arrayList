#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
#include <string.h>

int parserTarea(FILE* pFile , ArrayList* listaTarea)
{
    char descripcion[25],prioridad[20],demora[20];
    Tareas* tarea;

    if(listaTarea!=NULL)
    {
        pFile=fopen("tar.csv","r");
        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                fscanf(pFile, "%[^,],%[^,],%[^\n]\n",descripcion,prioridad,demora);
                tarea=tarea_new();
                strcpy(tarea->descripcion,descripcion);
                tarea->prioridad=atoi(prioridad);
                tarea->demora=atoi(demora);

                al_add(listaTarea,tarea);
           }
        }
    }
    fclose(pFile);

    return 0;
}
Tareas* tarea_new(void)
{

    Tareas*returnAux=NULL;
    returnAux=(Tareas*)malloc(sizeof(Tareas));
    return returnAux;

}

void tareas_print(Tareas* this)
{

    if(this!=NULL)
    {
        printf("%s\t\t%d\t\t%d\n",this->descripcion,this->prioridad,this->demora);
    }
}
int tarea_compare(void* pTareaA,void* pTareaB)
{
    int returnAux;
    Tareas* tareaA = (Tareas*) pTareaA;
    Tareas* tareaB = (Tareas*) pTareaB;

    returnAux = strcmp(tareaA->prioridad, tareaB->prioridad);

    return returnAux;
}
