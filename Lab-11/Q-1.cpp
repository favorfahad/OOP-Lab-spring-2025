#include "iostream"
#include "exception"
using namespace std;

class DimensionMismatchException : public exception {
    string text;
    public:
    DimensionMismatchException(string t) : text(t) {}
    const char* what() const noexcept override {
        return text.c_str();
    }
};

template<typename T>
class Matrix {
    T **matrix;
    int rows;
    int cols;
    public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
       matrix = new T*[rows];
       for (int i=0;i<rows;i++) {
        matrix[i] = new T[cols];
       }
    }

    void setMatrix() {
        for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
                cout << "Enter values for row " << i+1 << ": ";
                cin >> matrix[i][j];
            }
        }
        cout << "The values has been set to the Matrix successfully." << endl;
    }

    void displayMatrix() {
        cout << "\nThe Matrix is: " << endl;
        for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
                cout << matrix[i][j];
            }
        }
    }

    Matrix<T> operator+(Matrix &m2) {
        Matrix<int> result(rows, cols);
        try {
            if(rows != m2.rows || cols != m2.cols) {throw DimensionMismatchException("Invalid match of rows and columns\n");}
            for (int i=0;i<rows;i++) {
                for (int j=0;j<cols;j++) {
                        result.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
                    }
            }   
        }

        catch (DimensionMismatchException &E) { cout << E.what() << endl; }

        return result;
    }

    ~Matrix() {
        for (int i=0;i<rows;i++)
            delete[] matrix[i];
        delete matrix; 
    }
};

int main () {
    Matrix<int> M1(3, 3);
    Matrix<int> M2(2, 2);

    M1.setMatrix();
    M2.setMatrix();

    Matrix<int> result = M1 + M2;
    return 0;

}
