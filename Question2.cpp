#include <iostream>
#include <fstream>
using namespace std;

class student{
	int roll;
	char name[30];
    int clas;
	double marks;
public:
   void inputdata();
   void displaydata();
  
};
void student::inputdata(){
	cout<<"Enter name:";
	cin.getline(name,30);
    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter total marks outof 500: ";
    cin >> marks;
	cout<< "Enter Class: ";
	cin>> clas;
}
void student::displaydata(){
	cout << "\nRoll No. :: " << roll << endl;
    cout << "\nName :: " << name << endl;
    cout << "\nMarks :: " << marks << endl;
	cout << "\nClass:: "<< clas<< endl;
}

int main()
{
   student s[5];
   fstream file;
   int i;

   file.open("Student Data.txt", ios :: out);
    cout << "\nWriting Student information to the file :- " << endl;
    cout << "\nEnter 5 students Details to the File :- " << endl;

   for (int i = 0; i < 5; i++)
    {
      s[i].inputdata();
      file.write((char *)&s[i], sizeof(s[i]));
    }

   file.close();

   file.open("Student Data.txt", ios :: in);
   cout << "\nReading Student information to the file :- " << endl;

   for (i = 0; i < 3; i++)
    {
      
      file.read((char *)&s[i], sizeof(s[i]));
      s[i].displaydata();
    }

   file.close();

   return 0;
}
