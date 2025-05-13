#include <iostream>
#include <vector>
#include <string>

int main(){

    int n;

    std::cin >> n;

    std::vector < std::vector<int> > a (n, std::vector<int> (n));

    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout << a[i][j];
        }
    }


    return 0;
}