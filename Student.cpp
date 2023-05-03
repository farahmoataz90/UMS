#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
 inline Student::Student()
{
	this->ID = 0;
	this->AcademicYear = 0;
	this->MaxHoursAllowed = 0;
	this->GPA = 0;
	this->Name = "";
	this->Email = "";
	this->Password = "";
	this->FinishedCourses = nullptr;
	this->CoursesInProgress = nullptr;
}

Student::Student(int ID, int AcademicYear, int MaxHoursAllowed, float GPA, String^ Name, String^ Email, String^ Password, List<String^>^ FinishedCourses, List<String^>^ CoursesInProgress)
{
	this->ID = ID;
	this->AcademicYear = AcademicYear;
	this->MaxHoursAllowed = MaxHoursAllowed;
	this->GPA = GPA;
	this->Name = Name;
	this->Email = Email;
	this->Password = Password;
	this->FinishedCourses = FinishedCourses;
	this->CoursesInProgress = CoursesInProgress;
}

void Student::setName(String^ Name)
{
	this->Name = Name;
}

void Student::setAcademicYear(int AcademicYear)
{
	this->AcademicYear = AcademicYear;
}

void Student::setEmail(String^ Email)
{
	this->Email = Email;
}

void Student::setPassword(String^ Password)
{
	this->Password = Password;
}

void Student::setID(int ID)
{
	this->ID = ID;
}

void Student::setCoursesINProgress(List<String^>^ CoursesInProgress)
{
	this->CoursesInProgress = CoursesInProgress;
}

void Student::setFinishedCourses(List<String^>^ FinishedCourses)
{
	this->FinishedCourses = FinishedCourses;
}

void Student::setCoursesGPA(List<float>^ coursesGPA)
{
	this->coursesGPA = coursesGPA;
}

void Student::setMaxHoursAllowed(int MaxHoursAllowed)
{
	this->MaxHoursAllowed = MaxHoursAllowed;
}

void Student::setGPA(float GPA)
{
	this->GPA = GPA;
}

String^ Student::getName()
{
	return Name;
}

int Student::getAcademicYear()
{
	return AcademicYear;
}

String^ Student::getEmail()
{
	return Email;
}

String^ Student::getPassword()
{
	return Password;
}

int Student::getID()
{
	return ID;
}

List<String^>^ Student::getCoursesINProgress()
{
	return CoursesInProgress;
}

List<String^>^ Student::getFinishedCourses()
{
	return FinishedCourses;
}

List<float>^ Student::getCoursesGPA() {
	return coursesGPA;
}

int Student::getMaxHoursAllowed()
{
	return MaxHoursAllowed;
}

float Student::getGPA()
{
	return GPA;
}

List<String^>^ Student::CoursesAV()
{

	List<String^>^ AvCourses = gcnew List<String^>();
	
	//return an empty list if no finished courses
	if(FinishedCourses==nullptr)
		return nullptr;
	else
	{
		if (FinishedCourses->Count == 0)
			return nullptr;
	}
		for each (auto line in Course::preRequires)
		{
			//line = { course Name to be taken, list of its preRequisites}
			String^ courseToAdd = line.Key;
			List<String^>^ preReqs = line.Value;
			
			bool canBeAdded = true;
			for each (auto course in preReqs)
			{
				//searching if each preRequisite is in the student's finished courses
				if (!FinishedCourses->Contains(course))
				{
					canBeAdded = false;
					break;
				}
			}
			if (canBeAdded)
			{
				AvCourses->Add(courseToAdd);
			}
		}

	//return an empty list if no finished courses
	if (FinishedCourses->Count == 0);
	  return nullptr;

	for each (auto line in Course::preRequires)
	{
		//line = { course Name to be taken, list of its preRequisites}
		String^ courseToAdd = line.Key;
		List<String^>^ preReqs = line.Value;
		bool canBeAdded = true;
		for each (auto course in preReqs)
		{
			//searching if each preRequisite is in the student's finished courses
			if (!FinishedCourses->Contains(course))
			{
				canBeAdded = false;
				break;
			}
		}
		if (canBeAdded)
		{
			AvCourses->Add(courseToAdd);
		}
	}

	return AvCourses;
}


bool Student::validateIfCourseCanBeTaken(Course^ course)
{
	//to-do:
	// 
	//check Student::CoursesAV() for the required course
	List<String^>^ AvCourses = CoursesAV();
	if (AvCourses->Contains(course->getName()))	
		return true;
	

	return false;
}

bool Student::registerForCourse(Course^ course)
{
	//to-do :
	//1-use Student::validateIfCourseCanBeTaken 
	//2- handle if it's false
	//3-if true then put it in CoursesInProgress 
	if (!validateIfCourseCanBeTaken(course))
	{
		return false;
	}
	else
	{
		CoursesInProgress->Add(course->getName());
	}
	return true;

}

void Student::saveStudentDataToFile() {

	// Open the output file
	ofstream outFile("studentsData.txt");

	// Loop through each course in the dictionary
	for each (auto i in Student::allStudents)
	{
		//get data from each student obj
		String^ sysName = i->getName();
		String^ sysemail = i->getEmail();
		String^ syspassword = i->getPassword();
		int id = i->getID();
		int academicYear = i->getAcademicYear();
		int maxHours = i->getMaxHoursAllowed();
		float GPA = i->getGPA();
		List<String^>^ finishedCourses = i->getFinishedCourses();
		List<String^>^ coursesInProgress = i->getCoursesINProgress();
		List<float>^   coursesGPA = i->getCoursesGPA();

		//convert from system::string to std::string
		string name;
		for each (wchar_t c in sysName)
		{
			name += static_cast<char>(c);
		}

		string email;
		for each (wchar_t c in sysemail)
		{
			email += static_cast<char>(c);
		}

		string password;
		for each (wchar_t c in syspassword)
		{
			password += static_cast<char>(c);
		}

		//outputting data to file
		outFile << "1)" << name << endl;
		outFile << "2)" << email << endl;
		outFile << "3)" << password << endl;
		outFile << "4)" << to_string(id) << endl;
		outFile << "5)" << to_string(academicYear) << endl;
		outFile << "6)" << to_string(maxHours) << endl;
		outFile << "7)" << GPA<<setprecision(3) << endl;

		//outputting the vectos
		outFile << "8)";

		string line;
		for each (String ^ course in finishedCourses)
		{
			// Separate courses with commas
			if (!line.empty())
			{
				line += ",";
			}
			std::string x;
			for each (wchar_t c in course)
			{
				x += static_cast<char>(c);
			}
			line += x;

		}

		outFile << line << endl;

		outFile << "9)";
		//output gpas
		string line3;
		for each (float gpa in coursesGPA)
		{
			// Separate courses with commas
			if (!line3.empty())
			{
				outFile<<",";
			}
			outFile << gpa << setprecision(3);
			line3 += to_string(gpa);

		}
		outFile<<endl;


		outFile << "c)";
		string line2;
		for each (String ^ course in coursesInProgress)
		{
			// Separate courses with commas
			if (!line2.empty())
			{
				line2 += ",";
			}
			std::string y;
			for each (wchar_t c in course)
			{
				y += static_cast<char>(c);
			}
			line2 += y;

		}
		outFile << line2 << endl;
		//outputting the students separator (x)

		outFile << "x" << endl;


	}

	// Close the output file
	outFile.close();


}


void Student::loadStudentDataFromFile() {

	//loading data from file
	ifstream stdData("StudentsData.txt");
	string wholeLine;
	Student^ temp = gcnew Student();
	while (getline(stdData, wholeLine))
	{
		// to skip 'number' and ')' 
		// ex: 1), 2), 3)
		int i = 2;

		//if the student is finished
		if (wholeLine[0] == 'x')
		{
			Student::allStudents->Add(temp);
		}

		//if one word per line (not a list)
		if (wholeLine[0] != '8' && wholeLine[0] != '9' && wholeLine[0]!='c')
		{
			string var;
			while (i < wholeLine.size())
			{
				var += wholeLine[i];
				i++;
			}

			String^ sysVar = gcnew String(var.c_str());
			if (wholeLine[0] == '1'&&wholeLine[1]==')')
				temp->setName(sysVar);
			if (wholeLine[0] == '2')
				temp->setEmail(sysVar);
			if (wholeLine[0] == '3')
				temp->setPassword(sysVar);
			if (wholeLine[0] == '4')
				temp->setID(stoi(var)); // string to int
			if (wholeLine[0] == '5')
				temp->setAcademicYear(stoi(var));
			if (wholeLine[0] == '6')
				temp->setMaxHoursAllowed(stoi(var));
			if (wholeLine[0] == '7')
				temp->setGPA(float(stof(var))); //string to int then to float

		}
		else // a list of finished or current courses
		{
			List<String^>^ tempp = gcnew List<String^>();
			string push;
			while (i < wholeLine.size())
			{
				if (wholeLine[i] == ',')
				{
					i++;
					String^ sysVar = gcnew String(push.c_str());
					tempp->Add(sysVar);
					push = "";
				}
				push += wholeLine[i];
				i++;
			}
			String^ sysVar = gcnew String(push.c_str());
			tempp->Add(sysVar);

			if (wholeLine[0] == '8')// add to finished courses
				temp->setFinishedCourses(tempp);

			if (wholeLine[0] == 'c')//add courses in progress
				temp->setCoursesINProgress(tempp);
			if (wholeLine[0] == '9')//add gpa for each course
			{ 
				List<float>^ temppGpa = gcnew List<float>();

				for each(auto it in tempp)//convert from String^ to float
				{
					string y;
					for each (wchar_t c in it)//convert from String^ to std::string
					{
						y += static_cast<char>(c);
					}
					temppGpa->Add(stof(y));//add to list<float>
				}
				temp->setCoursesGPA(temppGpa);//add to student object
			}
		}
	}
}




