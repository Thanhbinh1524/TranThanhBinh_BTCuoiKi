 #include <iostream>

class ComplexNumber {
private:
    int a;
    int b;

public:
    // Constructor
    ComplexNumber(int real, int imag) : a(real), b(imag) {}

    // Phép cộng
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(a + other.a, b + other.b);
    }

    // Phép trừ
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(a - other.a, b - other.b);
    }

    // Phép đổi dấu
    ComplexNumber operator-() const {
        return ComplexNumber(-a, -b);
    }

    // Phép nhân
    ComplexNumber operator*(const ComplexNumber& other) const {
        // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
        int real = a * other.a - b * other.b;
        int imag = a * other.b + b * other.a;
        return ComplexNumber(real, imag);
    }

    // Xuất
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex) {
        os << complex.a;
        if (complex.b >= 0) {
            os << " + " << complex.b << "sqrt(7)";
        } else {
            os << " - " << -complex.b << "sqrt(7)";
        }
        return os;
    }

    // Nhập phần thực, phần ảo
    friend std::istream& operator>>(std::istream& is, ComplexNumber& complex) {
        std::cout << "Nhap phan thuc: ";
        is >> complex.a;
        std::cout << "Nhap phan ao: ";
        is >> complex.b;
        return is;
    }
};

int main() {
    ComplexNumber num1(2, 3);
    ComplexNumber num2(1, -2);

    // Thực hiện các thao tác
    ComplexNumber sum = num1 + num2;
    ComplexNumber difference = num1 - num2;
    ComplexNumber negation = -num1;
    ComplexNumber product = num1 * num2;

    // Xuất kết quả
    std::cout << "Tong: " << sum << std::endl;
    std::cout << "Hieu: " << difference << std::endl;
    std::cout << "Dao dau: " << negation << std::endl;
    std::cout << "Tich: " << product << std::endl;

    return 0;
}