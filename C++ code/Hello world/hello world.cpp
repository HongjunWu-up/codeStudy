/*
	加密解密程序
*/
#include <iostream>
#include <string>
using namespace std;
void encryption(string& s, string &key)
{
	int len = s.size();
	int keySize = key.size();
	for (int i = 0; i < len; i++)
	{
		s[i]  ^= key[i % keySize]; //重复使用key进行加密。
	}
}

void decode(string& s, string & key) //和加密文件一致
{
	int len = s.size();
	int keySize = key.size();
	for (int i = 0; i < len; i++)
	{
		s[i] ^= key[i % keySize]; //重复使用key进行解密。
	}
}
int main()
{
	string s = "hahahahaaaaaa";
	string key = "11234441";
	getline(cin, s);//输入字符串
	getline(cin, key);//
	encryption(s, key);//加密字符串
	cout << "encryption：" << s << endl;
	decode(s, key);//解密字符串
	cout << "decode：" << s << endl;
	return 0;

}