/*
*function: 用于验证新标准C++程序设计第三章控制结构涉及到的控制语句
* author： Wu Hongjun
* date:    2021.3.13
*/
#include <iostream>
#include <string>
#include <iomanip> //需要包含此头文件
using namespace std;

/*function：input a positive integer ,and then output all factors of the number.输入一个正整数，输出其所有因子，使用for循环语句*/
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
/*题目：给定正整数n和m，在1和n这n个数之间，取出两个不同的数，使得和是m的因子，共有多少种取法
*解题思路：枚举，取出所有的组合进行计算,两层for循环
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

/*题目：牛顿迭代法计算a的平方根，迭代公式：Xn+1=（Xn+a/Xn）/2
* 解题思路：利用while（误差判断表达式）进行计算,误差为两次迭代前后的误差
*/
int square_root()
{
	double a = 0;
	const double error = 0.001;
	cout << "please input a:";
	cin >> a;
	double Xn = a / 2, last_Xn = Xn + 1;
	//while ((Xn*Xn-a >= error)|| (a-Xn * Xn >= error)) // 精度很低
	//{
	//	Xn = (Xn + a / Xn) / 2;
	//}
	while ((Xn - last_Xn >= error) || (last_Xn - Xn >= error)) //精度增加
	{ 
		last_Xn = Xn;
		Xn = (Xn + a / Xn) / 2;
	}
	cout << "The squre root of a is" << Xn << endl;
	return 0;
}
/*
* 题目：例3.7如果两个不同的正整数,它们的和是它们的积的因子,就称这两个数为兄弟数，小的称为弟数,大的称为兄数。
*先后输入正整数n和m(n<m)，请在n至m这m一n+1个数中,找出一对兄弟数。如果找不到,就输出“No Solution.”。如果能
*找到,就找出和最小的那一对;如果有多对兄弟数和相同且都是最小,就找出弟数最小的那一对。
*解题思路：输入两个数，判断是否有兄弟数，有又要找出和最小，再判断是否有多对兄弟数和相同
*/
int findBrotherNumber() //存在两个问题，1是时间复杂度过高，2是增加了brotherNumberFlag = 1这行代码，计算量增加
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
			if ((i * j) % (i + j) == 0) { // 判断是否有兄弟数
				brotherNumberFlag = 1;
				if ((i + j) < (small_number + big_number)) // 找出和最小的兄弟数
				{  
					small_number = i;
					big_number = j;
				}
				else if ((i + j) == (small_number + big_number)) // 和相同，找出弟数最小的兄弟数
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
		cout << "brother numbers are：" << small_number << "    " << big_number << endl;
	}
	else
	{
		cout << "No solution!" << endl;
	}
	return 0;
}
int findBrotherNumber_better() // 减少了时间复杂度
{
	unsigned long long n = 0, m = 0;
	unsigned long long small_number = 0, big_number = 0;
	cout << "input n and m:";
	cin >> n >> m;
	small_number = m+1;
	big_number = m+1;
	for (unsigned long long i = n; i < m; ++i)
	{
		if ( i > (small_number + big_number) / 2) // 如果i大于兄弟和的一半，则i+j大于兄弟数的和，后面就不用计算了
		{
			break;
		}
		for (unsigned long long j = i + 1; j <= m; ++j)
		{
			if ( i + j > small_number + big_number) // 如果和大于兄弟数的和，则不用计算
			{ 
				break;
			}
			if ((i * j) % (i + j) == 0) // 判断是否有兄弟数
			{ 
				if ((i + j) < (small_number + big_number)) // 找出和最小的兄弟数
				{
					small_number = i;
					big_number = j;
				}
				else if ((i + j == small_number + big_number)&&(i < small_number)) // 和相同，找出弟数最小的兄弟数
				{
					small_number = i;
					big_number = j;
				}
			}
		}
	}
	if (small_number != m + 1)
	{
		cout << "brother numbers are：" << small_number << "    " << big_number << endl;
	}
	else
	{
		cout << "No solution!" << endl;
	}
	return 0;
}

/*题目：1.编写程序,每读入3个整数,就将它们从大到小排序输出。读到连续的3个0,则程序结束。
* 解题思路：条件判断，是否是三个0，不是则进行排序，从大到小
*/
int Sort()
{
	int a = -1, b = -1, c = -1, alter = -1; //保证进入循环。
	while (1)
	{
		cout << "input three numbers:";
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		if (b > a) // 排序
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

/*题目：2．编写程序,输入一个整数n,则输出一个由n行“*”构成的等腰三角形,第一行有一个“*”,第二行有3个“*”,第三行有5个“*”……每行比上一行多2个“*”。最后一行不能有空格。
* 解题思路：计算出每行共需要输出多少个元素，在分别输出，前面n+1行都需要输出对应的空格键；最后一行则全部是“*”
*/
int triangular()
{
	int n = 0; // 行数
	int N = 0; // 最后一行“*”的个数
	cout << "please input the number of row:";
	cin >> n;
	if (n > 0)  // 输入正确的行数
	{
		N = 2 * n - 1; //每行有多少个元素；
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
			if (i < n) // 最后一行没有空格
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
* 3．斐波那契数列第一项和第二项都是1,此后各项满足:Fn=Fn-1+Fn-2。编写程序，输人整数n,输出斐波那契数列第n项。
* 解题思路：大于3后直接叠加
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
/*7．计算有两个运算符的算术表达式的值。输入数据第一行是表达式的个数n,后面每行是一个表达式。表达式中没有括号,只有数字和“＋”、“一”“*”、“/”。对每个表达式,输出一行,即计算的结果。结果要精确到小数点后面6位。
输人样例;
2
3 +4*5
9/6+2
输出样例:
23.000000
3.500000
解题思路;要将每一行的字符提取出来，再进行计算。开始输入行数，判断出后面需要输入多少个表达式，再分别对每个表达式进行计算。
*/
void calculate_bad() //错误程序！！！本函数数据输入有问题，不能运行的。本函数输入格式是有要求的，表达式第一个必须是数字，最后一个必须是数字；想得过于复杂，后面熟练之后可以进行优化。
{
	string s[] = { "" };
	string x;
	unsigned int n = 0;
	unsigned int length = 0; // 长度
	int data[10][10] = { {0,0} }; // 保存数字数据数组,最多有10行表达式
	char data_operator[10][10] ;
	unsigned int data_count[] = {0}; // 计算数字的个数
	unsigned int out_data[] = { 0 }; // 保存每一行表达式的输出
	cout << "input n and expression:" << endl;
	cin >> n;
	for (unsigned int i = 0; i < n; ++i) // 输入n个表达式
	{
		getline(cin, s[i]);
	}
	for (unsigned int i = 0; i < n; ++i) // 数据保存
	{
		length = s[i].size();
		for (unsigned int j = 0; j < length; ++j)
		{
			if (s[i][j] >= '0' || s[i][j] <= '9') // 将数据存入对应的数组，有一个问题，判断第一
			{
				data[i][data_count[i]] = 10 * data[i][data_count[i]] + s[i][j];
			}
			else // 保存计算符号
			{
				data_operator[i][data_count[i]] = s[i][j];
				++data_count[i];
			}
		}

	}

	for (unsigned int i = 0; i < n; ++i)
	{
		out_data[i] = data[i][0]; // 将第一个数据保存在out_data中，便于后面迭代
		for (unsigned int j = 0; j < data_count[i]; ++j) //计算每一行的表达式
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
void calculate_simple()  // 思路简化，数据位，运算符位都是确定的，并且不用考虑数据保存的问题。（保存六位有效数字）
{
	char op1, op2;
	double n1, n2, n3, ans;
	unsigned int n;
	cin >> n;
	while (n--)//不能用--n,表示-1执行后的值，会少一行，n--为-1前的表达式
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
		cout << fixed << setprecision(6) << ans << endl; //#include <iomanip> //需要包含此头文件
	}
}
/*8.输人一个不超过6位的整数,输出其倒过来后的结果,符号不变。例如,输人“1234”,则应输出“4321”;输人“-9876”,则应输出“一6789”。
*解题思路：分别保存个十百千万十万位，再将顺序颠倒即可.开始几位是0，则不保存位置。
*/
void change_order()  // 程序复杂，考虑了保存数据，且作用的位数能超过6位，有局限性
{
	int n;
	int data[6];
	int data_count = 0;
	int n2 = 1000000;
	cin >> n;
	if (n > 0)
	{
		for (int i = 0; i < 6; ++i) // 保存每一位
		{
			n2 = n2 / 10;
			if (n / n2 != 0)
			{
				data[data_count] = n / n2;
				n -= data[data_count] * n2;
				++data_count;
			}
		}
		for (int i = 0; i < data_count; ++i) // 输出
		{
			cout << data[data_count - 1 - i];
		}
	}
	else
	{
		n = -1 * n;
		for (int i = 0; i < 6; ++i) // 保存每一位
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
		for (int i = 0; i < data_count; ++i) // 输出
		{
			cout << data[data_count - 1 - i];
		}
	}

}

void change_order_simple()  //非常简单的计算，得到各个位，可以用n%10得到每一位，中间用n=n/10对n进行更新。这就是一段非常漂亮的代码。
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
		while (n > 0) //得到一个数的各个位
		{
			cout << n % 10;
			n /= 10;
		}
	}
}
/*9.打印乘法口诀表
* 思路：直接两个for循环输出
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
/*10.输出所有“水仙花数”。“水仙花数”是一个3位正整数,其值等于各位数的立方和。例如,153就是水仙花数,因为153=1^3+5^3＋3^3。
*思路：得到各位，再进行计算，合适的则进行输出。
*/
void daffodil_number() //不能直接在i的基础上进行i=i/10，这种是错误的，中间把i修改了，则执行的顺序是乱的，i不是从100到999，中间全乱
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
* 11．输人一个二进制数(不超过8位),将其转换成一个十进制数输出。
*思路：定义一个中间变量数，每次循环中间数*2，再用每一位二进制数乘以中间数，得到每一位的数值，将所有的相加得到和。
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
/*12．井底的蜗牛离井口m米。白天蜗牛向上爬若干米,晚上蜗牛滑下来1米。
*每天白天向上爬的距离是昨天的1/3。已知第一天白天能向上爬n米,问几天
*后蜗牛能爬出井外(到井口就出去了)。输入两个整数数据为m和n,输出第几
*天爬出井口。如果永远爬不出，则输出“Never”。
* 思路：每天上升的距离进行计算，每天上升的距离为n,若n-1小于等于0，则never。否则一直叠加n-1，和为sum。sum大于m时，爬出井口，输出i即天数。
*/
void crawl_error() //错误的代码， 考虑一个问题，如果是白天跑了，就不能简单地用sum += n-1，进行计算
{
	double m = 0.0, n = 0.0;
	cout << "please input m and n:" << endl;
	cin >> m >> n;
	double sum = 0;
	int day = 0;
	while (sum < m)
	{
		if (n - 1 <= 0)  // 错误的地方，加入n=1，m=1，本程序会直接break，但是实际上在白天已经爬出来了。
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
void crawl() //纠正了上面的问题。
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
			sum += n; // 白天上升nm
			if (sum - m >= 0)
			{
				cout << "It spends " << day << " days" << endl;
				break;
			}
			sum -= 1;  // 晚上下降1m
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