#include<iostream>
using namespace std;

class Employee
{
private:
	float basic;
	int id;
public:
	Employee(int =0, float =0);
	void display();
	virtual float calculateSalary();
	float getbasic();
	int getid();
	void setvalues(int i, float b)
	{
		basic = b; id = i;
	}
};
Employee::Employee(int b, float i)
{
	basic = i;
	id = b;
}
void Employee::display()
{
	cout << "Basic salary:" << basic << endl;
	cout << "display id: " << id << endl;
}
float Employee::calculateSalary()
{
	return basic;
}
float Employee::getbasic()
{
	return basic;
}
int Employee::getid()
{
	return id;
}
class CommissionedEmployee :public Employee
{
private:
	int sa;
	int rate;
public:
	CommissionedEmployee(int = 0, float = 0, int = 0, int = 0);
	void display();
	float calculateSalary();
};
CommissionedEmployee::CommissionedEmployee(int b,float i,int s,int r)
{
	setvalues(b, i);
	sa = s;
	rate = r;
}
void CommissionedEmployee::display()
{
	cout << "Basic salary:" << getbasic() << endl;
	cout << "display id: " << getid() << endl;
	cout << "sales amount:" << sa << endl;
	cout << "rate:" << rate << endl;
}
float CommissionedEmployee::calculateSalary()
{
	display();
	float s = sa * rate / 100;
	return (s + getbasic());
}
class HourlyEmployee :public Employee
{
private:
	int eh;
	int ph;
public:
	HourlyEmployee(int = 0, float = 0, int = 0, int = 0);
	void display();
	float calculateSalary();
};
HourlyEmployee::HourlyEmployee(int b, float i, int e, int p)
{
	setvalues(b, i);
	eh = e;
	ph = p;
}

void HourlyEmployee::display()
{
	cout << "Basic salary:" << getbasic() << endl;
	cout << "display id: " << getid() << endl;
	cout << " Extra hour: " << eh << endl;
	cout << " pay per hour: " << ph << endl;
}
float HourlyEmployee::calculateSalary()
{
	display();
	return (getbasic() + eh * ph);
}
class RegularEmployee :public Employee
{
private:
	int bonus;
public:
	RegularEmployee(int = 0, float = 0, int = 0);
	void display();
	float calculateSalary();
};
RegularEmployee::RegularEmployee(int b, float i, int bn)
{
	setvalues(b, i);
	bonus = bn;
}
void RegularEmployee::display()
{
	cout << "Basic salary:" << getbasic() << endl;
	cout << "display id: " << getid() << endl;
	cout << " bonus; " << bonus << endl;
}
float RegularEmployee::calculateSalary()
{
	display();
	return (getbasic() + bonus);
}
int main()
{
	CommissionedEmployee E1(25, 5000, 1000, 10);
	// CASE 1 - derived Class Pointer pointing to Derived class object 
	
	CommissionedEmployee* ptr;
	ptr = &E1;
	cout << " Commissioned Employee salary:" << ptr->calculateSalary();
	cout << endl;
	// CASE 2 - Base Class Pointer pointing to Derived class object 
	Employee* eptr;
	eptr = &E1;
	
	cout << " Commissioned Employee salary:" << eptr->calculateSalary();
	cout << endl;
	
	CommissionedEmployee E2(25, 5000, 1000, 10);
	CommissionedEmployee E3(26, 5000, 2000, 10);
	HourlyEmployee H1(27, 5000, 10, 100);
	HourlyEmployee H2(28, 5000, 5, 100);
	RegularEmployee R1(29, 5000, 1000);
	RegularEmployee R2(29, 5000, 2000);
	
	Employee* list[6];
	list[0] = &E2;
	list[1] = &E3;
	list[2] = &H1;
	list[3] = &H2;
	list[4] = &R1;
	list[5] = &R2;
	
	for (int i = 0; i < 6; i++)
	{
		cout << "Employee " << i << " salary is : " << list[i] -> calculateSalary();
		cout << endl;
		cout << endl;
	}
	return 0;
}