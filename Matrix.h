// This is Matrix.h

#pragma once

class Matrix
{
    private:
        int rows, cols;
        char **matrix;
    
    public:
        // Constructor
        Matrix(int, int);

        // Function prototypes
        char **MatrixCreate(void);
        void MatrixInput(void);
        void MatrixPrint(void);
        void MatrixDelete(void);
        void MatrixGroundFill(void);
        bool MatrixInsertAt(int, int, char);

};