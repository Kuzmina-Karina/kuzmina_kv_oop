#include <iostream>
#include <utility> 
#include <chrono> 

class MyVector {
private:
    int* data;   // Указатель на массив
    size_t size; // Количество элементов

public:
    // 1. Обычный конструктор
    MyVector(size_t s = 0) : size(s) {
        data = new int[size];
        std::cout << "Создан вектор (" << size << " элементов)\n";
    }

    // 2. Деструктор
    ~MyVector() {
        delete[] data;
        std::cout << "Удален вектор (" << size << " элементов)\n";
    }

    // 3. Конструктор копирования
    MyVector(const MyVector& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        std::cout << "Скопирован вектор (" << size << " элементов)\n";
    }

    // 4. Оператор присваивания копированием
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        std::cout << "Присвоен вектор копированием (" << size << " элементов)\n";
        return *this;
    }

    // 5. Move конструктор
    MyVector(MyVector&& other) : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Перемещен вектор (Move конструктор, " << size << " элементов)\n";
    }

    // 6. Move оператор присваивания
    MyVector& operator=(MyVector&& other) {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        std::cout << "Присвоен вектор перемещением (Move оператор, " << size << " элементов)\n";
        return *this;
    }
};


int main() {
    const size_t N = 10000000;  

    {
        MyVector v1(N);
        auto start = std::chrono::high_resolution_clock::now();
        MyVector v2 = v1;  // копирование
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Копирование заняло: " << diff.count() << " сек.\n";
    }
    
    {
        MyVector v1(N);
        auto start = std::chrono::high_resolution_clock::now();
        MyVector v2 = std::move(v1);  // перемещение
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Перемещение заняло: " << diff.count() << " сек.\n";
    }

    return 0;
}