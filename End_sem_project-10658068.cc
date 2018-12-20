//Question
//Build a school management system with the following features;
//  ->Add/edit/delete courses
//  ->Add/edit/delete students
//  ->Add/edit/delete stuff
//  ->Assign student to courses
//  ->Record student grade
//  ->Print academic record of student

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;


struct stud_info{
public:
    int num_of_course = 10;
    vector<string> first_name;
    vector<string> second_name;
    vector<string> id;
    vector<char> gender;
    vector<string> courses;
    string classs;
    string grade[6];
    int credit_hrs[6];
    float gpt[6];
    float gpa;
};

struct staff_info{
public:
    vector<string> first_name;
    vector<string> second_name;
    vector<string> id;
    vector<char> gender;
    vector<string> qualification;
};

struct admin_info{
    string name;
    string password = "passed";
}admin;

float cal_gpt(int j);        //function to calculate grade point
float cal_gpa();             //function to calculate gpa per semester
string class_obtained();     //function to determine the class obtained by a student
void add_student();          //function to add student
void add_staff();            //function to add staff
void edit_student(int t);    //function to modify/edit details of student
void edit_staff(int k);      //function to modify/edit details of staff
void delete_student();       //function to delete student
void delete_staff();         //function to delete staff
void add_course();           //function to add course
void delete_course();        //function to delete course
void display_aca_rec(int num);      //function to display academice record of student

staff_info staff;
stud_info student;

int temp_in;
string input;

int main()
{
    int options;
    string pass;
    char exit;

while(1)        //outer loop
{
    system("cls");     //clears screen

        //main menu

    cout <<"--------SCHOOL MANAGEMENT SYSTEM--------\n";
    cout <<"----------------MAIN MENU---------------\n\n";
    cout << "You are Welcome\n" << endl;
    cout << "Choose the options below: " << endl;
    cout << "1. Administrator" <<endl;
    cout << "2. Staff" << endl;
    cout << "3. Student" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter(1-4): ";
    cin >> options;


   system("cls");     //clears screen

    switch(options)
    {

    case(1):        //administrator menu
    {

    while(1)     //inner loop 1
    {
    system("cls");     //clears screen

        cout << "Hello Administrator\n";
        cout << "Please enter your password: ";
        cin >> pass;

        system("cls");

        if(pass == admin.password)
        {
            cout <<"----Welcome Admin----\n";
            cout << "1. Add student\n" <<"2. Edit/Modify student\n"<< "3. Delete student\n" ;
            cout << "4. Add staff\n" <<"5. Edit/Modify staff\n"<< "6. Delete staff\n" << "7. Exit\n";
            cout << "Enter option(1-7): ";
            cin >> options;

            switch(options)
            {
                case 1:         //adds student
                {
                    char exit;
                    do{
                        add_student();

                        cout << "\nAdd more students?(y/n): ";
                        cin >>exit;

                    }

                    while(exit!='n');


                }continue;      //continue back to inner loop 1

                case 2:
                {
                    string id;
                    cout << "Enter student's ID to edit details: ";
                    cin >> id;

                    for(int i=0; i<student.id.size(); i++)
                    {
                        if(student.id[i] == id)
                        {
                            edit_student(i);
                        }

                        else
                        {
                            cout << "Student with ID - "<<id<<" does not exist!";
                        }
                    }
                }continue;

                case 3:         //deletes student
                {
                    char exit;
                    do{
                        delete_student();

                        cout << "\nDelete more students?(y/n): ";
                        cin >>exit;
                    }

                    while(exit!='n');
                }continue;      //continue back to inner loop 1

                case 4:         //adds staff
                {
                    char exit;
                    do{
                        add_staff();

                        cout << "\nAdd more staff?(y/n): ";
                        cin >>exit;

                    }

                    while(exit!='n');
                }continue;      //continue back to inner loop 1

                case 5:
                {
                    string id;
                    cout << "Enter staff's ID to edit details: ";
                    cin >> id;

                    for(int i=0; i<staff.id.size(); i++)
                    {
                        if(staff.id[i] == id)
                        {
                            edit_staff(i);
                        }

                        else
                        {
                            cout << "Staff with ID - "<<id<<" does not exist!";
                        }
                    }
                }continue;

                case 6:         //deletes staff
                {
                    char exit;
                    do{
                        delete_staff();

                        cout << "\nDelete more staff?(y/n): ";
                        cin >>exit;
                    }

                    while(exit!='n');
                }continue;      //continue back to inner loop 1

                case 7:         //exit
                {
                    cout << "Thanks for using this sevice\n";
                    break;
                }

                default:
                    cout << "\nInvalid input: Please try again\n";
            }
        }

        else{
            char ext;
            cout << "You don't have an authorised access - password incorrect!!!\n" ;
            cout << "Want to exit this menu or try password again?(e/t): ";
            cin >> ext;

            if(ext == 'e'){
                break;
            }

            else{
                continue;
            }

        }

       break;      //breaks inner loop 1
    }

        continue;       //continues to main menu

    }


    case(2):       //staff menu
    {
        while(1)        //inner loop 2
        {

        system("cls");     //clears screen

        string id;

        cout << "Hello Staff" << endl;
        cout << "Enter ID: ";
        cin >> id;

        for(int i=0; i<staff.id.size(); i++)
        {
            if(staff.id[i] == id)
            {
                cout << "\n----Welcome, "<<staff.first_name[i]<<"!----\n";
                cout << "1. View staff information\n";
                cout << "2. Add student's grade\n";
                cout << "3. Exit\n";
                cout << "Enter option: ";
                cin >> options;

                if(options == 1)
                {
                    cout << "\nName: "<<staff.first_name[i]<<" "<<staff.second_name[i]<<"\n";
                    cout << "Qualification: " <<staff.qualification[i]<<"\n";
                    cout << "Gender: " << staff.gender[i];

                    cout << "\n\nEnter any key to continue: ";
                    cin >> pass;
                }

                else if(options == 2)
                {
                    cout << "\nEnter student's ID: ";
                    cin >> input;

                    for(int i=0; i<student.id.size(); i++)
                    {
                        if(input == student.id[i])
                        {
                            for(int k=0; k<6; k++)
                            {
                                cout << "\nEnter grade for course" <<(k+1)<< ": ";
                                cin >> student.grade[i];

                                cout << "Enter credit hour: ";
                                cin >> student.credit_hrs[i];
                            }
                        }
                        else
                        {
                            cout << "Staff with ID - " <<input<<" does not exist! \n";
                        }
                    }
                }

                else if(options == 3)
                {
                    break;
                }
                else
                {
                    break;
                }
            }

            else{ cout << "\nStaff with ID - "<<id<<" does not exist\n"; }
        }

        break;      //breaks inner loop 2
        }

        continue;       //continues to main menu
    }

    case(3):       //student menu
    {
        while(1)        //inner loop 3
        {

        system("cls");     //clears screen

        string d;

        cout << "\nHello Student\n";
        cout << "Enter ID: ";
        cin >>d;

       system("cls");

       for(int i=0; i<student.id.size(); i++)
       {

        if(student.id[i] == d)
        {

        cout << "\n-----Welcome, "<<student.first_name[i]<<"!-----";
        cout << "\n1. Add course\n" << "2. Delete course\n";
        cout << "3. View academic record\n" << "4. Exit\n";
        cout << "Enter option: ";
        cin >> options;

        string stud_Name;
        string course_Name;
        string course;
        string find_course;
        char response;



            switch(options)
            {
                case 1:         //add course
                {
                    add_course();
                }continue;      //continue back to inner loop 3

                case 2:         //delete course
                {
                    delete_course();
                }continue;      //continue back to inner loop 3

                case 3:         //view academic record
                {
                    display_aca_rec(i);

                }continue;      //continue back to inner loop 3

                case 4:         //exits student
                {
                    cout << "Thanks for using this service!";
                }continue;      //continue back to inner loop 3

                default:
                    cout << "\nInvalid input: Please try again\n";
            }
        }

        else{cout << "\nStudent with ID - "<<d<<" does not exist\n";}
       }

       break;      //breaks inner loop 3
       }

       continue;       //continues to main menu

    }

    case(4):       //exits from main menu
    {
        cout << "Thanks for using this service!\n";
    }break;

    default:
        cout << "You have entered an incorrect input. Please try again" << endl;
    }

break;  //outer loop
}



    return 0;
}



float cal_gpt(int j)        //function to calculate grade point
{
        if((student.grade[j]=="A") || (student.grade[j]=="a"))
        {
            student.gpt[j] = 12.00;
        }
        else if((student.grade[j]=="B+") || (student.grade[j]=="b+"))
        {
            student.gpt[j] = 10.50;
        }
        else if((student.grade[j]=="B") || (student.grade[j]=="b"))
        {
            student.gpt[j] = 9.00;
        }
        else if((student.grade[j]=="C+") || (student.grade[j]=="c+"))
        {
            student.gpt[j] = 7.50;
        }
        else if((student.grade[j]=="C") || (student.grade[j]=="c"))
        {
            student.gpt[j] = 6.00;
        }
        else if((student.grade[j]=="D+") || (student.grade[j]=="d+"))
        {
            student.gpt[j] = 4.50;
        }
        else if((student.grade[j]=="D") || (student.grade[j]=="d"))
        {
            student.gpt[j] = 3.00;
        }
        else if((student.grade[j]=="E") || (student.grade[j]=="e"))
        {
            student.gpt[j] = 1.50;
        }
        else if((student.grade[j]=="F") || (student.grade[j]=="f"))
        {
            student.gpt[j] = 0.00;
        }

        return student.gpt[j];
}


float cal_gpa()  //this function calculates the GPA of a student
{
    float gpa;
    float total_gpt = 0;
    int total_credit_hrs = 0;


    for(int j=0; j<6; j++)
    {
        total_credit_hrs = total_credit_hrs + student.credit_hrs[j];
        total_gpt = total_gpt + student.gpt[j];
    }

    gpa = total_gpt/total_credit_hrs;

    student.gpa = gpa;

    return student.gpa;

}


string class_obtained()    //this function determines the class obtained by the student
{

    if(student.gpa>=3.6 && student.gpa<=4)
    {
        student.classs = "First Class";
    }
    else if(student.gpa>=3 && student.gpa<=3.59)
    {
        student.classs = "Second Class (Upper Division)";
    }
    else if(student.gpa>=2 && student.gpa<=2.99)
    {
        student.classs = "Second Class (Lower Division)";
    }
    else if(student.gpa>=1.5 && student.gpa<=1.99)
    {
        student.classs = "Third class";
    }
    else if(student.gpa>=1 && student.gpa<=1.99)
    {
        student.classs = "Pass";
    }
    else if(student.gpa>=0 && student.gpa<=0.99)
    {
        student.classs = "Fail";
    }

    return student.classs;
}


void add_staff()
{
    char tem;

    cout << "Enter staff first name: "; cin >> input;
    staff.first_name.push_back(input);

    cout << "Enter staff first name: "; cin >> input;
    staff.second_name.push_back(input);

    cout << "Enter staff gender(m/f): "; cin >> tem;
    staff.gender.push_back(tem);

    cout <<"Enter staff ID: "; cin >> input;
    staff.id.push_back(input);

    cout << "Enter staff qualification: "; cin >> input;
    staff.qualification.push_back(input);

     cout << "\nStaff Added: \n";
    cout << "Name: \t"<<staff.first_name.back()<< " "<<staff.second_name.back();
    cout << "\nGender: "<<staff.gender.back();
    cout << "\nQualification: \t"<<staff.qualification.back();
    cout << "\nID: \t"<<staff.id.back()<<"\n";

}

void add_student()
{
    char tem;

    cout << "Enter student first name: "; cin >> input;
    student.first_name.push_back(input);

    cout << "Enter student second name: "; cin >> input;
    student.second_name.push_back(input);

    cout << "Enter student gender(m/f): "; cin >> tem;
    student.gender.push_back(tem);


    cout << "Enter student ID: "; cin >> input;
    student.id.push_back(input);

    cout << "\nStudent Added: \n";
    cout << "Name: \t"<<student.first_name.back()<< " "<<student.second_name.back();
    cout << "\nGender: "<<student.gender.back();
    cout << "\nID: \t"<<student.id.back()<<"\n";


}

void edit_student(int t)
{
    int opt;
    string change;
    char chg;

    cout << "\n-----Edit/modify-----";
    cout << "\n1. Student's first name";
    cout << "\n2. Student's second name";
    cout << "\n3. Student's gender";
    cout << "\n4. Exit";
    cout << "Enter option: ";
    cin >> opt;

    if(opt == 1)
    {
        cout << "Enter new first name: ";
        cin >> change;

        student.first_name[t] = change;
        cout << "Student's first name successfully changed!";
    }

    else if(opt == 2)
    {
        cout << "Enter new second name: ";
        cin >> change;

        student.second_name[t] = change;
        cout << "Student's second name successfully changed!";
    }

    else if(opt == 3)
    {
        cout << "Enter new gender(m/f): ";
        cin >> chg;

        student.gender[t] = chg;
        cout << "Student's gender successfully changed!";
    }

    else if(opt == 4)
    {
        cout << "\nThank you";
    }

    else
    {
        cout << "\nYou have entered an incorrect option!!!";
    }

}


void edit_staff(int k)
{
    int opt;
    string change;
    char chg;

    cout << "\n-----Edit/modify-----";
    cout << "\n1. Staff's first name";
    cout << "\n2. Staff's second name";
    cout << "\n3. Staff's gender";
    cout << "\n4. Staff's qualification";
    cout << "\n5. Exit";
    cout << "Enter option: ";
    cin >> opt;

    if(opt == 1)
    {
        cout << "Enter new first name: ";
        cin >> change;

        staff.first_name[k] = change;
        cout << "Staff's first name successfully changed!";
    }

    else if(opt == 2)
    {
        cout << "Enter new second name: ";
        cin >> change;

        staff.second_name[k] = change;
        cout << "Staff's second name successfully changed!";
    }

    else if(opt == 3)
    {
        cout << "Enter new gender(m/f): ";
        cin >> chg;

        staff.gender[k] = chg;
        cout << "Staff's gender successfully changed!";
    }

    else if(opt == 4)
    {
        cout << "Enter staff's new qualification: ";
        cin >> change;

        staff.qualification[k] = change;
        cout << "staff's qualification successfully changed!";
    }

    else if(opt == 5)
    {
        cout << "\nThank you";
    }

    else
    {
        cout << "\nYou have entered an incorrect option!!!";
    }
}


void delete_student()
{
    string search_id;

    cout << "Enter student ID to delete student: ";
    cin >> search_id;

    for(int i=0; i<student.id.size(); i++)
    {
        if(student.id[i] == search_id)
        {
            student.id.erase(student.id.begin() + i);
            student.first_name.erase(student.first_name.begin() + i);
            student.second_name.erase(student.second_name.begin() + i);

            cout << "Stident with ID - "<<search_id<<" deleted \n";
        }

        else{
            cout << "Student with ID - "<<search_id<<" not found";
        }
    }

}

void delete_staff()
{
    string search_i;

    cout << "Enter student ID to delete student: ";
    cin >> search_i;

    for(int i=0; i<staff.id.size(); i++)
    {
        if(staff.id[i] == search_i)
        {
            staff.id.erase(staff.id.begin() + i);
            staff.first_name.erase(staff.first_name.begin() + i);
            staff.second_name.erase(staff.second_name.begin() + i);
            staff.qualification.erase(staff.qualification.begin() + i);

            cout << "Staff with ID - "<<search_i<<" deleted \n";
        }

        else{
            cout << "Staff with ID - "<<search_i<<" not found";
        }
    }
}


void add_course()
{
    char close;
    string temp;

    do{
    cout<<"\nPlease enter course code: "<<endl;
    cin >>temp;

    student.courses.push_back(temp);
    cout << "Course with course code "<<temp<< " added ";

    cout << "\nWould you like to add another course?(y/n): ";
    cin >> close;
    }

    while(close!='n');

}


void delete_course()
{
    string del;
    char close;

    do{
        cout << "\nPlease enter course to be deleted: ";
        cin >> del;

        for(int i=0; i<student.courses.size(); i++)
        {
            if(student.courses[i] == del)
            {
            student.courses.erase(student.courses.begin() + i);
            cout << "Course "<<del<<" deleted! \n";
            }

            else{
            cout << "Course "<<del<<" does not exist!!!\n";
            }
        }

        cout << "\nWould you like to add another course?(y/n): ";
        cin >> close;
    }

    while(close!='n');
}

void display_aca_rec(int num)
{
    string p;

    cout<<"\n\nName: "<<student.first_name[num]<<" "<< student.second_name[num]<< "\nID: "<<student.id[num];
    cout << "\nGender: " << student.gender[num] << "\n";

    for(int m=0; m<30; m++){cout <<"*";}

    cout <<"\nCourse\t\t" << "Grade\t" << "GPT\n";


    for(int j=0; j<6; j++)
    {
        cout << student.courses[j] <<"\t\t"<<student.grade[j]<<"\t"<<cal_gpt(j)<<"\n";
    }

    for(int m=0; m<30; m++){cout <<"*";}

    cout << endl << "GPA: " << cal_gpa();
    cout << "\nClass: " << class_obtained();

    cout <<"\n\nEnter any key to continue: ";
    cin >> p;
}
