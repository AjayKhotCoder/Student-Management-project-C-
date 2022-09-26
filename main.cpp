#include <iostream>

using namespace std;

class Student
{
    private:
    int choice,id;
    string stdName;
    int marks;

    public:
    Student()
    {
        id=0;
        stdName="Unknown";
        marks=0;
    }

    void setId(int stdId)
    {
        id=stdId;
    }

    void setStudentName(string name)
    {
        stdName=name;
    }

    void setMarks(int stdMarks)
    {
        marks=stdMarks;
    }

    int getId()
    {
        return id;
    }

    string getStudentName()
    {
        return stdName;
    }

    int getMarks()
    {
        return marks;
    }
};

class Controller
{
    int choice,i,n=0;
    Student s[100];
    public:

    void menu()
    {
        cout<<"\n====== :::MENU:::=====\n\n"<<endl;
        cout<<"1.Add Student"<<endl;
        cout<<"2.Show Student"<<endl;
        cout<<"3.Update Student"<<endl;
        cout<<"4.Search Student"<<endl;
        cout<<"0.Exit"<<endl;


        cout<<"\nEnter the Choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            showStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            srch();
            break;
        case 0:

            break;
        }
    }

    void addStudent()
    {
    int stdId;
    string name;
    int stdMarks;

     cout<<"\nEnter The No.of Student :"<<endl;
     cin>>n;

     cout<<"Ok........."<<endl;

     for(i=0;i<n;i++)
        {

            cout<<"\nStudent"<<i+1<<": "<<endl;

            cout<<"Enter Student ID :";
            cin>>stdId;

            cout<<"Enter Student Name :";
            cin>>name;

            cout<<"Enter Student Marks : ";
            cin>>stdMarks;

                s[i].setId(stdId);
                s[i].setStudentName(name);
                s[i].setMarks(stdMarks);

            cout<<"========================================================"<<endl;
            }

            cout<<"Ok....Done Data Saved"<<endl;

            menu();

      }

      void showStudent()
      {
          int choice;
          cout<<"========================================================"<<endl;
          cout<<"----------:: ALL STUDENT DATA RECORD ::-----------"<<endl;
          cout<<"========================================================\n"<<endl;
          cout<<"\tStudentID"<<"\t\tNAME"<<"\t\tMARKS"<<endl;


            for(i=0;i<n;i++)
              {
                  cout<<i+1<<".\t"<<s[i].getId()<<"\t\t"<<s[i].getStudentName()<<"\t\t"<<s[i].getMarks()<<endl;
              }
            cout<<"========================================================"<<endl;
              cout<<"Ok....Yes This Is All I GOt....."<<endl;

              menu();
      }


      void updateStudent()
      {
          int tmpId,ch,x=0;
          string newName, name;
          int stdMarks;

          int newMarks;
            k:cout<<"\nEnter Your Employee Id :";
            cin>>tmpId;
            for(i=0;i<n;i++)
            {
                    if(tmpId==s[i].getId())
                      {
                          cout<<"\tStudentID"<<"\t\tNAME"<<"\t\tMARKS"<<endl;
                          cout<<i+1<<".\t"<<s[i].getId()<<"\t\t"<<s[i].getStudentName()<<"\t\t"<<s[i].getMarks()<<endl;
                          cout<<"=========================================================="<<endl;
                          cout<<"\nOK.....What you Want To Update"<<endl;
                          cout<<"1. Name \n2.Marks"<<endl;
                          cout<<"\nEnter the Choice : ";
                          cin>>choice;
                            switch(choice)
                            {
                               case 1:
                                  cout<<"Your Old Name is : "<<s[i].getStudentName();
                                  cout<<"\n What is your Correct Name?"<<endl;
                                  cin>>newName;
                                  cout<<"Your New Name is "<<newName<<" and Your old Name is "<<s[i].getStudentName()<<endl;
                                  cout<<"\n"<<endl;

                               break;
                               case 2:
                                   cout<<"Your Old Marks is : "<<s[i].getMarks()<<endl;
                                   cout<<"\n What is your Correct Marks?"<<endl;
                                  cin>>newMarks;
                                  cout<<"Your New Marks is "<<newMarks<<" and Your old Marks is "<<s[i].getMarks()<<endl;
                                  cout<<"\n"<<endl;
                                  cout<<"Do you really want to change?"<<endl;
                                  cout<<"1. Yes \n 2. No"<<endl;
                                  cout<<"\nEnter the Choice : ";
                                  cin>>ch;
                                  switch(ch)
                                    {
                                    case 1:
                                        s[i].setMarks(newMarks);
                                        break;
                                    case 2:
                                        menu();
                                        break;
                                    }
                                break;
                            }
                            if (choice==1)
                            {
                                cout<<"Do you really want to change?"<<endl;
                                  cout<<"1. Yes \n 2. No"<<endl;
                                  cout<<"\nEnter the Choice : ";
                                  cin>>ch;
                                  switch(ch)
                                    {
                                    case 1:
                                        s[i].setStudentName(newName);
                                        break;
                                    case 2:
                                        menu();
                                        break;
                                    }
                            }


                      }
                      else
                      {
                          x++;
                      }

        }
        if (x==n)
        {
                        cout<<"=========================================================="<<endl;
                        cout<<"Sorry......invalid employee ID "<<endl;
                        cout<<"Please check your StudentId"<<endl;
                        cout<<"=========================================================="<<endl;
                        x=0;
                        goto k;
        }





            cout<<"Ok done record updated...."<<endl;
            cout<<"=============================="<<endl;
            menu();

      }

      void srch()
      {
          int tempId,x=0;
          string tempName;

          cout<<"Serach by Name/ID: "<<endl;
          cout<<"1. Name"<<endl;
          cout<<"2. StudentID\n"<<endl;
          cout<<"Enter choice :";
          cin>>choice;

          switch(choice)
          {
          case 1:
              p:cout<<"Enter the Name :";
              cin>>tempName;
              for(i=0;i<n;i++)
             {
                  if(tempName==s[i].getStudentName())
                  {
                      cout<<"=========================================================="<<endl;
                      cout<<"\tStudentID"<<"\t\tNAME"<<"\t\tMARKS"<<endl;
                      cout<<i+1<<".\t"<<s[i].getId()<<"\t\t"<<s[i].getStudentName()<<"\t\t"<<s[i].getMarks()<<endl;
                      cout<<"=========================================================="<<endl;
                  }
                  else if(tempName != s[i].getStudentName())
                  {
                      cout<<"Sorry......invalid Name "<<"Please enter correct name "<<endl;
                      goto p;
                  }
            }

          break;
          case 2:
              c:cout<<"Enter the StudentId :";
              cin>>tempId;
              for(i=0;i<n;i++)
             {
                  if(tempId==s[i].getId())
                  {
                      cout<<"=========================================================="<<endl;
                      cout<<"\tStudentID"<<"\t\tNAME"<<"\t\tMARKS"<<endl;
                      cout<<i+1<<".\t"<<s[i].getId()<<"\t\t"<<s[i].getStudentName()<<"\t\t"<<s[i].getMarks()<<endl;
                      cout<<"=========================================================="<<endl;
                  }
                  else
                  {
                      x++;
                  }
            }

           if(x==n) {
                      cout<<"Sorry you entered wrong StudentId ....Please enter correct StudentId."<<endl;
                      goto c;
           }





          } menu();
      }
};



int main()
{
Controller c;
cout<<"\n\t\t\t==============:: STUDENT MANAGEMENT SYSTEM ::============="<<endl;
c.menu();

return 0;
}

