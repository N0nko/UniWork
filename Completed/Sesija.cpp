#include <bits/stdc++.h>

using namespace std;

class Student
{
  private:
    string name;   //student name
    int grades[5]; //5 grades
  public:
    //Studentai privalo dekanatui pateikti ataskaitos lapuką su savo vardu ir penkiais egzaminų pažymiais.
    void setStudent()
    {
        cin >> name;
        for (int i = 0; i < 5; i++)
            cin >> grades[i];
    }

    double getAverageGrade()
    {
        double average = 0;
        for (int each : grades)
            average += each;
        return average / 5;
    }
    string getContendersName()
    {
        return name;
    }
};

class GradeCounter
{

  public:
  // Apskaičiuokite keli studentai gaus stipendiją, jeigu ji skiriama turintiems didesnį nei 9 vidurkį.
    int getScholarCount(vector<Student *> students)
    {
        int scholarCount = 0;
        for (Student *each : students)
            if (each->getAverageGrade() > 9)
                scholarCount++;
        return scholarCount;
    }
    //atspausdinkite geriausiai besimokančio studento vardą.
    string getBestStudent(vector<Student *> students)
    {
        int bestID;
        double bestGrade = -INFINITY;
        for (int i = 0; i < students.size(); i++)
        {
            double studentsGrade = students[i]->getAverageGrade();
            if (studentsGrade > bestGrade)
            {
                bestGrade = studentsGrade;
                bestID = i;
            }
        }
        return students[bestID]->getContendersName();
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<Student *> students;
    //input
    for (int i = 0; i < n; i++)
    {
        Student *newStudent = new Student();
        newStudent->setStudent();
        students.push_back(newStudent);
    }
    GradeCounter counter;

    cout << counter.getScholarCount(students) << " studentas/ai gaus stipendiją." << endl
         << "Geriausiai mokosi " << counter.getBestStudent(students) << "." << endl;

    return 0;
}