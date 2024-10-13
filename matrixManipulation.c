//Nevan Snider, KUID 3149896
//Lab05, Matrix Lab


#include<stdio.h>

//The defined size of the matrices
#define SIZE 5

/*As a heads up I initially
programmed these functions to work with any size
because I didnt see that we were assuming the size to
always be 5x5 so thats why its like that
*/

//Prints any matrix passed to it
void printMatrix(int matrix1[SIZE][SIZE], int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
}

//Adds matrices together and prints the new matrix
void addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int rows1, int columns1, int rows2, int columns2){
    int finalMatrix[SIZE][SIZE];
    if ((rows1 == rows2) && (columns1 == columns2)){
        for (int i = 0; i < rows1; i++){
            for (int j = 0; j < columns1; j++){
                finalMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        printMatrix(finalMatrix, SIZE, SIZE);
    }
}

//multiplies matrices together and prints the new matrix
void multiplyMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int firstRows, int firstColumns, int secondRows, int secondColumns){
    int finalMatrix[SIZE][SIZE];
    if ((firstRows == secondColumns)){
        for (int i = 0; i < firstRows; i++){
            for (int j = 0; j < secondColumns; j++){
                finalMatrix[i][j] = 0;
            }
        }

        for (int i = 0; i < firstRows; i++){
            for (int j = 0; j < secondColumns; j++){
                for (int k = 0; k < firstRows; k++){
                    finalMatrix[i][j] = finalMatrix[i][j] + ((matrix1[i][k] * matrix2[k][j]));
                }
            } 
        }
        printMatrix(finalMatrix, SIZE, SIZE);
    }
}

//transposes a given matrix and prints it
void transposeMatrix(int matrix1[SIZE][SIZE], int rows, int columns){
    int finalMatrix[SIZE][SIZE];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            finalMatrix[j][i] = matrix1[i][j];
        }
    }
    printMatrix(finalMatrix, SIZE, SIZE);
}

int main(void)
{
    //given input matrix
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    //2nd given input matrix
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    //Prints all the data using the functions
    printf("Matrix 1:\n");
    printMatrix(m1, SIZE, SIZE);

    printf("\nMatrix 2:\n");
    printMatrix(m2, SIZE, SIZE);

    printf("\nMatrices added together:\n");
    addMatrices(m1, m2, SIZE, SIZE, SIZE, SIZE);
    

    printf("\nMatrix 1 * Matrix 2:\n");
    multiplyMatrices(m1, m2, SIZE, SIZE, SIZE, SIZE);

    printf("\nMatrix 1 Transposed\n");
    transposeMatrix(m1, SIZE, SIZE);


    //when running the program in a command prompt window it would
    //close instantly before I could read anything and so I
    //added this exit so that the window stays open until a key is pressed
    printf("\nPress enter to exit"); 
    getchar();

    return 0;

}