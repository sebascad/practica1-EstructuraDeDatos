//
// Pepe Gallardo, Data Structures, UMA.
//

#include "Scheduler.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  struct Node* sch = Scheduler_new();
  // Enqueue a heap allocated task
  struct Task* p_task1 = Task_new(1, "Task1", 2);
  struct Task* p_task2 = Task_new(2, "Task2", 4);
  struct Task* p_task3 = Task_new(3, "Task3", 2);

  Scheduler_enqueue(&sch, p_task1);
  Scheduler_enqueue(&sch, p_task2);
  Scheduler_enqueue(&sch, p_task3);

  free(p_task1);
  free(p_task2);
  free(p_task3);

 //Se creativo....

  return 0;
}
