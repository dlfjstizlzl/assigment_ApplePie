#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer[3], guess[3], i, j, strike, ball;
    srand(time(NULL));

    for (i = 0; i < 3; i++) {
        answer[i] = rand() % 10;
        for (j = 0; j < i; j++)
            if (answer[i] == answer[j]) { i--; break; }
    }
    int life = 10;
    while (life>=0) {
        printf("3�ڸ� ���ڸ� �Է��ϼ���: ");
        scanf("%1d%1d%1d", &guess[0], &guess[1], &guess[2]);

        strike = ball = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (guess[i] == answer[j]) {
                    i == j ? strike++ : ball++;
                    break;
                }
            }
        }

        printf("%dS %dB\n", strike, ball);
        printf("���� ��ȸ : %d\n", life);
        life--;

        if (strike == 3) {
            printf("�����Դϴ�!\n");
            return 0;
        }
    }
    printf("%d%d%d�ε� ������������������", answer[0],answer[1], answer[2]);
    return 0;
}