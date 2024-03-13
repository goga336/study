#include <iostream>

struct list {
  int num;
  list* next;
  list* prev;
};

int count = 0;
list* head = nullptr;
list* tail = nullptr;

void push_back(int val){
 list* node = new list{val, nullptr, nullptr};
  if (count == 0){
    head = node;
    tail = node;
  }
  else
    {
      tail->next = node;
      node->prev = tail;
      tail = node;

    }
  count++;
}

void print(){
  list* current = head;
  while (current != nullptr) {
    std::cout << current->num << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

void find_posl(int find) {
  list* current = head;
  int k = 1;

  while (current != nullptr) {
    if (current->num == find) {
      std::cout << "Number " << find << " is at position " << k << std::endl;
      return;
    }
    current = current->next;
    k++;
  }
  std::cout << "Number " << find << " not found in the list." << std::endl;
}

void sort_bubble() {
    int swapped;
    list* ptr1;
    list* lptr = nullptr;

    // Пустой список
    if (head == nullptr)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->num > ptr1->next->num) {
                // Обмен значениями
                std::swap(ptr1->num, ptr1->next->num);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void delete_el(int ind) {
    list* current = head;
    while (current != nullptr) {
        if (current->num == ind) {
            if (current == head) {
                // Удаляемый элемент — первый в списке
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                } else {
                    // Если после удаления список стал пустым, обновляем tail
                    tail = nullptr;
                }
            } else {
                // Удаляемый элемент находится не в начале списка
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    // Если удаляемый элемент — последний в списке, обновляем tail
                    tail = current->prev;
                }
            }

            delete current;
            count--;
            return;
        }

        current = current->next;
    }

    std::cout << "Element " << ind << " not found in the list." << std::endl;
}

int main(){
  int mas[] = {230, 150, 100, 85, 77, 33, 93, 200, 57, 137, 205};
  int length = sizeof(mas) / sizeof(mas[0]);
  
  for (int i = 0; i < length; i++){
    push_back(mas[i]);
  }

  find_posl(100);
  print();
  sort_bubble();
  print();
  delete_el(100);
  print();
  return 0;
}
