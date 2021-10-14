#include <iostream>
#include <ctime>
using namespace std;
class Student
{
	string name, group;
	int number;
	int* grade;
public:
	void setname(string newname) { name = newname; }
	void setgroup(string newgroup) { group = newgroup; }
	void setnumber(int newnumber) { number = newnumber; }
	void setgrades(int newindex, int newgrade)
	{
		if ((newgrade <= 2) & (newgrade >= 5)) return;  grade[newindex] = newgrade;
	}
	string getname() { return name; }
	string getgroup() { return group; }
	int getnumber() { return number; }
	int* getgrades() { return grade; }
	void getgradeslist()
	{
		for (int i = 0; i < number; i++)
		{
			cout << grade[i] << endl;
		}
	}
	void increasegrades()
	{
		for (int i = 0; i < number; i++)
			if (grade[i] < 5)
				grade[i]++;
	}
	void showinfo()
	{
		cout << "Student " << name << " group " << group << " has " << number << " grades: " << endl;
		getgradeslist();

	}
	Student() : name("Ivanov"), group(" 20PIJB")
	{
		number = 3;
		grade = new int[3];
		grade[0] = 5;
		grade[1] = 5;
		grade[2] = 5;
	}
	Student(string newname, string newgroup, int newnumber) : name(newname), group(newgroup), number(newnumber)
	{
		grade = new int[number];
		for (int i = 0; i < number; i++)
			grade[i] = rand() % 4 + 2;
	}
	Student(const Student& newStudent) : name(newStudent.name), group(newStudent.group), number(newStudent.number)
	{
		grade = new int[newStudent.number];
		for (int i = 0; i < newStudent.number; i++)
			grade[i] = newStudent.grade[i];
	}
	~Student()
	{
		cout << name << " Deleted" << endl;
		delete[] grade;
	}

};
void main()
{
	srand(time(0));
	Student* start = new Student();
	Student Petrov("Petrov Petya ", "20pib ", 5);
	Student PetrovCopy = Petrov;
	PetrovCopy.setname("Petrov Vasya ");
	PetrovCopy.increasegrades();
	start->showinfo();
	start->getgradeslist();
	Petrov.showinfo();
	Petrov.getgradeslist();
	PetrovCopy.showinfo();
	PetrovCopy.getgradeslist();
	delete start;
}