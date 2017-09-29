#include<iostream>
#include<fstream>
#include<cstdlib>
#include "client.h"

//Global Variables
int numClients=0;


//Function For Adding Clients
void addClients(client cl[]);


//Function For Writing Client Information To File
void writeClientsToFile(client cl[]);

//Function For loading Client Information From File
void loadClients(client []);

//Function to display all clients information
void displayClients(client []);


//A Function That Returns A client Given his Account Number
client * GetClientFromAccount(client [],int);

//Function Withdraw
void withdraw(client *);

//Function Deposit
void deposit(client *);

//Function For displaying the menu
int menu();

//Function For displying the mini menu
int minimenu();

//Function For displaying the summary


int main()
{
	int j=0;
	int choice;
	client clients[100];
	loadClients(clients);
	do
	{
		system("CLS");
		choice=menu();
		switch(choice)
		{
			case 1:
				addClients(clients);
				writeClientsToFile(clients);
				break;
			case 2:
				if(numClients==0)
				{
				cout<<"Oops, There are no clients, You must add clients First\n";
				break;
				}
				else
				{
					system("CLS");
					int choice;
					choice=minimenu();
					switch(choice)
					{
						case 1:
							displayClients(clients);
							system("PAUSE");
							break;
						case 2:
							{
								client * cl;
								int accountNumber;
								cout<<"Enter the Clients Account Number: ";
								cin>>accountNumber;
								cl=GetClientFromAccount(clients,accountNumber);
								if(cl==NULL)
								{
									cout<<"Account Doesn't Exist!\n";
									system("PAUSE");
								}
								else
								{
								cout<<"Client with Account: "<<accountNumber<<endl<<"First Name: "<<cl->fname
									<<"\nLast Name: "<<cl->lname<<"\nChecking Balance: $"<<cl->checkingBalance
									<<"\nSaving Balance: $"<<cl->savingBalance<<endl<<endl;
								system("PAUSE");
								}
								break;
							}
							
						default:
							cout<<"\nInvalid Selection, Please Try Again!\n";
							system("PAUSE");
							break;
							
							
							
					}
					break;
				}
			case 3:
				{
				client * cl;
				int accountNumber;
				cout<<"Enter the Clients Account Number: ";
				cin>>accountNumber;
				cl=GetClientFromAccount(clients,accountNumber);
				if(cl==NULL)
				{
					cout<<"Invalid Account, Please try again!\n";
					system("PAUSE");
				}
				else
				{
					withdraw(cl);	
				}
				writeClientsToFile(clients);
				break;
				}
			case 4:
				{
				client * cl;
				int accountNumber;
				cout<<"Enter the Clients Account Number: ";
				cin>>accountNumber;
				cl=GetClientFromAccount(clients,accountNumber);
				if(cl==NULL)
				{
					cout<<"Invalid Account, Please try again!\n";
					system("PAUSE");
				}
				else
				{
					deposit(cl);	
				}
				writeClientsToFile(clients);
				break;
				}
				
			case 5:
				cout<<"Good bye, see you later\n";
				system("PAUSE");
				break;
			
			default:
				cout<<"\nInvalid Selection, Please Try Again!\n";
				system("PAUSE");
				break;
				
		}
	}while(choice!=5);
	return 0;
	
	
	
}


//Function For displaying The Menu
int menu()
{
	int choice;
	cout<<"==========Menu==========\n"
		<<"1. Add Clients\n"
		<<"2. Display Clients Information\n"
		<<"3. Withdraw\n"
		<<"4. Deposit\n"
		<<"5. Exit\n"
		<<"Enter your choice: ";
	cin>>choice;
	return choice;
}

//Function for displaying the mini menu
int minimenu()
{
	int choice;
	cout<<"==========Menu==========\n"
		<<"1. Display All Clients\n"
		<<"2. Display 1 Client\n"
		<<"Enter your choice: ";
	cin>>choice;
	return choice;
}


//Function For adding Clients
void addClients(client cl[])
{
	int size,i;
	cout<<"Enter the number of clients you want to add: ";
	cin>>size;
	for(i=0;i<size;i++)
	{
			system("CLS");
			cout<<"Enter Client #"<<(i+1)<<" Information\n"
				<<"Enter the first name: ";
			cin>>cl[i+numClients].fname;
			cout<<"Enter the last name: ";
			cin>>cl[i+numClients].lname;
			cout<<"Enter the Account Number: ";
			cin>>cl[i+numClients].accountNumber;
			cout<<"Enter the Checking Balance: ";
			cin>>cl[i+numClients].checkingBalance;
			cout<<"Enter the Saving Balance: ";
			cin>>cl[i+numClients].savingBalance;
			cout<<endl<<endl;
	}
	numClients=numClients+size;
}

//Function For Writing Client Information To File
void writeClientsToFile(client cl[])
{
	int i=0;
	ofstream outfile;
	outfile.open("clients.txt");
	if(outfile.is_open())
	{
		do
		{
			outfile<<cl[i].accountNumber<<" "<<cl[i].fname
					<<" "<<cl[i].lname<<" "<<cl[i].checkingBalance
					<<" "<<cl[i].savingBalance<<endl;
			i++;
		}while(i<numClients);
		
	}
	outfile.close();
}

//Function For loading Client Information From File
void loadClients(client cl[])
{
	int i=0;
	ifstream inData;
	inData.open("clients.txt");
	if(inData.is_open())
	{
		while(!inData.eof())
		{
			inData>>cl[i].accountNumber;
			inData>>cl[i].fname;
			inData>>cl[i].lname;
			inData>>cl[i].checkingBalance;
			inData>>cl[i].savingBalance;
			i++;
		}
		numClients=i-1;
	}
}

//Function to display all clients information
void displayClients(client clients[])
{
	if(numClients==0)
	{
		cout<<"Oops, There are no clients, You must add clients First\n";
	}
	else
	{
		cout<<"==========Display Client Summary=========\n\n";
		int j;
		for(j=0;j<numClients;j++)
		{
			cout<<"Client #"<<(j+1)<<endl<<"First Name: "<<clients[j].fname<<"\nLast Name: "
				<<clients[j].lname<<"\nChecking Balance: "<<clients[j].checkingBalance
				<<"\nSaving Balance: "<<clients[j].savingBalance
				<<"\nAccount Number: "<<clients[j].accountNumber<<endl<<endl;
		}
	}
}

client * GetClientFromAccount(client clients[],int accountNumber)
{
	int i=0;
	client * pcl;
	for(i=0;i<numClients;i++)
	{
		if(clients[i].accountNumber==accountNumber)
		{
			pcl=&clients[i];
		}
		
	}
	return pcl;
}


//Function Withdraw
void withdraw(client * cl)
{
	int select;
	double withdraw;
	cout<<"Choose From the following Options: \n"
			<<"1. Checking \n"
			<<"2. Saving \n"
			<<"Your choice is: ";
	cin>>select;
	if(select==1)
	{
		cout<<"Enter the amount to withdraw: $";
		cin>>withdraw;
		if(withdraw>cl->checkingBalance || withdraw<0)
		{
			cout<<"Wrong amount,  can't be withdrawn: \n";
			system("PAUSE");
		}
		else
		{
		cl->checkingBalance=cl->checkingBalance-withdraw;
		}
	}
	else
	{
		if(select==2)
		{
			cout<<"Enter the amount to withdraw: $";
			cin>>withdraw;
			if(withdraw>cl->savingBalance || withdraw<0)
			{
			cout<<"Wrong amount,  can't be withdrawn: \n";
			system("PAUSE");
			}
			else
			{
			cl->savingBalance=cl->savingBalance-withdraw;
			}
		}
		else
		{
			cout<<"invalid selection, please try again\n";
			system("PAUSE");
		}
	}
	
		
}

//Function Deposit
void deposit(client * cl)
{
	double deposit;
	int select;
	cout<<"Enter the amount to deposit: $ ";
	cin>>deposit;
	if(deposit<0)
	{
		cout<<"wrong amount, can't deposit a negative value\n";
		system("PAUSE");
	}
	else
	{
		cout<<"Choose From the following Options: \n"
			<<"1. Checking \n"
			<<"2. Saving \n"
			<<"your choice is: ";
		cin>>select;
		if(select==1)
		cl->checkingBalance=cl->checkingBalance+deposit;
		else
		{
			if(select==2)
			cl->savingBalance=cl->savingBalance+deposit;
			else
			{
				cout<<"invalid selection, please try again\n";
				system("PAUSE");
			}
		}
		
	}
}
