// main.cpp
#include <iostream>
#include <vector>
#include "strateg.hpp"

void print(const std::vector<int>& v) {
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {6, 5, 4, 3, 9, 1, 0, -1};
    
    BubbleSortStrategy bubble;
    QuickSortStrategy quick;
    StdSortStrategy stdSort;
    InsertionSortStrategy insertion;
    
    Sorter s1(bubble);
    Sorter s2(quick);
    Sorter s3(stdSort);
    Sorter s4(insertion);
    
    std::vector<int> d1 = data;
    s1.sortData(d1);
    std::cout << "Bubble:    "; print(d1);
    
    std::vector<int> d2 = data;
    s2.sortData(d2);
    std::cout << "Quick:     "; print(d2);
    
    std::vector<int> d3 = data;
    s3.sortData(d3);
    std::cout << "STD:       "; print(d3);

    std::vector<int> d4 = data;
    s4.sortData(d4);
    std::cout << "Insertion: "; print(d4);
}