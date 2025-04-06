/* Name: Fahad Qureshi
    Roll No: 24K-0824 */
#include "iostream"
using namespace std;

class Vector {
    private:
    double x;
    double y;
    public:
    Vector(double x, double y) : x(x), y(y) {}
    Vector() {}

    void operator+(Vector const &V) {
        x += V.x;
        y += V.y;
    }

    void operator-(Vector const &V) {
        x -= V.x;
        y -= V.y;
    }

    Vector operator*(double Scalar) {
        Vector v3;
        v3.x = x * Scalar;
        v3.y = y * Scalar;
        return v3;
    }

    friend double dotProduct(Vector &v1, Vector &v2);
    friend ostream& operator<<(ostream &output, Vector &v);
};

double dotProduct(Vector &v1, Vector &v2) {
    double dotProduct;
    dotProduct = (v1.x * v2.x) + (v1.y + v2.y);
    return dotProduct;
}

ostream& operator<<(ostream &output, Vector &v) {
    output << "Vector: " << "(" << v.x << " , " << v.y << ")" << endl;
    return output;
}

int main () {
    Vector v1(4.5, 6.7);
    Vector v2(9.8, 17);

    v1 + v2;
    v2 - v1;

    Vector v3 = v1 * 32;
    cout << v3;

    cout << "Dot Product: " << dotProduct(v1, v2);

    return 0;
}
