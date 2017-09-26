struct course
{
	int courseId;
	string courseName;
	int credits;
};
void SetCourseId(course * cou,int id)
{
	cou->courseId=id;
}
void SetCourseName(course * cou,string name)
{
	cou->courseName=name;
}
void SetCredits(course * cou,int credit)
{
	cou->credits=credit;
}
int GetCourseId(course * cou)
{
	return cou->courseId;
}
string GetCourseName(course * cou)
{
	return cou->courseName;
}
int GetCredits(course * cou)
{
	return cou->credits;
}

