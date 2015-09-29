#include "my.h"

int mypow(int base, int power) {
    int i;
    int answer = 1;
    for (i = 0; i < power; i++) {
        answer = base * answer;
    }
    return answer;

}

void my_num_base(int num, char* string) {
    int base = my_strlen(string);
    int i = 0;
    char output[num];
    if (!string)
        return;
    if (num < 0) {
        my_char('-');
        num = num * -1;
    }
    if (num == 0) {
        my_char(*string);
    }
    if (base == 1) {
        for (i = 0; i < num; i++) {
            my_char(*string);
        }
    } else {
        while (num > 0) {
            int d = (num % mypow(base, i + 1));
            int e = d / mypow(base, i);
            output[i] = *(string + e);
            num = num - d;
            i = i + 1;
        }
        i--;
        while (i >= 0) {
            my_char(output[i]);
            i--;
        }
    }
}

