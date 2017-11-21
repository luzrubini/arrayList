struct
{
    char descripcion[25];
    int prioridad;
    int demora;
}typedef Tareas;

Tareas* tarea_new(void);
int parserTarea(FILE*,ArrayList*);
void tareas_print(Tareas*);
int tarea_compare(void*,void*);
