#include <iostream>
using namespace std;

class Complex {
private:
	double real, imag;
public:
	void set_complex(double r, double i);
	void prin_Complex();
	void get_value() const;
	Complex();//默认构造函数，无参数
	Complex(double r);
	Complex(double r, double i);
	Complex(Complex c1, Complex c2);
	Complex(const Complex& a);
	
};
Complex::Complex()
{
	cout << "default constructor!" << endl;
}
Complex::Complex(double r) 
{
	real = r;
	imag = 0;
	cout << "complex 1" << endl;
}
Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
	cout << "complex 2" << endl;
}
Complex::Complex(Complex c1, Complex c2) // 构造函数
{
	real = c1.real + c2.real;
	imag = c1.imag + c2.imag;
}
Complex::Complex(const Complex& a) // 复制函数
{
	real = a.real;
	imag = a.imag;
	cout << "Copy function " << endl;
}
void Complex::set_complex(double r, double i)
{
	real = r;
	imag = i;
}
void Complex::prin_Complex()
{
	cout << real << "+" << imag<< "i" << endl;
	//cout << this->real << "+" << this->imag << "i" << endl;
}
void Complex::get_value() const
{
	// 常量成员函数不能改变成员变量值
	//real = 9;
	//imag = 4;
	// 常量成员函数不能使用非常量成员函数,静态成员函数除外。
	//prin_Complex();
	cout << real << "  " << imag << endl;
}

class Another_complex;
class basic_Complex {
private:
	int personal;
	friend class Another_complex;
public:
	int real_b;
	int imag_b;
public:
	basic_Complex(double r, double i) :real_b(r), imag_b(i) { personal = 0; };
	void print_basic();
};
void basic_Complex::print_basic()
{
	cout << "personal" << personal << endl;
}
class Another_complex {
private:
	double real, imag;
	basic_Complex xiaozhu;
public:
	basic_Complex ot;
public:
	Another_complex(double q, double w, double e, double r) :real(q), imag(w), xiaozhu(e, r),ot(e,r)
	{
		ot.personal = 2;
		real += xiaozhu.real_b;
		imag += xiaozhu.imag_b;
		cout << real << "+" << imag << "i" << endl;
	}
};
//
///* 课后题 */
//class A {
//public:
//	int val;
//	A(int n = 0) { val = n; };
//	int GetObj() {
//		return val;
//	}
//};
//int main() {
//	A a;
//	cout << a.val << endl;
//	a.GetObj() = 5;
//	cout << a.val << endl;
//	return 0;
//}
int main()
{
	//Complex Num(4, 5);
	//Num.prin_Complex();
	//Num.set_complex(49.5, 232);
	//Num.prin_Complex();
	//Complex AnotherNum(5);
	//AnotherNum.prin_Complex();
	//Complex Num3(Num, AnotherNum);
	//Num3.prin_Complex();
	//Complex Num4;
	//cout << "array test:" << endl;
	//Complex array1[2];
	//Complex array2[3] = { 2,3,4 };
	//Complex* array4 = new Complex[2];
	//delete []array4;
	//cout << "Copy function test:" << endl;
	//Complex Num5(Num);

	//cout << "常量对象测试" << endl;
	//const Complex OBJ(2, 3);
	//OBJ.get_value();
	Another_complex Num6(1, 2, 4, 5);
	Num6.ot.print_basic();
	return 0;
}