/*
*function: ������֤�±�׼C++������Ƶ����¿��ƽṹ�漰���Ŀ������
* author�� Wu Hongjun
* date:    2021.3.13
*/
#include <iostream>
#include <string>
#include <iomanip> //��Ҫ������ͷ�ļ�
using namespace std;

/*function��input a positive integer ,and then output all factors of the number.����һ����������������������ӣ�ʹ��forѭ�����*/
int outputAllfactors()
{
	unsigned int num = 0;
	unsigned int  factor_count =0;
	cout << "please input a positive integer:";
	cin >> num;
	for (unsigned int i = 1; i <= num; ++i) {
		if (num % i == 0) {
			cout << "factor:" << i << endl;
			++factor_count;
		}
	}
	cout << "There are "  << factor_count << " factors";
	return 0;
}
/*��Ŀ������������n��m����1��n��n����֮�䣬ȡ��������ͬ������ʹ�ú���m�����ӣ����ж�����ȡ��
*����˼·��ö�٣�ȡ�����е���Ͻ��м���,����forѭ��
*/
int findAllSolution()
{
	unsigned int n = 0, m = 0;
	unsigned int  factor_count = 0;
	cout << "please input n and m:"<<endl;
	cin >> n >> m;
	for (unsigned int i = 1;i<=n;++i) {
		for (unsigned int j = i + 1; j <= n; ++j) {
			if (m % (i + j) == 0) {
				cout << "factor:" <<i<<"+" <<j<<"="<<i+j << endl;
				++factor_count;
			}
		}
	}
	cout << "There are " << factor_count << " factors";
	return 0;
}

/*��Ŀ��ţ�ٵ���������a��ƽ������������ʽ��Xn+1=��Xn+a/Xn��/2
* ����˼·������while������жϱ��ʽ�����м���,���Ϊ���ε���ǰ������
*/
int square_root()
{
	double a = 0;
	const double error = 0.001;
	cout << "please input a:";
	cin >> a;
	double Xn = a / 2, last_Xn = Xn + 1;
	//while ((Xn*Xn-a >= error)|| (a-Xn * Xn >= error)) // ���Ⱥܵ�
	//{
	//	Xn = (Xn + a / Xn) / 2;
	//}
	while ((Xn - last_Xn >= error) || (last_Xn - Xn >= error)) //��������
	{ 
		last_Xn = Xn;
		Xn = (Xn + a / Xn) / 2;
	}
	cout << "The squre root of a is" << Xn << endl;
	return 0;
}
/*
* ��Ŀ����3.7���������ͬ��������,���ǵĺ������ǵĻ�������,�ͳ���������Ϊ�ֵ�����С�ĳ�Ϊ����,��ĳ�Ϊ������
*�Ⱥ�����������n��m(n<m)������n��m��mһn+1������,�ҳ�һ���ֵ���������Ҳ���,�������No Solution.���������
*�ҵ�,���ҳ�����С����һ��;����ж���ֵ�������ͬ�Ҷ�����С,���ҳ�������С����һ�ԡ�
*����˼·���������������ж��Ƿ����ֵ���������Ҫ�ҳ�����С�����ж��Ƿ��ж���ֵ�������ͬ
*/
int findBrotherNumber() //�����������⣬1��ʱ�临�Ӷȹ��ߣ�2��������brotherNumberFlag = 1���д��룬����������
{
	unsigned long long n = 0, m = 0;
	unsigned long long small_number = 0, big_number = 0;
	short brotherNumberFlag = 0;
	cout << "input n and m:";
	cin >> n >> m;
	small_number = m;
	big_number = m;
	for (unsigned long long i = n; i < m; ++i) 
	{
		for (unsigned long long j = i+1; j <=m; ++j)
		{
			if ((i * j) % (i + j) == 0) { // �ж��Ƿ����ֵ���
				brotherNumberFlag = 1;
				if ((i + j) < (small_number + big_number)) // �ҳ�����С���ֵ���
				{  
					small_number = i;
					big_number = j;
				}
				else if ((i + j) == (small_number + big_number)) // ����ͬ���ҳ�������С���ֵ���
				{  
					if (i < small_number) 
					{
						small_number = i;
						big_number = j;
					}
				}

							
			}
		}
	}
	if (brotherNumberFlag) 
	{
		cout << "brother numbers are��" << small_number << "    " << big_number << endl;
	}
	else
	{
		cout << "No solution!" << endl;
	}
	return 0;
}
int findBrotherNumber_better() // ������ʱ�临�Ӷ�
{
	unsigned long long n = 0, m = 0;
	unsigned long long small_number = 0, big_number = 0;
	cout << "input n and m:";
	cin >> n >> m;
	small_number = m+1;
	big_number = m+1;
	for (unsigned long long i = n; i < m; ++i)
	{
		if ( i > (small_number + big_number) / 2) // ���i�����ֵܺ͵�һ�룬��i+j�����ֵ����ĺͣ�����Ͳ��ü�����
		{
			break;
		}
		for (unsigned long long j = i + 1; j <= m; ++j)
		{
			if ( i + j > small_number + big_number) // ����ʹ����ֵ����ĺͣ����ü���
			{ 
				break;
			}
			if ((i * j) % (i + j) == 0) // �ж��Ƿ����ֵ���
			{ 
				if ((i + j) < (small_number + big_number)) // �ҳ�����С���ֵ���
				{
					small_number = i;
					big_number = j;
				}
				else if ((i + j == small_number + big_number)&&(i < small_number)) // ����ͬ���ҳ�������С���ֵ���
				{
					small_number = i;
					big_number = j;
				}
			}
		}
	}
	if (small_number != m + 1)
	{
		cout << "brother numbers are��" << small_number << "    " << big_number << endl;
	}
	else
	{
		cout << "No solution!" << endl;
	}
	return 0;
}

/*��Ŀ��1.��д����,ÿ����3������,�ͽ����ǴӴ�С�������������������3��0,����������
* ����˼·�������жϣ��Ƿ�������0��������������򣬴Ӵ�С
*/
int Sort()
{
	int a = -1, b = -1, c = -1, alter = -1; //��֤����ѭ����
	while (1)
	{
		cout << "input three numbers:";
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		if (b > a) // ����
		{
			alter = a;
			a = b; 
			b = alter;
		}
		if (c > b)
		{
			alter = b;
			b = c;
			c = alter;
		}
		if (b > a) 
		{
			alter = a;
			a = b;
			b = alter;
		}
		cout << "sort from largest to the smallest:" << a << "," << b << "," << c << endl;
	}
	cout << "The code is over!" << endl;
	return 0;

}

/*��Ŀ��2����д����,����һ������n,�����һ����n�С�*�����ɵĵ���������,��һ����һ����*��,�ڶ�����3����*��,��������5����*������ÿ�б���һ�ж�2����*�������һ�в����пո�
* ����˼·�������ÿ�й���Ҫ������ٸ�Ԫ�أ��ڷֱ������ǰ��n+1�ж���Ҫ�����Ӧ�Ŀո�������һ����ȫ���ǡ�*��
*/
int triangular()
{
	int n = 0; // ����
	int N = 0; // ���һ�С�*���ĸ���
	cout << "please input the number of row:";
	cin >> n;
	if (n > 0)  // ������ȷ������
	{
		N = 2 * n - 1; //ÿ���ж��ٸ�Ԫ�أ�
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n - i; ++j)
			{
				cout << " ";
			}
			for (int j = 1; j <= 2*i - 1; ++j)
			{
				cout << "*";
			}
			for (int j = 1; j <= n - i; ++j)
			{
				cout << " ";
			}
			if (i < n) // ���һ��û�пո�
			{
				cout << endl;
			}
		}
	}
	else
	{
		cout << "The row must be greater than 0." << endl;
	}
	return 0;
}
/*
* 3��쳲��������е�һ��͵ڶ����1,�˺��������:Fn=Fn-1+Fn-2����д������������n,���쳲��������е�n�
* ����˼·������3��ֱ�ӵ���
*/
void FibonacciSequence()
{
	unsigned long long  n = 0;
	cout << "The ?th term of the Fibonacci sequence:";
	cin >> n;
	unsigned long long Fn_1 = 0, Fn_2 = 0, Fn = 0;
	if (n == 1 || n == 2)
	{
		cout << "The " << n << "th term of the Fibonacci sequence is" << 1 << endl;
	}
	else if (n >= 3)
	{
		Fn_1 = 1, Fn_2 = 1;
		for (unsigned long long i = 2; i < n; ++i)
		{
			Fn = Fn_1 + Fn_2;
			Fn_2 = Fn_1;
			Fn_1 = Fn;
		}
		cout << "The " << n << "th term of the Fibonacci sequence is " << Fn << "." << endl;
	}
	else
	{
		cout << "please input a correct number!" << endl;
	}
}
/*7��������������������������ʽ��ֵ���������ݵ�һ���Ǳ��ʽ�ĸ���n,����ÿ����һ�����ʽ�����ʽ��û������,ֻ�����ֺ͡���������һ����*������/������ÿ�����ʽ,���һ��,������Ľ�������Ҫ��ȷ��С�������6λ��
��������;
2
3 +4*5
9/6+2
�������:
23.000000
3.500000
����˼·;Ҫ��ÿһ�е��ַ���ȡ�������ٽ��м��㡣��ʼ�����������жϳ�������Ҫ������ٸ����ʽ���ٷֱ��ÿ�����ʽ���м��㡣
*/
void calculate_bad() //������򣡣����������������������⣬�������еġ������������ʽ����Ҫ��ģ����ʽ��һ�����������֣����һ�����������֣���ù��ڸ��ӣ���������֮����Խ����Ż���
{
	string s[] = { "" };
	string x;
	unsigned int n = 0;
	unsigned int length = 0; // ����
	int data[10][10] = { {0,0} }; // ����������������,�����10�б��ʽ
	char data_operator[10][10] ;
	unsigned int data_count[] = {0}; // �������ֵĸ���
	unsigned int out_data[] = { 0 }; // ����ÿһ�б��ʽ�����
	cout << "input n and expression:" << endl;
	cin >> n;
	for (unsigned int i = 0; i < n; ++i) // ����n�����ʽ
	{
		getline(cin, s[i]);
	}
	for (unsigned int i = 0; i < n; ++i) // ���ݱ���
	{
		length = s[i].size();
		for (unsigned int j = 0; j < length; ++j)
		{
			if (s[i][j] >= '0' || s[i][j] <= '9') // �����ݴ����Ӧ�����飬��һ�����⣬�жϵ�һ
			{
				data[i][data_count[i]] = 10 * data[i][data_count[i]] + s[i][j];
			}
			else // ����������
			{
				data_operator[i][data_count[i]] = s[i][j];
				++data_count[i];
			}
		}

	}

	for (unsigned int i = 0; i < n; ++i)
	{
		out_data[i] = data[i][0]; // ����һ�����ݱ�����out_data�У����ں������
		for (unsigned int j = 0; j < data_count[i]; ++j) //����ÿһ�еı��ʽ
		{
			if (data_operator[i][j] == '+')
			{
				out_data[i] = out_data[i] + data[i][j + 1];
			}
			else if (data_operator[i][j] == '-')
			{
				out_data[i] = out_data[i] - data[i][j + 1];
			}
			else if (data_operator[i][j] == '*')
			{
				out_data[i] = out_data[i] - data[i][j + 1];
			}
			else if (data_operator[i][j] == '/')
			{
				out_data[i] = out_data[i] / data[i][j + 1];
			}
		}
		cout << out_data[i] << endl;
	}
}
void calculate_simple()  // ˼·�򻯣�����λ�������λ����ȷ���ģ����Ҳ��ÿ������ݱ�������⡣��������λ��Ч���֣�
{
	char op1, op2;
	double n1, n2, n3, ans;
	unsigned int n;
	cin >> n;
	while (n--)//������--n,��ʾ-1ִ�к��ֵ������һ�У�n--Ϊ-1ǰ�ı��ʽ
	{
		cin >> n1 >> op1 >> n2 >> op2 >> n3;
		switch (op1)
		{
		case '+':
			switch (op2)
			{
			case'+':
				ans = n1 + n2 + n3;
				break;
			case'-':
				ans = n1 + n2 - n3;
				break;
			case'*':
				ans = n1 + (double)n2 * n3;
				break;
			case'/':
				ans = n1 + (double)n2 / n3;
				break;
			}
			break;
		case'-':
			switch (op2)
			{
			case'+':
				ans = n1 - n2 + n3;
				break;
			case'-':
				ans = n1 - n2 - n3;
				break;
			case'*':
				ans = n1 - n2 * n3;
				break;
			case'/':
				ans = n1 - (double)n2 / n3;
				break;
			}
			break;
		case '*':
			switch (op2)
			{
			case'+':
				ans = n1 * n2 + n3;
				break;
			case'-':
				ans = n1 * n2 - n3;
				break;
			case'*':
				ans = n1 * n2 * n3;
				break;
			case'/':
				ans = n1 * (double)n2 / n3;
				break;
			}
			break;
		case'/':
			switch (op2)
			{
			case'+':
				ans = (double)n1 / n2 + n3;
				break;
			case'-':
				ans = (double)n1 / n2 - n3;
				break;
			case'*':
				ans = (double)n1 / n2 * n3;
				break;
			case'/':
				ans = (double)n1 / n2 / n3;
				break;
			}
			break;

		}
		cout << fixed << setprecision(6) << ans << endl; //#include <iomanip> //��Ҫ������ͷ�ļ�
	}
}
/*8.����һ��������6λ������,����䵹������Ľ��,���Ų��䡣����,���ˡ�1234��,��Ӧ�����4321��;���ˡ�-9876��,��Ӧ�����һ6789����
*����˼·���ֱ𱣴��ʮ��ǧ��ʮ��λ���ٽ�˳��ߵ�����.��ʼ��λ��0���򲻱���λ�á�
*/
void change_order()  // �����ӣ������˱������ݣ������õ�λ���ܳ���6λ���о�����
{
	int n;
	int data[6];
	int data_count = 0;
	int n2 = 1000000;
	cin >> n;
	if (n > 0)
	{
		for (int i = 0; i < 6; ++i) // ����ÿһλ
		{
			n2 = n2 / 10;
			if (n / n2 != 0)
			{
				data[data_count] = n / n2;
				n -= data[data_count] * n2;
				++data_count;
			}
		}
		for (int i = 0; i < data_count; ++i) // ���
		{
			cout << data[data_count - 1 - i];
		}
	}
	else
	{
		n = -1 * n;
		for (int i = 0; i < 6; ++i) // ����ÿһλ
		{
			n2 = n2 / 10;
			if (n / n2 != 0)
			{
				data[data_count] = n / n2;
				n -= data[data_count] * n2;
				++data_count;
			}
		}
		cout << "-";
		for (int i = 0; i < data_count; ++i) // ���
		{
			cout << data[data_count - 1 - i];
		}
	}

}

void change_order_simple()  //�ǳ��򵥵ļ��㣬�õ�����λ��������n%10�õ�ÿһλ���м���n=n/10��n���и��¡������һ�ηǳ�Ư���Ĵ��롣
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			cout << "-";
		}
		while (n > 0) //�õ�һ�����ĸ���λ
		{
			cout << n % 10;
			n /= 10;
		}
	}
}
/*9.��ӡ�˷��ھ���
* ˼·��ֱ������forѭ�����
*/
void multiply()
{
	cout << "*  1  2  3  4  5  6  7  8  9" << endl;
	for (int i = 1; i <= 9; ++i)
	{
		cout << i << " ";
		for (int j = 1; j <= 9; ++j)
		{
			if (i * j < 10)
			{
				cout << " " << i * j << " ";
			}
			else
			{
				cout << i * j << " ";
			}

		}
		cout << endl;

	}
}
/*10.������С�ˮ�ɻ���������ˮ�ɻ�������һ��3λ������,��ֵ���ڸ�λ���������͡�����,153����ˮ�ɻ���,��Ϊ153=1^3+5^3��3^3��
*˼·���õ���λ���ٽ��м��㣬���ʵ�����������
*/
void daffodil_number() //����ֱ����i�Ļ����Ͻ���i=i/10�������Ǵ���ģ��м��i�޸��ˣ���ִ�е�˳�����ҵģ�i���Ǵ�100��999���м�ȫ��
{
	int data[3] = { 0 };
	for (int i = 100; i < 1000; ++i)
	{
		int n = i;
		for (int j = 0; j < 3; ++j)
		{
			data[j] = n % 10;
			n /= 10;
		}
		if (data[0] * data[0] * data[0] + data[1] * data[1] * data[1] + data[2] * data[2] * data[2] == i)
		{
			cout << i << " ";
		}
		
	}
}
void daffodil_number_simple()
{
	int sum = 0;
	for (int i = 100; i < 1000; ++i)
	{
		sum = 0;
		int n = i;
		for (int j = 0; j < 3; ++j)
		{
			int a = n % 10;
			sum += a * a * a;
			n /= 10;
		}
		if (sum == i)
		{
			cout << i << " ";
		}
	}
}
/*
* 11������һ����������(������8λ),����ת����һ��ʮ�����������
*˼·������һ���м��������ÿ��ѭ���м���*2������ÿһλ�������������м������õ�ÿһλ����ֵ�������е���ӵõ��͡�
*/
void BinaryToDecimal()
{
	string s;
	getline(cin, s);
	int length = s.size();
	int sum = 0, iter = 1;
	for (int i = 0; i < length; ++i) 
	{
		sum += (s[length - 1 - i]-48) * iter;
		iter *= 2;
	}
	cout << sum << endl;
}
/*12�����׵���ţ�뾮��m�ס�������ţ������������,������ţ������1�ס�
*ÿ������������ľ����������1/3����֪��һ�������������n��,�ʼ���
*����ţ����������(�����ھͳ�ȥ��)������������������Ϊm��n,����ڼ�
*���������ڡ������Զ���������������Never����
* ˼·��ÿ�������ľ�����м��㣬ÿ�������ľ���Ϊn,��n-1С�ڵ���0����never������һֱ����n-1����Ϊsum��sum����mʱ���������ڣ����i��������
*/
void crawl_error() //����Ĵ��룬 ����һ�����⣬����ǰ������ˣ��Ͳ��ܼ򵥵���sum += n-1�����м���
{
	double m = 0.0, n = 0.0;
	cout << "please input m and n:" << endl;
	cin >> m >> n;
	double sum = 0;
	int day = 0;
	while (sum < m)
	{
		if (n - 1 <= 0)  // ����ĵط�������n=1��m=1���������ֱ��break������ʵ�����ڰ����Ѿ��������ˡ�
		{
			cout << "Never!";
			break;
		}
		sum += n - 1;
		n /= 3;
		++day;
		cout << sum << endl;
	}
	if (sum >= m)
	{
		cout << "It spends " << day << " days" << endl;
	}	
}
void crawl() //��������������⡣
{
	double m = 0.0, n = 0.0;
	cout << "please input m and n:" << endl;
	cin >> m >> n;
	int day = 0;
	if (n >= m)
	{
		day = 1;
		cout << "It spends " << day << " days" << endl;
	}
	else 
	{
		double sum = 0;
		while (1)
		{
			++day;
			sum += n; // ��������nm
			if (sum - m >= 0)
			{
				cout << "It spends " << day << " days" << endl;
				break;
			}
			sum -= 1;  // �����½�1m
			n /= 3;
			if (n - 1 <= 0)
			{
				cout << "Never!";
				break;
			}
		}
	}
}

int main()
{
	crawl();
	return 0;
}