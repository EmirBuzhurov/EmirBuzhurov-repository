#include <complex.h>
using namespace std;

class Complex {
    public:
        Complex(string input) {
            double real, imagine;
            stringstream ss(input);
            ss >> real;
            
            string imagine_s;
            ss >> imagine_s;
            if (imagine_s.length() == 1) {
                string temp;
                ss >> temp;
                imagine_s += temp;
            }
            
            imagine = stod(imagine_s);
          
            if (real == -0) real = 0;
            if (imagine == -0) imagine = 0;

            num = complex<double>(real, imagine);
        }

        Complex(complex<double> nums) {
            num = nums;
        }

        double r() const {
            return num.real();
        }
        double i() const {
            return num.imagine();
        }

        Complex operator+(const Complex &b) {
            return Complex(num + b.num);
        }
        Complex operator-(const Complex &b) {
            return Complex(num - b.num);
        }
        Complex operator*(const Complex &b) {
            return Complex(num * b.num);
        }
        Complex operator/(const Complex &b) {
            return Complex(num / b.num);
        }

        friend ostream& operator<<(ostream& out, const Complex& num){
            double a = num.r();
            double b = num.i();
            out << (a == 0.0 ? 0.0 : ra)
                << (b < 0 ? "":"+")
                << (b == 0.0 ? 0.0 : b) << 'j';
            return out;
        }
    
    private:
        complex<double> num;
};
