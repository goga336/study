#include <iostream>
#include <chrono>

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



int main() {
    int mas[] = {230, 150, 100, 85, 77, 33, 93, 200, 57, 137, 205};
    int length = sizeof(mas) / sizeof(mas[0]);

    // Засекаем начальное время до выполнения функции push_back
    auto start_push_back = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < length; i++) {
        push_back(mas[i]);
    }

    // Засекаем конечное время после выполнения функции push_back
    auto end_push_back = std::chrono::high_resolution_clock::now();
    auto duration_push_back = std::chrono::duration_cast<std::chrono::microseconds>(end_push_back - start_push_back);

    // Выводим результат времени выполнения функции push_back
    std::cout << "Время выполнения функции push_back: " << duration_push_back.count() << " микросекунд." << std::endl;

    // Засекаем начальное время до выполнения функции find_posl
    auto start_find_posl = std::chrono::high_resolution_clock::now();

    find_posl(205);

    // Засекаем конечное время после выполнения функции find_posl
    auto end_find_posl = std::chrono::high_resolution_clock::now();
    auto duration_find_posl = std::chrono::duration_cast<std::chrono::microseconds>(end_find_posl - start_find_posl);

    // Выводим результат времени выполнения функции find_posl
    std::cout << "Время выполнения функции find_posl: " << duration_find_posl.count() << " микросекунд." << std::endl;

    // Засекаем начальное время до выполнения функции sort_bubble
    auto start_sort_bubble = std::chrono::high_resolution_clock::now();

    sort_bubble();

    // Засекаем конечное время после выполнения функции sort_bubble
    auto end_sort_bubble = std::chrono::high_resolution_clock::now();
    auto duration_sort_bubble = std::chrono::duration_cast<std::chrono::microseconds>(end_sort_bubble - start_sort_bubble);

    // Выводим результат времени выполнения функции sort_bubble
    std::cout << "Время выполнения функции sort_bubble: " << duration_sort_bubble.count() << " микросекунд." << std::endl;

    // Засекаем начальное время до выполнения функции delete_el
    auto start_delete_el = std::chrono::high_resolution_clock::now();

    delete_el(100);

    // Засекаем конечное время после выполнения функции delete_el
    auto end_delete_el = std::chrono::high_resolution_clock::now();
    auto duration_delete_el = std::chrono::duration_cast<std::chrono::microseconds>(end_delete_el - start_delete_el);

    // Выводим результат времени выполнения функции delete_el
    std::cout << "Время выполнения функции delete_el: " << duration_delete_el.count() << " микросекунд." << std::endl;

    print();
    return 0;
}

// int main(){
//   int mas[] = {230, 150, 100, 85, 77, 33, 93, 200, 57, 137, 205};
//   int length = sizeof(mas) / sizeof(mas[0]);
//  auto start_time = std::chrono::high_resolution_clock::now();

//   for (int i = 0; i < length; i++){
//     push_back(mas[i]);
//   }
//   // Засекаем конечное время после выполнения функции
//     auto end_time = std::chrono::high_resolution_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

//     // Выводим результат
//     std::cout << "Время выполнения функции: " << duration.count() << " микросекунд." << std::endl;
//   find_posl(100);
//   print();
//   sort_bubble();
//   print();
  

//     delete_el(100);

  
//   print();
//   return 0;
// }
