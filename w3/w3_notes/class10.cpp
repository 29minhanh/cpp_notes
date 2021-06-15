#include<iostream>
using namespace std;

class Student {
public:
	Student();
	~Student();
	void getData(int,int,int);
	void printData();
	void add(Student, Student); //method to add two students together

private:
	int test[3];
};
 
Student::Student()
{	test[0] = test[1] = test[2] = 1; }

Student::~Student() // destructor - called when object is destroyed
{
	cout << "a student has been destructed" << endl;
	cout << "first test score for the student is " << test[0] << endl;
	cout << "second test score for the student is " << test[1] << endl;
	cout << "third test score for the student is " << test[2] << endl << endl;
}

void Student::getData(int a, int b, int c)
{
	test[0] = a;
	test[1] = b;
	test[2] = c;
}

void Student::printData()
{
	cout << "first test score for the student is " << test[0] << endl;
	cout << "second test score for the student is " << test[1] << endl;
	cout << "third test score for the student is " << test[2] << endl << endl;
}

void Student::add(Student a, Student b)
{
	for (int i = 0; i < 3; i++)
	{
		test [i] = a.test[i] + b.test[i];
	}

/*
	test[0] = a.test[0] + b.test[0];
	test[1] = a.test[1] + b.test[1];
	test[2] = a.test[2] + b.test[2];
*/
}

int main()
{
	Student one, two, three;

	cout << "student one data is" << endl;
	one.printData();
	two.getData(10, 20, 30);

	cout << "student two data is" << endl;
	two.printData();
	cout <<endl<< endl;

	three.add(one,two);

	cout << "THE NEW STUDENT DATA IS" << endl;
	three.printData();
	return 0;
}

/*
student one data is
first test score for the student is 1
second test score for the student is 1
third test score for the student is 1

student two data is
first test score for the student is 10
second test score for the student is 20
third test score for the student is 30



a student has been destructed
first test score for the student is 1
second test score for the student is 1	 **Note that the destructors are done here
third test score for the student is 1    **Because the local parameters are objects    
										 **and are destroyed at the end of the add method 
a student has been destructed
first test score for the student is 10
second test score for the student is 20
third test score for the student is 30

THE NEW STUDENT DATA IS
first test score for the student is 11
second test score for the student is 21
third test score for the student is 31

a student has been destructed
first test score for the student is 11
second test score for the student is 21
third test score for the student is 31

a student has been destructed
first test score for the student is 10
second test score for the student is 20
third test score for the student is 30

a student has been destructed
first test score for the student is 1
second test score for the student is 1
third test score for the student is 1

Press any key to continue 
*/