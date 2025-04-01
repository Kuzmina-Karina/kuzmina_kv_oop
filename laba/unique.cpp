#include <iostream>
int func(int size){
    auto ans = std::make_unique<int>();
    for(int i=1; i<size; i++){
    auto temp = std::make_unique<int>(i%5); //не удаляет память у temp
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
