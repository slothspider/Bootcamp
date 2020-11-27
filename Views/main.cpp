#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Controllers/controllers.h"

int main() {
  int patients, cure;
  ID id;
  scanf("%d %d", &patients, &cure); getchar();
  for (int i = 0; i < patients; i++) {
    scanf("%d %s %d - %[^\n]", &id.day, id.month, &id.year, id.name); getchar();
    insert(id);
  }
  if (cure >= patients) {
    while (head) {
      popHead();
    }
    printf("All patients get the cure, %d cure left\n", cure - patients);
  }
  else {
    printf("Need %d more cure\n", patients - cure);
    while (cure--) {
      popHead();
    }
    printAll();
    while (head) {
      popHead();
    }
  }
  return 0;
}