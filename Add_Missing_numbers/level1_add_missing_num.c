#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    int num[10] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i <= 9; i++) {
        for (int k = 0; k <= numbers_len; k++) {
            if (i == numbers[k]) {
                num[i] = -1;
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (num[i] != -1) {
            answer += num[i];
        }
    }
    return answer;
}

void main(void) {

    srand(time(NULL));
    int num_lens = rand() % 9 + 1;

    int* num = (int*)malloc(sizeof(int) * num_lens);

    for (int i = 0; i < num_lens; i++) {
        num[i] = rand() % 10;
        for (int ii = 0; ii < i; ii++) {
            if (num[i] == num[ii]) {
                i--;
                break;
            }
        }
    }

    for (int i = 0; i < num_lens; i++) {
        printf("%d", num[i]);
    }

    int answer = solution(num, num_lens);

    printf("\n%d", answer);
}


