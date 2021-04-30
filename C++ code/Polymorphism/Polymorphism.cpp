#include <iostream>
using namespace std;
/*û��ʹ�ö�̬���麯��*/
/*������Ҫ���Ĺ����ǽ����ֵ�C2707 ����д�ڲ�������*/
//class monster
//{
//protected:
//	int lifevalue;
//	int power;
//public:
//	monster(int _life, int _power) :lifevalue(_life), power(_power) {};
//
//};
//class dragon;
//class wolf : public monster
//{
//public:
//	void attack(dragon* p);
//	void hurted(int npower);
//	void fightaginst(dragon* p);
//	void printInfo();
//	wolf(int _life, int _power) :monster(_life, _power) {};
//
//};
//class dragon : public monster
//{
//public:
//	void attack(wolf* p);
//	void hurted(int npower);
//	void fightaginst(wolf* p);
//	void printInfo();
//	dragon(int _life, int _power) :monster(_life, _power) {};
//};
//void dragon::attack(wolf* p)
//{
//	p->hurted(power);
//	p->fightaginst(this);
//}
//void dragon::hurted(int npower)
//{
//	cout << "dragon is hurted." << endl;
//	lifevalue -= npower;
//}
//void dragon::fightaginst(wolf* p)
//{
//	p->hurted(power / 2);
//}
//void dragon::printInfo()
//{
//	cout << "dragon:" << lifevalue << "    " << power << endl;
//}
//
//void wolf::attack(dragon* p)
//{
//	p->hurted(power);
//	p->fightaginst(this);
//}
//void wolf::hurted(int npower)
//{
//	cout << "wolf is hurted." << endl;
//	lifevalue -= npower;
//}
//void wolf::fightaginst(dragon* p)
//{
//	p->hurted(power / 2);
//	cout << "fightagainst" << endl;
//}
//void wolf::printInfo()
//{
//	cout << "wolf:" << lifevalue << "    " << power << endl;
//}
//
//
//int main()
//{
//	dragon D_dragon1(1000, 100);
//	wolf D_wolf1(500, 70);
//	D_dragon1.printInfo();
//	D_wolf1.printInfo();
//	D_dragon1.attack(&D_wolf1);
//	D_dragon1.printInfo();
//	D_wolf1.printInfo();
//	D_wolf1.attack(&D_dragon1);
//	D_dragon1.printInfo();
//	D_wolf1.printInfo();
//	return 0;
//}

/*ʹ���麯��,�������亯��*/
/*
class monster
{
protected:
	int lifevalue;
	int power;
public:
	virtual void attack(monster* p) {};
	virtual void hurted(int npower) {};
	virtual void fightaginst(monster* p) {};
	virtual void printInfo() {};
	monster(int _life, int _power) :lifevalue(_life), power(_power) {};
	monster(): lifevalue(0), power(0) {};
};
class D_dragon :public monster
{
public:
	virtual void attack(monster* p);
	virtual void hurted(int npower);
	virtual void fightaginst(monster* p);
	virtual void printInfo();
	D_dragon(int _life, int _power) :monster(_life, _power) {};
	D_dragon() {};
};
void D_dragon::attack(monster* p)
{
	p->hurted(power);
	p->fightaginst(this);
}
void D_dragon::hurted(int npower)
{
	cout << "dragon is hurted." << endl;
	lifevalue -= npower;
}
void D_dragon::fightaginst(monster* p)
{
	p->hurted(power / 2);
}
void D_dragon::printInfo()
{
	cout << "dragon:" << lifevalue << "    " << power << endl;
}

class D_wolf :public monster
{
public:
	virtual void attack(monster* p);
	virtual void hurted(int npower);
	virtual void fightaginst(monster* p);
	virtual void printInfo();
	D_wolf(int _life, int _power) :monster(_life, _power) {};
	D_wolf() {};
};
void D_wolf::attack(monster* p)
{
	p->hurted(power);
	p->fightaginst(this);
}
void D_wolf::hurted(int npower)
{
	cout << "wolf is hurted." << endl;
	lifevalue -= npower;
}
void D_wolf::fightaginst(monster* p)
{
	p->hurted(power / 2);
}
void D_wolf::printInfo()
{
	cout << "dragon:" << lifevalue << "    " << power << endl;
}
//int main()
//{
//	D_dragon dragon2(1000, 100);
//	D_wolf wolf2(500, 70);
//	dragon2.printInfo();
//	wolf2.printInfo();
//	dragon2.attack(&wolf2);
//	dragon2.printInfo();
//	wolf2.printInfo();
//	return 0;
//}
*/
/*ʹ�ö�̬����������������*/
class geometry
{
protected:
	double area;
	string  shape;
public:
	virtual double calculate() { return 0; };
	virtual void printInfo() {};
	geometry(int _area, string _shape) :area(_area), shape(_shape) {};
	geometry() {};
};
class Cycle :public geometry //Բ��
{
public:
	double r;
	virtual double calculate();
	virtual void printInfo();
	Cycle(double _area, string _shape,double _r) :geometry(_area, _shape),r(_r) {};
	Cycle() {};
};
double Cycle::calculate()
{
	area = 3.1415926 * r * r;
	return area;
}
void Cycle::printInfo()
{
	calculate();
	cout << "information:" << "shape  " << shape << "  area   " << area << endl;
}
class Rectangle :public geometry //����
{
public:
	double length,width;
public:
	virtual double calculate();
	virtual void printInfo();
	Rectangle(double _area, string _shape, double _length, double _width) :geometry(_area, _shape), length(_length), width(_width){};
	Rectangle() {};
};
double Rectangle::calculate()
{
	area = length * width;
	return area;
}
void Rectangle::printInfo()
{
	calculate();
	cout << "information:" << "shape  " << shape << "  area   " << area << endl;
}
class Triangle :public geometry //������
{
public:
	double a, b, c;
public:
	virtual double calculate();
	virtual void printInfo();
	Triangle(int _area, string _shape, double _a, double _b, double _c) :geometry(_area, _shape), a(_a), b(_b),c(_c) {};
	Triangle() {};
};
double Triangle::calculate()
{
	double p = (a + b + c) / 2.0;
	area = sqrt (p*(p-a) * (p - b) * (p - c));
	return area;
}
void Triangle::printInfo()
{
	calculate();// ����ʱ�Ѿ������ˣ������п��ܲ��ü�����
	cout << "information:" << "shape  " << shape << "  area   " << area << endl;
}

int compare(const void* s1, const void* s2)
{
	geometry** p1 = (geometry**)s1;
	geometry** p2 = (geometry**)s2;
	double a1 = (*p1)->calculate();
	double a2 = (*p2)->calculate();
	if (a1 > a2)
		return 1;
	else if (a1 < a2)
		return -1;
	else
		return 0;
}
geometry* pShapes[100];//���ڱ���ָ�룬����ָ��ָ�����������ָ������������ָ�롣
int main()
{
	int n;
	cin >> n;
	Cycle* pc;
	Rectangle* pr;
	Triangle* pt;
	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		switch(c)
		{
		case 'C':
			pc=new Cycle();
			cin >> pc->r;
			pShapes[i] = pc;
			//delete pc;
			break;
		case 'R':
			pr=new Rectangle;
			cin >> pr->length >> pr->width;
			pShapes[i] = pr;//��ָ�����������
		/*	delete pr;*/ // ע������ɾ���˾��ǰѶ�Ӧλ�õ����ݶ�ɾ���ˣ�geometry* pShapes[100];ֻ�Ƕ��������ָ�룬��ʾָ��ָ���ָ��
			break;
		case 'T':
			pt=new Triangle;
			cin >> pt->a >> pt->b >> pt->c;
			pShapes[i] = pt;
		/*	delete pt;*/
			break;
		}
	}
	qsort(pShapes, n, sizeof(geometry*), compare);
	for (int i = 0; i < n; ++i)
	{
		pShapes[i]->printInfo();
		delete pShapes[i];
	}
	/*delete[]pShapes;*/
	return 0;
}