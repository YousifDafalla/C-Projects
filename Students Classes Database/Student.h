struct student
{
	int studentId;
	std::string fname;
	std::string lname;
};
void SetId(student * stu,int id)
{
	stu->studentId=id;
}
void SetFirstName(student * stu,std::string name)
{
	stu->fname=name;	
}
void SetLastName(student * stu,string name)
{
	stu->lname=name;
}
int GetId(student * stu)
{
	return stu->studentId;
}
string GetFirstName(student * stu)
{
	return stu->fname;
}
string GetLastName(student * stu)
{
	return stu->lname;
}
