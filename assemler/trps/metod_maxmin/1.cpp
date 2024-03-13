#include <iostream>

int main(){
  int mas[] = {4, 2, 7, 9};
  int length = sizeof(mas) / sizeof(mas[0]);
for(int j = 0; j < length; j++){
  int min_adr = j;
  for(int i = j + 1; i < length; i++){
    if (mas[i] < mas[min_adr]){
      min_adr = i;
    }

  }
  std::swap(mas[min_adr], mas[j]);
}
for(int i = 0; i < length; i++){
  std::cout << mas[i] << ", ";
 }
}
