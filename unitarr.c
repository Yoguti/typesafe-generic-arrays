
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool ok = true;
    int number;
    int digit; // Declare 'digit' here
    bool digit_seen[10] = {false};
    scanf("%d", &number);

    while (number > 0) {
        digit = number % 10;
        if (digit_seen[digit]) {
            ok = false;
            break;
        }
        digit_seen[digit] = true;
        number /= 10;
    }

    return 0;
}


