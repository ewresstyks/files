#include <fstream>
#include <iostream>
using namespace std;

class Student
{
	string name;
	string surname;
	int age;
public:
	Student() = default;
	Student(const char* n, const char* sur, int a)
	{
		name = n;
		surname = sur;
		age = a;
	}
	void Print()
	{
		cout << "Name -- " << name << endl << "Surname -- "
		<< surname << endl << "Age -- " << age;
	}
	void SaveFile()
	{
		ofstream write("StudentFile.txt");
		write << "Name -- " << name << endl << "Surname -- " 
		<< surname << endl << "Age -- " << age;
	}
	void ReadFile()
	{
		ifstream read("StudentFile.txt");
		if (read) {
			const int size = 300;
			do {
				char buffer[size] = {};
				read.getline(buffer, size);
				cout << buffer << endl;
			}
		while (read);
			read.close();
		}
		else {
			cout << "Could not open the file --" << endl;
		}
	}

};

int main() {
	Student Margoshka("Margo", "Boiko", 16);
	Margoshka.Print();
	Margoshka.ReadFile();
}