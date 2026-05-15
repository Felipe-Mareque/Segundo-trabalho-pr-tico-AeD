#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* nextGreaterElements( int *nums, int numsSize, int *returnSize ) {

    int *resposta = malloc( sizeof( int ) * numsSize );
    *returnSize = numsSize;

    for ( int x = 0; x < numsSize; x++ ) {

        int encontrou = 0;
        int y = x + 1;

        while ( y < numsSize && nums[x] >= nums[y] ) {
            y++;
        }

        if ( y < numsSize && nums[y] > nums[x] ) {

            resposta[x] = nums[y];
            encontrou = 1;

        } else {

            int a = 0;

            while ( a < x ) {

                if ( nums[a] > nums[x] ) {

                    resposta[x] = nums[a];
                    encontrou = 1;
                    break;
                }

                a++;
            }

            if ( encontrou != 1 ) {
                resposta[x] = -1;
            }
        }
    }

    return resposta;
}

int main() {

    int nums[] = { 1, 2, 1 };

    int numsSize = sizeof( nums ) / sizeof( nums[0] );

    int returnSize;

    int *resultado = nextGreaterElements(
        nums,
        numsSize,
        &returnSize
    );

    printf( "Resultado:\n" );

    for ( int i = 0; i < returnSize; i++ ) {
        printf( "%d ", resultado[i] );
    }

    free( resultado );

    return 0;
}