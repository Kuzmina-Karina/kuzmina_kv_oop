#include <iostream>
#include <string>
#include <stdexcept> // для исключений

// Шаблон класса MyArray с параметром размера N и типа T
template <typename T, size_t N>
class MyArray {
private:
    T data[N]; // Статический массив типа T размера N

public:
    // Конструктор по умолчанию
    MyArray() {
        std::cout << "Создан массив размера " << N << std::endl;
    }

    // Метод для доступа к элементам с проверкой границ
    T& at(size_t index) {
        if (index >= N) {
            throw std::out_of_range("Индекс выходит за границы массива");
        }
        return data[index];
    }

    // Константная версия метода at()
    const T& at(size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Индекс выходит за границы массива");
        }
        return data[index];
    }

    // Оператор [] для доступа к элементам (без проверки границ)
    T& operator[](size_t index) {
        return data[index];
    }

    // Константная версия оператора []
    const T& operator[](size_t index) const {
        return data[index];
    }

    // Метод для получения размера массива
    size_t size() const {
        return N;
    }

    // Метод для заполнения массива значением
    void fill(const T& value) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = value;
        }
    }
};

int main() {
    try {
        // 1. Массив целых чисел размера 5
        MyArray<int, 5> v;
        
        // Заполняем массив
        for (size_t i = 0; i < v.size(); ++i) {
            v[i] = i * 10;
        }
        
        // Выводим элементы
        std::cout << "Массив int: ";
        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << v.at(i) << " ";
        }
        std::cout << std::endl;

        // 2. Массив строк размера 3
        MyArray<std::string, 3> v_s;
        v_s[0] = "Hello";
        v_s[1] = "World";
        v_s[2] = "C++";
        
        std::cout << "Массив string: ";
        for (size_t i = 0; i < v_s.size(); ++i) {
            std::cout << v_s[i] << " ";
        }
        std::cout << std::endl;

        // 3. fill()
        MyArray<double, 4> v_d;
        v_d.fill(3.14);
        
        std::cout << "Массив double: ";
        for (size_t i = 0; i < v_d.size(); ++i) {
            std::cout << v_d[i] << " ";
        }
        std::cout << std::endl;

        // 4. ошибки
        std::cout << "Попытка доступа за границами: ";
        std::cout << v.at(10) << std::endl; // Будет исключение

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}