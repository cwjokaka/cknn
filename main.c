#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ** create2dArray(int rows, int cols, int size){
    void ** array;
    array = (void **)malloc(sizeof(void *) * rows);
    for (int i = 0; i < rows; ++i) {
        array[i] = malloc(sizeof(void) * cols * size);
    }
    return array;
};

void load2dData(const char * filePath, int *rows, int *cols, float *** returnData){
    FILE *pFile = fopen(filePath ,"r");
    fscanf(pFile, "rows=%d,cols=%d", rows, cols);
    *returnData = (float **)create2dArray(*rows, *cols, sizeof(float));
    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *cols; ++j) {
            fscanf(pFile, "%f", &(*returnData)[i][j]);
        }
    }
    fclose(pFile);
}

void main(){
    int rows, cols;
    float **array = NULL;
    load2dData("../data.txt", &rows, &cols, &array);

    if (NULL == array){
        return;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%f ", array[i][j]);
        }
        printf("\n");
    }



}