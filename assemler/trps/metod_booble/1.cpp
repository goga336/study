#include <iostream>

int main(){
  int mas[] = {3, 5 ,7, 1, 2};
  int length = sizeof(mas) / sizeof(mas[0]);
  
  for(int i = 0; i < length; i++){
    int j = i + 1;
    for(j; length - j;  j++){
      if (mas[i] > mas[j]){
	std::swap(mas[i], mas[j]);
      }
    }
  }
  for(int i = 0; i < length; i++){
    std::cout << mas[i] << ", ";
  }
  return 0;
}
