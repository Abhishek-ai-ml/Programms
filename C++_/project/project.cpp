#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
using namespace std;
char un[20];
class Admin
{
    char name[20];
    int totsub;
    char subject[10][10];
    char mobile[15],mail[50],fname[20];
    char passwd[20],rpasswd[20];
    public:
    char rollno[15];
    void getsdata()
    {
        cout<<"Enter the Student name:\n";
        gets(name);
        cout<<"Enter the Roll no.:\n";
        cin>>rollno;
        cout<<"Enter the student Father Name:\n";
        gets(fname);
        cout<<"Enter the mobile no:\n";
        gets(mobile);
        cout<<"Enter the E-mail ID:\n";
        gets(mail);
        cout<<"Enter the total subject:";
        cin>>totsub;
        for(int i=0;i<totsub;i++)
        {
            cout<<"Enter the Subject"<<i+1<<"Name :";
            cin>>subject[i];
        }
        cout<<"Create Your Login Password";
        cin>>passwd;
        cout<<"Enter the Unique keyword to recover password:";
        cin>>rpasswd;
        cout<<"Please note your Username is Roll no.\n";
    }
    int login()
    {
        if((strcmp(::un,rollno))==0)
        {
            cout<<"\nEnter the Login Password :";
            int len=0;
            len=strlen(passwd);
            char inputpasswd[20];
            for(int i=0;i<len;i++)
            {
                inputpasswd[i]=getchar();
                cout<<"#";
            }
            //inputpasswd[i]=NULL;
            if((strcmp(::un,rollno)==0)&&(strcmp(passwd,inputpasswd)==0))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    int recover()
    {
        char key[20];
        if(strcmp(::un,rollno)==0)
        {
            cout<<"Enter the Unique password:";
            cin>>key;
            if((strcmp(key,passwd)==0))
            {
                cout<<"\nYou are a valid user";
                cout<<"\nYour password is "<<passwd;
                cout<<"\nPlease Exit to Login Again ";
                return 1; 
            }
            else 
                return 0;
        }
        else
            return 0;
    }
    int faprofile()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"\nFaculty Name          :"<<name;
            cout<<"\nFaculty Father's Name :"<<fname;
            cout<<"\nFaculty Mobile No.    :"<<mobile;
            cout<<"\nFaculty E-mail ID     :"<<mail;
            return 1;
        }
        else
            return 0;
    }
    int knowfasub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"Faculty total Subjects : "<<totsub;
            for(int i=0;i<totsub;i++)
            {
                cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
            }
            return 1;
        }
        else
            return 0;
    }
    void addfasub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"Enter the New Subject : ";
            cin>>subject[totsub];
            totsub++;
            cout<<"\nNew Subject Added Successfully ";
        }
    }
    void delfasub()
    {
        knowfasub();
        int de=0;
        if((strcmp(::un,rollno)==0))
        {
            if(totsub==0||totsub<0)
            {
                totsub=0;
                cout<<"\nNo Subject Exists ::::";
                getchar();
                exit(0);
            }
            cout<<"\nEnter the Subject number to be deleted\n :";
            cin>>de;
            if(de==totsub)
            {
                totsub--;
                strcpy(subject[totsub]," ");
            }
            else if(totsub==1)
            {
                totsub=0;
                strcpy(subject[totsub]," ");
            }
            else
            {
                de--;
                strcpy(subject[totsub]," ");
                for(int p=de;p<totsub;p++)
                {
                    strcpy(subject[p],subject[p+1]);
                }
                totsub--;
            }
            cout<<"Record Updated Successfully:::"<<endl;
        }
    }
    void modfaprofile()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"The Profile Details are : "<<endl;
            cout<<"1. Faculty E-mail : "<<mail<<endl;
            cout<<"2. Faculty Mobile : "<<mobile<<endl;
            int g=-1;
            cout<<"Enter the Detail Number to be modified : "<<endl;
            cin>>g;
            if(g==1)
            {
                char nmail[50];
                cout<<"Enter the new E-mail Address : "<<endl;
                gets(nmail);
                strcpy(mail,nmail);
                cout<<"Record Updated Sucessfully"<<endl;
            }
            else if(g==2)
            {
                char nmobile[15];
                cout<<"Enter the new Mobile number : "<<endl;
                gets(mobile);
                strcpy(mobile,nmobile);
                cout<<"Record Updated Successfully"<<endl;
            }
            else
            cout<<"Invalid value entered "<<endl;
        }
    }
    int stprofile()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"Student name           :"<<name<<endl;
            cout<<"Student Father name    :"<<fname<<endl;
            cout<<"Student Mobile number  :"<<mobile<<endl;
            cout<<"Student E-mail ID      :"<<mail<<endl;
            return 1;
        }
        else
            return 0;
    }
    int knowstsub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"Student total subjects : "<<totsub;
            for(int i=0;i<totsub;i++)
            {
                cout<<"Subject"<<i+1<<" : "<<subject[i]<<endl;
            }
            return 1;
        }
        else 
            return 0;
    }
    void addstsub()
    {
        if((strcmp(::un,rollno)==0))
        {
            cout<<"Enter the new subject : "<<endl;
            cin>>subject[totsub];
            totsub++;
            cout<<"New Subject Added Sucessfully"<<endl;
        }
    }
    void delstsub()
    {
        knowstsub();
        int de=0;
        if((strcmp(::un,rollno)==0))
        {
            if(totsub==0||totsub<0)
            {
                totsub=0;
                cout<<"\nNo Subject Exists ::::";
                getchar();
                exit(0);
            }
            cout<<"\nEnter the Subject number to be deleted\n :";
            cin>>de;
            if(de==totsub)
            {
                totsub--;
                strcpy(subject[totsub]," ");
            }
            else if(totsub==1)
            {
                totsub=0;
                strcpy(subject[totsub]," ");
            }
            else
            {
                de--;
                strcpy(subject[totsub]," ");
                for(int p=de;p<totsub;p++)
                {
                    strcpy(subject[p],subject[p+1]);
                }
                totsub--;
            }
            cout<<"Record Updated Successfully:::"<<endl;
        }
    
    }
    void modstprofile()
    {
       if((strcmp(::un,rollno)==0))
        {
            cout<<"The Profile Details are : "<<endl;
            cout<<"1. Student E-mail : "<<mail<<endl;
            cout<<"2. Student Mobile : "<<mobile<<endl;
            int g=-1;
            cout<<"Enter the Detail Number to be modified : "<<endl;
            cin>>g;
            if(g==1)
            {
                char nmail[50];
                cout<<"Enter the new E-mail Address : "<<endl;
                gets(nmail);
                strcpy(mail,nmail);
                cout<<"Record Updated Sucessfully"<<endl;
            }
            else if(g==2)
            {
                char nmobile[15];
                cout<<"Enter the new Mobile number : "<<endl;
                gets(mobile);
                strcpy(mobile,nmobile);
                cout<<"Record Updated Successfully"<<endl;
            }
            else
            cout<<"Invalid value entered "<<endl;
        } 
    }
    void getfadata()
    {
        cout<<"Enter the Faculty name : "<<endl;
        gets(name);
        cout<<"Enter the Faculty ID : "<<endl;
        cin>>rollno;
        cout<<"Enter the Faculty Father name : "<<endl;
        gets(fname);
        cout<<"Enter the Mobile number : "<<endl;
        gets(mobile);
        cout<<"Enter the E-mail ID : "<<endl;
        gets(mail);
        cout<<"Enter the total subject : "<<endl;
        cin>>totsub;
        cout<<"The total subject choosen are : "<<totsub;
        for(int i=0;i<totsub;i++)
        {
            cout<<"Enter the subject "<<i+1<<" name : "<<endl;
            cin>>subject[i];
        }
        cout<<"Create Your Login Password : "<<endl;
        cin>>passwd;
        cout<<"Enter the Unique Keyword to Recover Password : "<<endl;
        cin>>rpasswd;
        cout<<"Please note your Username is ID "<<endl;
    }
    void stdisplay()
    {
        cout<<"Student Name           : "<<name<<endl;
        cout<<"Student ID/Roll no.    : "<<rollno<<endl;
        cout<<"Student Father Name    : "<<fname<<endl;
        cout<<"Student Mobile number  : "<<mobile<<endl;
        cout<<"Student E-mail ID      : "<<mail<<endl;
        cout<<"Student Subjects       : "<<totsub<<endl;
        for(int i=0;i<totsub;i++)
        {
            cout<<"Subject "<<i+1<<" : "<<subject[i];
        }
        if(totsub==0)
        {
            cout<<"No Subject Registered "<<endl;
        }
    }
    void fadisplay()
    {
        cout<<"Faculty Name           : "<<name<<endl;
        cout<<"Faculty ID/Roll no.    : "<<rollno<<endl;
        cout<<"Faculty Father Name    : "<<fname<<endl;
        cout<<"Faculty Mobile number  : "<<mobile<<endl;
        cout<<"Faculty E-mail ID      : "<<mail<<endl;
        cout<<"Faculty Subjects       : "<<totsub<<endl;
        for(int i=0;i<totsub;i++)
        {
            cout<<"Subject "<<i+1<<" : "<<subject[i];
        }
        if(totsub==0)
        {
            cout<<"No Subject Registered "<<endl;
        }
    }


}a;
Admin f;
int main()
{
    int ch;
    system("cls");
    cout<<"\n\n\n\t\t\tWelcome to DTU Database Portal ";
    cout<<"\n\n\n\t\t\t\tEnter to Continue ";
    getchar();
    system("cls");
    cout<<"\n\n\n\t\t\tEnter 1. For Admin Portal ";
    cout<<"\n\t\t\tEnter 2. For Faculty Portal ";
    cout<<"\n\t\t\tEnter 3. For Student Portal ";
    cout<<"\n\n\t\t\tEnter Your Choice ";
    cin>>ch;
    system("cls");
    if(ch==1)
    {
        char adminuser[20],adminpass[20];
        cout<<"\n\t\t\tWelcome To Admin Login Portal ";
        cout<<"\n\nEnter the Username : ";
        cin>>adminuser;
        cout<<"\nEnter the password : ";
        for(int k=0;k<8;k++)
        {
            adminpass[k]=getchar();
        }
        getchar();
        //adminpass[k]=NULL;
        if((strcmp(adminuser,"admin")==0)&&(strcmp(adminpass,"password")==0))
        {
            system("cls");
        }
        else
        {
            cout<<"\n\n\t\t\tInvalid User name and Password ";
            cout<<"\n\n\t\t\tThank You !!!!";
            getchar();
            exit(0);
        }
        char opera='y';
        do
        {
            int temp;
            cout<<"\n\t\t\t\tWelcome To Admin Panel";
            cout<<"\n\nEnter 1 to Add a Faculty Record "<<endl;
            cout<<"Enter 2 to Add Multiple Records of Faculty "<<endl;
            cout<<"Enter 3 to View All Records of Faculty "<<endl;
            cout<<"Enter 4 to Delete a Faculty Record "<<endl;
            cout<<"Enter 5 to Add a Student Record "<<endl;
            cout<<"Enter 6 to Add Multiple Records of Students "<<endl;
            cout<<"Enter 7 to View All Records of Students "<<endl;
            cout<<"Enter 8 to Delete a Student Record "<<endl;
            cout<<"Enter 9 To Exit "<<endl;
            cout<<"\n\tEnter Your Choice : ";
            cin>>temp;
            system("cls");
            if(temp==1)
            {
                cout<<"Enter the Details : "<<endl;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
                a.getfadata();
                fs.write((char*)&a,sizeof(Admin));
                fs.close();
                cout<<"Recor Entered Sucessfully"<<endl;
            }
            if(temp==2)
            {
                int m=0;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
                do
                {
                    cout<<"Enter the Details : "<<endl;
                    a.getfadata();
                    fs.write((char*)&a,sizeof(Admin));
                    cout<<"Press 0 If You Want To Enter More Record : "<<endl;
                    cin>>m;
                }while(m==0);
                fs.close();
                cout<<"Record Entered Successfully "<<endl;
            }
            if(temp==3)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char*)&a,sizeof(Admin));
                    a.fadisplay();
                }
                fs.close();
            }
            if(temp==4)
            {
                char tempfaid[15];
                int de=0,result =-1;
                cout<<"Enter the Faculty ID : "<<endl;
                cin>>tempfaid;
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fstream fs1;
                fs1.open("fanewinfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char*)&a,sizeof(Admin));
                    result=strcmp(tempfaid,a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else
                    {
                        fs1.write((char*)&a,sizeof(Admin));
                    }
                }
                if(de==1)
                {
                    cout<<"Record Deleted Successfully "<<endl;
                }
                else
                {
                    cout<<"Record Not Found "<<endl;
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("fanewinfo.txt","fainfo.txt");
            }
            if(temp==5)
            {
                cout<<"Enter the Details : "<<endl;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
                a.getsdata();
                fs.write((char*)&a,sizeof(Admin));
                fs.close();
                cout<<"Record Entered Succesfully "<<endl;
            }
            if(temp==6)
            {
                int m=0;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
                do
                {
                    cout<<"Enter the Details : "<<endl;
                    a.getsdata();
                    fs.write((char*)&a,sizeof(Admin));
                    cout<<"Enter 0 If You Want To Enter More Records : "<<endl;
                    cin>>m;
                }while(m==0);
                fs.close();
                cout<<"Record Entered Successfully "<<endl;
            }
            if(temp==7)
            {
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char*)&a,sizeof(Admin));
                    a.stdisplay();
                }
                fs.close();
            }
            if(temp==8)
            {
                char tempstid[15];
                int de=0,result=-1;
                cout<<"Enter the Student ID/Roll no."<<endl;
                cin>>tempstid;
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fstream fs1;
                fs1.open("stnewinfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char*)&a,sizeof(Admin));
                    result=strcmp(tempstid,a.rollno);
                    if(result==0)
                    {
                        de=1;
                    }
                    else
                    fs1.write((char*)&a,sizeof(Admin));
                }
                if(de==1)
                {
                    cout<<"Record Deleted Succesfully "<<endl;
                }
                else
                {
                    cout<<"Record Not Found "<<endl;
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("stnewinfo.txt","stinfo.txt");
            }
            if(temp==9)
            {
                cout<<"\n\n\n\t\t\t\tThank You"<<endl;
                getchar();
                exit(0);
            }
            if(temp<1||temp>9)
            {
                system("cls");
                cout<<"\n\n\n\t\t\t\tInvlaid Input"<<endl;
            }
            getchar();
            cout<<"\nEnter Y for more operation Otherwise N"<<endl;
            cin>>opera;
            if(opera!='y')
            {
                getchar();
                system("cls");
                cout<<"\n\n\n\n\n\t\t\t\tThank You"<<endl;
                getchar();
            }
        }while(opera=='Y'||opera=='y');
    }
    if(ch==2)
    {
        system("cls");
        char un[20];
        int val,s=0;
        cout<<"\n\t\t\tWelcome to Faculty Login Page "<<endl;
        cout<<"\nEnter the UserName : "<<endl;
        cin>>::un;
        fstream fs;
        fs.open("fainfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        while(!fs.eof())
        {
            val=-1;
            fs.read((char*)&f,sizeof(Admin));
            val=f.login();
            if(val==1)
            {
                s=1;
                break;
            }
        }
        fs.close();
        if(s==1)
        {
            system("cls");
        }
        if(s!=1)
        {
            system("cls");
            int ho=0;
            cout<<"\n\n\t\tYour Login Credential Are Incorrect "<<endl;
            cout<<"The Username Is Your ID/Roll no."<<endl;
            cout<<"The Password is Case Sensitive "<<endl;
            cout<<"Enter 1 to Recover Password "<<endl;
            cout<<"Enter 2 to Re attempt Login"<<endl;
            cout<<"Enter Your Choice "<<endl;
            cin>>ho;
            if(ho==1)
            {
                cout<<"Enter the Username : "<<endl;
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re,su=-1;
                while(!fs.eof())
                {
                    re=-1;
                    fs.read((char*)&f,sizeof(Admin));
                    re=f.recover();
                    if(re==1)
                    {
                        su=1;
                        break;
                    }
                }
                fs.close();
                if(su==1)
                {
                    getchar();
                    system("cls");
                    cout<<"\n\n\n\n\t\t\tThank You";
                    getchar();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou are a Invalid User ";
                    getchar();
                    exit(0);
                }
            }
            if(ho==2)
            {
                cout<<"Enter the Username : "<<endl;
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int suc=-1,valu;
                while(!fs.eof())
                {
                    valu=-1;
                    fs.read((char*)&f,sizeof(Admin));
                    valu=f.login();
                    if(valu==1)
                    {
                        suc=1;
                        break;
                    }
                }
                fs.close();
                if(suc==1)
                {
                    system("cls");
                }
                else
                {
                    getchar();
                    cout<<"\nYou are an Invalid User";
                    cout<<"\nThank you";
                    getchar();
                    exit(0);
                    exit(0);
                }
            }
            if(ho!=1&&ho!=2)
            {
                cout<<"\nInvalid Input Provided "<<endl;
                cout<<"\n\t\t\tThan You"<<endl;
                getchar();
                exit(0);
            }
        }
        char con='y';
        do
        {
            system("cls");
            cout<<"\n\n\t\t\tWelcome To Faculty Panel";
            cout<<"\n\n\t\t\t\t\t\t    Your UserID is : "<<::un;
            cout<<"\n\nEnter 1 To View Your Profile "<<endl;
            cout<<"Enter 2 To Know Your Subject"<<endl;
            cout<<"Enter 3 To Add A Subject"<<endl;
            cout<<"Enter 4 To Delete A Subject"<<endl;
            cout<<"Enter 5 To Modify Your Profile"<<endl;
            int choice;
            cin>>choice;
            if(choice==1)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                int x;
                while(!fs.eof())
                {
                    x=0;
                    fs.read((char*)&f,sizeof(Admin));
                    x=f.faprofile();
                    if(x==1)
                    {
                        break;
                    }
                }
                fs.close();
            }
            if(choice==2)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                int y;
                while(!fs.eof())
                {
                    y=0;
                    fs.read((char*)&f,sizeof(Admin));
                    y=f.knowfasub();
                    if(y==1)
                    {
                        break;
                    }
                }
                fs.close();
            }
            if(choice==3)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs1.open("tempfainfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char*)&f,sizeof(Admin));
                    f.addfasub();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("tempfainfo.txt","fainfo.txt");
            }
            if(choice==4)
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fstream fs1;
                fs1.open("delfainfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char*)&f,sizeof(Admin));
                    f.delfasub();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("delfainfo.txt","fainfo.txt");
            }
            if(choice==5)
            {
                fstream fs;
                fstream fs1;
                fs.open("fainfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                fs1.open("modfainfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char*)&f,sizeof(Admin));
                    f.modfaprofile();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("fainfo.txt");
                rename("modfainfo.txt","fainfo.txt");
            }
            if(choice<1||choice>5)
            {
                cout<<"\nInvalid Input Provided "<<endl;
            }
            cout<<"\n\t\t\t\tEnter To Continue"<<endl;
            getchar();
            cout<<"\nEnter y to Continue Otherwise n:"<<endl;
            cin>>con;
            if(con!='y'&&con!='Y')
            {
                system("cls");
                cout<<"\n\n\n\n\n\t\t\t\tThank You";
                getchar();
                exit(0);
            }
        }while(con=='y'||con=='Y');
    }
    if(ch==3)
    {
        system("cls");
        int value,s1=0;
        cout<<"\n\t\t\tWelcome to Student Login Page ";
        cout<<"\n\nEnter The Username ";
        cin>>::un;
        fstream fs;
        fs.open("stinfo.txt",ios::in|ios::binary);
        fs.seekg(0);
        while(!fs.eof())
        {
            value=-1;
            fs.read((char*)&f,sizeof(Admin));
            value=f.login();
            if(value==1)
            {
                s1=1;
                break;
            }
        }
        fs.close();
        if(s1==1)
        {
            system("cls");
            cout<<"\n\n\n\t\t\t\tWelcome To Student Page";
        }
        if(s1!=1)
        {
           system("cls");
            int sho=0;
            cout<<"\n\n\t\tYour Login Credential Are Incorrect "<<endl;
            cout<<"The Username Is Your ID/Roll no."<<endl;
            cout<<"The Password is Case Sensitive "<<endl;
            cout<<"Enter 1 to Recover Password "<<endl;
            cout<<"Enter 2 to Re attempt Login"<<endl;
            cout<<"Enter Your Choice "<<endl;
            cin>>sho;
            if(sho==1)
            {
                cout<<"Enter the Username : "<<endl;
                cin>>::un;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int re,su=-1;
                while(!fs.eof())
                {
                    re=-1;
                    fs.read((char*)&f,sizeof(Admin));
                    re=f.recover();
                    if(re==1)
                    {
                        su=1;
                        break;
                    }
                }
                fs.close();
                if(su==1)
                {
                    getchar();
                    system("cls");
                    cout<<"\n\n\n\n\t\t\tThank You";
                    getchar();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou are a Invalid User ";
                    getchar();
                    exit(0);
                }
            }
            if(sho==2)
            {
                cout<<"Enter the Username : "<<endl;
                cin>>::un;
                fstream fs;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                int suc=-1,valu;
                while(!fs.eof())
                {
                    valu=-1;
                    fs.read((char*)&f,sizeof(Admin));
                    valu=f.login();
                    if(valu==1)
                    {
                        suc=1;
                        break;
                    }
                }
                fs.close();
                if(suc==1)
                {
                    system("cls");
                }
                else
                {
                    getchar();
                    cout<<"\nYou are an Invalid User";
                    cout<<"\nThank you";
                    getchar();
                    exit(0);
                    exit(0);
                }
            }
            if(sho!=1&&sho!=2)
            {
                cout<<"\nInvalid Input Provided "<<endl;
                cout<<"\n\t\t\tThan You"<<endl;
                getchar();
                exit(0);
            } 
        }
        char moreop='y';
        do
        {
            system("cls");
            cout<<"\n\n\t\t\tWelcome to Student Panel";
            cout<<"\n\n\t\t\t\t\t\tYour User ID is "<<::un;
            cout<<"\n\nEnter 1 To View Your Profile"<<endl;
            cout<<"Enter 2 To Know Your Subject"<<endl;
            cout<<"Enter 3 To Add a Subject"<<endl;
            cout<<"Enter 4 To Delete a Subject"<<endl;
            cout<<"Enter 5 To Modify Your Profile"<<endl;
            int inchoice;
            cin>>inchoice;
            if(inchoice==1)
            {
               fstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                int x;
                while(!fs.eof())
                {
                    x=0;
                    fs.read((char*)&f,sizeof(Admin));
                    x=f.stprofile();
                    if(x==1)
                    {
                        break;
                    }
                }
                fs.close(); 
            }
            if(inchoice==2)
            {
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                int y;
                while(!fs.eof())
                {
                    y=0;
                    fs.read((char*)&f,sizeof(Admin));
                    y=f.knowstsub();
                    if(y==1)
                    {
                        break;
                    }
                }
                fs.close();
            }
            if(inchoice==3)
            {
               fstream fs;
                fstream fs1;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs1.open("tempstinfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char*)&f,sizeof(Admin));
                    f.addstsub();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("tempstinfo.txt","stinfo.txt"); 
            }
            if(inchoice==4)
            {
               fstream fs;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fstream fs1;
                fs1.open("delstinfo.txt",ios::out|ios::ate);
                fs.seekg(0);
                while(!fs.eof())
                {
                    fs.read((char*)&f,sizeof(Admin));
                    f.delstsub();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("delstinfo.txt","stinfo.txt"); 
            }
            if(inchoice==5)
            {
               fstream fs;
                fstream fs1;
                fs.open("stinfo.txt",ios::in|ios::binary);
                fs.seekg(0);
                fs1.open("modstinfo.txt",ios::out|ios::ate);
                while(!fs.eof())
                {
                    fs.read((char*)&f,sizeof(Admin));
                    f.modstprofile();
                    fs1.write((char*)&f,sizeof(Admin));
                }
                fs.close();
                fs1.close();
                remove("stinfo.txt");
                rename("modstinfo.txt","stinfo.txt"); 
            }
            if(inchoice<1||inchoice>5)
            {
               cout<<"\nInvalid Input Provide "<<endl; 
            }
            cout<<"\n\t\t\tEnter To Continue "<<endl;
            getchar();
            cout<<"\nEnter y otherwise n";
            cin>>moreop;
            if(moreop!='Y'&&moreop!='y')
            {
                system("cls");
                cout<<"\n\n\t\t\t\tThank You";
                getchar();
                exit(0);
            }
        }while(moreop=='Y'||moreop=='y');
        getchar();
    }
    if(ch<1||ch>3)
    {
        cout<<"\n\nInvalid Input Provided";
        getchar();
        system("cls");
        cout<<"\n\n\t\tThank You";
    }
    return 0;
}