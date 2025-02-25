#include "utils.cpp"

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << func_sum(a, b) << '\n';
    std::cout << func_razn(a, b)<< '\n';
    std::cout << "new output"<< '\n';
    std::cout << func_umn(a, b)<< '\n';
    std::cout << func_del(a, b)<< '\n';
}