#include <stdio.h>

int main(void) {
    float a, big, small, total;
    int div;

    if (scanf("%f", &a) != 1)
        return 1;

    big = small = total = a;
    div = 1;
    while (scanf("%f", &a) == 1) {
        if (big < a) {
            big = a;
        }
        if (small > a) {
            small = a;
        }
        div++;
        total += a;
    }
    printf("%.2f %.2f %.2f\n", small, big, total / div);
    return 0;
}
