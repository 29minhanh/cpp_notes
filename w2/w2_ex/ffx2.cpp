#include <iostream>
#include <fstream>
using namespace std;

int main ()
{

    char name[30];
    double cost, discper, quantity, disc, total, fin;

	ifstream infile("d:\\items.dat", ios::in);
	ofstream outfile("d:\\costs.dat", ios::out);

	while(infile.getline(name,40))
	{
		infile >> cost >> quantity >> discper;
		total = cost * quantity;
		disc = total * discper / 100;
		fin = total - disc;
		outfile << name << endl;
		outfile << total<< ' ' << disc << ' ' << fin <<endl;
		infile.ignore(40, '\n');
	}
	infile.close(); 
	outfile.close();

}