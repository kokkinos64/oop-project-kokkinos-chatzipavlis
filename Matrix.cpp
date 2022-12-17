#include <iostream>
#include "Matrix.h"
#include "Map.h"
#include "Characters.h"

using namespace std;

// CONSTRUCTOR CODE
Matrix::Matrix(int r = 5, int c = 5) : rows(r), cols(c)     // Default matrix dimentions: 5x5
{
    cout << rows << "x" << cols << " dimentions were set." << endl;
    matrix = MatrixCreate();
}

// FUNCTION CODE
char **Matrix::MatrixCreate(void)
{
    int i;

    // Creating the matrix
    /* char ** */ matrix = new char *[rows];

    // Chack if memory space was not allocated
    if (matrix == NULL)
    {
        cout << "Cannot allocate memory (outer matrix)" << endl;
        exit(-1);
    }

    for (i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];

        // Chack if memory space was not allocated
        if (matrix[i] == NULL)
        {
            cout << "Cannot allocate memory (inner matrix)" << endl;
            exit(-1);
        }
    }

    return matrix;
}

void Matrix::MatrixGroundFill(void)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matrix[i][j] = '*';
        }
    }
}

bool Matrix::MatrixInsertAt(int i, int j, char c)
{
    if (matrix[i][j] == '*')    // If the selected spot on the matrix is empty
    {
        matrix[i][j] = c;       // Insert the given character there
        return true;            // Success
    }
    else
    {
        return false;           // Failure
    }
}

void Matrix::MatrixInput(void)
{
    int i, j;

    cout << "Enter characters:\n";

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void Matrix::MatrixPrint(void)
{
    int i, j;

    cout << "\n================================\n";

    for (i = 0; i < rows; i++)
    {
        cout << "matrix[" << i << "]: "; // Print the number of the current row

        for (j = 0; j < cols; j++)
        {
            cout << " " << matrix[i][j];
        }

        cout << endl;
    }

    cout << "================================\n";
}

void Matrix::MatrixDelete(void)
{
    int i;

    // Memory dislocation for the matrix
    for (i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}