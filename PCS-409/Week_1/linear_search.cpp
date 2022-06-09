#include <iostream>
#include <tuple>
#include <vector>

std::pair<std::string, int> linear_search(int arr[], int size, int key) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        count++;
        if (key == arr[i]) {
            return std::make_tuple("Present", count);
        }
    }
    return std::make_tuple("Not Present", count);
}

int main() {
    std::pair<std::string, int> pair;
    std::vector<std::pair<std::string, int> > vec;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int no_of_elements;
        std::cin >> no_of_elements;
        int arr[no_of_elements];
        for (int j = 0; j < no_of_elements; j++) {
            int element;
            std::cin >> element;
            arr[j] = element;
        }

        int key;
        std::cin >> key;

        pair = linear_search(arr, no_of_elements, key);
        vec.push_back(pair);
    }

    for (auto v : vec) {
        std::cout << v.first << " " << v.second << "\n";
    }

    return 0;
}