struct session
{
	int sessionId;
	int studentId;
	int courseId;
	string startDate;
	string endDate;
}; 
void SetSessionId(session * ses,int id)
{
	ses->sessionId=id;
}
void SetStudentId(session * ses,int id)
{
	ses->studentId=id;
}
void SetCourseId(session * ses,int id)
{
	ses->courseId=id;
}
void SetStartDate(session * ses,string date)
{
	ses->startDate=date;
}
void SetEndDate(session * ses,string date)
{
	ses->endDate=date;
}
int GetSessionId(session * ses)
{
	return ses->sessionId;
}
int GetStudentId(session * ses)
{
	return ses->studentId;
}
int GetCourseId(session * ses)
{
	return ses->courseId;
}
string GetStartDate(session * ses)
{
	return ses->startDate;
}
string GetEndDate(session * ses)
{
	return ses->endDate;
}

