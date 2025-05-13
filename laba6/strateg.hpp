// SortingStrategies.h
#include <vector>
#include <algorithm>

class SortingStrategy {
public:
    virtual ~SortingStrategy() = default;
    virtual void sort(std::vector<int>& data) const = 0;
};

class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) const override {
        for (size_t i = 0; i < data.size(); ++i)
            for (size_t j = 0; j < data.size()-1; ++j)
                if (data[j] > data[j+1])
                    std::swap(data[j], data[j+1]);
    }
};

class QuickSortStrategy : public SortingStrategy {
    void quickSort(std::vector<int>& data, int left, int right) const {
        if (left >= right) return;
        
        int pivot = data[(left + right) / 2];
        int i = left, j = right;
        
        while (i <= j) {
            while (data[i] < pivot) i++;
            while (data[j] > pivot) j--;
            if (i <= j) std::swap(data[i++], data[j--]);
        }
        
        quickSort(data, left, j);
        quickSort(data, i, right);
    }
    
public:
    void sort(std::vector<int>& data) const override {
        if (!data.empty())
            quickSort(data, 0, data.size()-1);
    }
};

class StdSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) const override {
        std::sort(data.begin(), data.end());
    }
};

class InsertionSortStrategy : public SortingStrategy {
    public:
        void sort(std::vector<int>& data) const override {
            for (size_t i = 1; i < data.size(); ++i) {
                int key = data[i];
                int j = i-1;
                while (j >= 0 && data[j] > key) {
                    data[j+1] = data[j];
                    j--;
                }
                data[j+1] = key;
            }
        }
    };

class Sorter {
    const SortingStrategy& strategy;
public:
    Sorter(const SortingStrategy& s) : strategy(s) {}
    
    void sortData(std::vector<int>& data) const {
        strategy.sort(data);
    }
};