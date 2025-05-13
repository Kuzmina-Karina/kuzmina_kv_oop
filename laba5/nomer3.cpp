#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>


int counter_mutex = 0;
std::mutex mtx;  // Мьютекс для защиты counter_mutex

// Атомарный счетчик 
std::atomic<int> counter_atomic(0);

// мьютекс
void increment_with_mutex(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        mtx.lock();      // Захватываем мьютекс
        counter_mutex++; 
        mtx.unlock();    // Освобождаем мьютекс
    }
}

void increment_with_atomic(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        counter_atomic++; // Атомарная операция
    }
}

int main() {
    const int count_proc = 4;     // Количество потоков
    const int count_I = 100000; // Итераций на поток

    // Тест с мьютексом 
    std::vector<std::thread> threads_mutex;
    for (int i = 0; i < count_proc; ++i) {
        threads_mutex.emplace_back(increment_with_mutex, count_I);
    }

    for (auto& thread : threads_mutex) {
        thread.join();
    }

    std::cout << "With mutex:    " << counter_mutex << " (expected: " 
              << count_proc * count_I << ")\n";

    // Тест с atomic 
    std::vector<std::thread> threads_atomic;
    for (int i = 0; i < count_proc; ++i) {
        threads_atomic.emplace_back(increment_with_atomic, count_I);
    }

    for (auto& thread : threads_atomic) {
        thread.join();
    }

    std::cout << "With atomic:   " << counter_atomic << " (expected: " 
              << count_proc * count_I << ")\n";

    return 0;
}