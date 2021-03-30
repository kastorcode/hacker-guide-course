#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[3][3];

    v[0][0] = 1;
    v[0][1] = 2;
    v[0][2] = 3;

    v[1][0] = 4;
    v[1][1] = 5;
    v[1][2] = 6;

    v[2][0] = 7;
    v[2][1] = 8;
    v[2][2] = 9;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", v[i][j]);
        }

        printf("\n");
    }

    return 0;
}
