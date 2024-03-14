#include <iostream>
#include <chrono>
struct bin {
  int num;
  bin* left;
  bin* right;
};

bin* head = nullptr;

void add_tobin(int el) {
  bin* current = new bin{el, nullptr, nullptr};
  if (head == nullptr) {
    head = current;
  } else {
    bin* temp = head;
    while (temp != nullptr) {
      if (el < temp->num) {
        if (temp->left == nullptr) {
          temp->left = current;
          break;
        } else {
          temp = temp->left;
        }
      } else {
        if (temp->right == nullptr) {
          temp->right = current;
          break;
        } else {
          temp = temp->right;
        }
      }
    }
  }
}

void print_tree(bin* node) {
  if (node != nullptr) {
    print_tree(node->left);
    std::cout << node->num << " ";
    print_tree(node->right);
  }
}

bin* find_min(bin* node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

bin* delete_from_bin(bin* root, int el) {
  if (root == nullptr) {
    return root;
  }

  if (el < root->num) {
    root->left = delete_from_bin(root->left, el);
  } else if (el > root->num) {
    root->right = delete_from_bin(root->right, el);
  } else {
    if (root->left == nullptr) {
      bin* temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      bin* temp = root->left;
      delete root;
      return temp;
    }

    bin* temp = find_min(root->right);
    root->num = temp->num;
    root->right = delete_from_bin(root->right, temp->num);
  }

  return root;
}

void find_in_bin(bin* root, int el) {
  bool found = false;
  while (root != nullptr) {
    if (el == root->num) {
      std::cout << "Значение успешно найдено\n";
      found = true;
      break;
    } else if (el < root->num) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
  if (!found) {
    std::cout << "Значение не найдено\n";
  }
}


int main() {
  int arr[] = {230, 150, 100, 85, 77, 33, 93, 200, 57, 137, 205};
  int length = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < length; i++) {
    add_tobin(arr[i]);
  }

  std::cout << "Исходное дерево: ";
  print_tree(head);
  std::cout << std::endl;

  int element_to_delete = 100;
  head = delete_from_bin(head, element_to_delete);
     find_in_bin(head, 2001);

  std::cout << "Дерево после удаления " << element_to_delete << ": ";
  print_tree(head);
  std::cout << std::endl;

  return 0;
}


// int main() {
//   int arr[] = {230, 150, 100, 85, 77, 33, 93, 200, 57, 137, 205};
//   int length = sizeof(arr) / sizeof(arr[0]);

//   // Засекаем начальное время перед циклом записи
//   auto start_write_time = std::chrono::high_resolution_clock::now();

//   for (int i = 0; i < length; i++) {
//     add_tobin(arr[i]);
//   }

//   // Засекаем конечное время после цикла записи
//   auto end_write_time = std::chrono::high_resolution_clock::now();
//   auto duration_write = std::chrono::duration_cast<std::chrono::microseconds>(end_write_time - start_write_time);

//   // Выводим результат времени выполнения цикла записи
//   std::cout << "Время выполнения цикла записи: " << duration_write.count() << " микросекунд." << std::endl;

//   // Выводим исходное дерево
//   std::cout << "Исходное дерево: ";
//   print_tree(head);
//   std::cout << std::endl;

//   // Засекаем начальное время перед удалением элемента
//   auto start_delete_time = std::chrono::high_resolution_clock::now();

//   int element_to_delete = 205;
//   head = delete_from_bin(head, element_to_delete);

//   // Засекаем конечное время после удаления элемента
//   auto end_delete_time = std::chrono::high_resolution_clock::now();
//   auto duration_delete = std::chrono::duration_cast<std::chrono::microseconds>(end_delete_time - start_delete_time);

//   // Выводим результат времени выполнения удаления
//   std::cout << "Время выполнения функции delete_from_bin: " << duration_delete.count() << " микросекунд." << std::endl;

//   // Выводим дерево после удаления элемента
//   std::cout << "Дерево после удаления " << element_to_delete << ": ";
//   print_tree(head);
//   std::cout << std::endl;
// auto start_print_time1 = std::chrono::high_resolution_clock::now();
//  std::cout << "Нашел в дереве " << element_to_delete << ": ";
// find_in_bin(head, 100);
// std::cout << std::endl;

//   // Засекаем конечное время после принта
//   auto end_print_time1 = std::chrono::high_resolution_clock::now();
//   auto duration_print1 = std::chrono::duration_cast<std::chrono::microseconds>(end_print_time1 - start_print_time1);
// std::cout << "Время нахождения " << duration_print1.count() << " микросекунд." << std::endl;
//   // Засекаем начальное время перед принтом
//   auto start_print_time = std::chrono::high_resolution_clock::now();
//   // Выводим дерево после удаления элемента
//   std::cout << "Дерево после удаления " << element_to_delete << ": ";
//   print_tree(head);
//   std::cout << std::endl;

//   // Засекаем конечное время после принта
//   auto end_print_time = std::chrono::high_resolution_clock::now();
//   auto duration_print = std::chrono::duration_cast<std::chrono::microseconds>(end_print_time - start_print_time);

//   // Выводим результат времени выполнения принта
//   std::cout << "Время выполнения принта дерева: " << duration_print.count() << " микросекунд." << std::endl;

//   return 0;
// }
