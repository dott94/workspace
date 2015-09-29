#include "my.h"
void my_int(int i) {
    int tens = 1000000000;
    if (i < 0) {
        my_char('-');
        i = i * -1;
    }
    while (tens >= 1) {
        int digit = (i - (i % tens)) / tens % 10 + 48;
        if (tens <= i)
            my_char(digit);
        tens = tens / 10;
    }
    if (i == 0)
        my_char('0');
}

