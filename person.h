#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<string>
#include<stdlib.h> 

using namespace std;

// Person Class
class Person
{  	
protected:
	string password;
	string id;
public:
	void setID(string id){
		this->id = id;
	}

	void setPassword(string password){
		this->password = password;
	}

	void setdata()
	{
		cout << endl << "Enter Id :"; 
		cin >> id;
		cout << endl << "Enter Password :"; 
		cin >> password;
	}
	void getData()
	{
		cout << endl << "ID: " << id << endl << "Password: " << password << endl;
	}
	string getPassword()
	{
		return password;
	}
	string getID()
	{
		return id;
	}
};

