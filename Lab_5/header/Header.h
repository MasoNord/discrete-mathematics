#pragma once
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
// Creating/Deleting  of matrix

int** CreateMatrix(int SIZE);
void DeletingMatrix(int** a, int SIZE);

// Main Action

void CreateGraph(int** a, int SIZE);
void OutputArray(int** a, int SIZE);


