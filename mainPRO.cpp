//
//  main.cpp
//  ProLab1
//
//  Created by Serhii Kopach on 23.09.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

int performCalculationsWithMatrix(int **matrix, int dimension) {
    int maxRowElementsSum = 0;
    for (int i = 0; i < dimension; i++) {
        int maxRowElement = matrix[i][0];
        for (int j = 0; j < dimension; j++) {
            if (matrix[i][j] > maxRowElement) {
                maxRowElement = matrix[i][j];
            }
        }
        maxRowElementsSum += maxRowElement;
    }
    
    int minColumnElementsSum = 0;
    for (int j = 0; j < dimension; j++) {
        int minColumnElement = matrix[0][j];
        for (int i = 0; i < dimension; i++) {
            if (matrix[i][j] < minColumnElement) {
                minColumnElement = matrix[i][j];
            }
        }
        minColumnElementsSum += minColumnElement;
    }
    
    return maxRowElementsSum + minColumnElementsSum;
}

int** fillMatrix(int **matrix, int dimension, int maximumNumber) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            //matrix[i][j] = arc4random_uniform(maximumNumber + 1);
            matrix[i][j] = rand () % (maximumNumber + 1);
        }
    }
    
    return matrix;
}
int** initMatrix(int **matrix, int dimension) {
    matrix = new int* [dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new int[dimension];
    }
    return matrix;
}
void deleteMatrix(int **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        delete [] matrix[i];
    }
}
void showMatrix(int **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

long long mtime () {
	struct timeval t;
    gettimeofday(&t, NULL);
    long long mt = (long long)t.tv_sec * 1000 + t.tv_usec / 1000;
    return mt;
}

int main () {
    srand(time(NULL));
    
    // Matrix initialization
    
    std::cout << "Enter matrix dimension: ";
    
    int matrixDimension;
    std::cin >> matrixDimension;
    
    if (matrixDimension <= 0) {
        std::cout << "Matrix dimension should be more than 0." << std::endl;
        return 0;
    }
    
    /*std::cout << "Enter maximum number: ";
    
    int maximumNumber;
    std::cin >> maximumNumber;
    
    if (maximumNumber <= 0) {
        std::cout << "Maximum number should be more than 0." << std::endl;
        return 0;
    }*/
    int maximumNumber = 5;
    
    int **matrix;
    matrix = initMatrix(matrix, matrixDimension);
    matrix = fillMatrix(matrix, matrixDimension, maximumNumber);
    
    //showMatrix(matrix, matrixDimension);
    
    // Performing calculations with matrix
    
    long long time1 = mtime ();
    int result = performCalculationsWithMatrix(matrix, matrixDimension);
    long long time2 = mtime ();
    
    std::cout << "Result: " << result << std::endl;
    std::cout << "Time: " << time2 - time1 << " ms" << std::endl;
    
    // Matrix deletion
    
    deleteMatrix(matrix, matrixDimension);
    return 0;
}
