/*
*To judge the n_th number of a.
* author: wu hongjun
* programmed on 2021.3.10
*/
#include <iostream>
using namespace std;
int main()
{
	int a = 0xfffffff0;
	int n = 0;
	cout << "input n:";
	cin >> n;
	a &= (1 << n);
	a >>= n;
	cout << "The nth number of a is:" << a << endl;
	return 0;
}