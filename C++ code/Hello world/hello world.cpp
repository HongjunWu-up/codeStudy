/*
	���ܽ��ܳ���
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
		s[i]  ^= key[i % keySize]; //�ظ�ʹ��key���м��ܡ�
	}
}

void decode(string& s, string & key) //�ͼ����ļ�һ��
{
	int len = s.size();
	int keySize = key.size();
	for (int i = 0; i < len; i++)
	{
		s[i] ^= key[i % keySize]; //�ظ�ʹ��key���н��ܡ�
	}
}
int main()
{
	string s = "hahahahaaaaaa";
	string key = "11234441";
	getline(cin, s);//�����ַ���
	getline(cin, key);//
	encryption(s, key);//�����ַ���
	cout << "encryption��" << s << endl;
	decode(s, key);//�����ַ���
	cout << "decode��" << s << endl;
	return 0;

}