#include <iostream>

bool two_sum(int array[], int left, int right, const int key) {
    bool flag = false;
    while (left <= right) {
        int temp_sum = array[left] + array[right];
        if (temp_sum == key) {
            flag = true;
            std::cout << "(" << array[left] << ", " << array[right] << ") ";
            if (array[left] == array[left + 1] && array[right] != array[right - 1])
                left++;
            else if (array[left] != array[left + 1] && array[right] == array[right - 1])
                right--;
            else {
                left++;
                right--;
            }
        } else if (temp_sum > key)
            right--;
        else
            left++;
    }
    return flag;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int no_of_elements;
        std::cin >> no_of_elements;
        int array[no_of_elements];

        for (int j = 0; j < no_of_elements; j++) {
            int element;
            std::cin >> element;
            array[j] = element;
        }

        std::sort(array, array + no_of_elements);

        int key;
        std::cin >> key;
        bool pair_exist = two_sum(array, 0, no_of_elements - 1, key);

        if (!pair_exist) std::cout << "No such pair exist.";
        std::cout << "\n";
    }
    return 0;
}