#include <iostream>
#include <cmath>
#include <cassert>


class Complex {
private:
    double real;
    double img;

public:
    Complex(double real, double img) : real(real), img(img) {}

    double getReal() const {
        return real;
    }

    void setReal(double real) {
        this->real = real;
    }

    double getImg() const {
        return img;
    }

    void setImg(double img) {
        this->img = img;
    }

    Complex operator+(const Complex& other) const {
        double sumReal = real + other.real;
        double sumImg = img + other.img;
        return Complex(sumReal, sumImg);
    }

    Complex operator-(const Complex& other) const {
        double diffReal = real - other.real;
        double diffImg = img - other.img;
        return Complex(diffReal, diffImg);
    }

    Complex operator*(const Complex& other) const {
        double multReal = real * other.real - img * other.img;
        double multImg = real * other.img + img * other.real;
        return Complex(multReal, multImg);
    }

    Complex operator/(const Complex& other) const {
        double divReal = (real * other.real + img * other.img) / (other.real * other.real + other.img * other.img);
        double divImg = (img * other.real - real * other.img) / (other.real * other.real + other.img * other.img);
        return Complex(divReal, divImg);
    }

    bool operator==(const Complex& other) const {
        return real == other.real && img == other.img;
    }

    bool operator==(int number) const {
        return real == number && img == 0;
    }

    bool operator==(float number) const {
        return real == number && img == 0;
    }

    Complex power(int exponent) const {
        double modulus = sqrt(real * real + img * img);
        double angle = atan2(img, real);
        double newModulus = pow(modulus, exponent);
        double newAngle = angle * exponent;
        double newReal = newModulus * cos(newAngle);
        double newImg = newModulus * sin(newAngle);
        return Complex(newReal, newImg);
    }

    double modulus() const {
        return sqrt(real * real + img * img);
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& number) {
        out << "(" << number.real << " + " << number.img << "i)";
        return out;
    }
    
};

//Test

void TestGet() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    assert(c1.getReal() == 2);
    assert(c1.getImg() == 3);
    assert(c2.getReal() == 4);
    assert(c2.getImg() == 5);

    Complex sum = c1 + c2;
    assert(sum.getReal() == 6);
    assert(sum.getImg() == 8);

    Complex diff = c1 - c2;
    assert(diff.getReal() == -2);
    assert(diff.getImg() == -2);
    std::cout << "TestGet Ok\n";
}
void testSet() {
    Complex c(0,0);
    c.setReal(2);
    c.setImg(5);
    assert(c.getReal() == 2);
    assert(c.getImg() == 5);
    std::cout << "TestSet Ok\n";
}
void testSum() {
    Complex a(2, 3);
    Complex b(4, 5);
    Complex c(-1, 0);
    Complex result1 = a+b;
    Complex result2 = a + c;
    assert(result1.getReal() == 6);
    assert(result1.getImg() == 8);
    assert(result2.getReal() == 1);
    assert(result2.getImg() == 3);
    std::cout << "TestOperator+ Ok\n";
}
void testDiff() {
    Complex a(2, 3);
    Complex b(4, 5);
    Complex c(-1, 0);
    Complex result1 = a - b;
    Complex result2 = a - c;
    assert(result1.getReal() == -2);
    assert(result1.getImg() == -2);
    assert(result2.getReal() == 3);
    assert(result2.getImg() == 3);
    std::cout << "TestOperator- Ok\n";
}
void testMult() {
    Complex a(2, 3);
    Complex b(4, 5);
    Complex c(-1, 0);
    Complex result1 = a * b;
    Complex result2 = a * c;
    assert(result1.getReal() == -7);
    assert(result1.getImg() == 22);
    assert(result2.getReal() == -2);
    assert(result2.getImg() == -3);
    std::cout << "TestOperator* Ok\n";
}
void testDiv() {
    Complex a(2, 3);
    Complex b(4, 5);
    Complex c(-1, 1);
    Complex result1 = a / b;
    Complex result2 = a / c;
    assert(std::abs(result1.getReal() - 0.560976) < 0.0001);
    assert(std::abs(result1.getImg() - 0.0487805) < 0.0001);
    assert(std::abs(result2.getReal() - 0.5) < 0.0001);
    assert(std::abs(result2.getImg() - (-2.5)) < 0.0001);
    std::cout << "TestOperator/ Ok\n";
}
void testComp() {
    Complex a(2, 3);
    Complex b(4, 0);
    Complex c(2, 3);
    Complex result1 = a / b;
    Complex result2 = a / c;
    assert(a == c);
    assert((a == b)==0);
    assert((a == 2)==0);
    assert((b == 4)==1);
    assert((a == 2.0f)==0);
    assert((b == 4.0f)==1);
    std::cout << "TestOperator== Ok\n";
}
void testPow() {
    Complex a(2, 3);
    Complex c(0, 0);
    Complex result1 = a.power(3);
    Complex result2 = a.power(2);
    Complex result3 = c.power(2);
    assert(std::abs(result1.getReal() - (-46)) < 0.0001);
    assert(std::abs(result1.getImg() - 9) < 0.0001);
    assert(std::abs(result2.getReal() - (-5)) < 0.0001);
    assert(std::abs(result2.getImg() - 12) < 0.0001);
    assert(std::abs(result3.getReal() - 0) < 0.0001);
    assert(std::abs(result3.getImg() - 0) < 0.0001);
    std::cout << "TestPower Ok\n";
}
void testMod() {
    Complex a(2, 3);
    Complex b(-4, 5);
    Complex c(0, 0);
    assert(std::abs(a.modulus() - 3.60555) < 0.0001);
    assert(std::abs(b.modulus() - 6.40312) < 0.0001);
    assert(std::abs(c.modulus() - 0) < 0.0001);
    
    std::cout << "TestModulus Ok\n";
}


int main() {
    
    TestGet();
    testSet();
    testSum();
    testDiff();
    testMult();
    testDiv();
    testComp();
    testPow();
    testMod();

    return 0;
}