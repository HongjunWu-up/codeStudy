/*
 function : 第五章数组部分课后题
 author： wu hongjun
 date：   2021.4.4
*/
# include <iostream>
# include <cstring>
# include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
int  matrixMultiple();
int MyItoa();
void swap(int* p1, int* p2)
{
	int* tmp = p1;
	p1 = p2;
	p2 = tmp;
}
void swap1(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int contrast()
{
	int m = 4, n = 3;
	int* pm = &m;
	int* pn = &n;
	cout << *pm << " " << *pn << " " << pm << " " << pn << endl;
	cout << &m << " " << &n << endl;
	cout << m << " " << n << endl;
	swap(pm, pn);
	cout << *pm << " " << *pn << " " << pm << " " << pn << endl;
	cout << &m << " " << &n << endl;
	cout << m << " " << n << endl;
	
	return 0;
}
//class STUDENT
//{
//private:
//	char name[10] = {0};
//	int age;
//	int ID;
//	float grade1;
//public:
//	int print_information();
//	STUDENT();
//	~STUDENT();
//
//private:
//
//};
//int STUDENT::print_information()
//{
//	//string s;
//	//getline(cin, s);
//	char input_information[110];
//	//cin.getline(input_information, 100);
//	sscanf_s("tom 231 43 " ,"%s %d %d", name, age, ID);
//	cout << name;
//	return 0;
//}
//STUDENT::STUDENT()
//{
//	age = 0;
//	ID = 0000;
//}
//
//STUDENT::~STUDENT()
//{
//}

//class CStudent
//{
//private:
//	int age;
//	int id;
//	char name[20];
//	int averageScore[4];
//public:
//	int average() {
//		int sum = 0;
//		for (int i = 0; i < 4; ++i)
//			sum += averageScore[i];
//		return sum / 4;
//	}
//	void printInfo() {
//		printf("%s,%d,%d,%d", name, age, id, average());
//	}
//	void readInfo() {
//		char buf[110];
//		cin.getline(buf, 100);
//		char* p = strchr(buf, ',');
//		p[0] = 0;
//		strcpy(name, buf);
//		sscanf(p + 1, "%d,%d,%d,%d,%d,%d", &id, &age,
//			averageScore, averageScore + 1, averageScore + 2, averageScore + 3);
//	}
//};
//int main()
//{
//	CStudent s;
//	s.readInfo();
//	s.printInfo();
//	return 0;
//}
int main()
{

}
/*6.编程求两个矩阵相乘的结果。输入第一行是整数m,n,表示第一个矩阵是m行n列的;
然后是一个m×n的矩阵。再下一行的输入是整数p，q,表示下一个矩阵是p行q列的（n=p）;
然后就是一个p行q列的矩阵。要求输出两个矩阵相乘的结果（1<m,n,p,q<=8）*/

int  matrixMultiple()
{
	int m, n, p, q;
	cout << "input matrix A:" << endl;
	cin >> m >> n;
	int A[8][8];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> A[i][j];
		}
	}
	cout << "input matrix B:" << endl;
	cin >> p >> q;
	if (p != n)  // 不满足输入要求，结束程序。
	{
		cout << "input error!" << endl;
		return -1;
	}
	int B[8][8]; 
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			cin >> B[i][j];
		}
	}
	int C[8][8]; 
	cout << "matrix C:" << endl;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			C[i][j] = 0;
			for (int k = 0; k < n; ++k)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
			cout << C[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;

}
/*第六章，思考题将字符串数组中的数字字符转换成数字输出*/
int MyItoa()
{
	char s[100];
	cout << "input:";
	cin >> s;
	int number = 0;
	int iter = 1;
	short Change[100] = { 0 };
	int i = 0;
	while (s[i] != 0)
	{
		Change[i] = (short)s[i]-48;
		++i;
	}
	for (int j = i-1; j>=0; --j)
	{
		number += Change[j] * iter;
		iter *= 10;
	}
	cout << "output:" << number << endl;
	return 0;
}