#include <iostream>
#include <memory>

struct temp{
    int val;
    temp(int v): val(v) {std::cout << "создано " << val << '\n';} //конструктор
    ~temp(){std::cout << "удалено " << val << '\n';} //диструкотр
};

int main(){
    auto ptr1 = std::make_shared<temp>(100);
    std::cout << "Кол-во владельцев: " << ptr1.use_count() << '\n';
    {
        auto ptr2 = ptr1;
        std::cout << "Кол-во владельцев: " << ptr1.use_count() << '\n';
        ptr2->val += 100;
        std::cout << "Значение " << ptr1->val << '\n';
    }
    std::cout << "Кол-во владельцев: " << ptr1.use_count() << '\n';
    return 0;
}