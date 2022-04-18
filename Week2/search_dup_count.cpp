#include <iostream>
#include <vector>

int binary_search(int arr[], int lower_bound, int upper_bound, int key) {
    while (lower_bound <= upper_bound) {
        int mid = (lower_bound + upper_bound) / 2;
        if (key == arr[mid])
            return mid;
        else if (key > arr[mid])
            lower_bound = mid + 1;
        else if (key < arr[mid])
            upper_bound = mid - 1;
    }
    return -1;
}

int duplicate_count(int arr[], int index, int size, int key) {
    int left_count = 0, right_count = 0;
    int i = index, j = index;
    while (key == arr[i] && i >= 0) {
        left_count++;
        i--;
    }
    while (key == arr[j] && j < size) {
        right_count++;
        j++;
    }
    return left_count + right_count - 1;
}

int main() {
    int n;
    std::cin >> n;

    std::pair<int, int> pair;
    std::vector<std::pair<int, int> > vec;

    for (int i = 0; i < n; i++) {
        int no_of_elements;
        std::cin >> no_of_elements;
        int arr[no_of_elements];
        for (int i = 0; i < no_of_elements; i++) {
            int element;
            std::cin >> element;
            arr[i] = element;
        }

        int duplicates = 0;
        int key;
        std::cin >> key;

        int index = binary_search(arr, 0, no_of_elements - 1, key);

        if (index != -1)
            duplicates = duplicate_count(arr, index, no_of_elements, key);

        pair = std::make_tuple(key, duplicates);
        vec.push_back(pair);
    }
    for (auto v : vec) {
        if (v.second == 0) {
            std::cout << "key not present"
                      << " " << v.second << "\n";
        } else
            std::cout << v.first << " " << v.second << "\n";
    }
    return 0;
}