#include <iostream>
#include <string>
using namespace std;

class car
{
private:
	string man;
	int model;
	double power;
	int tyres;
public:
	car(string = "Null", int = 0, double = 0, int = 0);
	void setvalues(string, int, double, int);
	string getMan();
	int getM();
	double getP();
	int getT();
	void print();
};
car::car(string n, int m, double p, int t)
{
	man = n; model = m; power = p; tyres = t;
}
void car::setvalues(string n, int m, double p, int t)
{
	man = n; model = m; power = p; tyres = t;
}
string car::getMan()
{
	return man;
}
int car::getM()
{
	return model;
}
double car::getP()
{
	return power;
}
int car::getT()
{
	return tyres;
}
void car::print()
{
	cout << " Manufacturer: " << man << endl;
	cout << " Model: " << model << endl;
	cout << " Engine Power: " << power << endl;
	cout << " Number of tyres: " << tyres << endl;
}

class showroom :public car
{
private:
	string name;
	int num;
public:
	showroom(string = "Null", int = 0, string = "Null", int = 0, double = 0, int = 0);
	void setValues(string, int, string, int, double, int);
	void Print();
};
showroom::showroom(string n, int nc, string n1, int m, double p, int t)
{
	name = n; num = nc;
	setvalues(n1, m, p, t);
}
void showroom::setValues(string n, int nc, string n1, int m, double p, int t)
{
	name = n; num = nc;
	setvalues(n1, m, p, t);
}
void showroom::Print()
{
	cout << " Showroom name: " << name << endl;
	cout << " Number of cars: " << num << endl;
	print();
}
int main()
{
	showroom s;

	string sn, mn;
	int nc, t, m;
	double ep;

	cout << " Enter showroom name: ";
	
	getline(cin, sn);
	cout << " Enter number of cars: ";
	cin >> nc;
	cout << " Enter manufacturer of cars: ";
	cin.ignore();
	getline(cin, mn);
	cout << " Enter number of tyres: ";
	cin >> t;
	cout << " Enter model number: ";
	cin >> m;
	cout << " ENter engine power: ";
	cin >> ep;

	s.setValues(sn, nc, mn, m, ep, t);

	cout << " \n\n\n";
	s.Print();

	return 0;
}