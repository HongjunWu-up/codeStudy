#include <iostream>
using namespace std;
class Student
{
public:
	string name;
	string ID;
	int age;
	string gender;
protected:
	int npro;
public:
	Student(const string &name_, const  string& ID_, const int age_, const string& gender_);
	Student() { cout << "constructor!" << endl; };
	~Student();
	int SetInfo(const string &name_, const  string& ID_, const int age_, const string& gender_);

};

Student::Student(const string &name_, const  string& ID_, const int age_, const string &gender_) :name(name_),ID(ID_),age(age_),gender(gender_)
{
	////name = name_;
	//ID = ID_;
	//age = age_;
	//gender = gender_;
	cout << name << "," << ID << "," << age << "," << gender <<endl;
}

Student::~Student()
{
}
int Student::SetInfo(const string &name_, const  string &ID_, const int age_, const string &gender_)
{
	name = name_;
	ID = ID_;
	age = age_;
	gender = gender_;
	cout << name << "," << ID << "," << age << "," << gender << endl;
	return 0;
}
class UStudent:public Student
{
private:
	string department;
public:
	int SetInfo(const string& name_, const  string& ID_, const int age_, const string &gender_, const string &department_);
	UStudent() {};
	UStudent(const string& name_, const  string& ID_, const int age_, const string& gender_, const string &department_);
	~UStudent();
};
UStudent::UStudent(const string& name_, const  string& ID_, const int age_, const string& gender_, const string& department_):Student::Student(name_,ID_,age_,gender_),department(department_)
{
	Student wanger;
	//wanger.npro = 1;  //不能作用在其他的对象上面，只作用在this上面。
	cout << name << "," << ID << "," << age << "," << gender <<","<< department << endl;
}

UStudent::~UStudent()
{
}
int UStudent::SetInfo(const string& name_, const  string& ID_, const int age_, const string& gender_, const string& department_)
{
	Student::SetInfo(name_, ID_, age_, gender_);
	department = department_;
	return 0;
}

/* 复合和继承关系*/
class Master;
class Dog
{
	Master* man;
};
class Master
{
	Dog* dog[10];
	int Dognum;
};
//class Master;
//class Dog
//{
//	Master man; // 错误的，不知道master的对象是什么样的，换成指针的话就只用知道地址，不用知道具体的对象是什么样的。
//};
//class Master
//{
//	Dog dog[10];
//	int Dognum;
//};
/*多重继承*/
class Base {
public:
	Base() { cout << "constructor!" << endl; };
	~Base() { cout << "destory!" << endl; };

};
class Base1 :virtual public Base {};
class Base2 :virtual public Base {};
class Base3 :public Base1, public Base2 {};


int main()
{
	Base3 study;
	cout << "test" << endl;
	Student Stu1("LiHua", "123456", 25, "Male");
	UStudent Stu2("zhangsan", "123456", 25, "Male","CS");
	Stu1 = Stu2;
	Student Stu3 = Stu2;
	Student& r = Stu2;
	Student* pa = &Stu2;
	cout << "finished" << endl;
	return 0;
}