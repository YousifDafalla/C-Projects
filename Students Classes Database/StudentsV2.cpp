//Student Courses Database
//Author: Yousif Dafalla
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
#include "Student.h"
#include "Courses.h"
#include "Session.h"

const string list[16]={"First","Second","Third","Fourth","Fifth","Sixth","Seventh","Eighth","Ninth","Tenth","eleventh","twelvth",
"Thirteenth","Fourteetnh","Fifteenth","sixteenth"};

//Function for entering student information
void fillStudents(student *,int);

//Function for entering courses information
void fillCourses(course *,int);

//Function for entering session information
void fillSessions(session *,student *,int,int *);

//void displaySummary(s) displays each student with the courses enrolled in
void displaySummary(session *,student *,course *,int,int,int);

int menu();
int main()
{
	int choice;
	int numberOfStudents,numberOfCourses,numberOfSessions;
	bool exit=false,stuDef=false,couDef=false,sesDef=false;
	student students[20];
	course courses[20];
	session sessions[20];
	for(;;)
	{
		system("CLS");
		choice=menu();
		switch(choice)
		{
			case 1:
				system("CLS");
				cout<<"\tEnter Students Information\n";
				cout<<"Enter the number of students: ";
				cin>>numberOfStudents;
				fillStudents(students,numberOfStudents);
				stuDef=true;
				break;
			case 2:
				system("CLS");
				cout<<"\tCourses Information\n";
				cout<<"Enter the number of Courses: ";
				cin>>numberOfCourses;
				fillCourses(courses,numberOfCourses);
				couDef=true;
				break;
			case 3:
				system("CLS");
				if(stuDef==false)
				{
					cout<<"Error! There are no students defined.\nYou have to define Students first\n\n";
					system("PAUSE");
					break;
				}
				if(couDef==false)
				{
					cout<<"There is no courses defined\n";
					system("PAUSE");
					break;
				}
				cout<<"\tAssigning Courses To Students\n";
				fillSessions(sessions,students,numberOfStudents,&numberOfSessions);
				sesDef=true;
				break;
				
			case 4:
				if(stuDef==false)
				{
					cout<<"Error! There are no students defined.\nYou have to define Students first\n\n";
					system("PAUSE");
					break;
				}
				if(couDef==false)
				{
					cout<<"Error! There are no courses defined.\nYou have to define Courses first\n\n";
					system("PAUSE");
					break;
				}
				if(sesDef==false)
				{
					cout<<"Error! There are no courses assigned to students yet.\nYou have to assign courses to Students First\n\n";
					system("PAUSE");
					break;
				}
				cout<<"============Summary\n";
				displaySummary(sessions,students,courses,numberOfStudents,numberOfSessions,numberOfCourses);
				break;
				
			case 5:
				exit=true;
				break;
			default:
				cout<<"Oops Wrong option, Please enter another value"<<endl;
				break;
		}
		if(exit==true)
		break;
	}
	return 0;
}
int menu()
{
	int choice;
	cout << "==========[MAIN MENU]=========="<<endl;
	cout << " 1. Create Students"<<endl;
	cout << " 2. Create Courses"<<endl;
	cout << " 3. Assign Courses to Students"<<endl;
	cout << " 4. Display Summary"<<endl;
	cout << " 5. Exit"<<endl;
	cout << "Enter an option: ";
	cin >> choice;
	return choice;
}

//Function for filling the sessions
void fillSessions(session * sess,student * stu,int size,int * ptrNumber)
{
	int numb=0,number,j;
	for(j=0;j<size;j++)
	{
		cout<<"Enter the numebr of Sessions for Student: "<<(stu+j)->fname
			<<" "<<(stu+j)->lname<<": ";
		cin>>number;
		for(int i=0;i<number;i++)
		{
			system("CLS");
			cout<<"\tEnter the "<<list[i+numb]<<" Session Information\n";
			cout<<"Enter Session Id: ";
			cin>>(sess+i+numb)->sessionId;
			(sess+i+numb)->studentId=(stu+j)->studentId;
			cout<<"Enter the Course Id: ";
			cin>>(sess+i+numb)->courseId;
			cout<<"Enter the Start Date (mm/yy): ";
			cin>>(sess+i+numb)->startDate;
			cout<<"Enter the End Date (mm/yy): ";
			cin>>(sess+i+numb)->endDate;
			system("CLS");
		}
		numb+=number;
	}
	*ptrNumber=numb;
}

//Function for filling in the students
void fillStudents(student * stu,int size)
{
	for(int i=0;i<size;i++)
	{
		system("CLS");
		cout<<"\tEnter the "<<list[i]<<" Student information \n ";
		cout<<"Enter Student ID: ";
		cin>>(stu+i)->studentId;
		cout<<"Enter the Student first name: ";
		cin>>(stu+i)->fname;
		cout<<"Enter the Student last name: ";
		cin>>(stu+i)->lname;
	}
}

//The function that fills the courses
void fillCourses(course * cou,int size)
{
	for(int i=0;i<size;i++)
	{
		system("CLS");
		cout<<"\tEnter the "<<list[i]<<" Course Information\n ";
		cout<<"Enter the Course Id ";
		cin>>(cou+i)->courseId;
		cout<<"Enter the Course Name: ";
		cin.ignore();
		getline(cin,(cou+i)->courseName);
		cout<<"Enter the number of credits for this course: ";
		cin>>(cou+i)->credits;
	}
}

//Display summary
void displaySummary(session * sessions,student * students,course * courses,int numberOfStudents,int numberOfSessions
,int numberOfCourses)
{
	int i,j,k;
	for(i=0;i<numberOfStudents;i++)
	{
		int count=0,credits=0;
		cout<<"\t"<<list[i]<<" Student Information\n";
		cout<<"Student "<<"Name: "<<(students+i)->fname<<" "<<(students+i)->lname<<"\n\n";
		cout<<"========= Courses Taken ==========\n";
		for(j=0;j<numberOfSessions;j++)
		{
			if((((students+i)->studentId))==(sessions+j)->studentId)
			{
				count++;
				cout<<count<<". ";
				//The next part of the code is for searching for the name of the course
				for(k=0;k<numberOfCourses;k++)
				{
					if((((sessions+j)->courseId))==((courses+k)->courseId))
					{
					cout<<(courses+k)->courseName<<endl;
					credits+=(courses+k)->credits;
					break;
					}
				}
			}
		}
		cout<<"Total Number of credits: "<<credits;
		cout<<endl<<endl;
	}
	system("PAUSE");
}


