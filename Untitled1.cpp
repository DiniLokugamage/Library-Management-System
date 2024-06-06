#include <iostream> //to output values to the console or get inputs from the user
#include <conio.h>	//getch();
#include <windows.h> //to access system commands like Sleep,system("cls")
#include <string>	//string related functions(substring)
#include <fstream>	//for the file handling to read and write files
#include <sstream>	//allows to separate values in a single line which is seperated by a delimeter.
#include <cctype>	//tolower and toupper (sigle character)
#include <algorithm> //transform function allowes to apply a function for multiple values
#include <ctime>	//time related functions
#include <stdlib.h>  //to convert string values to integers

using namespace std;

//int borrowingLimit = 3;
string availability = "available";
string librarianBookRecord = " ";


//function prototyping
void welcomeConsole();
void mainMenu();
void adminLogIn(); //Admin tasks
void adminMenu();
void libSignUp();
void changeDisplayFine();
float displayFineRate();
void updateFineRate();
void modifyDisplayBorrowingLimit();
void displayBorrowingLimit();
void modifyBorrowingLimit();
void librarianLogIn(); //Librarian tasks
void librarianMenu();
void addDeleteBooks();
void addBooks();
void deleteBooks();
void searchUpdateBooks();
void searchBooks();
void updateBooks();
void issueReturnedBooks();
void issueReturnedBooksMenu(string borrowerID, string bookID, int newBrrCount);
void issueBooks(string borrowerID, string bookID, int newBrrCount);
void acceptReturnedBooks(string borrowerID, string bookID, int newBrrCount);
void addDeleteBorrowers();
void addBorrowers();
void deleteBorrowers();
void searchUpdateBorrowers();
void searchBorrowers();
void updateBorrowers();
void showAllBorrowedDetails();

int main(){
	
	welcomeConsole();
	return 0;
}


void welcomeConsole(){		
		system("Color 0F");
		cout << "\n\n" ;
		cout << "                  **--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**\n";
		cout << "\n\t\t**\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           **";
		cout << "\n\t\t**\t\t@@                                                 @@           **";
		cout << "\n\t\t**\t\t@@                ~WELCOME                         @@           **";
		cout << "\n\t\t**\t\t@@                   TO                            @@           **";
		cout << "\n\t\t**\t\t@@                 LIBRARY                         @@           **";
		cout << "\n\t\t**\t\t@@                LUMINAR!!!                       @@           **";
		cout << "\n\t\t**\t\t@@                                                 @@           **";
		cout << "\n\t\t**\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           **\n\n";
		cout << "                  **--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**\n\n";
		
		Sleep(2000);
		system("cls");
		mainMenu();
}

void mainMenu(){
	
	int option=0;
	do{		
		//Display the user type
		cout << "\n\n\t============================-MAIN MENU-=======================================\n";
		cout << "\t||             -USER TYPE-                                                  ||\n";	
		cout << "\t||                          [1]ADMIN                                        ||\n";	
		cout << "\t||                          [2]LIBRARIAN                                    ||\n";	
		cout << "\t||                          [3]EXIT                                         ||\n";
		cout << "\t||                                                                          ||\n";
		cout << "\t==============================================================================\n\n";
		
		//get user input(main options: Admin,Librarian,Borrower)
		cout << "\t\tChoose an option: " ;
		cin >> option;	
		
		switch(option){
			case 1:{
				system("cls");
				adminLogIn();
				break;
			}
			
			case 2:{ 
				system("cls");
				librarianLogIn();
				break;
			}
			
			case 3:{
				system("cls");
				cout << "\n\n           **--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**\n";
				cout << "\n\t\t\t  THANK YOU FOR USING LIBRARY MANAGEMENT SYSTEM!\n\n";
				cout << "            **--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**\n\n\n";
				exit(0); //system call
			}
			
			default:{
				char opt = '0';
				cout <<"\n\t\t\tINVALID INPUT!! Do you want to try again?(y/n): ";
				cin >> opt;
				
				if(opt=='y'||opt=='Y'){
					system("cls");
					mainMenu();
				}
				
				else{
					system("cls");
					cout << "\n\n            **--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**\n";
					cout << "\n\t\t\t  THANK YOU FOR USING LIBRARY MANAGEMENT SYSTEM!\n\n";
					cout << "            **--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**\n\n\n";
					exit(0); //system call
				}
			
			}
		}
		
	}while(option!=3);
	
}

//validate adminUserName and Password
void adminLogIn(){
	
	string userName;
	string password;
	int loginAttempts = 0;
	
	while(loginAttempts<3){
		string adminUserName = "Luminar";
		string adminPassword = "1111";
				
		char choice = '0';	
			
		cout << "\n\n" ;
		cout << "\t |%%%%%%%%%%%%%%%%%%%%%|-'ADMIN LOGIN'-|%%%%%%%%%%%%%%%%%%%%%%%%|\n\n";	
		cout << "\t\t\t [*]ENTER USERNAME: ";       
		cin >> 	userName;
		cout << "\t\t\t [*]ENTER PASSWORD: " ;	
		cin >> password;
		cout << "\n\t |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|\n\n";

			
		if(userName==adminUserName && password==adminPassword){
			//intialize the string
			string S = "\t\t\tADMIN LOGIN SUCCESSFULLY!!\n";
			
			//Travers the given string S
			for(int i = 0; i < S[i]; i++){
				cout << S[i];
				Sleep(100);
			}
			
			Sleep(2000);
			system("cls");
			adminMenu();
				
		}
			
		else{
			cout << "\t\t\tINCORRECT USERNAME OR PASSWORD!!\n\n";
			cout << "\t\t\tDo you want to try again?(y/n): ";
			cin >> choice;
				
				if (choice=='Y' || choice=='y'){
					system("cls");
					loginAttempts++;
					continue;
				}
					
				else{
					system("cls");
					mainMenu();
				}
			}
	}
	cout << "\n\n\n\t\t________________________________________________________________________________\n\n";
	cout << "\t\tYou have entered INCORRECT LOGIN-DETAILS 3 times.Please try again in 5 Seconds\n";
	cout << "\t\t________________________________________________________________________________\n\n";
	Sleep(5000);
	system("cls");
	adminLogIn();
}

//validate Librarians'UserName and Password (log in)
void librarianLogIn(){
	
	char choice = '0';
	string userName;
	string password;
	int loginAttempts = 0;
	
	while(loginAttempts < 3){
		cout << "\n\n" ;
		cout << "\t |%%%%%%%%%%%%%%%%%%%%%|-'LIBRARIAN LOGIN'-|%%%%%%%%%%%%%%%%%%%%%%%%|\n\n";	
		cout << "\t\t\t [*]ENTER USERNAME: ";       
		cin >> 	userName;
		cout << "\t\t\t [*]ENTER PASSWORD: " ;	
		cin >> password;
		cout << "\n\t |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|\n\n";
		
		//reading (myFile to validate librarian login)
		fstream myFile;		//create an object named(myFile) from fstream class
		
		myFile.open("librarian.dat",ios::in);  //open librarian.dat file to read
		
		if(myFile.is_open()){
			string line;	//To store file records line by line
			while(getline(myFile, line)){	//while opend file has records to read
				istringstream iss(line);	//get the line without space(trim)
				string libID, name, mail, phone, homeAddress, libName, pinNumber;
				getline(iss, libID, '|');
				getline(iss, name, '|');
				getline(iss, mail, '|');
				getline(iss, phone, '|');
				getline(iss, homeAddress, '|');
				getline(iss, libName, '|');
				getline(iss, pinNumber, '|');
				
				if(userName==libName && password==pinNumber){
					
					librarianBookRecord = libID;
					//intialize the string
					string S = "\t\t\tLIBRARIAN LOGIN SUCCESSFULLY!!\n";
					
					//Travers the given string S
					for(int i = 0; i < S[i]; i++){
						cout << S[i];
						Sleep(100);
					}
					
					Sleep(2000);
					system("cls");
					librarianMenu();
				}
				
			}
		
			cout << "\t\t\tINCORRECT USERNAME OR PASSWORD!!\n\n";
			cout << "\t\t\tDo you want to try again?(y/n) ";
			cin >> choice;
				
			if (choice=='Y' || choice=='y'){
				system("cls");
				loginAttempts++;
				continue;
			}
					
			else{
				system("cls");
				mainMenu();
			}
						 
		}
		else{
		cout << "\t\t__'FILE DOES NOT EXIST!!'__";
		Sleep(2000);
		system("cls");
		librarianMenu();
		}
									
	}
	cout << "\n\n\n\t\t________________________________________________________________________________\n\n";
	cout << "\t\tYou have entered INCORRECT LOGIN-DETAILS 3 times.Please try again in 5 Seconds\n";
	cout << "\t\t________________________________________________________________________________\n\n";
	Sleep(5000);
	system("cls");
	librarianLogIn();
				
}	


//admin menu panel
void adminMenu(){

	while(true){
		int option=0;
		
		cout << "\n\n\t++++++++++++++++++++++++++++++-ADMIN MENU-++++++++++++++++++++++++++++++++++++\n";
		cout << "\t|                                                                            |\n";
		cout << "\t|                       [1]-SIGN UP LIBRARIANS                               |\n";	
		cout << "\t|                       [2]-UPDATE THE FINE RATE                             |\n";	
		cout << "\t|                       [3]-MODIFY MAXIMUM BORROWING LIMITS                  |\n";
		cout << "\t|                       [4]-BACK TO MAIN MENU                                |\n";
		cout << "\t|____________________________________________________________________________|\n\n";
		
		//get user input
		cout << "\t\tChoose an option: ";
		cin >> option;	
			
			
		switch(option){
			case 1:{
				system("cls");
				libSignUp();
				break;
			}
				
			case 2:{ 
				system("cls");
				changeDisplayFine();
				break;
			}
				
			case 3:{
				system("cls");
				modifyDisplayBorrowingLimit();
				break;	
			}
			
			case 4:{
				system("cls");
				mainMenu();
			}
			
			default:{
				char opt = '0';
					cout <<"\n\t\t\tINVALID INPUT!! Do you want to try again?(y/n): ";
					cin >> opt;
					
					if(opt=='y'||opt=='Y'){
						system("cls");
						adminMenu();
					}
					
					else{
						system("cls");
						mainMenu();
					}
			}
		}	
	}
}

void libSignUp(){
	
	string nic,fullName,email,conNumber,address,userName,password,rePassword;
	
	while(true){
		//Getting user input (NIC no) to check whether that librarian already exist in the current system.
		cout << "\n\n\t |#######################|-'LIBRARIAN SIGN-UP INFO'-|########################|\n\n";
		cout << "\t\t\tNIC Number: ";
		cin >> nic;
		cout << "\n\t |############################################################################|\n\n";
		
		if(nic.length() == 9 || nic.length() == 12 ){
			break;
		}	
		
		else{
			char option = '0';
			
			cout << "\n\t\t\tINVALID NIC NUMBER!!\n";
			cout << "\n\t\t\tDo you want to try again?(y/n):  ";
			cin >> option;
			
			if(option=='y'||option=='Y'){
				system("cls");
				continue;
			}
			
			else if(option=='n'||option=='N'){
				system("cls");
				adminMenu();
			}
			
			else{
			cout << "INVALID INPUT!!\n";
			cout << "\n\t\t_'Press any key to return Admin Menu'_";
			getch();
			system("cls");
			adminMenu();
			}
		}	
	}
	
	//Create an Id for the librarian
	string id = "LLIB#" + nic;		//LIB#200351501449
	
	//reading (myFile to to check whether already exist)
	fstream myFile;
	
	myFile.open("librarian.dat",ios::in);	 //open librarian.dat file to read
	
	if(myFile.is_open()){
		string line;		//To store file records line by line
		while(getline(myFile, line)){	//while opend file has records to read
			istringstream ss(line);		//get the line without space(trim)
			string libID;
			getline(ss, libID, '|');
			
			if(id==libID){
				cout << "\t\t_'LIBRARIAN ALREADY EXIST'_\n\n";
				myFile.close();
				cout << "\n\t\t_'Press any key to return Admin Menu'_";
				getch();
				system("cls");
				adminMenu();
			}
		}	 
	}
	
	else{
		cout << "__'FILE DOES NOT EXIST!!'__";
		Sleep(2000);
		system("cls");
		adminMenu();
	}
	
	cout << "\t\t__'LIBRARIAN DOES NOT EXIST!!'__\n";
	Sleep(1000);
	system("cls");
	
	//getting user inputs to sign up librarians(name,email,address,contact info.)
	cout << "\n\n\t|#######################|-'LIBRARIAN SIGN-UP FORM'-|############################|\n\n";
	cout << "\t\tFULL NAME\t: ";
	cin.ignore();
	getline (cin,fullName);
	cout << "\t\tE-MAIL\t\t: ";
	cin >> email;
	cout << "\t\tCONTACT NUMBER\t: ";
	cin >> conNumber;
	cout << "\t\tADDRESS\t\t: ";
	cin >> address;
	while(true){	
		cout << "\n\t________________________________________________________________________________\n";
		cout << "\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^-LOGIN DETAILS-^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
		cout << "\t\tUSER NAME\t\t: ";
		cin >> userName;
		cout << "\t\tPASSWORD\t\t: ";
		cin >> password;
		cout << "\t\tRE-ENTER PASSWORD\t: ";
		cin >> rePassword;
		
		if(rePassword==password){
			break;
		}
		cout << "\n\t\tRe-Entered password not match!TRY AGAIN!";
		Sleep(1000);
		system("cls");
		continue;
	}
	cout << "\n\t|################################################################################|\n\n";
	
	
	//saving informations in the file("librarian.dat")
	fstream myFileWrite;	//create object called myFileWrite from fstream class
	
	//calling open()function through File object.
	myFileWrite.open("librarian.dat",ios::app);	//file path mode
											   
	
	if(!myFileWrite){
		cout << "FILE OPEN FAILED!!\n";
		Sleep(2000);
		system("cls");
		libSignUp();
	}
	else{
		myFileWrite << id << "|" << fullName << "|" << email << "|" << conNumber << "|" << address << "|" << userName << "|" << password << "\n";
		myFileWrite.close();
		
		//intialize the string
		string S = "\t\t\tLIBRARIAN SUCCESSFULLY ADDED!!\n";	
		//Travers the given string S
		for(int i = 0; i < S[i]; i++){
			cout << S[i];
			Sleep(100);
		}
			
		Sleep(2000);
		system("cls");
		adminMenu();
	}
	
}


void changeDisplayFine(){
	char option = '0';
	char opt = '0';
	
	do{
		cout << "\n\n\t========================================================================================\n";
		cout << "\t|+++++++++++++++++++++++++++++-'FINE RATE'-++++++++++++++++++++++++++++++++++++++++++++|\n\n";
		cout << "\t\t\t[1].DISPLAY CURRENT FINE RATE                                                  \n";
		cout << "\t\t\t[2].UPDATE FINE RATE                                                           \n";
		cout << "\t\t\t[3].BACK TO ADMIN MENU {<<-}                                                   \n";
		cout << "\n\t========================================================================================\n\n";
		
		//get user input
		cout << "\t\tChoose an option: " ;
		cin >> opt;
		
		switch(opt){
			case '1':{
				displayFineRate();
				break;
			}
			
			case '2':{
				updateFineRate();
				break;
			}
			
			case '3':{
				system("cls");
				adminMenu();
				break;
			}
			
			default:{
				char opt = '0';
				cout <<"\n\t\t\tINVALID INPUT! Do you want to try again?(y/n): ";
				cin >> opt;
				
				if(opt=='y'||opt=='Y'){
					system("cls");
					adminMenu();
				}
				
				else if(option=='n'||option=='N'){
				system("cls");
				mainMenu();
				}
						
				else{
					cout << "INVALID INPUT!!\n";
					cout << "\n\t\t_'Press any key to return Admin Menu'_\n";
					getch();
					system("cls");
					adminMenu();
				}
			}
		}
	}while(opt==!3);
	
}


float displayFineRate(){
	
	float fineRate = 0.0;
	
	fstream inFineFile;

	inFineFile.open("fineRate.dat",ios::in);
	
	if(!inFineFile){
		cout << "\t\tFILE OPENED FAIL!!!\n";
		Sleep(1000);
		cout << "\n\t\t_'Press any key to return Admin Menu'_\n";
		getch();
		system("cls");
		adminMenu();
	}
	
	else{
		
		inFineFile >> fineRate;	//read the fine rate from the file
		
		cout << "\n\n\t\t------------------------------------------------------------------\n\n";
		cout << "\t\t\tCURRENT FINE RATE(Rs.): " << fineRate;
		cout << "\n\n\t\t------------------------------------------------------------------\n";
		
		inFineFile.close();
		
		Sleep(2000);
		system("cls");
		changeDisplayFine();
	}
	//return fineRate;
}


void updateFineRate(){
	fstream outFineFile;
			
	outFineFile.open("fineRate.dat",ios::out);
	
	if(!outFineFile){
		cout << "FILE OPENED FAIL!!!\n";
		Sleep(1000);
		cout << "\n\t\t_'Press any key to return Admin Menu'_\n";
		getch();
		system("cls");
		adminMenu();	
	}
	
	else{
		float fineRate = 0.0;
		while(true){
			cout << "\n\t\t\tEnter new fine rate(Rs.): ";
			cin >> fineRate;
			
			if(fineRate < 0){
				cout << "\t\tINVALID FINE RATE!!!\n";
				cout << "\t\tPress any key to try again";
				getch();
				system("cls");
				continue;
			}
			outFineFile << fineRate ;
			outFineFile.close();
			break;
		}
	}
	
	
	//intialize the string
	string S = "\n\t\t\tFINE CHANGED SUCCESSFULLY !!\n\n";	
	//Travers the given string S
	for(int i = 0; i < S[i]; i++){
		cout << S[i];
		Sleep(100);
	}
	
	Sleep(1000);
	system("cls");
	changeDisplayFine();
}


void modifyDisplayBorrowingLimit(){
	char option = '0';
	char opt = '0';
	
	do{
		cout << "\n\n\t========================================================================================\n";
		cout << "\t|+++++++++++++++++++++++++++++-'BORROWING LIMIT'-+++++++++++++++++++++++++++++++++++++++|\n\n";
		cout << "\t\t\t[1].DISPLAY CURRENT MAXIMUM BORROWING LIMIT                                    \n";
		cout << "\t\t\t[2].UPDATE BORROWING LIMIT                                                     \n";
		cout << "\t\t\t[3].BACK TO ADMIN MENU {<<-}                                                   \n";
		cout << "\n\t========================================================================================\n\n";
		
		//get user input
		cout << "\t\tChoose an option: " ;
		cin >> opt;
		
		switch(opt){
			case '1':{
				displayBorrowingLimit();
				break;
			}
			
			case '2':{
				modifyBorrowingLimit();
				break;
			}
			
			case '3':{
				system("cls");
				adminMenu();
				break;
			}
			
			default:{
				char opt = '0';
				cout <<"\n\t\t\tINVALID INPUT! Do you want to try again?(y/n): ";
				cin >> opt;
				
				if(opt=='y'||opt=='Y'){
					system("cls");
					adminMenu();
				}
				
				else if(option=='n'||option=='N'){
				system("cls");
				mainMenu();
				}
						
				else{
					cout << "INVALID INPUT!!\n";
					cout << "\n\t\t_'Press any key to return Admin Menu'_\n";
					getch();
					system("cls");
					adminMenu();
				}
			}
		}
	}while(opt==!3);
	
}


void displayBorrowingLimit(){
	fstream inMaxBorrowFile;
	
	inMaxBorrowFile.open("borrowingLimit.dat",ios::in);
	
	if(!inMaxBorrowFile){
		cout << "\t\tFILE OPENED FAIL!!!\n";
		Sleep(1000);
		cout << "\n\t\t_'Press any key to return Admin Menu'_\n";
		getch();
		system("cls");
		adminMenu();
	}
	else{
		int borrowingLimit = 0;
		inMaxBorrowFile >> borrowingLimit;	//read the fine rate from the file
		cout << "\n\n\t\t------------------------------------------------------------------\n\n";
		cout << "\t\t\tCURRENT BORROWING LIMIT(Books): " << borrowingLimit;
		cout << "\n\n\t\t------------------------------------------------------------------\n";
		
		inMaxBorrowFile.close();
		
		Sleep(2000);
		system("cls");
		modifyDisplayBorrowingLimit();
	}
}


void modifyBorrowingLimit(){
	fstream outMaxBorrowFile;
			
	outMaxBorrowFile.open("borrowingLimit.dat",ios::out);
	
	if(!outMaxBorrowFile){
		cout << "FILE OPENED FAIL!!!\n";
		Sleep(1000);
		cout << "\n\t\t_'Press any key to return Admin Menu'_\n";
		getch();
		system("cls");
		adminMenu();
	}
	
	else{
		int borrowingLimit = 0;
		
		while(true){
			cout << "\n\t\t\tEnter new borrowing limit(Books): ";
			cin >> borrowingLimit;
			if(borrowingLimit < 0){
					cout << "\t\tINVALID BORROWING LIMIT!!!\n";
					cout << "\t\tPress any key to try again";
					getch();
					system("cls");
					continue;
			}
			break;
		}
		outMaxBorrowFile << borrowingLimit ;	//write maximum borrowing limit in the file
		outMaxBorrowFile.close();
	}
	
	
	//intialize the string
	string S = "\n\t\t\tBORROWING LIMIT CHANGED SUCCESSFULLY !!\n\n";	
	//Travers the given string S
	for(int i = 0; i < S[i]; i++){
		cout << S[i];
		Sleep(100);
	}
	
	Sleep(1000);
	system("cls");
	modifyDisplayBorrowingLimit();
}
	
	
//librarian menu panel
void librarianMenu(){
	int opt=0;
	do{		
		cout << "\n\n\t ++++++++++++++++++++++++++++++-LIBRARIANS' MENU-++++++++++++++++++++++++++++++++++\n";
		cout << "\t|                                                                                 |\n";
		cout << "\t|                       [1]-ADD OR DELETE BOOKS                                   |\n";	
		cout << "\t|                       [2]-SEARCH OR UPDATE BOOKS                                |\n";	
		cout << "\t|                       [3]-BOOK CHECKOUT OR RETURN BOOKS [ISSUE/ACCEPT]          |\n";
		cout << "\t|                       [4]-ADD OR DELETE BORROWERS                               |\n";
		cout << "\t|                       [5]-SEARCH OR UPDATE BORROWERS                            |\n";
		cout << "\t|                       [6]-SHOW ALL THE ISSUED BOOK DETAILS                      |\n";
		cout << "\t|                       [7]-BACK TO MAIN MENU                                     |\n";
		cout << "\t|_________________________________________________________________________________|\n\n";
		
		//get user input
		cout << "\t\tChoose an option: ";
		cin >> opt;	
			
			
		switch(opt){
			case 1:{
				system("cls");
				addDeleteBooks();
				break;
			}
				
			case 2:{ 
				system("cls");
				searchUpdateBooks();
				break;
			}
				
			case 3:{
				system("cls");
				issueReturnedBooks();
				break;	
			}
			
			case 4:{
				system("cls");
				addDeleteBorrowers();
				break;	
			}
			
			case 5:{
				system("cls");
				searchUpdateBorrowers();
				break;	
			}
			
			case 6:{
				system("cls");
				showAllBorrowedDetails();
			}
			
			case 7:{
				system("cls");
				mainMenu();
				break;
			}
			
			default:{
				char opt = '0';
				cout <<"\n\t\t\tINVALID INPUT! Do you want to try again?(y/n): ";
				cin >> opt;
				
				if(opt=='y'||opt=='Y'){
					system("cls");
					librarianMenu();
				}
				
				else if(opt=='n'||opt=='N'){
				system("cls");
				mainMenu();
				}
					
				else{
				cout << "INVALID INPUT!!\n";
				cout << "\n\t\t_'Press any key to return librarian Menu'_";
				getch();
				system("cls");
				librarianMenu();
				}
			} 
		}	
	}while(opt!=6);
}


void addDeleteBooks(){
	
	int opt = 0;
	
	cout << "\n\n\t======================================================================================\n";
	cout << "\t|+++++++++++++++++++++++++++++-'ADD OR DELETE BOOKS'-+++++++++++++++++++++++++++++++++|\n\n";
	cout << "\t\t\t[1].ADD BOOKS{+}                                                                 \n";
	cout << "\t\t\t[2].DELETE BOOKS{-}                                                              \n";
	cout << "\t\t\t[3].BACK TO LIBRARIANS' MENU {<<-}                                               \n";
	cout << "\n\t======================================================================================\n\n";
	
	//get user input
	cout << "\t\tChoose an option: " ;
	cin >> opt;	
		
		
	switch(opt){
		case 1:{
			system("cls");
			addBooks();
			break;
		}
			
		case 2:{ 
			system("cls");
			deleteBooks();
			break;
		}
			
		case 3:{
			system("cls");
			librarianMenu();
			break;	
		}
		
		default:{
			char opt = '0';
			cout <<"\n\t\t\tINVALID INPUT!! Do you want to try again?(y/n): ";
			cin >> opt;
			
			if(opt=='y'||opt=='Y'){
				system("cls");
				addDeleteBooks();
			}
			
			else{
				system("cls");
				librarianMenu();
			}
		}
	}
}

void searchUpdateBooks(){
	int opt = 0;
	
	cout << "\n\n\t======================================================================================\n";
	cout << "\t|+++++++++++++++++++++++++++-'SEARCH 0R UPDATE BOOKS'-++++++++++++++++++++++++++++++++|\n\n";
	cout << "\t\t\t[1].SEARCH BOOKS{?}                                                                 \n";
	cout << "\t\t\t[2].UPDATE BOOKS{()}                                                              \n";
	cout << "\t\t\t[3].BACK TO LIBRARIANS' MENU {<<-}                                               \n";
	cout << "\n\t======================================================================================\n\n";
	
	//get user input
	cout << "\t\tChoose an option: " ;
	cin >> opt;	
		
		
	switch(opt){
		case 1:{
			system("cls");
			searchBooks();
			break;
		}
			
		case 2:{ 
			system("cls");
			updateBooks();
			break;
		}
			
		case 3:{
			system("cls");
			librarianMenu();
			break;	
		}
		
		default:{
			char opt = '0';
			cout <<"\n\t\t\tINVALID INPUT!! Do you want to try again?(y/n): ";
			cin >> opt;
			
			if(opt=='y'||opt=='Y'){
				system("cls");
				searchUpdateBooks();
			}
			else{
				system("cls");
				librarianMenu();
			}
		}
	}
}


void issueReturnedBooks(){
	
	
	string bookID, borrowerID;
	int bookFound = 0;
	int borrowerFound = 0;
	int bookLimitMatch = 0;
	int borrowingLimit = 0;
	int newBrrCount = 0;
	
	while(true){
		cout << "\n\n\t |#######################|-'ISSUE OR RETURN BOOK'-|########################|\n\n";
		cout << "\t\t\tBOOK ID\t\t: ";
		cin >> bookID;
		cout << "\t\t\tBORROWER ID\t: ";
		cin >> borrowerID;
		cout << "\n\t |############################################################################|\n\n";
		
		transform(bookID.begin(),bookID.end(),bookID.begin(),::tolower);
		transform(borrowerID.begin(),borrowerID.end(),borrowerID.begin(),::tolower);
	
		//check whether Book ID and Borrower ID are already exist in the file
		fstream BookFile,BorrowFile;
		
		BookFile.open("books.dat",ios::in);
		BorrowFile.open("borrower.dat",ios::in);
		//check whether Book ID  already exist in the file
		if(BookFile.is_open() && BorrowFile.is_open()){
			string line;
			while(getline(BookFile,line)){
				string bookid;		//variables to store the details of the each books
				istringstream iss(line);
				getline(iss, bookid, '|');		//extract book details to variables
				
				//convert bookid to lowercase
				transform(bookid.begin(), bookid.end(), bookid.begin(), ::tolower);
				
				if(bookID==bookid){

					bookFound++;
					break;
				}
			}
			if(bookFound==0){
				char opt = '0';
				cout << "\t\tYOU CAN'T BORROW [BOOK DOES NOT EXIST]";
				cout << "\n\t\tDO YOU WANT TO ISSUE ANOTHER BOOK?";
				cin >> opt;
				if(opt=='y'||opt=='Y'){
					system("cls");
					continue;
				}
				
				else if(opt=='n'||opt=='N'){
				system("cls");
				librarianMenu;
				}
					
				else{
				cout << "\n\t\tINVALID INPUT!!\n";
				cout << "\n\t\t_'Press any key to return librarian Menu'_";
				getch();
				system("cls");
				librarianMenu();
				}
			}
			
			//read the Maximum borrowlimit to get the borrow limit
			fstream inMaxBorrowFile;
			inMaxBorrowFile.open("borrowingLimit.dat", ios::in);
			
			if(!inMaxBorrowFile){
				cout << "\t\tFILE OPENED FAIL!!!\n";
				Sleep(1000);
				cout << "\n\t\t_'Press any key to return Admin Menu'_\n";
				getch();
				system("cls");
				adminMenu();
			}
			inMaxBorrowFile >> borrowingLimit;  //read the borrow limit
				
				
			//check whether	Borrower ID is already exist in the file
			string line2;	//variable that store each line of the borrower file
			//read each line of the borrower file
			while(getline(BorrowFile,line2)){
				
				//variables to store the details of the each borrower
				string borrowerid,name,phoneNo,email,address,joinedDate,brrCount,librarian;
		
				istringstream iss(line2);
				//extract borrower details to variables
				getline(iss, borrowerid, '|');
				getline(iss, name, '|');
				getline(iss, phoneNo, '|');
				getline(iss, email, '|');
				getline(iss, address, '|');
				getline(iss, joinedDate, '|');
				getline(iss, brrCount, '|');
				getline(iss, librarian, '|');
		
				
				//convert borrower id to lowercase
				transform(borrowerid.begin(), borrowerid.end(), borrowerid.begin(), ::tolower);
			
				istringstream ss(brrCount);		// convert brrCount string value into integer value
				ss >> newBrrCount;
				
				
				
				
				//check if the current borrower matches to the users' Target 
				if(borrowerID==borrowerid){
					borrowerFound++;
					if(newBrrCount < borrowingLimit){
						bookLimitMatch++;		//if book limit matches(greater than or equal) the current count of books, (add+)
						break;
					}
				}
			}
			if(borrowerFound==0){
				char opt = '0';
				cout << "\t\tBORROWER DOES NOT EXIST!!!\n";
				cout << "\n\t\tDO YOU WANT TO TRY AGAIN(y/n)?";
				cin >> opt;
				if(opt=='y'||opt=='Y'){
					system("cls");
					continue;
				}
				
				else if(opt=='n'||opt=='N'){
					system("cls");
					librarianMenu;
				}
					
				else{
					cout << "\n\t\tINVALID INPUT!!\n";
					cout << "\n\t\t_'Press any key to return librarian Menu'_";
					getch();
					system("cls");
					librarianMenu();
				}
			}
			
			if(bookLimitMatch==0){
				char opt = '0';
				cout << "\t\tBORROWER EXCEDED THE MAXIMUM BORROWING LIMIT!!!\n";
				cout << "\n\t\tDO YOU WANT TO TRY AGAIN(y/n)?";
				cin >> opt;
				if(opt=='y'||opt=='Y'){
					system("cls");
					continue;
				}
				
				else if(opt=='n'||opt=='N'){
					system("cls");
					librarianMenu;
				}
					
				else{
					cout << "\n\t\tINVALID INPUT!!\n";
					cout << "\n\t\t_'Press any key to return librarian Menu'_";
					getch();
					system("cls");
					librarianMenu();
				}
			}
		}
			
		else{
			cout << "\n\t\tBOOK FILE OR BORROW FILE NOT FOUND!!";
		}
		
		BookFile.close();
		BorrowFile.close();
		
		//if both book and borrower exist check whether to issue or accept a book.
		if(bookFound==1 && borrowerFound==1 && bookLimitMatch==1){
			cout << "\n\t\tBOOK ID AND BORROWER ID VALID!! YOU CAN GO AHEAD!!";
			Sleep(2500);
			system("cls");
			issueReturnedBooksMenu(borrowerID, bookID, newBrrCount);
		}
		else{
			char option = '0';
			cout << "\n\t\t BOOK ID OR BORROWER ID DOES NOT FOUND!!";
			cout << "\n\t\tDO YOU WANT TO TRY AGAIN?";
			cin  >> option;
			
			if(option=='y'||option=='Y'){
				system("cls");
				continue;
			}
			
			else if(option=='n'||option=='N'){
				system("cls");
				librarianMenu;
			}
				
			else{
				cout << "\n\t\tINVALID INPUT!!\n";
				cout << "\n\t\t_'Press any key to return librarian Menu'_";
				getch();
				system("cls");
				librarianMenu();
			}
		}
	}
}

void issueReturnedBooksMenu(string borrowerID, string bookID, int newBrrCount){
	char opt = '0';
	do{
		cout << "\n\n\t======================================================================================\n";
		cout << "\t|++++++++++++++++++++++-'ISSUE' OR 'ACCEPT RETURNED BOOKS'''-++++++++++++++++++++++++|\n\n";
		cout << "\t\t\t[1].ISSUE BOOKS{+}                                                                 \n";
		cout << "\t\t\t[2].ACCEPT RETURNED BOOKS{-}                                                              \n";
		cout << "\t\t\t[3].BACK TO LIBRARIANS' MENU {<<-}                                               \n";
		cout << "\n\t======================================================================================\n\n";
		
		//get user input
		cout << "\t\tChoose an option: ";
		cin >> opt;	
			
			
		switch(opt){
			case '1':{
				system("cls");
				issueBooks(borrowerID, bookID, newBrrCount);
				break;
			}
				
			case '2':{ 
				system("cls");
				acceptReturnedBooks(borrowerID, bookID, newBrrCount);
				break;
			}
				
			case '3':{
				system("cls");
				librarianMenu();
				break;	
			}
			
			default:{
				char option = '0';
				cout <<"\n\t\t\tINVALID INPUT! Do you want to try again?(y/n): ";
				cin >> opt;
				
				if(option=='y'||option=='Y'){
					system("cls");
					continue;
				}
				
				else if(option=='n'||option=='N'){
				system("cls");
				librarianMenu();
				}
					
				else{
				cout << "\t\tINVALID INPUT!!\n";
				cout << "\n\t\t_'Press any key to return librarian Menu'_";
				getch();
				system("cls");
				librarianMenu();
				}
			} 
		}
	}while(opt!='3');
}


void issueBooks(string borrowerID, string bookID, int newBrrCount){
															
	string bookTitle;
	float fine = 0.0;
	
	//get current date
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	
	tm issueDate = {};
	issueDate.tm_year = year - 1900;
	issueDate.tm_mon = month - 1;
	issueDate.tm_mday = day;
	
	//calculate the due date
	tm dueDate = issueDate;
	dueDate.tm_mday +=14;
	mktime(&dueDate); //normalize even after 30 th day
	
	//open book.dat file to read
	fstream BookFile,TempFile1;
	BookFile.open("books.dat", ios::in);
	TempFile1.open("temp.dat", ios::out);
	
	//when borrowing a book displays 'unavailable' in "books.dat"
	if(BookFile.is_open() && TempFile1.is_open()){
		string line;
		while(getline(BookFile,line)){
			istringstream iss(line);
			string bookid, title, author, publisher, genre, price, availability, addedDate,librarian;
    		getline(iss,bookid,'|');
    		getline(iss,title,'|');
    		getline(iss,author,'|');
    		getline(iss,publisher,'|');
    		getline(iss,genre,'|');
    		getline(iss,price,'|');
    		getline(iss,availability,'|');
    		getline(iss,addedDate,'|');
    		getline(iss,librarian,'|');
    		
    		transform(bookid.begin(), bookid.end(), bookid.begin(), ::tolower);

    		if(bookID == bookid){
    			transform(bookid.begin(), bookid.end(), bookid.begin(), ::toupper);
    			bookTitle = title;
    			TempFile1 << bookid << "|" << title << "|" << author << "|" << publisher << "|" << genre << "|" << price << "|" << "UNAVAILABLE" << "|" << addedDate << "|" << librarian << "\n";
			}
			else{
				TempFile1 << line << "\n";
			}
		}
		BookFile.close();
		TempFile1.close();
		
		remove("books.dat");
		rename("temp.dat", "books.dat");
	}
	else{
		cout << "\n\t\tBOOK FILE OR TEMP FILE DOES NOT FOUND!!!\n";
		Sleep(2000);
		cout << "Press any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
	
	//finally write borrowing informations to the borrowing record file
	fstream BorrowingRecordFile;
	BorrowingRecordFile.open("borrowingRec.dat",ios::app);
	
	if(!BorrowingRecordFile.is_open()){
		cout << "\n\t\tBORROWING RECORD FILE DOES NOT FOUND!!!\n";
		Sleep(2000);
		cout << "Press any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
	
	else{
		
		transform(borrowerID.begin(), borrowerID.end(), borrowerID.begin(),::toupper);
		transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(),::toupper);
		transform(bookID.begin(), bookID.end(), bookID.begin(),::toupper);
		
		BorrowingRecordFile << borrowerID << "|" << bookTitle << "|" << bookID << "|" << year << "/" << month << "/" << day << "|" << (1900+dueDate.tm_year) << "/" << (1+dueDate.tm_mon) << "/" << (dueDate.tm_mday) << "\n";
		BorrowingRecordFile.close();				
	}
	
	cout << "\t-----------------------------------------------------------------------------\n";
	cout << "\t\t\tBORROWER ID\t\t: " << borrowerID << endl;
	cout << "\t\t\tBOOK ID\t\t\t: " << bookID << endl;
	cout << "\t\t\tBOOK TITLE\t\t: " << bookTitle << endl;
	cout << "\t\t\tISSUE DATE\t\t: " << year << "/" << month << "/" << day << endl;
	cout << "\t\t\tDUE DATE\t\t: " << (1900+dueDate.tm_year) << "/" << (1+dueDate.tm_mon) << "/" << (dueDate.tm_mday) << "\n";
	cout << "\t-----------------------------------------------------------------------------\n";
	
	//intialize the string
	string S = "\n\t\t\tBOOK ISSUED SUCCESSFULLY!!!";	
	//Travers the given string S
	for(int i = 0; i < S[i]; i++){
		cout << S[i];
		Sleep(100);
	}
	
	//convert the borrowerID to lowercase
	transform(borrowerID.begin(), borrowerID.end(), borrowerID.begin(), ::tolower);
	
	//open original Borrower File for reading and TempFile for writing
	fstream BorrowerFile, TempFile2;
	BorrowerFile.open("borrower.dat",ios::in);
	TempFile2.open("temp.dat",ios::out);
	
	//check if the borrower file is successfully opened
	if(!BorrowerFile.is_open() && !TempFile2.is_open()){
		cout << "\t\t\tFILE OPENINING ERROR!!!\n";
		cout << "\n\t\tPress any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
	
	string line;	//variable that store each line of the borrower file
	
	//read each line of the borrower file
	while(getline(BorrowerFile,line)){
		
		//variables to store the details of the each borrower
		string borrowerid,name,phoneNo,email,address,joinedDate,brrCount,librarian;
		
		istringstream iss(line);
		//extract borrower details to variables
		getline(iss, borrowerid, '|');
		getline(iss, name, '|');
		getline(iss, phoneNo, '|');
		getline(iss, email, '|');
		getline(iss, address, '|');
		getline(iss, joinedDate, '|');
		getline(iss, brrCount, '|');
		getline(iss, librarian, '|');
		
		//convert borrower id to lowercase
		transform(borrowerid.begin(), borrowerid.end(), borrowerid.begin(), ::tolower);
		
		
		
		//check if the current borrower matches to the users' Target 
		if(borrowerID==borrowerid){
			//convert borrower id to uppercase
			transform(borrowerid.begin(), borrowerid.end(), borrowerid.begin(), ::toupper);
		
			//write the updated details(newBorrow count) to the temporary file
			TempFile2 << borrowerid << "|" << name << "|" << phoneNo << "|" << email << "|" << address << "|" << joinedDate << "|" << (newBrrCount+1) << "|" << librarian << "\n";
		}
		
		else{
			TempFile2 << line << "\n";
		}		
	}
	
	//close both files
	BorrowerFile.flush();
	BorrowerFile.close();
	
	TempFile2.flush();
	TempFile2.close();
	
	//delete BookFile and rename TempFile
	remove("borrower.dat");
	rename("temp.dat","borrower.dat");
			
	
	
	char option = '0';
	Sleep(1000);
	cout << "\n\t\t\tDo you want to borrow another book?(y/n): ";
	cin >> option;
	if(option=='y'||option=='Y'){
		system("cls");
		issueReturnedBooks();
	}
				
	else if(option=='n'||option=='N'){
		system("cls");
		librarianMenu();
	}
					
	else{
		cout << "\t\tINVALID INPUT!!\n";
		cout << "\n\t\t_'Press any key to return librarian Menu'_";
		getch();
		system("cls");
		librarianMenu();
	}
}


void acceptReturnedBooks(string borrowerID, string bookID, int newBrrCount){
	
	cout << borrowerID << endl;
	cout << bookID << endl;
	cout << newBrrCount;
	getch();
	
	//calculate the return date
	time_t returnDate = time(0);
	
	// Get the user input (return data)
	int year, month, day;
	cout << "\t\tEnter Return Date(yyyy/mm/dd): ";
	cin >> year >> month >> day;
	
	// Find the return the date
	tm returnDateCal = {};
	returnDateCal.tm_year = year - 1900;
	returnDateCal.tm_mon = month - 1;
	returnDateCal.tm_mday = day;
	
	// Get the fine rate from fineRateDisplay()
	float fineRate = displayFineRate();
	cout << fineRate;
	getch();
	
	
	
	
}


void addDeleteBorrowers(){
	int opt = 0;
	
	cout << "\n\n\t======================================================================================\n";
	cout << "\t|+++++++++++++++++++++++++++-'ADD OR DELETE BORROWERS'-+++++++++++++++++++++++++++++++|\n\n";
	cout << "\t\t\t[1].ADD BORROWERS{+}                                                                 \n";
	cout << "\t\t\t[2].DELETE BORROWERS{-}                                                              \n";
	cout << "\t\t\t[3].BACK TO LIBRARIANS' MENU {<<-}                                               \n";
	cout << "\n\t======================================================================================\n\n";
	
	//get user input
	cout << "\t\tChoose an option: " ;
	cin >> opt;	
		
		
	switch(opt){
		case 1:{
			system("cls");
			addBorrowers();
			break;
		}
			
		case 2:{ 
			system("cls");
			deleteBorrowers();
			break;
		}
			
		case 3:{
			system("cls");
			librarianMenu();
			break;	
		}
		
		default:{
			char opt = '0';
			cout <<"\n\t\t\tINVALID INPUT!! Do you want to try again?(y/n): ";
			cin >> opt;
			
			if(opt=='y'||opt=='Y'){
				system("cls");
				addDeleteBorrowers();
			}
			else if(opt=='n'||opt=='N'){
				system("cls");
				librarianMenu();
			}
			
			else{
			cout << "INVALID INPUT!!\n";
			cout << "\n\t\t_'Press any key to return Librarian Menu'_";
			getch();
			system("cls");
			librarianMenu();
			}
		}
	}
}


void searchUpdateBorrowers(){
		int opt = 0;
	
	cout << "\n\n\t======================================================================================\n";
	cout << "\t|+++++++++++++++++++++++++++-'SEARCH OR UPDATE BORROWERS'-++++++++++++++++++++++++++++|\n\n";
	cout << "\t\t\t[1].SEARCH BORROWERS{?}                                                                 \n";
	cout << "\t\t\t[2].UPDATE BORROWERS{()}                                                              \n";
	cout << "\t\t\t[3].BACK TO LIBRARIANS' MENU {<<-}                                               \n";
	cout << "\n\t======================================================================================\n\n";
	
	//get user input
	cout << "\t\tChoose an option: " ;
	cin >> opt;	
		
		
	switch(opt){
		case 1:{
			system("cls");
			searchBorrowers();
			break;
		}
			
		case 2:{ 
			system("cls");
			updateBorrowers();
			break;
		}
			
		case 3:{
			system("cls");
			librarianMenu();
			break;	
		}
		
		default:{
			char opt = '0';
			cout <<"\n\t\t\tINVALID INPUT!! Do you want to try again?(y/n): ";
			cin >> opt;
			
			if(opt=='y'||opt=='Y'){
				system("cls");
				searchUpdateBorrowers();
			}
			else if(opt=='n'||opt=='N'){
				librarianMenu();
			}
			
			else{
				cout << "\t\t\tINVALID INPUT!!!\n";
				cout << "Press any key to return Librarian Menu";
				getch();
				system("cls");
				librarianMenu();
			}
		}
	}
}

void addBooks(){

	string isbn, title, author, price, publisher, genre;
	
	while(true){
		//Getting user input (NIC no) to check whether that book already exist in the current system.
		cout << "\n\n\t |#######################|-'ADD BOOK INFO'-|########################|\n\n";
		cout << "\t\t\tBOOK ISBN: ";
		cin >> isbn;
		cout << "\n\t |############################################################################|\n\n";
		
		if(isbn.length() == 10 || isbn.length() == 13 ){
			break;
		}	
		
		else{
			char option = '0';
			
			cout << "\n\t\t\tINVALID ISBN!!\n";
			cout << "\n\t\t\tDo you want to try again?(y/n):  ";
			cin >> option;
			
			if(option=='y'||option=='Y'){
				system("cls");
				continue;
			}
			
			else if(option=='n'||option=='N'){
				system("cls");
				librarianMenu();
			}
			
			else{
				cout << "\t\t\tINVALID INPUT!!!\n";
				cout << "Press any key to return Librarian Menu";
				getch();
				system("cls");
				librarianMenu();
			}
		}	
	}
	
	//Create an Id for the book
	string bookId = "LBK#" + isbn;		//LBOOK#20035150144
	
	//read the books.dat file and check whether that book already exist in the system
	fstream BookFile;
	
	BookFile.open("books.dat",ios::in);
	
	if(BookFile.is_open()){
		string line;
		while(getline(BookFile, line)){
			istringstream iss(line);
			string searchBookID;
			getline(iss, searchBookID, '|');
			
			
			if(bookId==searchBookID){
				cout << "\t\t_'THIS BOOK ALREADY EXIST'_\n\n";
				BookFile.close();
				cout << "\n\t\t_'Press any key to return librarian Menu'_";
				getch();
				system("cls");
				librarianMenu();
			}
		}	 
	}
	
	else{
		cout << "\t\t__'FILE DOES NOT EXIST!!'__";
		Sleep(2000);
		system("cls");
		librarianMenu();
	}
	
	cout << "\t\t__'THIS BOOK DOES NOT EXIST!!'__\n";
	Sleep(1000);
	system("cls");
	

	//getting user inputs to add books(Title,Author,Price,Publisher,Genre)
	cout << "\n\n\t|#######################|-'ADD BOOKS'-|#########################################|\n\n";
	cout << "\t\tTITLE\t\t: ";
	cin.ignore();
	getline(cin, title);
	cout << "\t\tAUTHOR\t\t: ";
	getline(cin, author);
	cout << "\t\tPUBLISHER\t: ";
	getline(cin, publisher);;
	cout << "\t\tGENRE\t\t: ";
	getline(cin, genre);;
	cout << "\t\tPRICE(LKR)\t: ";
	cin >> price;
	cout << "\n\t|################################################################################|\n\n";
	
	//create object called BookFileWrite from fstream class.
	fstream BookFileWrite;
	
	BookFileWrite.open("books.dat",ios::app);
	 
	if(!BookFileWrite){
		cout << "\t\tFILE CANNOT BE OPENED!!";
		cout << "\n\t\t_'Press any key to return librarian Menu'_";
		getch();
		system("cls");
		librarianMenu();
	}
	else{
		
		//get current date
		time_t now = time(0);
		tm *ltm = localtime(&now);
		
		int year = 1900 + ltm->tm_year;
		int month = 1 + ltm->tm_mon;
		int day = ltm->tm_mday;
		
		transform(title.begin(), title.end(), title.begin(),::toupper);
		transform(author.begin(), author.end(), author.begin(),::toupper);
		transform(publisher.begin(), publisher.end(), publisher.begin(),::toupper);
		transform(genre.begin(), genre.end(), genre.begin(),::toupper);
		
		BookFileWrite << bookId << "|" << title << "|" << author << "|" << publisher << "|" << genre << "|" << price << "|" << availability << "|" << year << "/" << month << "/" << day << "|" << librarianBookRecord << "\n";
		BookFileWrite.close();
		
		//intialize the string
		string S = "\t\t\tTHE BOOK SUCCESSFULLY ADDED!!\n";	
		//Travers the given string S
		for(int i = 0; i < S[i]; i++){
			cout << S[i];
			Sleep(100);
		}
			
		Sleep(2000);
		system("cls");
		librarianMenu();
	}
}


void deleteBooks(){
	
	int deletedCount = 0;
	string eraseTarget;
	
	cout << "\n\n\t |#######################|-'DELETE BOOKS'-|################################|\n\n";
	cout << "\t\tENTER ID/TITLE\t: ";
	cin.ignore();
	getline(cin, eraseTarget);
	cout << "\n\t |############################################################################|\n\n";
	
	//convert inputs to lowercase for case-insensitive comparison
	transform(eraseTarget.begin(), eraseTarget.end(), eraseTarget.begin(), ::tolower);
	
	fstream BookFile, TempFile;
	BookFile.open("books.dat", ios::in);
	TempFile.open("temp.dat", ios::out);
	
	if(!BookFile.is_open()){
		"\t\t\tFILE OPENINING ERROR!!!\n";
		cout << "\t\tPress any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
	
	string line;
	while(getline(BookFile, line)){
		string bookID, title;
		istringstream iss(line);
		getline(iss, bookID, '|');
		getline(iss, title, '|');
	
		//convert details to lowercase for case-insensitive comparison
		transform(bookID.begin(), bookID.end(), bookID.begin(), ::tolower);
		transform(title.begin(), title.end(), title.begin(), ::tolower);
		
		//check whether the file matches eraseTarget
		if(eraseTarget==bookID||eraseTarget==title){
			deletedCount++;
		}
		else{
			TempFile << line << "\n";	//write to the temporary file if it's not the target book
		}
	}
	
	BookFile.close();
	TempFile.close();
	
	remove("books.dat");
	rename("temp.dat","books.dat");
	
	if(deletedCount>0){
		//intialize the string
		string S = "\t\t\tTHE BOOK DELETED SUCCESSFULLY !!\n";	
		//Travers the given string S
		for(int i = 0; i < S[i]; i++){
			cout << S[i];
			Sleep(100);
		}
			
		Sleep(2000);
		cout << "\n\n\t\tPress any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
	
	else{
		cout << "\t\tBOOK NOT FOUND!!!\n";
		Sleep(2000);
		cout << "\n\t\tPress any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
}


void searchBooks(){
	string userInput = " ";
	cout << "\n\n\t |#######################|-'SEARCH BOOKS'-|##################################|\n\n";
	cout << "\tENTER ID/TITLE/AUTHOR/PUBLISHER/GENRE/AVAILABILITY/ENTERED LIBRARIAN: ";
	cin.ignore();
	getline(cin,userInput);
	cout << "\n\t |############################################################################|\n\n";

	transform(userInput.begin(),userInput.end(),userInput.begin(),::tolower);	//converting user input to lowercase <algorithm>
	
	//read books.dat file and get the line by line
    
    fstream BookFile;
    BookFile.open("books.dat",ios::in);
    
    int matchCount = 0;	//This is a counter for found book.
    
    //search matching items for the userInput
    if(BookFile.is_open()){
    	string line;
    	
    	 string bookID, title, author, publisher, genre, price, availability, addedDate, librarian;
		
    	while(getline(BookFile,line)){
    		istringstream iss(line);
    		getline(iss,bookID,'|');
    		getline(iss,title,'|');
    		getline(iss,author,'|');
    		getline(iss,publisher,'|');
    		getline(iss,genre,'|');
    		getline(iss,price,'|');
    		getline(iss,availability,'|');
    		getline(iss,addedDate,'|');
    		getline(iss,librarian,'|');
    		
    		//converting all the informations to lowercase 
			transform(bookID.begin(),bookID.end(),bookID.begin(),::tolower);
			transform(title.begin(),title.end(),title.begin(),::tolower);
			transform(author.begin(),author.end(),author.begin(),::tolower);
			transform(publisher.begin(),publisher.end(),publisher.begin(),::tolower);
			transform(genre.begin(),genre.end(),genre.begin(),::tolower);
			transform(availability.begin(),availability.end(),availability.begin(),::tolower);
			transform(librarian.begin(),librarian.end(),librarian.begin(),::tolower);
						
			if(userInput==bookID||userInput==title||userInput==author||userInput==publisher||userInput==genre||userInput==availability||userInput==librarian){
				
				matchCount++;	//increment the counter when match is found
				cout << "\t-----------------------------------------------------------------------------\n";
				cout << "\t\t\tBOOK ID\t\t\t: " << bookID << endl;
				cout << "\t\t\tTITLE\t\t\t: " << title << endl;
				cout << "\t\t\tAUTHOR\t\t\t: " << author << endl;
				cout << "\t\t\tPUBLISHER\t\t: " << publisher << endl;
				cout << "\t\t\tGENRE\t\t\t: " << genre << endl;
				cout << "\t\t\tPRICE\t\t\t: " << price << endl;
				cout << "\t\t\tAVAILABILITY\t\t: " << availability << endl;
				cout << "\t\t\tADDED DATE\t\t: " << addedDate << endl;
				cout << "\t\t\tTHE BOOK ENTERED BY\t: " << librarian << endl;
				cout << "\t-----------------------------------------------------------------------------\n";
			}
		}
		
		if(matchCount==0){
			char opt = '0';
			cout << "\n\n\t\t\tTHE BOOK IS NOT FOUND!!!\n";
			cout << "\n\t\tDO YOU WANT TO SEARCH ANOTHER BOOK?(y/n): ";
			cin >> opt;
			
			if(opt=='y'||opt=='Y'){
				system("cls");
				searchBooks();
			}
			
			else if(opt=='n'||opt=='N'){
				system("cls");
				librarianMenu();
			}
			
			else{
				cout << "\n\n\t\t\tINVALID INPUT!!!\n";
				cout << "\n\t\tPress any key to return Librarian Menu";
				getch();
				system("cls");
				librarianMenu();
			}
		}
		
	}
	
	else{
		cout << "\t\t\tFILE IS NOT OPENED!!!\n";
		Sleep(1000);
		cout << "\n\t\t_'Press any key to return librarian Menu'_";
		getch();
		system("cls");
		librarianMenu();
	}
	
	BookFile.close();
	cout << "\n\t\t_'Press any key to return librarian Menu'_";
	getch();
	system("cls");
	librarianMenu();
}


void updateBooks(){
	
	string updateTarget;
	cout << "\n\n\t |########################|-'UPDATE BOOKS'-|#########################################|\n\n";
	cout << "\t\tENTER THE BOOK ID/TITLE TO UPDATE\t: ";
	cin.ignore();
	getline(cin, updateTarget);
	cout << "\n\t |###################################################################################|\n\n";
	
	//convert the usser's input to lowercase
	transform(updateTarget.begin(), updateTarget.end(), updateTarget.begin(), ::tolower);
	
	//open original BookFile for reading and TempFile for writing
	fstream BookFile, TempFile;
	BookFile.open("books.dat",ios::in);
	TempFile.open("temp.dat",ios::out);
	
	//check if the book file is successfully opened
	if(!BookFile.is_open() && !TempFile.is_open()){
		cout << "\t\t\tFILE OPENINING ERROR!!!\n";
		cout << "\n\t\tPress any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
	
	int updatedCount = 0;
	string line;	//variable that store each line of the book file
	
	while(getline(BookFile,line)){
		
		//variables to store the details of the each books
		string bookID, title, author, publisher, genre, price, availability, addedDate, librarian;
		
		istringstream iss(line);
		//extract book details to variables
		getline(iss, bookID, '|');
		getline(iss, title, '|');
		getline(iss, author, '|');
		getline(iss, publisher, '|');
		getline(iss, genre, '|');
		getline(iss, price, '|');
		getline(iss, availability, '|');
		getline(iss, addedDate, '|');
		getline(iss, librarian, '|');
		
		//convert bookid,title to lowercase
		transform(bookID.begin(), bookID.end(), bookID.begin(), ::tolower);
		transform(title.begin(), title.end(), title.begin(), ::tolower);
		
		//check if the current book matches to the users' Target 
		if(updateTarget==bookID||updateTarget==title){
			updatedCount++;
			
			int opt = 0;
			
			while(true){
				cout << "\n\t======================================================================================\n";
				cout << "\t|+++++++++++++++++++++++++++++-'UPDATE BOOKS'-+++++++++++++++++++++++++++++++++++++++|\n\n";
				cout << "\t\t\t[1].TITLE                                                                 \n";
				cout << "\t\t\t[2].AUTHOR                                                             	 \n";
				cout << "\t\t\t[3].GENRE                                                                 \n";
				cout << "\t\t\t[4].AVAILABILITY                               						     \n";
				cout << "\t\t\t[5].BACK TO (SEARCH OR UPDATE BOOKS) MENU                  				     \n";
				cout << "\n\t======================================================================================\n\n";
				
				//get user input
				cout << "\t\tChoose an option: " ;
				cin >> opt;	
				
				if(opt < 1 || opt > 6){
					cout << "\n\n\t\t\tINVALID INPUT!!!\n";
					cout << "\n\t\tPress any key to re-enter";
					getch();
					system("cls");
					continue;
				}
				break;
			}
			
			if(opt == 1){
				//update title
				cout << "\n\t--------------------------------------------------------------------------------------\n";
				cout << "\t\tCURRENT TITLE\t\t: " << title <<"\n\n";
				cout << "\n\t\tNEW TITLE\t\t: ";
				cin.ignore();
				getline(cin,title);	
				cout << "\t--------------------------------------------------------------------------------------\n";
				
			}
			else if(opt == 2){
				//update author
				cout << "\n\t--------------------------------------------------------------------------------------\n";
				cout << "\t\tCURRENT AUTHOR\t\t: " << author <<"\n\n";
				cout << "\n\t\tNEW AUTHOR\t\t: ";
				cin.ignore();
				getline(cin,author);
				cout << "\t--------------------------------------------------------------------------------------\n";
						
			}
			else if(opt == 3){
				//update genre
				cout << "\n\t--------------------------------------------------------------------------------------\n";
				cout << "\t\tCURRENT GENRE\t\t: " << genre <<"\n\n";
				cout << "\n\t\tNEW GENRE\t\t: ";
				cin.ignore();
				getline(cin,genre);
				cout << "\t--------------------------------------------------------------------------------------\n";
			}
			else if(opt == 4){
				//update availability
				cout << "\n\t--------------------------------------------------------------------------------------\n";
				cout << "\t\tCURRENT AVAILABILITY\t: " << availability <<"\n\n";
				cout << "\n\t\tNEW AVAILABILITY\t: ";
				cin.ignore();	
				getline(cin,availability);
				cout << "\t--------------------------------------------------------------------------------------\n";
			}
			else if(opt == 5){
				system("cls");
				searchUpdateBooks();
			}
			
			//convert to uppercase
			transform(bookID.begin(), bookID.end(), bookID.begin(), ::toupper);
			transform(title.begin(), title.end(), title.begin(), ::toupper);
			transform(author.begin(), author.end(), author.begin(), ::toupper);
			transform(genre.begin(), genre.end(), genre.begin(), ::toupper);
			transform(availability.begin(), availability.end(), availability.begin(), ::toupper);

			
			//write the updated details to the temporary file
			TempFile << bookID << "|" << title << "|" << author << "|" << publisher << "|" << genre << "|" << price << "|" << availability << "|" << addedDate << "|" << librarian << "\n";	
		}
		else{
			TempFile << line << "\n";
		}
			
	}
	//close both files
	BookFile.flush();
	BookFile.close();
	
	TempFile.flush();
	TempFile.close();
	
	//delete BookFile and rename TempFile
	remove("books.dat");
	rename("temp.dat","books.dat");
	
	if(updatedCount > 0){
		
		char opt = '0';
		
		//intialize the string
		string S = "\n\t\t\tTHE BOOK UPDATED SUCCESSFULLY!!\n";	
		//Travers the given string S
		for(int i = 0; i < S[i]; i++){
			cout << S[i];
			Sleep(100);
		}
		
		Sleep(1000);
		cout << "\n\t\t\tDo you want to (SEARCH/UPDATE) again?(y/n)\t: ";
		cin >> opt;
		if(opt = 'y' || opt == 'Y'){
			system("cls");
			searchUpdateBooks();
		}
		else{
			system("cls");
			librarianMenu();
		}
	}
	
	else{
		cout << "\t\t\tBOOK NOT FOUND!!\n";
		cout << "\n\t\tPress any key to (SEARCH/UPDATE) Menu again";
		getch();
		system("cls");	
		searchUpdateBooks();
	}
	
	
}

void addBorrowers(){
	string nic, name, phoneNo,  email, address ;
	int newPhoneNumber = 0;
	while(true){
		//Getting user input (NIC no) to check whether that borrower already exist in the current system.
		cout << "\n\n\t |#######################|-'ADD BORROWER INFO'-|########################|\n\n";
		cout << "\t\t\tNIC NUMBER: ";
		cin >> nic;
		cout << "\n\t |############################################################################|\n\n";
		
		if(nic.length() == 9 || nic.length() == 12 ){
			break;
		}	
		
		else{
			char option = '0';
			
			cout << "\n\t\t\tINVALID NIC NUMBER!!\n";
			cout << "\n\t\t\tDo you want to try again?(y/n):  ";
			cin >> option;
			
			if(option=='y'||option=='Y'){
				system("cls");
				continue;
			}
			
			else{
				system("cls");
				librarianMenu();
			}
		}	
	}
	
	//Create an Id for the Borrower
	string borrowerID = "LBOR#" + nic;		//LIBB#200351501449
	
	//read borrower File and see whether is that person already exist in the system
	fstream BorrowerFile;
	
	BorrowerFile.open("borrower.dat",ios::in);
	
	if(BorrowerFile.is_open()){
		string line;
		while(getline(BorrowerFile, line)){
			istringstream iss(line);
			string borrowerNo;
			getline(iss,borrowerNo,'|');
			
			if(borrowerID==borrowerNo){
				cout << "\t\t_'THIS BORROWER ALREADY EXIST'_\n\n";
				BorrowerFile.close();
				cout << "\n\t\t_'Press any key to return librarian Menu'_";
				getch();
				system("cls");
				librarianMenu();
			}
		}	 
	}
	
	else{
		cout << "\t\t__'FILE DOES NOT EXIST!!'__";
		Sleep(2000);
		system("cls");
		librarianMenu();
	}
	
	cout << "\t\t__'THIS BORROWER DOES NOT EXIST!!'__\n";
	Sleep(1000);
	system("cls");
	
	
	//getting user inputs to add borrower(Name, phoneNo, email, address) 
	cout << "\n\n\t|#######################|-'ADD BORROWERS'-|#########################################|\n\n";
	cout << "\t\tNAME\t\t: ";
	cin.ignore();
	getline(cin, name);
	
	
	while(true){
		cout << "\t\tPHONE NUMBER\t: ";
		getline(cin, phoneNo);
	
		if(phoneNo.length()!=10){
			cout << "\t\tINVALID PHONE NUMBER.TRY AGAIN!!";
			continue;	
		}
		else{
			break;
		}
	}
	
	cout << "\t\tE MAIL\t\t: ";
	getline(cin, email);;
	cout << "\t\tADDRESS\t\t: ";
	getline(cin, address);;
	cout << "\n\t|################################################################################|\n\n";
	
	//create object called BorrowerFileWrite from fstream class.
	fstream BorrowerFileWrite;
	
	BorrowerFileWrite.open("borrower.dat",ios::app);
	 
	if(!BorrowerFileWrite){
		cout << "\t\tFile cannot be opened!!";
	}
	else{
		//get current date
		time_t now = time(0);
		tm *ltm = localtime(&now);
		
		int year = 1900 + ltm->tm_year;
		int month = 1 + ltm->tm_mon;
		int day = ltm->tm_mday;
		
		transform(name.begin(), name.end(), name.begin(),::toupper);
		transform(email.begin(), email.end(), email.begin(),::toupper);
		transform(address.begin(), address.end(), address.begin(),::toupper);
		
		BorrowerFileWrite << borrowerID << "|" << name << "|" << phoneNo << "|" << email << "|" << address << "|" << year << "/" << month << "/" << day << "|" << 0 << "|" << librarianBookRecord << "\n";
		BorrowerFileWrite.close();
		
		//intialize the string
		string S = "\t\t\tTHE BORROWER SUCCESSFULLY ADDED!!\n";	
		//Travers the given string S
		for(int i = 0; i < S[i]; i++){
			cout << S[i];
			Sleep(100);
		}
			
		Sleep(2000);
		system("cls");
		librarianMenu();
	}

}


void deleteBorrowers(){
	int deletedCount = 0;
	string eraseTarget;
	
	cout << "\n\n\t |#######################|-'DELETE BORROWERS'-|################################|\n\n";
	cout << "\t\tENTER ID/NAME\t: ";
	cin.ignore();
	getline(cin, eraseTarget);
	cout << "\n\t |############################################################################|\n\n";
	
	//convert inputs to lowercase for case-insensitive comparison
	transform(eraseTarget.begin(), eraseTarget.end(), eraseTarget.begin(), ::tolower);
	
	fstream BorrowerFile, TempFile;
	BorrowerFile.open("borrower.dat", ios::in);
	TempFile.open("temp.dat", ios::out);
	
	if(!BorrowerFile.is_open()){
		"\t\t\tFILE OPENINING ERROR!!!\n";
		cout << "\t\tPress any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
	
	string line;
	while(getline(BorrowerFile, line)){
		string borrowerID, name;
		istringstream iss(line);
		getline(iss, borrowerID, '|');
		getline(iss, name, '|');
	
		//convert details to lowercase for case-insensitive comparison
		transform(borrowerID.begin(), borrowerID.end(), borrowerID.begin(), ::tolower);
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		
		//check whether the file matches eraseTarget
		if(eraseTarget==borrowerID||eraseTarget==name){
			deletedCount++;
		}
		else{
			TempFile << line << "\n";	//write to the temporary file if it's not the target borrower
		}
	}
	
	BorrowerFile.close();
	TempFile.close();
	
	remove("borrower.dat");
	rename("temp.dat","borrower.dat");
	
	if(deletedCount>0){
		//intialize the string
		string S = "\t\t\tTHE BORROWER DELETED SUCCESSFULLY !!\n";	
		//Travers the given string S
		for(int i = 0; i < S[i]; i++){
			cout << S[i];
			Sleep(100);
		}
			
		Sleep(2000);
		cout << "\n\n\t\tPress any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
	
	else{
		cout << "\t\tBORROWER NOT FOUND!!!\n";
		Sleep(2000);
		cout << "\n\t\tPress any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
}


void searchBorrowers(){
	string userInput;
	cout << "\n\n\t |#######################|-'SEARCH BORROWERS'-|##############################|\n\n";
	cout << "\tENTER BORROWER ID/NAME/PHONE NUMBER/EMAIL/ENTERED LIBRARIANS' ID: ";
	cin.ignore();
	getline(cin,userInput);
	cout << "\n\t |############################################################################|\n\n";

	transform(userInput.begin(),userInput.end(),userInput.begin(),::tolower);	//converting user input to lowercase <algorithm>
	
	//read borrower.dat file and get the line by line
    
    fstream BorrowerFile;
    BorrowerFile.open("borrower.dat",ios::in);
    
    int matchCount = 0;	//This is a counter for found borrower.
    
    //search matching items for the userInput
    if(BorrowerFile.is_open()){
    	string line;
    	string borrowerID,name,phoneNo,email,address,joinedDate,brrCount,librarian;
    	while(getline(BorrowerFile,line)){
    		istringstream iss(line);
    		getline(iss,borrowerID,'|');
    		getline(iss,name,'|');
    		getline(iss,phoneNo,'|');
    		getline(iss,email,'|');
    		getline(iss,address,'|');
    		getline(iss,joinedDate,'|');
    		getline(iss, brrCount, '|');
    		getline(iss,librarian,'|');
    		
    		//converting all the informations to lowercase 
			transform(borrowerID.begin(),borrowerID.end(),borrowerID.begin(),::tolower);
			transform(name.begin(),name.end(),name.begin(),::tolower);
			transform(email.begin(),email.end(),email.begin(),::tolower);
			transform(address.begin(),address.end(),address.begin(),::tolower);
			transform(librarian.begin(),librarian.end(),librarian.begin(),::tolower);
			
			if(userInput==borrowerID||userInput==name||userInput==phoneNo||userInput==email||userInput==address||userInput==librarian){
				matchCount++;	//increment the counter when match is found
				cout << "\t-----------------------------------------------------------------------------\n";
				cout << "\t\t\tBORROWER ID\t\t\t: " << borrowerID << endl;
				cout << "\t\t\tNAME\t\t\t\t: " << name << endl;
				cout << "\t\t\tPHONE NUMBER\t\t\t: " << phoneNo << endl;
				cout << "\t\t\tE-MAIL ADDRESS\t\t\t: " << email << endl;
				cout << "\t\t\tADDRESS\t\t\t\t: " << address << endl;
				cout << "\t\t\tJOINED DATE\t\t\t: " << joinedDate << endl;
				cout << "\t\t\tBORROWED COUNT\t\t\t: " << brrCount << endl;
				cout << "\t\t\tTHE BORROWER ENTERED BY\t\t: " << librarian << endl;
				cout << "\t-----------------------------------------------------------------------------\n";
			}
		}
		
		if(matchCount==0){
			char opt = '0';
			cout << "\n\n\t\t\tTHIS BORROWER IS NOT FOUND!!!\n\n";
			cout << "\n\t\tDO YOU WANT TO SEARCH ANOTHER BORROWER(y/n)?";
			cin >> opt;
			
			if(opt=='y'||opt=='Y'){
				system("cls");
				searchBorrowers();
			}
			
			else if(opt=='n'||opt=='N'){
				system("cls");
				librarianMenu();
			}
			
			else{
				cout << "\n\t\t\tINVALID INPUT!!!\n";
				cout << "\n\t\tPress any key to return Librarian Menu";
				getch();
				system("cls");
				librarianMenu();
			}
		}
		
	}
	
	else{
		cout << "\t\t\tFILE IS NOT OPENED!!!\n";
		Sleep(1000);
		cout << "\n\t\t_'Press any key to return librarian Menu'_";
		getch();
		system("cls");
		librarianMenu();
	}
	
	BorrowerFile.close();
	cout << "\n\t\t_'Press any key to return librarian Menu'_";
	getch();
	system("cls");
	librarianMenu();
}



void updateBorrowers(){
	string updateTarget;
	cout << "\n\n\t |##############################|-'UPDATE BORROWERS'-|###############################|\n\n";
	cout << "\t\tENTER THE BORROWER ID/NAME TO UPDATE\t: ";
	cin.ignore();
	getline(cin, updateTarget);
	cout << "\n\t |###################################################################################|\n\n";
	 
	//convert the usser's input to lowercase
	transform(updateTarget.begin(), updateTarget.end(), updateTarget.begin(), ::tolower);
	
	//open original Borrower File for reading and TempFile for writing
	fstream BorrowerFile, TempFile;
	BorrowerFile.open("borrower.dat",ios::in);
	TempFile.open("temp.dat",ios::out);
	
	//check if the borrower file is successfully opened
	if(!BorrowerFile.is_open() && !TempFile.is_open()){
		cout << "\t\t\tFILE OPENINING ERROR!!!\n";
		cout << "\n\t\tPress any key to return Librarian Menu";
		getch();
		system("cls");
		librarianMenu();
	}
	
	int updatedCount = 0;
	string line;	//variable that store each line of the borrower file
	
	//read each line of the borrower file
	while(getline(BorrowerFile,line)){
		
		//variables to store the details of the each borrower
		string borrowerID,name,phoneNo,email,address,joinedDate,brrCount,librarian;
		
		istringstream iss(line);
		//extract borrower details to variables
		getline(iss, borrowerID, '|');
		getline(iss, name, '|');
		getline(iss, phoneNo, '|');
		getline(iss, email, '|');
		getline(iss, address, '|');
		getline(iss, joinedDate, '|');
		getline(iss, brrCount, '|');
		getline(iss, librarian, '|');
		
		//convert borrower id,name to lowercase
		transform(borrowerID.begin(), borrowerID.end(), borrowerID.begin(), ::tolower);
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		
		//check if the current borrower matches to the users' Target 
		if(updateTarget==borrowerID||updateTarget==name){
			updatedCount++;
			char choice = '0';
			
			int opt = 0;
			
			while(true){
				cout << "\n\t======================================================================================\n";
				cout << "\t|+++++++++++++++++++++++++++++-'UPDATE BORROWERS'-+++++++++++++++++++++++++++++++++++|\n\n";
				cout << "\t\t\t[1].NAME                                                                    \n";
				cout << "\t\t\t[2].PHONE NUMBER                                                            \n";
				cout << "\t\t\t[3].E-MAIL ADDRESS                                                          \n";
				cout << "\t\t\t[4].ADDRESS                               						             ";
				cout << "\t\t\t[5].BACK TO (SEARCH OR UPDATE BORROWER) MENU                  	  	       \n";
				cout << "\n\t======================================================================================\n\n";
				
				//get user input
				cout << "\t\tChoose an option: " ;
				cin >> opt;	
				
				if(opt < 1 || opt > 6){
					cout << "\n\n\t\t\tINVALID INPUT!!!\n";
					cout << "\n\t\tPress any key to re-enter";
					getch();
					system("cls");
					continue;
				}
				break;
			}
			
			if(opt == 1){
				//update name
				cout << "\n\t---------------------------------------------------------------------------------------\n";
				cout << "\t\tCURRENT NAME\t\t: " << name <<"\n\n";
				cout << "\n\t\tNEW NAME\t\t:";
				cin.ignore();
				getline(cin,name);	
				cout << "\t---------------------------------------------------------------------------------------\n";
				
			}
			else if(opt == 2){
				//update phone number
				cout << "\n\t---------------------------------------------------------------------------------------\n";
				cout << "\t\tCURRENT PHONE NUMBER \t\t: " << phoneNo <<"\n\n";
				cout << "\n\t\tNEW PHONE NUMBER \t\t:";
				cin.ignore();
				getline(cin,phoneNo);
				cout << "\t---------------------------------------------------------------------------------------\n";
						
			}
			else if(opt == 3){
				//update email
				cout << "\n\t---------------------------------------------------------------------------------------\n";
				cout << "\t\tCURRENT E-MAIL ADDRESS\t\t: " << email <<"\n\n";
				cout << "\n\t\tNEW E-MAIL ADDRESS\t\t:";
				cin.ignore();
				getline(cin,email);
				cout << "\t---------------------------------------------------------------------------------------\n";
			}
			else if(opt == 4){
				//update address
				cout << "\n\t---------------------------------------------------------------------------------------\n";
				cout << "\t\tCURRENT ADDRESS\t: " << address <<"\n\n";
				cout << "\n\t\tNEW ADDRESS\t:";
				cin.ignore();	
				getline(cin,address);
				cout << "\t---------------------------------------------------------------------------------------\n";
			}
			else if(opt == 5){
				system("cls");
				searchUpdateBorrowers();
			}
			
			//convert to uppercase
			transform(borrowerID.begin(), borrowerID.end(), borrowerID.begin(), ::toupper);
			transform(name.begin(), name.end(), name.begin(), ::toupper);
			transform(email.begin(), email.end(), email.begin(), ::toupper);
			transform(address.begin(), address.end(), address.begin(), ::toupper);
			
			//write the updated details to the temporary file
			TempFile << borrowerID << "|" << name << "|" << phoneNo << "|" << email << "|" << address << "|" << joinedDate << "|" << brrCount << "|" << librarian << "\n";
		
		}
		
		else{
			TempFile << line << "\n";
		}		
	}
	
	//close both files
	BorrowerFile.flush();
	BorrowerFile.close();
	
	TempFile.flush();
	TempFile.close();
	
	//delete BookFile and rename TempFile
	remove("borrower.dat");
	rename("temp.dat","borrower.dat");
	
	if(updatedCount > 0){
		
		char opt = '0';
		
		//intialize the string
		string S = "\n\t\t\tTHE BORROWER UPDATED SUCCESSFULLY!!\n";	
		//Travers the given string S
		for(int i = 0; i < S[i]; i++){
			cout << S[i];
			Sleep(100);
			
		}
		
		cout << "\n\t\t\tDo you want to (SEARCH/UPDATE) again?(y/n)\t: ";
		if(opt = 'y' || opt == 'Y'){
			system("cls");
			searchUpdateBorrowers();
		}
		else{
			system("cls");
			librarianMenu();
		}
	}
	
	else{
	cout << "\t\t\tBORROWER NOT FOUND!!\n";
	cout << "\n\t\tPress any key to (SEARCH/UPDATE) Menu again";
	getch();
	system("cls");	
	searchUpdateBorrowers();
	}
		
}

void showAllBorrowedDetails(){
	cout << "\n\n\t ++++++++++++++++++++++++++++++-DISPLAY All BORROWED DETAILS-++++++++++++++++++++++++++++++++++\n\n";
	fstream DisplayAllFile;
	DisplayAllFile.open("borrowingRec.dat", ios::in);
	string line;
	
	while(getline(DisplayAllFile,line)){
		istringstream iss(line);
		string brid,bookName,bookid,issuedDate,returnDate;
		getline(iss,brid,'|');
		getline(iss,bookName,'|');
		getline(iss,bookid,'|');
		getline(iss,issuedDate,'|');
		getline(iss,returnDate,'|');
		
		cout << "\t\tBORROWER ID\t:" << brid << endl;
		cout << "\t\tBOOK TITLE\t:" << bookName << endl;
		cout << "\t\tBOOK ID\t\t:" << bookid << endl;
		cout << "\t\tISSUED DATE\t:" << issuedDate << endl;
		cout << "\t\tRETURN DATE\t:" << returnDate << endl;
		cout << "\n\n\t\t------------------------------------------------------------------\n\n";
	}
	cout << "Press Any Key to return Librarians' Menu";
	getch();
	system("cls");
	librarianMenu();	
}
