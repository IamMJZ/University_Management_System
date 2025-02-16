#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<string>
#include<stdlib.h> 

using namespace std;

bool RegisterProffessor(string *ID);
void isBlocked(string user_id);
string checkIDForProfessor(string ID);
bool isAlreadyRegisterationProfessor(string ID);

    // Professor Class
class Professor{
private: 
		string id;
		string name; 
		string surname;
		string phoneNumber;
		string subject;
		string identity;
		int grade;
		string studentID;
public: 
		void showInformationAboutTeacher(string ID){
			takeInfoFromFile(ID);
			cout << "ID: " << ID << endl;
			cout << "Name: " << name << " " << surname<< endl;
			cout << "Telephone Number: " << phoneNumber << endl;
			cout << "Subject: " << subject << endl;
			cout << "Identity: " << identity << endl;
		}

        void takeInfoFromFile(string ID){
            ifstream InfoFile("ProfessorInformations.txt");
			string checker1;
			while (InfoFile >> checker1) 
			{
				if (checker1 == ID) 
				{
					InfoFile >> name;
					InfoFile >> surname;
					InfoFile >> phoneNumber;
					InfoFile >> subject;
					InfoFile >> identity;
					break;
				}
			}
			InfoFile.close();
        }


		void EditInfoAboutProfessor(string *ID){

			string line;
			ifstream infile;
			ofstream outfile;
			infile.open("ProfessorInformations.txt");
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

			rename("temp.txt", "ProfessorInformations.txt");
			remove("temp.txt");

			RegisterProffessor(&(*ID));
		}
		void giveMarks(string ID)
		{
            takeInfoFromFile(ID);

			cout << "Enter student ID:" << endl;
			cin >> studentID;
			cout << "Enter grade:" << endl;
			cin >> grade;
			if(subject == "Calculus")
			{

			string line;
			ifstream infile;
			ofstream outfile;
			infile.open("Calculus.txt");
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
			outfile << grade << endl;
			outfile.close();

			rename("temp.txt", "Calculus.txt");
			remove("temp.txt");
			}else if(subject == "Physics")
			{
			string line;
			ifstream infile;
			ofstream outfile;
			infile.open("Physics.txt");
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
			outfile << grade << endl;
			outfile.close();

			rename("temp.txt", "Physics.txt");
			remove("temp.txt");
			}else if(subject == "OOP")
			{
			string line;
			ifstream infile;
			ofstream outfile;
			infile.open("OOP.txt");
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
			outfile << grade << endl;
			outfile.close();

			rename("temp.txt", "OOP.txt");
			remove("temp.txt");
			}
		}
	};


   /// Function for registering Professor
	bool RegisterProffessor(string *ID){
		    string name;
			string surname;
			string phoneNum;
			string fullPhoneNum;
			string Subject;
			string identity;
			string userID;
		labelY:
			cout << "Enter new informations ..." << endl;

            string x = "x";
            while(x == "x"){
			    cout << "\n\nID: ";    cin >> userID;
                x = checkIDForProfessor(userID);
            }
			userID = x;

			isBlocked(userID);
			
			if(isAlreadyRegisterationProfessor(userID)){
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
			    cout << "Phone Number: +998 ";    cin >> phoneNum;
                fullPhoneNum = "+998" + phoneNum;
                x = checkPhone(fullPhoneNum);
            }

			cout << "School: ";  
			cout << "\n1.Calculus\t2.OOP\t3.Physics" << endl;
			int optionx;
			while(true){
				cin >> optionx;
			if(optionx == 1){
				Subject = "Calculus";
				break;
			}else if(optionx == 2){
				Subject = "OOP";
				break;
			}else if(optionx == 3){
				Subject = "Physics";
				break;
			}else{
				cout << "Try again!" << endl;
			}}
			cout << "Identity: ";
			cout << "\n1.Professor\n2.Teacher Assistant" << endl;
			int optiony;
			while(true){
				cin >> optiony;
			if(optiony == 1){
				identity = "Professor";
				break;
			}else if(optiony == 2){
				identity = "TeacherAssistant";
				break;
			}else{
				cout << "Try again!" << endl;
			}}
			ofstream outFile("ProfessorInformations.txt", ios::app);
					outFile << userID << endl;
					outFile << name << endl;
					outFile << surname << endl;
					outFile << fullPhoneNum << endl;
					outFile << Subject << endl;
					outFile << identity << endl;
			outFile.close();
			return false;
	}

void isBlocked(string user_id){
	ifstream InfoFile("BlockedUsers.txt");
			string checker1;
			while (InfoFile >> checker1) 
			{
				if (checker1 == user_id) 
				{
					cout << "You are a blocked user !!!" << endl;
                    exit(0);
				}
			}
			InfoFile.close();	
}


        string checkIDForProfessor(string ID){
            if(ID[0] == 'u' || ID[0] == 'U'){
                ID[0] = 'U';
            }else{
                cout << "Leading letter must be only 'U' or u.\nPlease, try again !!!" << endl;
                return "x";
            }
            for(int i = 1; i < 4; i++){
                if(!(ID[i]=='0'||ID[i]=='1'||ID[i]=='2'||ID[i]=='3'||ID[i]=='4'||ID[i]=='5'||ID[i]=='6'||ID[i]=='7'||ID[i]=='8'||ID[i]=='9')){
                    cout << "After U or u, there must be only numbers" << endl;
                     return "x";
                }
            }
            if(ID.length() != 4){
                cout << "There should be 4 letters for Professor !\nPlease, Try again !" << endl;
                 return "x";
            }
            return ID;
        }


			bool isAlreadyRegisterationProfessor(string ID){
			string line;
			ifstream infile;
			infile.open("ProfessorInformations.txt");

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