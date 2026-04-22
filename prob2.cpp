#include "queue.h"
#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int arr[100];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    Queue q;
    init(&q);

    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        enqueue(&q, arr[i]);
        windowSum += arr[i];
    }

    bool first = true;
    for (int i = k; i <= n; i++) {
        if (!first) std::cout << " ";
        std::cout << windowSum;
        first = false;

        if (i < n) {
            windowSum -= front(&q);
            dequeue(&q);
            enqueue(&q, arr[i]);
            windowSum += arr[i];
        }
    }
    std::cout << std::endl;
    return 0;
}
