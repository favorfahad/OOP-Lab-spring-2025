/* Name: Fahad Qureshi
    Roll No: 24K-0824 */
#include "iostream"
#include "complex"
using namespace std;

class Complex {
    private:
    double real;
    double img;

    public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex() {real = 0; img = 0;}

    void operator+(Complex const &c2) {
        real += c2.real;
        img += img + c2.img;
    }

    void operator-(Complex const &c2) {
        real -= c2.real;
        img -= img + c2.img;
    }

    void operator*(Complex const &c2) {
        real *= c2.real;
        img *= img + c2.img;
    }

    void operator/(Complex const &c2) {
        real /= c2.real;
        img /= img + c2.img;
    }

    friend ostream& operator<<(ostream &output, Complex const &c);
    friend double magnitude(Complex const &c);
};

ostream& operator<<(ostream &output, Complex const &c) {
    output << "The real part is: " << c.real << endl;
    output << "The imaginary part is: " << c.img << "i" << endl;
    return output;
}

double magnitude(Complex const &c) {
    complex<double> F(c.real, c.img);
    double magnitude = abs(F);
    return magnitude;
}

int main ()  {
    Complex c1(4.4, 9);
    Complex c2(9, 13);

    c1 + c2;
    c1 - c2;
    c1 * c2;
    c1 / c2;

    cout << c1;
    
    cout << "The magnitude of the complex number is: " << magnitude(c1) << endl;

    return 0;
}
