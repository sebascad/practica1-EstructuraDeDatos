//
// NOMBRE:
//

#include "Task.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LEN 20 // Maximum length of task name

/*struct Task {
  unsigned int id;              // Unique task identifier
  char name[1 + MAX_NAME_LEN];  // String with name of task
  unsigned int quantum;         // Time quantum assigned to the task
};*/

struct Task* Task_new(unsigned int id, const char name[], unsigned int quantum){
  
  if (strlen(name) > MAX_NAME_LEN)
  {
    perror("ERROR, el tamaño máximo del nombre es 20");
    exit(1);
  }

  struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
  if (newTask == NULL)
  {
    perror("ERROR, no se pudo alocar la memoria");
    exit(1);
  }

  newTask->id = id;
  strcpy(newTask->name,name);
  newTask->quantum = quantum;

  return newTask;

}

void Task_free(struct Task** p_p_task){
  if (p_p_task == NULL || *p_p_task == NULL)
  {
    perror("El puntero introducido es nulo");
    exit(1);
  }
  
  free(*p_p_task);
  *p_p_task = NULL;

}

struct Task* Task_copyOf(const struct Task* p_task){
  struct Task* copy = (struct Task*)malloc(sizeof(struct Task));
  if (p_task == NULL)
  {
    perror("ERROR al pasar los parámetros");
    exit(1);
  }
  
  if (copy == NULL)
  {
    perror("ERROR, no se pudo alocar la memoria");
    exit(1);
  }
  copy->id = p_task->id;
  strcpy(copy->name,p_task->name);
  copy->quantum = p_task->quantum;
  
  return copy;

}

void Task_print(const struct Task* p_task){
  printf("La identificador de la tarea es %d, el nombre es %s y el quatum asignado es %d\n",
  p_task->id,p_task->name,p_task->quantum);
}