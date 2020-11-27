#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Models/models.h"

int checkMonth(char* month) {
  if (!strcmp(month, "january")) {
    return 1;
  }
  else if (!strcmp(month, "february")) {
    return 2;
  }
  else if (!strcmp(month, "march")) {
    return 3;
  }
  else if (!strcmp(month, "april")) {
    return 4;
  }
  else if (!strcmp(month, "may")) {
    return 5;
  }
  else if (!strcmp(month, "june")) {
    return 6;
  }
  else if (!strcmp(month, "july")) {
    return 7;
  }
  else if (!strcmp(month, "august")) {
    return 8;
  }
  else if (!strcmp(month, "september")) {
    return 9;
  }
  else if (!strcmp(month, "october")) {
    return 10;
  }
  else if (!strcmp(month, "november")) {
    return 11;
  }
  else if (!strcmp(month, "december")) {
    return 12;
  }
  return 0;
}

Node* createNode(ID id) {
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->id.day = id.day;
  strcpy(temp->id.month, id.month);
  temp->id.year = id.year;
  strcpy(temp->id.name, id.name);
  temp->prev = temp->next = NULL;
  return temp;
}

int check(Node* more, Node* less) {
  if (more->id.year > less->id.year) {
    return 1;
  }
  else if (more->id.year < less->id.year) {
    return 0;
  }

  if (checkMonth(more->id.month) > checkMonth(less->id.month)) {
    return 1;
  }
  else if (checkMonth(more->id.month) < checkMonth(less->id.month)) {
    return 0;
  }

  if (more->id.day > less->id.day) {
    return 1;
  }
  else if (more->id.day < less->id.day) {
    return 0;
  }

  return 0;
}

void insert(ID id) {
  Node* temp = createNode(id);
  if (!head) {
    head = tail = temp;
  }
  else if (check(head, temp)) {
    if (!head) {
      head = tail = temp;
    }
    else {
      head->prev = temp;
      temp->next = head;
      head = temp;
    }
  }
  else if (check(temp, tail)) {
    if (!head) {
      head = tail = temp;
    }
    else {
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
  }
  else {
    curr = head;
    while (!check(curr, temp)) {
      curr = curr->next;
    }
    temp->prev = curr->prev;
    temp->next = curr;
    curr->prev->next = temp;
    curr->prev = temp;
  }
}

void popHead() {
  if (head && head == tail) {
    head = tail = NULL;
    free(head);
  }
  else {
    Node* newHead = head->next;
    head->next = newHead->prev = NULL;
    free(head);
    head = newHead;
  }
}

void printAll() {
  curr = head;
  while (curr) {
    printf("%d %s %d - %s\n", curr->id.day, curr->id.month, curr->id.year, curr->id.name);
    curr = curr->next;
  }
}
