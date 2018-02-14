#include <iostream>
using namespace std;


class ComplexNumber {
private:
	int real;
	int imaginary;

public:
	ComplexNumber();
	ComplexNumber(int r, int i);
	ComplexNumber(const ComplexNumber& c);
	~ComplexNumber();

	ComplexNumber operator+(const ComplexNumber& c);
	ComplexNumber operator-(const ComplexNumber& c);
	ComplexNumber operator*(const ComplexNumber& c);

	ComplexNumber operator-();
	ComplexNumber operator++();
	ComplexNumber operator++(int);

	int& operator[](int i);

	bool operator==(const ComplexNumber& c);

	friend ostream& operator<<(ostream& ostr, const ComplexNumber& c);
	friend istream& operator>>(istream& istr, ComplexNumber& c);
};


ComplexNumber::ComplexNumber(){
	real = 0;
	imaginary = 0;
}

ComplexNumber::ComplexNumber(int r, int i){
	real = r;
	imaginary = i;
}

ComplexNumber::ComplexNumber(const ComplexNumber& c){
	real = c.real;
	imaginary = c.imaginary;
}

ComplexNumber::~ComplexNumber(){

}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& c){
	int sum_real = real + c.real;
	int sum_imaginary = imaginary + c.imaginary;
	ComplexNumber sum(sum_real, sum_imaginary);
	return sum;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& c){
	int sub_real = real - c.real;
	int sub_imaginary = imaginary - c.imaginary;
	ComplexNumber sub(sub_real, sub_imaginary);
	return sub;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& c){
	int prod_real = real * c.real - imaginary * c.imaginary;
	int prod_imaginary = imaginary * c.real + real * c.imaginary;
	ComplexNumber prod(prod_real, prod_imaginary);
	return prod;
}

ComplexNumber ComplexNumber::operator-(){
	int neg_real = - real;
	int neg_imaginary = - imaginary;
	ComplexNumber neg(neg_real, neg_imaginary);
	return neg;
}

ComplexNumber ComplexNumber::operator++(){
	++real;
	++imaginary;
	return ComplexNumber(real,imaginary);
}

ComplexNumber ComplexNumber::operator++(int){
	ComplexNumber old(real, imaginary);
	++real;
	++imaginary;
	return old;
}

int& ComplexNumber::operator[](int i){
	if (i == 0) {
		return real;
	} else if (i == 1) {
		return imaginary;
	}
}

bool ComplexNumber::operator==(const ComplexNumber& c){
	if (real != c.real){
		return 0;
	}
	if (imaginary != c.imaginary){
		return 0;
	}
	return 1;
}

ostream& operator<<(ostream& ostr, const ComplexNumber& c){
	ostr << c.real << " + " << c.imaginary << "i";
	return ostr;
}

istream& operator>>(istream& istr, ComplexNumber& c){
	istr >> c.real;
	cout << endl;
	istr >> c.imaginary;
	cout << endl;
	return istr;
}


int main()
{
    ComplexNumber n1(3.5, 7.0); // 3.5 + 7.0i
    ComplexNumber n2;  // 0 + 0i, default constructor
    
    cout << "Two complex numbers: \n"
         << "number 1: " << n1 << endl // output operator
	 << "number 2: " << n2 << endl;
    cout << "Enter a complex number\n";
    cin >> n1; // input operator
    cout << "Enter another complex number\n";
    cin >> n2;

    ComplexNumber n3 = (++n2); // incremental operator and copy contructor
    ComplexNumber n4 = -n1; // negation and copy constructor
    cout << n3 << " + " << n4 << " = " << n3+n4 << endl;
    cout << n3 << " - " << n4 << " = " << n3-n4 << endl;
    cout << n3 << " * " << n4 << " = " << n3*n4 << endl;

    if (n1 == n2) // equality comparison
        cout << "number 1 and number 2 are the same.\n";
    else
        cout << "number 1 and number 2 are NOT the same.\n";

    n3[0] = 10.5; // change the real part to 10.5, overload index operator []
    n3[1] = n3[0]; // change the imaginary part
                   // to be the same as the real part
    cout << "Now the number becomes: " << n3 << endl;

    return 0;
}