//Banking Part 2
//Test the algorithms
//Author: Yousif Dafalla
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

//Menu is a function that displays the menu
int menu();

//This function is used to create the account in this case it is only one account
void createAccount(string *,string *,int *);

//Function For Withdraw
void withdraw(double *);

//Functin For Deposit
void deposit(double *);

//This is the main function
int main()
{
	int choice,select,option;
	bool accountCreated;
	double checkingBalance=0,savingBalance=0;
	string fname,lname;
	int accountNumber;
	do
	{
		choice=menu();
		switch(choice)
		{
			case 1:
				createAccount(&fname,&lname,&accountNumber);
				accountCreated=true;
				break;
			case 2:
				if(accountCreated==false)
				{
					cout<<"Oops, You need to create an acount first!\n";
					break;
				}
				else
				{
					do
					{
						system("CLS");
						cout<<"==========Withdraw===========\n";
						cout<<"\tChoose from the following options\n";
						cout<<"1. Checking\n";
						cout<<"2. Saving\n";
						cout<<"Enter your choice: ";
						cin>>select;
						//This next part of the code is divided in two parts
						//The first part deals with a right choice for either withdraw or
						//deposit
						if(select==1 || select==2)
						{
						system("CLS");
						cout<<"==========Withdraw===========\n";
						cout<<"\tChoose from the following options\n";
						cout<<"1. Withdraw\n";
						cout<<"2. Deposit\n";
						cout<<"Enter your choice: ";
						cin>>option;
						if(option==1)
						{
							if(select==1)
							withdraw(&checkingBalance);
							else
							withdraw(&savingBalance);
							
						}
						else
						{
							if(option==2)
							{
								if(select==1)
								deposit(&checkingBalance);
								else
								deposit(&savingBalance);
							}
							else
							cout<<"Invalid, Choice Try again!\n";
							
						}	
						}
						else
						{
							cout<<"Invalid selection, try again \n";
							select=0;
							system("PAUSE");
						}
					}while(select==0);
					break;
				}
			case 3:
				cout<<"First Name: "<<fname<<endl;
				cout<<"Last Name: "<<lname<<endl;
				cout<<"Account Number: "<<accountNumber<<endl;
				cout<<"Checking Balance: $"<<checkingBalance<<endl;
				cout<<"Saving Balance: $"<<savingBalance<<endl;
				break;
			case 4:
				cout<<"Goodbye, see you later. \n";
				break;
			default:
				cout<<"Error invalid, Option Enter another option";				
		}
		system("PAUSE");
	}while(choice!=4);
	system("PAUSE");
	return 0;
}

int menu()
{
	int choice;
	system("CLS");
	cout<<"==========Main Menu===========\n";
	cout<<"\tChoose from the following options\n";
	cout<<"1. Create an accout\n";
	cout<<"2. Apply Transaction\n";
	cout<<"3. Display account information\n";
	cout<<"4. Exit \n"; 
	cout<<"Enter your choice: ";
	cin>>choice;
	return choice;
}


void createAccount(string * firstName,string * lastName,int * acc)
{
	system("CLS");
	cout<<"Enter the first name: ";
	cin>>(*firstName);
	cout<<"Enter the last name: ";
	cin>>*lastName;
	cout<<"Enter the account number: ";
	cin>>*acc;
}

//Function For Withdraw
void withdraw(double * balance)
{
	double withdraw;
	cout<<"Enter the amount to withdraw: $ ";
	cin>>withdraw;
	if(withdraw>*balance || withdraw<0)
	{
		cout<<"Wrong amount,  can't be withdrawn: \n";
	}
	else
	{
		*balance=*balance-withdraw;
	}
	
}

//Function For deposit
void deposit(double * balance)
{
	double deposit;
	cout<<"Enter the amount to deposit: $ ";
	cin>>deposit;
	if(deposit<0)
	{
		cout<<"wrong amount, can't deposit a negative value\n";
	}
	else
	{
		*balance=*balance+deposit;
	}
}
