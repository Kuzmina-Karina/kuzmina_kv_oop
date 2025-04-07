#include <memory>
#include <iostream>

struct temp{
    int val;
    temp(int v): val(v) {std::cout << "создано " << val << '\n';} //конструктор
    ~temp(){std::cout << "удалено " << val << '\n';} //диструкотр
};

int main() {
    auto sh = std::make_shared<temp>(100);
    std::cout << "sh кол-во владельцев : " << sh.use_count() << '\n'; 

    std::weak_ptr<temp> weak = sh;
    std::cout << "sh кол-во владельцев : " << sh.use_count() << '\n'; 

    if (auto t_sh = weak.lock()) {
        std::cout << "живой! : " << t_sh->val << '\n';
    } else {
        std::cout << "мёртв(" << '\n';
    }

    sh.reset();
    std::cout << "sh кол-во владельцев : " << sh.use_count() << '\n'; // 0

    if (auto t_sh = weak.lock()) {
        std::cout << "живой! : " << t_sh->val << '\n';
    } else {
        std::cout << "мёртв(" << '\n';
    }
}