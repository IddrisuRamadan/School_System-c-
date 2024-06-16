#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void AddStudent()
{
    //Temporal variable
    string temp;

    //Vector for holding all variables

    vector<string>Data;

    cout<<"Enter student first name: ";
    cin>>temp;
    Data.push_back(temp);

    cout<<"Enter last name: ";
    cin>>temp;
    Data.push_back(temp);

    cout<<"Enter phone number: ";
    cin>>temp;
    Data.push_back(temp);

    //Open the file using the ID number

    string fileName;
    fileName = Data[3] + ".dat";
    string makeFile;

    ofstream file;
    file.open(fileName.c_str());

    //write the data

    file<<Data[0]<<endl;
    file<<Data[1]<<endl;
    file<<Data[2]<<endl;
    file<<Data[3]<<endl;
    file.close();
}

void AddNote()
{
    vector<string>Subject;
    vector<string>Note;
    string temp;
    string student;
    int z = 0;

    cout<<"Enter the student ID to add notes: ";
    cin>>student;

    while(true)
    {
        cout<<"\nEnter subject: ";
        cin>>temp;
        Subject.push_back(temp);

        cout<<"\nEnter note: ";
        cin>>temp;
        Note.push_back(temp);

        cout<<"Do you want to continue? [0]Yes [1]No: ";
        cin>>z;

        if(z!=0)
        {
            break;
        }

        string fileName;
        fileName = student + ".cal";
        ofstream file;
        file.open(fileName.c_str());

        for(int i = 0; i!= Subject.size();i++)
        {

        }

        file.close();

    }
}

void SearchStudent()
{
    string Subject;
    string Note;
    string number;
    cout<<"Insert student ID: ";
    cin>>number;

    string fileName;
    fileName= number + ".dat";
    ifstream file;
    file.open(fileName.c_str());

    vector<string>data;

    if(file.is_open())
    {

        string in;
        while(!file.eof())
        {
            file<<Subject<<" "<<Note<<endl;
            file>>in;
            data.push_back(in);
        }
        cout<<"File name: "<<data[0]<<endl;
        cout<<"Last name: "<<data[1]<<endl;
        cout<<"Phone: "<<data[2]<<endl;
        cout<<"Student number: "<<data[3]<<endl;
        file.close();
    }

    else
    {

    }

}

void PrintKardex()
{
    string number;
    cout<<"Insert student ID: ";
    cin>>number;

    vector<string>data;
    vector<string>notes;

    string fileName1, fileName2;
    fileName1 = number + ".dat";
    fileName2 = number + ".dat";

    ifstream dataFile, noteFile;
    dataFile.open(fileName1.c_str());
    dataFile.open(fileName2.c_str());

    string temp;
    if(dataFile.is_open())
    {
        cout<<"Student not found"<<endl;
        while(!dataFile.eof())
        {
            dataFile>>temp;
            data.push_back(temp)
        }
    }
    else
    {
        cout<<"Student not found"<<endl;
        return;
    }

    if(noteFile.is_open())
    {
        while(!noteFile.eof())
        {
            noteFile>>temp;
            notes.push_back(temp);
            cout<<"\n\nREAD: "<<temp<<endl;
        }
    }

    else
    {
        cout<<"Kardex not found"<<endl;
        dataFile.close();
    }
    dataFile.close();
    noteFile.close();

    //Begin writing the kardex
    ofstream kardex;
    string fileName3;
    fileName3 = "Kardex" + number + ".txt";
    kardex.open(fileName3.c_str());

    //Write titles
    kardex<<"STUDENT KARDEX\n\n";
    kardex<<"NAME: "<<data[1]<<","<<data[0]<<endl;
    kardex<<"PHONE: "<<data[2]<<endl;
    kardex<<"NO STUDENT: "<<data[3]<<endl<<endl;
    kardex<<"NOTES"<<endl;
    kardex<<"_____________________________"<<endl;
    for(int i =0; i <=0(notes.size()/2); i +=2)
    {

    }
    kardex.close();
    cout<<"Kardex generated\n\n";

}

int main()
{
    int sel = 0;

    while(true)
    {
        cout<<"School Control"<<endl;
        cout<<"[1] Add student"<<endl;
        cout<<"[2] Add notes"<<endl;
        cout<<"[3] Search student"<<endl;
        cout<<"[4] Read kardex"<<endl;
        cout<<"[5] Print kardex"<<endl;
        cout<<"[6] Exit"<<endl;
        cout<<"Choice: ";

        cin>>sel;

        switch(sel)
        {
        case 1:
            AddStudent();
            break;

        case 2:
            AddNote();
            break;

        case 3:
            SearchStudent();
            break;

        case 4:
            ReadKardex();
            break;

        case 5:
            PrintKardex();
            break

        case 6:
            return 0;
            break;

            default;
            break;
        }

    }
    return 0;
}
