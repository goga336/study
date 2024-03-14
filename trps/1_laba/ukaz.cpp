#include <iostream>

struct list{
  int num;
  list* next;
};
list * ptr = nullptr;
list *head = nullptr;
int count = 0;
void add(int a){
list *node = new list{a, nullptr};
  if (count == 0){
    ptr = node;
    head = node;
}
else{
  ptr->next = node;
  ptr = node;
count ++;
}
void print(){
  list* cur = head;
  while ()
}
int main(){
 int mas[] = {230, 150, 100, 85, 77, 33, 93, 200, 57, 137, 205};
 
  int length = sizeof(mas) / sizeof(mas[0]);
  
  for (int i = 0; i < length; i++){
    add(mas[i]);
  }
}
