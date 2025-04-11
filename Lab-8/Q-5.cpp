/* Name: Fahad Qureshi
    Roll No: 24K-0824 */
#include "iostream"
using namespace std;

class Matrix2x2 {
    int a, b, c, d;
    public:
    Matrix2x2(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
    Matrix2x2() {}

    friend int determinant(Matrix2x2 &m);
    friend class MatrixHelper;
    friend ostream& operator<<(ostream &os, const Matrix2x2 &m);
};

class MatrixHelper {
    Matrix2x2 *matrix;
    public:
    MatrixHelper(Matrix2x2 &m) {
        matrix = new Matrix2x2(m);
    }
    void setElement(int pos, int value) {
        if (pos == 1) matrix->a = value;
        else if (pos == 2) matrix->b = value;
        else if (pos == 3) matrix->c = value;
        else if (pos == 4) matrix->d = value;
    }
    ~MatrixHelper() {
        delete matrix;
    }
};

int determinant(Matrix2x2 &m) {
    return m.a * m.d - m.b * m.c;
}

Matrix2x2 operator+(Matrix2x2 &m1, Matrix2x2 &m2) {
    return Matrix2x2(m1.a + m2.a, m1.b + m2.b, m1.c + m2.c, m1.d + m2.d);
}

Matrix2x2 operator-(Matrix2x2 &m1, Matrix2x2 &m2) {
    return Matrix2x2(m1.a - m2.a, m1.b - m2.b, m1.c - m2.c, m1.d - m2.d);
}

Matrix2x2 operator*(Matrix2x2 &m1, Matrix2x2 &m2) {
    return Matrix2x2(
        m1.a * m2.a + m1.b * m2.c,
        m1.a * m2.b + m1.b * m2.d,
        m1.c * m2.a + m1.d * m2.c,
        m1.c * m2.b + m1.d * m2.d
    );
}

ostream& operator<<(ostream &os, const Matrix2x2 &m) {
    os << m.a << " " << m.b << endl;
    os << m.c << " " << m.d << endl;
    return os;
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 product = m1 * m2;

    cout << "Sum:" << endl << sum;
    cout << "Difference:" << endl << diff;
    cout << "Product:" << endl << product;

    cout << "Determinant of m1: " << determinant(m1) << endl;

    MatrixHelper helper(m1);
    helper.setElement(2, 10);
    cout << "Modified m1:" << endl << m1;

    return 0;
}
