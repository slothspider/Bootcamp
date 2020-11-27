struct ID {
  char name[255];
  int day;
  char month[255];
  int year;
};

struct Node {
  ID id;
  Node* prev, * next;
} *head, * tail, * curr;