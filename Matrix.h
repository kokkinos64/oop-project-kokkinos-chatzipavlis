// This is Matrix.h

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

};