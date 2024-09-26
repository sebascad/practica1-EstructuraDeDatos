//
// NOMBRE:
//

#include "Scheduler.h"
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
/*
struct Node {
  struct Task *task;    // Task to be executed
  struct Node* p_next; // Pointer to next node in circular list
};*/

struct Node* Scheduler_new(void){
  return NULL;
} 

size_t Scheduler_size(const struct Node* p_last){
  //Si la lista esta vacía
  if (p_last == NULL)
  {
    return 0;
  }

  struct Node* iter = p_last->p_next;
  size_t contador = 1;
  while (iter != p_last)
  {
    iter = iter->p_next;
    contador++;
  }
  return contador;

}

void Scheduler_clear(struct Node** p_p_last){
  // Si solo hay un nodo
  struct Node* primero = (*p_p_last)->p_next;
  struct Node* iter;
  if (primero == *p_p_last) {
    free(*p_p_last);
    *p_p_last = NULL;
  }
  else {

  while (primero != *p_p_last) {
    iter = primero->p_next;
    free(primero);
    primero = iter;
  }
  free(*p_p_last);
    *p_p_last = NULL;
  }
}

struct Task* Scheduler_first(const struct Node* p_last){
  if (p_last == NULL) {
  perror("ERROR al introducir los parametros");
  exit(1);
  }
  // Si es el mismo elemento
  if (p_last->p_next == p_last) {
    return p_last->task;
  }
  else {
    return p_last->p_next->task;
  }
}
void Scheduler_enqueue(struct Node** p_p_last,const struct Task* p_task){
//Inicializar si la lista está vacía
 if (p_p_last == NULL || *p_p_last == NULL)
 {
  *p_p_last = (struct Node*) malloc(sizeof(struct Node));
  (*p_p_last)->p_next = *p_p_last;
  (*p_p_last)->task = p_task;
 }
 // Si la lista contiene a algun elemento
 else{
  struct Node* next = (struct Node*) malloc(sizeof(struct Node));
  next->task = p_task;
  next->p_next = (*p_p_last)->p_next;
  (*p_p_last)->p_next = next;
  *p_p_last = next;
 }

} 
void Scheduler_dequeue(struct Node** p_p_last){
  
}
void Scheduler_step(struct Node** p_p_last){
  ;
}
void Scheduler_print(const struct Node* p_last){
  ;
}