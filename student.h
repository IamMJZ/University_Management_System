#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<string>
#include<stdlib.h> 
#include "person.h"
using namespace std;

void isBlocked(string user_id);
bool RegisterStudent(string *ID);
string checkIDForStudent(string ID);
string checkPhone(string ph);
bool isAlreadyRegisterationStudent(string ID);
// Student Class
class Student: public Person
{
private:
	
	//int grade;

public:

		void viewCalculusGrade(string ID){
			ifstream calculusFile1("Calculus.txt");
			double calculus;
			string checker1;
			bool x = 0;
			while (calculusFile1 >> checker1) 
			{
				if (checker1 == ID) 
				{
					calculusFile1 >> calculus;
					x = 1;
					break;
				}
			}
			calculusFile1.close();
			if (x == 0)
			{
				ofstream calculusFile2("Calculus.txt", ios::app);
				string check1;
				calculusFile2 << ID << endl;
				calculus = 0;
				calculusFile2 << calculus << endl;
				calculusFile2.close();
			}
			cout << "Your grade from Calculus: " << calculus << endl;	
		}

		void viewOOPGrade(string ID){
			ifstream OOPFile1("OOP.txt");
			double OOP;
			string checker3;
			bool x = 0;
			while (OOPFile1 >> checker3) 
			{
				if (checker3 == ID) 
				{
					OOPFile1 >> OOP;
					x = 1;
					break;
				}
			}
			OOPFile1.close();
			if (x==0)
			{
				ofstream OOPFile2("OOP.txt", ios::app);
				string check3;
				OOPFile2 << ID << endl;
				OOP = 0;
				OOPFile2 << OOP << endl;
				OOPFile2.close();
			}
			cout << "Grade of OOP: " << OOP << endl;
		}

		void viewGradeFromPhyscis(string ID){
				ifstream physicsFile1("Physics.txt");
			double physics;
			string checker2;
			bool x = 0;
			while (physicsFile1 >> checker2) 
			{
				if (checker2 == ID) 
				{
					physicsFile1 >> physics;
					x = 1;
					break;
				}
			}
			physicsFile1.close();
			if (x==0)
			{
				ofstream physicsFile2("Physics.txt", ios::app);
				string check2;
				physicsFile2 << ID << endl;
				physics = 0;
				physicsFile2 << physics << endl;
				physicsFile2.close();
			}
			cout << "Grade of Physics: " << physics << endl;
		}

		void showInformationAboutStudent(string ID){
			ifstream InfoFile("StudentInformations.txt");
			string name;
			string surname;
			string phoneNum;
			string school;
			string identity;
			string checker1;
			while (InfoFile >> checker1) 
			{
				if (checker1 == ID) 
				{
					InfoFile >> name;
					InfoFile >> surname;
					InfoFile >> phoneNum;
					InfoFile >> school;
					InfoFile >> identity;
					break;
				}
			}
			InfoFile.close();
			cout << "ID: " << ID << endl;
			cout << "Name: " << name << " " << surname<< endl;
			cout << "Telephone Number: " << phoneNum << endl;
			cout << "School: " << school << endl;
			cout << "Identity: " << identity << endl;
		}

		void EditInfoAboutUser(string *ID){

			string line;
			ifstream infile;
			ofstream outfile;
			infile.open("StudentInformations.txt");
			outfile.open("temp.txt");
			
			while(infile)
			{
			getline(infile,line);
			if(line == *ID){
				for(int i = 1; i <= 5; i++){
				getline(infile,line);
				}
			}else{
				outfile << line << endl;
			}
			}

			infile.close();
			outfile.close();

			rename("temp.txt", "StudentInformations.txt");
			remove("temp.txt");

			RegisterStudent(&(*ID));
		}

         void getPaymentStatus(string ID){
			ifstream PaymentFile1("PaymentStatus.txt");
			string status;
			string checker1;
			bool x = 0;
			while (PaymentFile1 >> checker1) 
			{
				if (checker1 == ID) 
				{
					PaymentFile1 >> status;
					x = 1;
					break;
				}
			}
			PaymentFile1.close();
			if (x == 0)
			{
				ofstream PaymentFile2("PaymentStatus.txt", ios::app);
				string check1;
				PaymentFile2 << ID << endl;
				status = "Unpaid";
				PaymentFile2 << status << endl;
				PaymentFile2.close();
			}
			cout << "\nYour Status: " << status << endl;	
		}

        void payTuitationFee(string ID){
            cout << "The Tuitaion fee for the semester is 1500$" << endl;
            while(true){
            cout << "Please enter your 16 digit card number? " << endl;
                string num;
                int sum = 0;
                cin>>num;
                for(int i = 0; i < 16; i++)
                {
                sum += (num[i] - 48);
                }
                sum %= 10;
                if((sum == 0 && num.size() == 16) || (sum == 1 && num.size() == 16)){
                    cout << "Payment has been done !!!" << endl;
                    ChangePaymentStatus(ID);
                    break;
                }else{
                    cout << "Wrong card number. Please, try again !!!" << endl;
                }
            }            
        }
        	void ChangePaymentStatus(string studentID){

                string line;
                ifstream infile;
                ofstream outfile;
                infile.open("PaymentStatus.txt");
                outfile.open("temp.txt", ios::app);

                while(infile)
                {
                getline(infile,line);
                if(line == studentID){
                    for(int i = 1; i <= 1; i++){
                    getline(infile,line);
                    }
                }else{
                    outfile << line << endl;
                }
                }
                infile.close();

                outfile << studentID << endl;
                outfile << "Paid" << endl;
                outfile.close();

                rename("temp.txt", "PaymentStatus.txt");
                remove("temp.txt");
            }
           
};


// Function for registering
    bool RegisterStudent(string *ID){
		string name;
			string surname;
			string phoneNum;
			string fullPhoneNum;
			string school;
			string identity;
			string userID;
		labelY:
			cout << "Enter new informations ..." << endl;

              string x = "x";
            while(x == "x"){
			    cout << "ID: ";    cin >> userID;
                x = checkIDForStudent(userID);
            }

			userID = x;

			isBlocked(userID);

			if(isAlreadyRegisterationStudent(userID)){
				cout << "1. Try again\n2. Log In" << endl;
				int f;
				cin >> f;
				if(f == 1){
					goto labelY;
				}else{
					return true;
				}
			}


            

			*ID = userID;
			cout << "Name: ";   cin >> name;
			cout << "Surname: "; cin >> surname;

            x = "x";
            while(x == "x"){
			    cout << "\n\nPhone Number: +998 ";    cin >> phoneNum;
                fullPhoneNum = "+998" + phoneNum;
                x = checkPhone(fullPhoneNum);
            }

			cout << "School: ";  
			cout << "\n1. SOCIE\t2.Logistics\t3.Business" << endl;
			int optionx;
			while(true){
				cin >> optionx;
			if(optionx == 1){
				school = "SOCIE";
				break;
			}else if(optionx == 2){
				school = "Logistics";
				break;
			}else if(optionx == 3){
				school = "Business";
				break;
			}else{
				cout << "Try again!" << endl;
			}}
			cout << "Identity: ";
			cout << "\n1.Freshman\n2.Sophomore\n3.Junior\n4.Senior" << endl;
			int optiony;
			while(true){
				cin >> optiony;
			if(optiony == 1){
				identity = "Freshman";
				break;
			}else if(optiony == 2){
				identity = "Sophomore";
				break;
			}else if(optiony == 3){
				identity = "Junior";
				break;
			}else if(optiony == 4){
				identity = "Senior";
				break;
			}else{
				cout << "Try again!" << endl;
			}}
			ofstream outFile("StudentInformations.txt", ios::app);
					outFile << userID << endl;
					outFile << name << endl;
					outFile << surname << endl;
					outFile << fullPhoneNum << endl;
					outFile << school << endl;
					outFile << identity << endl;
			outFile.close();
			return false;
	}


   string checkIDForStudent(string ID){
            if(ID[0] == 'u' || ID[0] == 'U'){
                ID[0] = 'U';
            }else{
                cout << "Leading letter mus be only 'U' or u.\nPlease, try again !!!" << endl;
                return "x";
            }
            for(int i = 1; i < 8; i++){
                if(!(ID[i]=='0'||ID[i]=='1'||ID[i]=='2'||ID[i]=='3'||ID[i]=='4'||ID[i]=='5'||ID[i]=='6'||ID[i]=='7'||ID[i]=='8'||ID[i]=='9')){
                    cout << "After U or u, there must be only numbers" << endl;
                     return "x";
                }
            }
            if(ID.length() != 8){
                cout << "There should be 8 letters for student !\nPlease, Try again !" << endl;
                 return "x";
            }
            return ID;
        }

           string checkPhone(string ph){
            for(int i = 1; i < 13; i++){
                if(!(ph[i]=='0'||ph[i]=='1'||ph[i]=='2'||ph[i]=='3'||ph[i]=='4'||ph[i]=='5'||ph[i]=='6'||ph[i]=='7'||ph[i]=='8'||ph[i]=='9')){
                    cout << "There must be only numbers" << endl;
                     return "x";
                }
            }
            if(ph.length() != 13){
                cout << "There should be 13 digits in a phone number!\nPlease, Try again !" << endl;
                 return "x";
            }
            return ph;
        }

		bool isAlreadyRegisterationStudent(string ID){
			string line;
			ifstream infile;
			infile.open("StudentInformations.txt");

			while(infile)
			{
			getline(infile,line);
			if(line == ID){
				cout << "You have already registered !!!" << endl;
				return true;
			}
			}
			infile.close();
			return false;
		}