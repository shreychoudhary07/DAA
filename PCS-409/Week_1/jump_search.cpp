#include <cmath>
#include <iostream>
int main() {
    int n, key, ctr = 1, i = 0, j, flag = 0, t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        int a[n];
        for (i = 0; i < n; i++) std::cin >> a[i];
        i = 0;
        std::cin >> key;
        if (a[0] == key)
            std::cout << "Present " << ctr << "\n";
        else {
            while (1) {
                if (a[(int)pow(2, i)] > key) {
                    for (j = pow(2, i); j < std::min((int)pow(2, i + 1), n); j++) {
                        ctr++;
                        if (a[j] == key) flag = 1;
                    }
                    if (flag)
                        std::cout << "Present " << ctr << "\n";
                    else
                        std::cout << "Not Present " << ctr << "\n";
                    break;
                }
                ctr++;
                i++;
            }
        }
    }
    return 0;
}
