#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<string>
#include<stdlib.h> 

using namespace std;

bool RegisterStaff(string *ID);
string checkIDForStaff(string ID);
bool isAlreadyRegisterationAdmin(string ID);

class Staff
{
	private:
		string id;
		string name; 
		string surname;
		string phoneNumber;
	public:
		void showInformationAboutStaff(string ID){
			ifstream InfoFile("StaffInformations.txt");
			string checker1;
			while (InfoFile >> checker1) 
			{
				if (checker1 == ID) 
				{
					InfoFile >> name;
					InfoFile >> surname;
					InfoFile >> phoneNumber;
					break;
				}
			}
			InfoFile.close();
			cout << "ID: " << ID << endl;
			cout << "Name: " << name << " " << surname<< endl;
			cout << "Telephone Number: " << phoneNumber << endl;
		}
		void EditInfoAboutStaff(string *ID){

			string line;
			ifstream infile;
			ofstream outfile;
			infile.open("StaffInformations.txt");
			outfile.open("temp.txt");

			while(infile)
			{
			getline(infile,line);
			if(line == *ID){
				for(int i = 1; i <= 3; i++){
				getline(infile,line);
				}
			}else{
				outfile << line << endl;
			}
			}
			infile.close();

			rename("temp.txt", "StaffInformations.txt");
			remove("temp.txt");

			RegisterStaff(&(*ID));
		}

        void getPaymentStatus(){
            cout << "To get payment status of student\nEnter student ID: ";
            string ID;
            cin >> ID;
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
			cout << "\nStudent Status: " << status << endl;	
		}

        void blockStudent(){
            cout << "To block student\nEnter user ID: ";
            string usID;
            cin >> usID;
            ofstream PaymentFile2("BlockedUsers.txt", ios::app);
			PaymentFile2 << usID << endl;
			PaymentFile2.close();
            cout << "\n\t\tBlocked !!!" << endl;
        }

        void unBlockStudent(){
            cout << "To unblock student\nEnter user ID: ";
            string usID;
            cin >> usID;

            string line;
			ifstream infile;
			ofstream outfile;
			infile.open("BlockedUsers.txt");
			outfile.open("temp.txt");

			while(infile)
			{
			getline(infile,line);
			if(line == usID){
				getline(infile,line);
			}else{
				outfile << line << endl;
			}
			}
			infile.close();
            outfile.close();

			rename("temp.txt", "BlockedUsers.txt");
			remove("temp.txt");
        }

        void seeAllBlockedStudents(){
            ifstream infile;
            string line;
            infile.open("BlockedUsers.txt");
            cout << "\n\t\tBlocked Users:" << endl;
            while(infile){
                getline(infile,line);
                cout << line << endl;
            }
            infile.close();
        }

        void whoRegistered(){
        // Function for adding records       /// Only test Function
                Person per;
                fstream f;

                f.open("Person.dat", ios::in | ios::out | ios::ate | ios::binary);

                f.seekg(0);

                cout << endl << "Conents of the file are as follows " << endl;

                while (f.read((char *)&per, sizeof(per))){
                    per.getData();
                }
                f.close();

        }
};


bool RegisterStaff(string *ID){
		    string name;
			string surname;
			string phoneNum;
			string fullPhoneNum;
			string identity;
			string userID;
	labelX:
			cout << "Enter your new informations ..." << endl;

            string x = "x";
            while(x == "x"){
			    cout << "\n\nID: ";    cin >> userID;
                x = checkIDForStaff(userID);
            }
			
			userID = x;

			if(isAlreadyRegisterationAdmin(userID)){
				cout << "1. Try again\n2. Log In" << endl;
				int f;
				cin >> f;
				if(f == 1){
					goto labelX;
				}else{
					return true;
				}
			}

			*ID = userID;
			cout << "Name: ";   cin >> name;
			cout << "Surname: "; cin >> surname;
			
			 x = "x";
            while(x == "x"){
			    cout << "Phone Number: +998 ";    cin >> phoneNum;
                fullPhoneNum = "+998" + phoneNum;
                x = checkPhone(fullPhoneNum);
            }

			ofstream outFile("StaffInformations.txt", ios::app);
					outFile << userID << endl;
					outFile << name << endl;
					outFile << surname << endl;
					outFile << fullPhoneNum << endl;
			outFile.close();
			return false;
	}


   string checkIDForStaff(string ID){
            if(ID[0] == 'u' || ID[0] == 'U'){
                ID[0] = 'U';
            }else{
                cout << "Leading letter mus be only 'U' or u.\nPlease, try again !!!" << endl;
                return "x";
            }
            for(int i = 1; i < 3; i++){
                if(!(ID[i]=='0'||ID[i]=='1'||ID[i]=='2'||ID[i]=='3'||ID[i]=='4'||ID[i]=='5'||ID[i]=='6'||ID[i]=='7'||ID[i]=='8'||ID[i]=='9')){
                    cout << "After U or u, there must be only numbers" << endl;
                     return "x";
                }
            }
            if(ID.length() != 3){
                cout << "There should be 3 letters for administrator !\nPlease, Try again !" << endl;
                 return "x";
            }
            return ID;
        }


			bool isAlreadyRegisterationAdmin(string ID){
			string line;
			ifstream infile;
			infile.open("StaffInformations.txt");

			while(infile)
			{
			getline(infile,line);
			if(line == ID){
				cout << "\nThis account have already been registered !!!" << endl;
				cout << "\nPlease, Enter another id or go to Log In page ..." << endl;
				return true;
			}
			}
			infile.close();
			return false;
		}