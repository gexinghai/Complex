#include <iostream>
using namespace std;

class Complex
{
public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    bool operator>(Complex& c) const;
    bool operator<(Complex& c) const;
    bool operator==(Complex& c) const;
    Complex operator+(Complex& c) const;
    Complex operator-(Complex& c) const;
    Complex operator-=(Complex& c);
    friend istream& operator>>(istream& cin, Complex& c);
    friend ostream& operator<<(ostream& cout, Complex& c);
    void operator()(double, double);
    void Display() const;

private:
    double real;
    double imag;
};

bool Complex::operator>(Complex& c) const
{
    return (this->real * this->real + this->imag * this->imag) >
        (c.real * c.real + c.imag * c.imag);
}

bool Complex::operator<(Complex& c) const
{
    return (this->real * this->real + this->imag * this->imag) <
        (c.real * c.real + c.imag * c.imag);
}

bool Complex::operator==(Complex& c) const
{
    return (this->real * this->real + this->imag * this->imag) ==
        (c.real * c.real + c.imag * c.imag);
}

Complex Complex::operator+(Complex& c) const
{
    return Complex(this->real + c.real, this->imag + c.imag);
}

Complex Complex::operator-(Complex& c) const
{
    return Complex(this->real - c.real, this->imag - c.imag);
}

Complex Complex::operator-=(Complex& c)
{
    return Complex(this->real -= c.real, this->imag -= c.imag);
}

void Complex::operator()(double real, double imag)
{
    this->real = real;
    this->imag = imag;
}

istream& operator>>(istream& cin, Complex& c) {
    double real, imag;
    char op, ch;
    cin >> real >> op >> imag >> ch;
    if (op == '-') {
        imag = -imag;
    }
    c(real, imag);
    return cin;
}

ostream& operator<<(ostream& cout, Complex& c) {
    cout << c.real;
    if (c.imag > 0) {
        cout << '+' << c.imag << 'i';
    }
    else if (c.imag < 0) {
        cout << c.imag << 'i';
    }
    cout << endl;;
    return cout;
}

void Complex::Display() const
{
    cout << '(' << this->real << ", " << this->imag << ')' << endl;
}

Complex* inputComplex(int n)
{
    Complex* cArray = new Complex[10];
    double real, imag;
    for (int i = 0; i < n; ++i)
    {
        cin >> real >> imag;
        cArray[i](real, imag);
    }
    return cArray;
}

void question1()
{
    Complex* cArray = inputComplex(2);
    if (cArray[0] > cArray[1])
    {
        cout << 1 << endl;
    }
    else if (cArray[0] < cArray[1])
    {
        cout << -1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    delete[] cArray;
}

void question2() {
    Complex* cArray = inputComplex(2);
    (cArray[0] + cArray[1]).Display();
    (cArray[0] - cArray[1]).Display();
    ((cArray[0] - cArray[1]) -= cArray[0]).Display();
    delete[] cArray;
}

void question5() {
    Complex c;
    cin >> c;
    cout << c << endl;
}

int main()
{
    //question1();
    //question2();
    question5();

    return 0;
}