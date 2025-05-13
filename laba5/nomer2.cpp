#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

struct Color {
    unsigned char r, g, b;
};

// Функция размытия для части изображения
void blurPart(const std::vector<std::vector<Color>>& input, 
              std::vector<std::vector<Color>>& output,
              int startY, int endY) {
    int height = input.size();
    int width = input[0].size();

    for (int y = startY; y < endY; ++y) {
        for (int x = 0; x < width; ++x) {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    int ny = y + dy;
                    int nx = x + dx;

                    if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
                        sum_r += input[ny][nx].r;
                        sum_g += input[ny][nx].g;
                        sum_b += input[ny][nx].b;
                        count++;
                    }
                }
            }

            output[y][x].r = sum_r / count;
            output[y][x].g = sum_g / count;
            output[y][x].b = sum_b / count;
        }
    }
}

// Параллельное размытие с использованием std::thread
std::vector<std::vector<Color>> parallelBlurThreads(const std::vector<std::vector<Color>>& input, int numThreads) {
    if (input.empty()) return {};

    int height = input.size();
    int width = input[0].size();

    std::vector<std::vector<Color>> output(height, std::vector<Color>(width));
    std::vector<std::thread> threads;

    int rowsPerThread = height / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        int startY = i * rowsPerThread;
        int endY = (i == numThreads - 1) ? height : startY + rowsPerThread;

        threads.emplace_back(blurPart, std::cref(input), std::ref(output), startY, endY);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return output;
}

// Вывод изображения (только R-компонента)
void printImage(const std::vector<std::vector<Color>>& img) {
    for (const auto& row : img) {
        for (const Color& pixel : row) {
            std::cout << static_cast<int>(pixel.r) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Создание тестового изображения
std::vector<std::vector<Color>> createTestImage(int width, int height) {
    std::vector<std::vector<Color>> image(height, std::vector<Color>(width));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            image[y][x] = {
                static_cast<unsigned char>((x + y) % 256),
                static_cast<unsigned char>((x * 2) % 256),
                static_cast<unsigned char>((y * 2) % 256)
            };
        }
    }
    return image;
}

int main() {
    // Маленькое изображение для проверки
    std::vector<std::vector<Color>> smallImage = {
        {{255,0,0}, {0,255,0}, {0,0,255}, {100,100,100}, {50,50,50}},
        {{200,0,0}, {0,200,0}, {0,0,200}, {80,80,80}, {40,40,40}},
        {{150,0,0}, {0,150,0}, {0,0,150}, {60,60,60}, {30,30,30}},
        {{100,0,0}, {0,100,0}, {0,0,100}, {40,40,40}, {20,20,20}},
        {{50,0,0}, {0,50,0}, {0,0,50}, {20,20,20}, {10,10,10}}
    };

    std::cout << "Original small image (R):\n";
    printImage(smallImage);

    auto blurredSmall = parallelBlurThreads(smallImage, 2);
    std::cout << "Blurred small image (R):\n";
    printImage(blurredSmall);

    // Большое изображение для теста производительности
    const int width = 5000;
    const int height = 5000;
    auto largeImage = createTestImage(width, height);

    std::cout << "Blurring large image (" << width << "x" << height << ") with 4 threads...\n";
    auto start = std::chrono::high_resolution_clock::now();
    auto blurredLarge = parallelBlurThreads(largeImage, 4);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}