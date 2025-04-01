#include <iostream>
int func(int size){
    int* ans = new int();
    for(int i=1; i<size; i++){
       int* temp = new int (i%5); //не удаляет память у temp
       if (*temp ==0){
            *ans += i;
       }
    }
    return *ans;
    //не удаляет память у ans
}

int main(){
    std::cout << func(100);
}