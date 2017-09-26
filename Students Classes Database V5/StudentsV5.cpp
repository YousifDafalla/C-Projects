//Student Courses Database
//Author: Yousif Dafalla
//File System Included
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
#include "Student.h"
#include "Courses.h"
#include "Session.h"

const string list[10]={"First","Second","Third","Fourth","Fifth","Sixth","Seventh","Eighth","Ninth","Tenth"};

//Function for loading initial data
//void loadData();

//Function for entering student information
void fillStudents(student *,int);

//Function for entering courses information
void fillCourses(course *,int);

//Function for entering session information
void fillSessions(session *,int);


//Function for writing student data to the file Students
void writeStudentsToFile(student stu[],int);

//Function for reading students data from file Students
void readStudentsFromFile(student stu[],int *);

//Functin for writing course data to the file Courses
void writeCoursesToFile(course [],int);


//Function for reading data from file Courses
void readCoursesFromFile(course cou[],int *);

//Function for reading data from file Sessions
void readSessionsFromFile(session sess[],int*);


//Function for writing session data to the file Sessions
void writeSessionsToFile(session sess[],int);

//Function for reading data from session file
void readSessionsFromFile(session sess[],int*);

//load data funcitons
void loadData(student [],course [],session [],int *,int *,int *);
//display students
//void displayStudents(student [],int);


//display courses
//void displayCourses(course cou[],int);

//void displaySummary(s) displays each student with the courses enrolled in
void displaySummary(session *,student *,course *,int,int,int);

int menu();
int main()
{
	int choice;
	int studentCount=0,courseCount=0,sessionCount=0;
	int numberOfStudents,numberOfCourses,numberOfSessions;
	bool exit=false,stuDef=false,couDef=false,sesDef=false;
	student students[20];
	course courses[20];
	session sessions[20];
	loadData(students,courses,sessions,&studentCount,&courseCount,&sessionCount);
	if(studentCount>0)
	stuDef=true;
	//readCoursesFromFile(courses,&courseCount);
	if(courseCount>0)
	couDef=true;
	//readSessionsFromFile(sessions,&sessionCount);
	if(sessionCount>0)
	sesDef=true;
	//displayStudents(students,studentCount);
	
	//system("PAUSE");
	
	for(;;)
	{
		system("CLS");
		choice=menu();
		switch(choice)
		{
			case 1:
				{
				system("CLS");
				cout<<"\tADD Students Information\n";
				cout<<"Enter the number of students: ";
				cin>>numberOfStudents;
				student tempStudents[numberOfStudents];
				fillStudents(tempStudents,numberOfStudents);
				writeStudentsToFile(tempStudents,numberOfStudents);
				readStudentsFromFile(students,&studentCount);
				//This part was for testing and debugging purposes
				//readStudentsFromFile(students,&studentCount);//additional lines must be removed
				//displayStudents(students,studentCount);// additional lines must be removed
				//system("PAUSE");//additional line must be removed
				stuDef=true;
				break;
				}
			case 2:
				{
				system("CLS");
				cout<<"\tCourses Information\n";
				cout<<"Enter the number of Courses to add: ";
				cin>>numberOfCourses;
				course tempCourses[numberOfCourses];
				fillCourses(tempCourses,numberOfCourses);
				writeCoursesToFile(tempCourses,numberOfCourses);
				readCoursesFromFile(courses,&courseCount);
				//This code was used for debugging purposes
				//readCoursesFromFile(courses,&courseCount);
				//displayCourses(courses,courseCount);
				//system("PAUSE");
				couDef=true;
				break;
				}
			case 3:
				{
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
					cout<<"Enter the number of Sessions to add: ";
					cin>>numberOfSessions;
					session tempSessions[numberOfSessions];
					fillSessions(tempSessions,numberOfSessions);
					writeSessionsToFile(tempSessions,numberOfSessions);
					readSessionsFromFile(sessions,&sessionCount);
					sesDef=true;
					break;
				}
				
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
				displaySummary(sessions,students,courses,studentCount,sessionCount,courseCount);
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
	cout << " 1. ADD Students"<<endl;
	cout << " 2. ADD Courses"<<endl;
	cout << " 3. Assign Courses to Students"<<endl;
	cout << " 4. Display Summary"<<endl;
	cout << " 5. Exit"<<endl;
	cout << "Enter an option: ";
	cin >> choice;
	return choice;
}

//Function for filling the sessions
void fillSessions(session * sess,int size)
{
	for(int i=0;i<size;i++)
	{
		system("CLS");
		cout<<"\tEnter the "<<list[i]<<" Session Information\n";
		cout<<"Enter Session Id ";
		cin>>(sess+i)->sessionId;
		cout<<"Enter Student Id ";
		cin>>(sess+i)->studentId;
		cout<<"Enter the Course Id ";
		cin>>(sess+i)->courseId;
		cout<<"Enter the Start Date (mm/yy) ";
		cin>>(sess+i)->startDate;
		cout<<"Enter the End Date (mm/yy) ";
		cin>>(sess+i)->endDate;
	}
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
		//This part is nice but it won't work with this version of my code
		//cin.ignore();
		//getline(cin,(cou+i)->courseName);
		cin>>(cou+i)->courseName;
		cout<<"Enter the number of credits for this course: ";
		cin>>(cou+i)->credits;
	}
}


//Function for writing Students Data to a file
void writeStudentsToFile(student stu[],int size)
{
	int i;
	ofstream outfile;
	outfile.open("Students.txt",ios::app);
	if(outfile.tellp()!=0)
	outfile<<"\n";
	for(i=0;i<size;i++)
	{
		outfile<<stu[i].studentId<<" "<<stu[i].fname
				<<" "<<stu[i].lname<<"\n";
	}
	outfile.close();
}

//Function Writing Courses to file
void writeCoursesToFile(course cou[],int size)
{
	int i;
	ofstream outfile;
	outfile.open("Courses.txt",ios::app);
	if(outfile.tellp()!=0)
	outfile<<"\n";
	for(i=0;i<size;i++)
	{
		outfile<<cou[i].courseId<<" "<<cou[i].courseName
				<<" "<<cou[i].credits<<"\n";
	}
	outfile.close();
}

//Funtioin for writing session data to file
void writeSessionsToFile(session sess[],int size)
{
	int i;
	ofstream outfile;
	outfile.open("Sessions.txt",ios::app);
	if(outfile.tellp()!=0)
	outfile<<"\n";
	for(i=0;i<size;i++)
	{
		outfile<<sess[i].sessionId<<" "<<sess[i].studentId
				<<" "<<sess[i].courseId<<" "<<sess[i].startDate
				<<" "<<sess[i].endDate<<"\n";
	}
	outfile.close();
}

//Function To read Students From File
void readStudentsFromFile(student stu[],int * pCount)
{
	ifstream inData;
	int i=0;//added line should be deleted
	*pCount=0;
	inData.open("Students.txt");
	if(inData.is_open())
	{
		while(!inData.eof())
		{
			inData>>stu[i].studentId;
			inData>>stu[i].fname;
			inData>>stu[i].lname;
			i++;//added lines should be deleted
			*pCount=*pCount+1;
		}
		*pCount=*pCount-1;
	}
}

//Function to read Courses from file
void readCoursesFromFile(course cou[],int * count)
{
	ifstream inData;
	int i=0;
	*count=0;
	inData.open("Courses.txt");
	if(inData.is_open())
	{
		while(!inData.eof())
		{
			inData>>cou[i].courseId;
			inData>>cou[i].courseName;
			inData>>cou[i].credits;
			i++;
			*count=*count+1;
		}
		*count=*count;
	}
}


//Function to read sessions from file
void readSessionsFromFile(session sess[],int * count)
{
	ifstream inData;
	int i=0;
	*count=0;
	inData.open("Sessions.txt");
	if(inData.is_open())
	{
		while(!inData.eof())
		{
			inData>>sess[i].sessionId;
			inData>>sess[i].studentId;
			inData>>sess[i].courseId;
			inData>>sess[i].startDate;
			inData>>sess[i].endDate;
			i++;
			*count=*count+1;
		}
		*count=*count;
	}
	
}

//Function load data
void loadData(student stu[],course cou[],session sess[],int *studentCount,int *courseCount,int *sessionCount)
{
	readStudentsFromFile(stu,studentCount);
	readCoursesFromFile(cou,courseCount);
	readSessionsFromFile(sess,sessionCount);
}


//Display summary
void displaySummary(session * sessions,student * students,course * courses,int numberOfStudents,
int numberOfSessions,int numberOfCourses)
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
		if(count==0)
		cout<<"No courses Assigned for this student!\n";
		cout<<"Total Number of credits: "<<credits;
		cout<<endl<<endl;
	}
	system("PAUSE");
}


