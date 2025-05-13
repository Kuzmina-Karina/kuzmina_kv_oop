#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <sstream>


// Шаблонная функция обмена
template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Шаблонная функция контейнер в строку
template <typename T>
std::string containerToString(const T& c) {
    std::ostringstream oss;
    oss << "[";
    bool first = true;
    for (typename T::const_iterator it = c.begin(); it != c.end(); ++it) {
        if (!first) {
            oss << ", ";
        }
        oss << *it;
        first = false;
    }
    oss << "]";
    return oss.str();
}

void testSwap() {
    // Обмен целых чисел
    int x = 5, y = 10;
    std::cout << "До swap: x = " << x << ", y = " << y << std::endl;
    mySwap(x, y);
    std::cout << "После swap: x = " << x << ", y = " << y << std::endl;

    // Обмен строк
    std::string s1 = "Привет", s2 = "Мир";
    std::cout << "До swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    mySwap(s1, s2);
    std::cout << "После swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
}

void testContainerToString() {
    // Тестируем с vector<int> 
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    std::cout << "Вектор: " << containerToString(vec) << std::endl;

    // Тестируем с list<string>
    std::list<std::string> lst;
    lst.push_back("Яблоко");
    lst.push_back("Банан");
    lst.push_back("Апельсин");
    std::cout << "Список: " << containerToString(lst) << std::endl;

    // Тестируем с set<double>
    std::set<double> st;
    st.insert(1.1);
    st.insert(2.2);
    st.insert(3.3);
    std::cout << "Множество: " << containerToString(st) << std::endl;
}

int main() {
    // Тестирование mySwap
    std::cout << "=== Тестирование mySwap ===" << std::endl;
    testSwap();
    
    // Тестирование containerToString
    std::cout << "\n=== Тестирование containerToString ===" << std::endl;
    testContainerToString();
    
    return 0;
}