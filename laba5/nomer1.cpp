#include <vector>
#include <iostream>
#include <chrono> // Для измерения времени

struct Color {
    unsigned char r, g, b;
};

std::vector<std::vector<Color>> sequentialBlur(const std::vector<std::vector<Color>>& input) {
    if (input.empty()) return {};

    int height = input.size();
    int width = input[0].size();

    std::vector<std::vector<Color>> output(height, std::vector<Color>(width));

    for (int y = 0; y < height; ++y) {
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
    return output;
}

void printImage(const std::vector<std::vector<Color>>& img) {
    for (const auto& row : img) {
        for (const Color& pixel : row) {
            std::cout << static_cast<int>(pixel.r) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Функция для создания большого изображения (для теста производительности)
std::vector<std::vector<Color>> createLargeImage(int width, int height) {
    std::vector<std::vector<Color>> image(height, std::vector<Color>(width));
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Простой паттерн для теста
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

    // Тест с маленьким изображением (5x5)
    std::vector<std::vector<Color>> smallImage = {
        {{255,0,0}, {0,255,0}, {0,0,255}, {100,100,100}, {50,50,50}},
        {{200,0,0}, {0,200,0}, {0,0,200}, {80,80,80}, {40,40,40}},
        {{150,0,0}, {0,150,0}, {0,0,150}, {60,60,60}, {30,30,30}},
        {{100,0,0}, {0,100,0}, {0,0,100}, {40,40,40}, {20,20,20}},
        {{50,0,0}, {0,50,0}, {0,0,50}, {20,20,20}, {10,10,10}}
    };

    std::cout << "Small:\n" << "Original (R):\n";
    printImage(smallImage);
    auto blurredSmall = sequentialBlur(smallImage);
    std::cout << "Blurred (R):\n";
    printImage(blurredSmall);


    // Тест с большим изображением 
    const int Width = 5000;
    const int Height = 5000;
    std::cout << "Image (" << Width << "x" << Height << ")...\n";
    auto largeImage = createLargeImage(Width, Height);

    std::cout << "Blurring...\n";
    auto startLarge = std::chrono::high_resolution_clock::now();
    auto blurredLarge = sequentialBlur(largeImage);
    auto endLarge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedLarge = endLarge - startLarge;

    std::cout << "time: " << elapsedLarge.count() << " seconds\n";

    return 0;
}
