
#include <iostream>
#include <string>
using namespace std;
struct Date {
    int year;
    int month;
    int day;
};
struct Student {
    int ID;
    string name;
    Date birth_date;
    char gender;
    double GPA;

};
void inputAllStudents(Student* studentsArray, int numberOfStudents)
{
    cout <<"Enter "<<numberOfStudents<<" students info in this order (id, name, birth date (day/month/year), gender, GPA" << endl;
    for (int i = 0; i < numberOfStudents; i++)
    {
        //cout << "Enter student " << i + 1 << " info in this order (id, name, birth date (day/month/year), gender, GPA"<< endl;//
        cin >> studentsArray[i].ID >> studentsArray[i].name >> studentsArray[i].birth_date.day >>
            studentsArray[i].birth_date.month >> studentsArray[i].birth_date.year >> studentsArray[i].gender >> studentsArray[i].GPA;
    }
}
void outputAllStudents(Student* studentsArray, int numberOfStudents)
{
    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << studentsArray[i].ID << " "<< studentsArray[i].name<<" " << studentsArray[i].birth_date.day<<"/" <<
            studentsArray[i].birth_date.month<<"/" << studentsArray[i].birth_date.year<<" " << studentsArray[i].gender<< " " << studentsArray[i].GPA <<endl;
    }
}
void sortStudentsByGpa(Student* s, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (s[i].GPA > s[j].GPA)
            {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
bool isOlder(Student* s1, Student* s2)
{
    if (s1->birth_date.year < s2->birth_date.year)
    {
        return true;
    }
    else if (s1->birth_date.year == s2->birth_date.year && s1->birth_date.month < s2->birth_date.month)
    {
        return true;
    }
    else if (s1->birth_date.year == s2->birth_date.year && s1->birth_date.month == s2->birth_date.month && s1->birth_date.day < s2->birth_date.day)
    {
        return true;
    }
    else return false;
}
void sortStudentsByBirthdate(Student* s, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isOlder(&s[i], &s[j]))
            {
                continue;
            }
            else
            {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
Student* searchStudentsById(Student* s, int n, int ID)
{
    int flag = 0;
    Student found;
    Student* pfound = &found;
    for (int i = 0; i < n; i++)
    {
        if (s[i].ID == ID)
        {
            flag = 1;
            found = s[i];
        }
    }
    if (flag == 1)
    {
        return pfound;
    }
    else
    {
        return nullptr;
    }
}
int main()
{
    int numberOfStudents, idToSearch, choice;
    int flag = 1;
    Student s1, s2;
    Student* ps1= &s1, * ps2 = &s2;
    cout << "Enter number of students" << endl;
    cin >> numberOfStudents;
    Student* studentsArray = new Student[numberOfStudents];
    inputAllStudents(studentsArray, numberOfStudents);
    while (flag == 1)
    {
        cout << "To output all data press \"1\"" << endl << "To Sort students by birth date press \"2\"" << endl << "To Sort students by GPA press \"3\"" <<
            endl << "To Search students by ID press \"4\"" << endl << "To Exit the program press \"5\"" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            outputAllStudents(studentsArray, numberOfStudents);
            break;
        case 2:
            sortStudentsByBirthdate(studentsArray, numberOfStudents);
            break;
        case 3:
            sortStudentsByGpa(studentsArray, numberOfStudents);
            break;
        case 4:
            int idToSearch;
            cout << "Enter id to search for" << endl;
            cin >> idToSearch;
            searchStudentsById(studentsArray, numberOfStudents, idToSearch)->ID;
            break;
        case 5:
            flag = 0;
            break;
        default:
            cout << "You entered wrong number" << endl;
            break;
        }
    }

    delete[] studentsArray;
    return 0;
}

