#include <iostream>
//vstavka
int main(){
  int mas[]={2, 3, 4, 5};
  int length = sizeof(mas) / sizeof(mas[0]);
  std::cout << length << std::endl;
  for(int i = 0; i < length; i++){
    int key = mas[i];
    int j = i - 1;
    while(mas[j] > key && j >= 0){
      mas[j + 1] = mas[j]; 
      j = j - 1;
    }
    mas[j + 1] = key;
  }
 for(int i = 0; i < length; i++){
  std::cout << mas[i]<<",";
}
}

