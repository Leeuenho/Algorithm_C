#include <stdio.h>
#include <stdlib.h>

#define NUM 6

void main(void) {

	int lottos[NUM];
	int win_nums[NUM];

	int lottos_len = sizeof(lottos)/sizeof(int);
	int win_nums_len = sizeof(win_nums) / sizeof(int);
	//printf("%d", win_nums_len);

	//민우의 로또 번호 (0~45)
	for (int i = 0; i < lottos_len; i++) {
		lottos[i] = rand() % 46;
	}
	//정답 로또 번호 (1~45)
	for (int i = 0; i < win_nums_len; i++) {
		win_nums[i] = rand() % 45 + 1;
	}

	printf("lottos : ");
	for (int i = 0; i < lottos_len; i++) {
		printf("%d ", lottos[i]);
	}
	printf("\nwin_num : ");
	for (int i = 0; i < win_nums_len; i++) {
		printf("%d ", win_nums[i]);
	}

	/*
	int answer[2];

	answer[0], answer[1] = solution(lottos, lottos_len, win_nums, win_nums_len);

	printf("\nBest %d등", answer[0]);
	printf("\nWorst %d등", answer[1]);
	*/
	
}

int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
	int* answer = (int*)malloc(sizeof(int) * 2);
	int cnt = 0;
	int zeros = 0;

	int arr[7] = { 6, 6, 5, 4, 3, 2, 1 };

	for (int i = 0; i < lottos_len; i++) {
		if (lottos[i] == 0) {
			zeros++;
			continue;
		}
		for (int ii = 0; ii < win_nums_len; ii++) {
			if (lottos[i] == win_nums[ii]) {
				cnt++;
			}
		}
	}

	//answer[0] = arr[cnt + zeros];
	//answer[1] = arr[cnt];

	return answer;
}