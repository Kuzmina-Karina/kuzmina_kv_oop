#include "utils.cpp"

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << func_sum(a, b);
    std::cout << func_razn(a, b);
    std::cout << func_umn(a, b);
}