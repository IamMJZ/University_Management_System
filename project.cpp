// University management system project

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<string>
#include "student.h"
#include "professor.h"
#include "admin.h"

#include<stdlib.h> 
using namespace std;

void aboutUniversity();
void printIUT();

//////////////////// Functions ////////////////////////////////////

/// checking password and id when logging in
bool loggedinSuccesfully(string* userID){
        Person per;
	    ifstream file;
	    file.open("Person.dat", ios::in | ios::binary);

		cout << "\nEnter ID: "; 
		string id;
		cin >> id;

		isBlocked(id);

		*userID = id;
        cout << "Enter password: "; 
        string password;
        cin >> password;

            file.seekg(0);

		while (file.read((char *)&per, sizeof(per)))
		{
			if (per.getID() == id && per.getPassword() == password)
			{
                file.close();
				return true;
			}
		}
        file.close();
        return false;
}



// funciton for showing Register or Log in to enter the system
	string EnteringSystem(){
	string userID; 
	label1:
    cout << "\n1. Register" << endl;
    cout << "2. Log in" << endl;
	cout << "0. Exit" << endl;
    char choice2; 
    cin >> choice2;

	while(1){
    if(choice2 == '1'){
		while(true){
		string id;
		cout << "\n1. Student" << endl;
		cout << "2. Professor" << endl;
		cout << "3. Administrator" << endl;
		cout << "Choose one ..." << endl;
		int choicex;
		cin >> choicex;

	cout << "\nPlease, note that student has 8 symbols in ID, professor has 4 symbols in ID and staff has 3 symbols in ID\n" << endl;
		if(choicex == 1){
		if(RegisterStudent(&id) == true){
				goto label1;
			}
		}else if(choicex == 2){
		if(RegisterProffessor(&id) == true){
				goto label1;
			}
		}else{
			if(RegisterStaff(&id) == true){
				goto label1;
			}
		}
			cout << "\nPlease, Enter you new password: ";
			string password; 
			cin >> password;

			Person per;
			fstream f;
			per.setID(id);
			per.setPassword(password);
			per.getData();
			f.open("Person.dat", ios::in | ios::out | ios::ate | ios::binary);
			f.write((char *)&per, sizeof(per));
			f.close();
			cout << "You registered succesfully!!!" << endl;
			goto label1;
			break; 

		}
    }else if (choice2 == '2'){
        while(true){
        if(loggedinSuccesfully(&userID)){
            cout << "You logged in succesrfully !!!" << endl;
            break;
        }else{
            cout << "\n\nWrong ID or Password. Please, try again !!!\n" << endl;
        }
        }
		break;
    }else if(choice2 == '0'){
		exit(0);
	}
	}
	return userID;
	}

 // Function for showing main menu
	string mainMenu(){
		string userID;
	int control, control2;
	label2:
	cout << "\n\n1. Enter the University system" << endl;
	cout << "2. Information about the university" << endl;
	cout << "0. Quit program" << endl;
	cin >> control;
	switch(control)
	{
		case 1:
		{ 
   			userID = EnteringSystem();	
			   break;
		}
		case 2:
		{	
			aboutUniversity();
			cout << "\n0. Back" << endl;
			cin >> control2;
			if(control2 == 0)
			{
				goto label2;
			}
			break;
		}	
	}
	return userID;
	}



////////////////////////// main function ////////////////////////////////
int main()
{
	printIUT();

	mainLabel:
	string userID = mainMenu();
   

	// Here Student 
	if(userID.length() == 8) {
	label1: 
		Student inhaStudent;
		cout << "\n\n\t\t\tMenu " << endl;
		cout << "\n1. Show informations" << endl; 
		cout << "2. See grade from Calculus" << endl; 
		cout << "3. See grade from OOP" << endl; 
		cout << "4. See grade from Physics" << endl;
		cout << "5. See your payment status for the semester" << endl;
		cout << "6. Pay the tuition fee" << endl;
		cout << "0. Log out" << endl;
		int option = 1; 
        int option1;
		while(1){
		cin >> option;
		switch(option){
			case 1: {
				inhaStudent.showInformationAboutStudent(userID);
				cout << "\n0. Back " << endl;
				cin >> option1;
				if(option1 == 0){
					goto label1;
				}
				break;
			}
			case 2:{
				inhaStudent.viewCalculusGrade(userID);
				cout << "\n0. Back " << endl;
				cin >> option1;
				if(option1 == 0){
					goto label1;
				}
				break;
			}case 3:{
				inhaStudent.viewOOPGrade(userID);
				cout << "\n0. Back " << endl;
				cin >> option1;
				if(option1 == 0){
					goto label1;
				}
				break;
			}case 4:{
				inhaStudent.viewGradeFromPhyscis(userID);
				cout << "\n0. Back " << endl;
				cin >> option1;
				if(option1 == 0){
					goto label1;
				}
				break;
		    }case 5:{
				inhaStudent.getPaymentStatus(userID);
				cout << "\n0. Back " << endl;
				cin >> option1;
				if(option1 == 0){
					goto label1;
				}
				break;
			}case 6:{

				ifstream PaymentFile1("PaymentStatus.txt");
				string status;
				string checker1;
				while (PaymentFile1 >> checker1) 
				{
					if (checker1 == userID) 
					{
						PaymentFile1 >> status;
						break;
					}
				}
				if(status == "Paid"){
					cout << "You have already paid tuitation fee !!!" << endl;
				}else{
				inhaStudent.payTuitationFee(userID);
				}
				cout << "\n0. Back " << endl;
				cin >> option1;
				if(option1 == 0){
					goto label1;
				}
				break;
			}case 0:{
				goto mainLabel;
			}

		}}}

	// Here Professor
	else if (userID.length() == 4) {
		// Professor
		Professor prof; 
		label2: 
		cout << "\n1. Show informations" << endl; 
		cout << "2. Change grade" << endl; 
		cout << "0. Log out" << endl;
		int option = 1; 
        int option1;
		while(1){
		cin >> option;
		switch(option){
			case 1: {
				prof.showInformationAboutTeacher(userID);
				cout << "\n0. Back " << endl;
				cin >> option1;
				if(option1 == 0){
					goto label2;
				}
				break;
			}case 2:{
				prof.giveMarks(userID);
				cout << "\n0. Back " << endl;
				cin >> option1;
				if(option1 == 0){
					goto label2;
				}
				break;
			}case 0: {
				goto mainLabel;
			}
			
		}
		}
	}

	/// Here Staff
	else if (userID.length() == 3)
	{
		Staff staff;
		label3:
		cout << "1. Show information" << endl;
		cout << "2. Change Student information" << endl;
		cout << "3. Change Teacher Information" << endl;
		cout << "4. Change your information" << endl;
		cout << "5. See the Payment Status" << endl;
		cout << "6. Block the user" << endl;
		cout << "7. Unblock the user" << endl;
		cout << "8. See all blocked users" << endl;
		cout << "9. Registered Users" << endl;
		cout << "0. Log out" << endl;
		int option = 1; 
        int option1;
		while(1)
		{
			cin >> option;
			switch(option)
			{
				case 1: 
					{
						staff.showInformationAboutStaff(userID);
						cout << "\n0. Back " << endl;
						cin >> option1;
						if(option1 == 0)
						{
							goto label3;
						}
						break;
					}
					case 2: 
					{
						Student instudent;
						string studentid;
						cout << "To change informations about student\nEnter student ID: ";
						cin >> studentid;
						instudent.EditInfoAboutUser(&studentid);
						cout << "\n0. Back " << endl;
						cin >> option1;
						if(option1 == 0)
						{
							goto label3;
						}
						break;
					}
					case 3: 
					{
						Professor inhaProf;
						string profID;
						cout << "To change professor informations\nEnter professor ID: ";
						cin >> profID;
						inhaProf.EditInfoAboutProfessor(&profID);
						cout << "\n0. Back " << endl;
						cin >> option1;
						if(option1 == 0)
						{
							goto label3;
						}
						break;
					}
					case 4: 
					{
						staff.EditInfoAboutStaff(&userID);
						cout << "\n0. Back " << endl;
						cin >> option1;
						if(option1 == 0)
						{
							goto label3;
						}
						break;
					}case 5:
					{
						staff.getPaymentStatus();
						cout << "\n0. Back " << endl;
						cin >> option1;
						if(option1 == 0)
						{
							goto label3;
						}
						break;
					}case 6:{
						staff.blockStudent();
						cout << "\n0. Back " << endl;
						cin >> option1;
						if(option1 == 0)
						{
							goto label3;
						}
						break;
					}
					case 7:{
						staff.unBlockStudent();
						cout << "\n0. Back " << endl;
						cin >> option1;
						if(option1 == 0)
						{
							goto label3;
						}
						break;
					}
					case 8:{
						staff.seeAllBlockedStudents();
						cout << "\n0. Back " << endl;
						cin >> option1;
						if(option1 == 0)
						{
							goto label3;
						}
						break;
					}case 9:{
						staff.whoRegistered();
						cout << "\n0. Back " << endl;
						cin >> option1;
						if(option1 == 0)
						{
							goto label3;
						}
						break;
					}case 0: {
						goto mainLabel;
					}
				
			}
		}
	}

	system("pause");
	return 0;
}

	void aboutUniversity(){
		cout << "\n\n\t\t\tInha University In Tashkent\n" << endl;
		cout << "We have three schools, SOCIE, SBL and SOL. Please, note that students who are admitted to the SOCIE" << endl;
		cout << "will be assigned to one of two departments (CSE and ICE) by the regulation of IUT after completing " << endl;
		cout << "the first year of the education program at IUT." << endl;
         cout << "\n\n\t\t\tAdmission criterias\n" << endl;
		 cout << "We have 420 quotas, 300 for SOCIE, 70 for Business Administration and 50 for Logistics." << endl;
		 cout << "Among Pre-University students who take the final examination, 81 students (up to 30% of 270) for SOCIE and 21" << endl;
		 cout << "students for Business Administration and 15 students for Logistics (up to 30% of 120) for SBL can be admitted." << endl;
        cout << "Our University has two blocks, which are A block and B block." << endl;
	}

	void printIUT(){
    cout << endl << endl;
    cout << "     **          **          **      ** ** ** ** ** ** **               " << endl;
    cout << "     **          **          **               **             " << endl;
    cout << "     **          **          **               **          " << endl;
    cout << "     **          **          **               **           " << endl;
    cout << "     **          **          **               **          " << endl;
    cout << "     **          **          **               **           " << endl;
    cout << "     **          **          **               **            " << endl;
    cout << "     **          **          **               **               " << endl;
    cout << "     **          ** ** ** ** **               **                " << endl;

	cout << "\n\n\t\tMANAGEMENT SYSTEM" << endl;
}