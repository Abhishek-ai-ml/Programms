#include<fstream>
#include<string>
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class state
{
public: void password();
void addition(void);
void modification(void);
void deletion(void);
void list(void);
void search(void);
float amount(char [], float, char);
int foundcode(char []);
private:
char stcode[10], name[20];
float doc,docadd,ndoc,ndocadd;
};
class Date
{
public:
int valid(void);
int dd,mm,yy;
};
class customer
{
public:
void booking(void);
void search(void);
void dailylist(void);

void monthlylist(void);
private:
int lastcustcode(void);
int custcode;
char name[20], address[30],phone[10], stcode[10], cname[20], caddress[30],cphone[10], type;
float weight, amount;
Date DoB;
};
// Function To Check The Validity Of The Given Date
int Date :: valid(void)
{
int days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
if ((yy<1900 || dd<1 || dd>31 || mm<1|| mm>12) ||
((dd>days[mm]) || ((yy%4!=0) && mm==2 && dd>28)))
return 0;
else
return 1;
}
// FUNCTION RETURN LAST CODE NO. OF THE COUSTOMER
int customer :: lastcustcode(void)
{
int tcode=0;
fstream f;
f.open("customer.dat",ios::in);
while (f.read((char*) this,sizeof(customer)))
tcode = custcode;
f.close();
return tcode;
}
// FUNCTION TO BOOK COURIER FOR THE CUSTOMER
void customer :: booking(void)
{
system("cls");
char tstcode[10], ch;
int tcustcode;
state s;
cout<<"BOOKING COURIER\n\n";
cout<<"Enter Station Code (Destination) :";
gets(tstcode);
if(!s.foundcode(tstcode))
{
cout<<"\n\nStation code does not exist.";
getchar();

return;
}
cout<<"\nINPUT CONSINOR INFORMATION";
tcustcode = lastcustcode()+1;
cout<<"\n\nCustomer Code : "<<tcustcode;
cout<<"\nEnter Name of the consinor : ";
gets(name);
cout<<"Enter Address of the consinor : ";
gets(address);
cout<<"Enter Phone no. of the consiner : ";
gets(phone);
cout<<"\n\nINPUT CONSINEE INFORMATION";
cout<<"\n\nEnter Name of the consinee : ";
gets(cname);
cout<<"Enter Address of the consinee : ";
gets(caddress);
cout<<"Enter Phone no.of the consinee : ";
gets(cphone);
cout<<"\n";
while(1)
{
cout<<"Enter date of Booking(dd mm yy):";
cin>>DoB.dd>>DoB.mm>>DoB.yy;
if(DoB.valid())
break;
else
cout<<"Invalid Date\n";
}
do
{
cout<<"\nEnter Type of courier(D=Doc. N=Non doc.):";
type=getchar();
type=toupper(type);
}
while(type!='D'&&type!='N');
cout<<"\nEnter Weight(in gms):";
cin>>weight;
amount=s.amount(tstcode,weight,type);
cout<<"Amount:"<<amount<<"\n";
do
{
cout<<"\nSave?(y/n):";
ch=getchar();
ch=toupper(ch);
}
while(ch!='Y'&&ch!='N');
if(ch=='Y');
{
strcpy(stcode,strupr(tstcode));
custcode=tcustcode;

fstream f;
f.open("customer.dat",ios::app);
f.write((char*)this,sizeof(customer));
f.close();
cout<<"\n\nRecord Saved";
getchar();
}
}
//FUNCTION TO SEARCH FOR THE CUSTOMER RECORD
void customer::search(void)
{
int tcode;
system("cls");
cout<<"Search Customer Record\n\n";
cout<<"Enter Custoer Code:";
cin>>tcode;
fstream f;
int found=0;
f.open("customer.dat",ios::in);
while(f.read((char*)this,sizeof(customer)))
{
if(tcode==custcode)
{
found=1;
cout<<"\nStation Code:"<<stcode;
cout<<"\n\nConsinor Information";
cout<<"\n\nName Of The Consinor:"<<name;
cout<<"\nAddress Of The Consinor:"<<address;
cout<<"\nPhone no.of hte consinor:"<<phone;
cout<<"\n\nConsinee Information";
cout<<"\n\nName of the Consinee:"<<cname;
cout<<"\nAddress of the consinee:"<<caddress;
cout<<"\nPhone no.of hte consinee:"<<cphone;
cout<<"\n\nDate of booking:"<<DoB.dd<<"/"<<DoB.mm<<"/"<<DoB.yy;
if(type=='D')
cout<<"\nType of courier:Document";
else
cout<<"\n Type of courier:Non-Document";
cout<<"\n Weight(in gms):"<<weight;
cout<<"\nAmount:Rs."<<amount;
break;
}
}
f.close();
if(!found)
cout<<"\n\nCustomer code does not exist.";
getchar();
}
//FUNCTION TO DISPLAY DAILY LIST OF THE BOOKING STATUS

void customer::dailylist(void)
{
system("cls");
Date tdate;
while(1)
{
cout<<"Enter Date Of Booking(dd mm yy):";
cin>>tdate.dd>>tdate.mm>>tdate.yy;
if(tdate.valid())
break;
else
cout<<"Invalid Date\n";
}
system("cls");
fstream f;
f.open("customer.dat",ios::in);
int row=5,found=0;
gotoxy(23,1);
cout<<"DailyBooking Status("<<tdate.dd<<"/"<<tdate.mm<<"/"<<tdate.yy<<")";
gotoxy(23,2);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
gotoxy(1,3);
cout<<"Code Consinor Consinee Station Code Type Weight Amount";
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
while(f.read((char*)this,sizeof(customer)))
{
if(tdate.dd==DoB.dd && tdate.mm==DoB.mm && tdate.yy==DoB.yy)
{
found=1;
gotoxy(2,row);
cout<<custcode;
gotoxy(7,row);
cout<<name;
gotoxy(23,row);
cout<<cname;
gotoxy(41,row);
cout<<stcode;
gotoxy(55,row);
if(type=='D')
cout<<"Doc.";
else
cout<<"Non-Doc.";
gotoxy(65,row);
cout<<weight;
gotoxy(73,row);
cout<<amount;
if(row==23)
{
row=5;
gotoxy(1,25);

cout<<"Press any key to continue";
getchar();
system("cls");
gotoxy(23,1);
cout<<"Daily Booking Status("<<tdate.dd<<"/"<<tdate.mm<<"/"<<tdate.yy<<")";
gotoxy(23,2);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
gotoxy(1,3);
cout<<"Code Consinor Cconsinee Station Code Type Weight Amount";
gotoxy(1,4);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}
else
row++;
}
}
if(!found)
{
gotoxy(5,10);
cout<<"Record Not Found";
}
gotoxy(1,25);
cout<<"Press Any Key To Continue";
getchar();
f.close();
}
//FUNCTION TO DISPLAY MONTHLY LIST OF THE BOOKING STATION
void customer::monthlylist(void)
{
system("cls");
Date tdate;
while(1)
{
cout<<"Enter Month And Year Of Booking(mm yy)";
cin>>tdate.mm>>tdate.yy;
tdate.dd=1;
if(tdate.valid())
break;
else
cout<<"Invalid Date\n";
}
system("cls");
fstream f;
f.open("customer.dat",ios::in);
int row=5,found=0;
char month[12][10]={"January","February","March","April","May","June","July"
,"August","September","October","November","December"};
gotoxy(22,1);
cout<<"Monthly Booking Status("<<month[tdate.mm-1]<<","<<tdate.yy<<")";
gotoxy(1,3);

cout<<"Code Consinor Consinee Station Code Type Weight Amount";
gotoxy(1,4);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
while(f.read((char*)this,sizeof(customer)))
{
if(tdate.mm==DoB.mm&&tdate.yy==DoB.yy)
{
found=1;
gotoxy(2,row);
cout<<custcode;
gotoxy(7,row);
cout<<name;
gotoxy(23,row);
cout<<cname;
gotoxy(41,row);
cout<<stcode;
gotoxy(55,row);
if(type=='D')
cout<<"Doc.";
else
cout<<"Non-Doc.";
gotoxy(65,row);
cout<<weight;
gotoxy(73,row);
cout<<amount;
if(row==23)
{
row=5;
gotoxy(1,25);
cout<<"Press Any Key To Continue";
getchar();
system("cls");
gotoxy(23,1);
cout<<"Daily Booking Status("<<tdate.dd<<"/"<<tdate.mm<<"/"<<tdate.yy<<")";
gotoxy(23,2);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~";
gotoxy(1,3);
cout<<"Code Consinor Consinee Station Code Type Weight Amount";
gotoxy(1,4);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}
else
row++;
}
}
if(!found)
{
gotoxy(5,10);
cout<<"Record Not Found";
}

gotoxy(1,25);
cout<<"Press Any Key To Continue";
getchar();
f.close();
}
//FUNCTION TO RETURN WHETHER STATION CODE FOUND IN STATION FILE OR NOT
int state::foundcode(char tcode[10])
{
int found=0;
fstream f;
f.open("station.dat",ios::in);
while(f.read((char*)this,sizeof(state)))
{
if(!strcmpi(tcode,stcode))
{
found=1;
break;
}
}
f.close();
return found;
}
//FUNCTION TO CALCULATE AND RETURN AMOUNT
float state::amount(char tcode[10],float weight,char type)
{
float tweight,amount=0.0;
fstream f;
f.open("station.dat",ios::in);
while(f.read((char*)this,sizeof(state)))
{
if(!strcmpi(tcode,stcode))
{
tweight=weight;
if(type=='D')
{
amount=doc;
tweight=tweight-500;
while(tweight>0)
{
amount=amount+docadd;
tweight=tweight-500;
}
}
else
{
amount=ndoc;
tweight=tweight-500;
while(tweight>0)
{
amount=amount+ndocadd;

tweight=tweight-500;
}
}
break;
}
}
f.close();
return amount;
}
//FUNCTION TO ADD NEW RECORD FOR STATION
void state::addition(void)
{
char tcode[10],ch;
system("cls");
cout<<"Add New Station Record\n\n";
cout<<"Enter Station Code";
gets(tcode);
if(foundcode(tcode))
{
cout<<"\n\nStation Code Already Exist";
getchar();
return;
}
cout<<"Enter Name Of The Station";
gets(name);
cout<<"Enter Charges For Document(upto 500g):Rs.";
cin>>doc;
cout<<"Enter Charges For Document(addition 500g):Rs.";
cin>>docadd;
cout<<"Enter Charges For Non-Document(upto 500g):Rs.";
cin>>ndoc;
cout<<"Enter Charges For Non-Document(addition 500g):Rs.";
cin>>ndocadd;
do
{
cout<<"/nSave?(y/n):";
ch=getchar();
ch=toupper(ch);
}
while(ch!='Y'&&ch!='N');
if(ch=='Y')
{
strcpy(stcode,tcode);
fstream f;
f.open("station.dat",ios::app);
f.write((char*)this,sizeof(state));
f.close();
cout<<"\n\nRecord Saved";
getchar();
}

}
//FUNCTION TO MODIFY EXISTING RECORD OF STATION
void state::modification(void)
{
char tcode[10],ch;
char tname[20];
float tdoc,tdocadd,tndoc,tndocadd;
system("cls");
cout<<"Modify Station Record\n\n";
cout<<"Enter Station Code:";
gets(tcode);
fstream f,t;
int found=0;
f.open("station.dat",ios::in);
t.open("temp.dat",ios::out);
while(f.read((char*)this,sizeof(state)))
{
if(!strcmpi(tcode,stcode))
{
found=1;
cout<<"\n\nInput New Data\n\n";
cout<<"Enter Name Of The Station:";
gets(tname);
cout<<"Enter Charges For Document(upto 500g) :Rs.";
cin>>tdoc;
cout<<"Enter Charges For Document(addition 500g) :Rs.";
cin>>tdocadd;
cout<<"Enter Charges For Non-Document(upto 500g) :Rs.";
cin>>tndoc;
cout<<"Enter Charges For Document(upto 500g) :Rs.";
cin>>tndocadd;
do
{
cout<<"\nUpdate?(y/n)";
ch=getchar();
ch=toupper(ch);
}
while(ch!='Y'&&ch!='N');
if(ch=='Y')
{
strcpy(name,tname);
doc=tdoc;
docadd=tdocadd;
ndoc=tndoc;
ndocadd=tndocadd;
t.write((char*)this,sizeof(state));
}
else
t.write((char*)this,sizeof(state));
}

else
t.write((char*)this,sizeof(state));
}
f.close();
t.close();
if(!found)
{
cout<<"\n\nStation Code Does Not Exist";
getchar();
return;
}
if(ch=='N')
return;
f.open("station.dat",ios::out);
t.open("temp.dat",ios::in);
while(t.read((char*)this,sizeof(state)))
f.write((char*)this,sizeof(state));
f.close();
t.close();
cout<<"\n\nRecord Modified";
getchar();
}
//FUNCTION TO DELETE EXISTING RECORD OF STATION
void state::deletion(void)
{
char tcode[10],ch;
system("cls");
cout<<"Delete Station Record\n\n";
cout<<"Enter Station Record";
gets(tcode);
fstream f,t;
int found=0;
f.open("station.dat",ios::in);
t.open("temp.dat",ios::out);
while(f.read((char*)this,sizeof(state)))
{
if(!strcmpi(tcode,stcode))
{
found=1;
cout<<"\nName Of The Station"<<name;
cout<<"\nCharges For Document(upto 500g) :Rs."<<doc;
cout<<"\nCharges For Document(addition 500g) :Rs."<<docadd;
cout<<"\nCharges For Non-Document(upto 500g) :Rs."<<ndoc;
cout<<"\nCharges For Non-Document(upto 500g) :Rs."<<ndocadd;
do
{
cout<<"\n\nDelete?(y/n)";
ch=getchar();
ch=toupper(ch);
}

while(ch!='Y'&&ch!='N');
if(ch=='N')
t.write((char*)this,sizeof(state));
}
else
t.write((char*)this,sizeof(state));
}
f.close();
t.close();
if(!found)
{
cout<<"\n\nStation Code Does Not Exist";
getchar();
return;
}
if(ch=='N')
return;
f.open("station.dat",ios::out);
t.open("temp.dat",ios::in);
while(t.read((char*)this,sizeof(state)))
f.write((char*)this,sizeof(state));
f.close();
t.close();
cout<<"\n\nRecord Deleted";
getchar();
}
//FUNCTION TO SEARCH RECORD FOR STATION
void state::search(void)
{
char tcode[10];
system("cls");
cout<<"Search Station Record\n\n";
cout<<"Enter Station code";
gets(tcode);
fstream f;
int found=0;
f.open("station.dat",ios::in);
while(f.read((char*)this,sizeof(state)))
{
if(!strcmpi(tcode,stcode))
{
found=1;
cout<<"\nName Of The station"<<name;
cout<<"\nCharges For Document(upto 500g) :Rs."<<doc;
cout<<"\nCharges For Document(addition 500g) :Rs."<<docadd;
cout<<"\nCharges For Non-Document(upto 500g) :Rs."<<ndoc;
cout<<"\nCharges For Non-Document(addition 500g) :Rs."<<ndocadd;
break;
}
}

f.close();
if(!found)
cout<<"\n\nStation Code Does Not Exist";
getchar();
}
//FUNCTION TO DISPLAY LIST OF THE STATIONS
void state::list(void)
{
system("cls");
fstream f;
f.open("station.dat",ios::in);
int row=5,found=0;
gotoxy(28,1);
cout<<"Station Information";
gotoxy(28,2);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~";
gotoxy(1,3);
cout<<"Code Name Charges: Doc. Additional Non.Doc Additional";
gotoxy(1,4);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
while(f.read((char*)this,sizeof(state)))
{
found=1;
gotoxy(1,row);
cout<<stcode;
gotoxy(11,row);
cout<<name;
gotoxy(40,row);
cout<<doc;
gotoxy(47,row);
cout<<docadd;
gotoxy(60,row);
cout<<ndoc;
gotoxy(69,row);
cout<<ndocadd;
if(row==23)
{
row=5;
gotoxy(1,25);
cout<<"Press Any Key To Continue";
getchar();
system("cls");
gotoxy(28,1);
cout<<"Station Information";
gotoxy(1,3);
cout<<"Code Name Charges: Doc. Additional Non Doc. Additional";
gotoxy(1,4);
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}
else

row++;
}
if(!found)
{
gotoxy(5,10);
cout<<"Record Not Found";
}
gotoxy(1,25);
cout<<"Press Any Key To Continue";
getchar();
f.close();
}
void state::password()
{
int p1,p2,p3,p4,p5,p6,p7;
cout<<"\n\n\n\n\n\n\n";
cout<<"\t\tEnter The Password";
p1=getchar();
cout<<"*";
p2=getchar();
cout<<"*";
p3=getchar();
cout<<"*";
p4=getchar();
cout<<"*";
p5=getchar();
cout<<"*";
p6=getchar();
cout<<"*";
p7=getchar();
cout<<"*";
if(p1=='C'&&p2=='O'&&p3=='U'&&p4=='R'&&p5=='I'&&p6=='E'&&p7=='R')
{
cout<<"\n\n\n\t\t\a";
cout<<"**********Password Matched************";
return;
}
else
{
cout<<"\n\n\n\n\t\t\a";
for(int y=0;y<=4;y++)
{
cout<<"_*_";
}
cout<<"Access Denied";
}
for(int t=0;t<=4;t++)
{

cout<<"_*_";
}
exit(0);
}
//MAIN FUNCTION
void main()
{
system("cls");
state s;
customer c;
char ch,ch1;
s.password();
do
{
system("cls");
gotoxy(30,6);
cout<<"DHL COURIER SERVICE";
gotoxy(30,7);
cout<<"^^^^^^^^^^^^^^^^^";
gotoxy(30,10);
cout<<"1.Station Information";
gotoxy(30,11);
cout<<"2.Booking";
gotoxy(30,12);
cout<<"3.Search Station";
gotoxy(30,13);
cout<<"4.Customer Record";
gotoxy(30,14);
cout<<"5.Reports";
gotoxy(30,15);
cout<<"6.Edit Station";
gotoxy(30,16);
cout<<"0.Quit";
gotoxy(30,18);
cout<<"Enter Your Choice";
ch=getchar();
switch(ch)
{
case'1':
s.list();
break;
case'2':
c.booking();
break;
case'3':
s.search();
break;
case'4':c.search();
break;

case'5':
do
{
system("cls");
gotoxy(34,8);
cout<<"Reports Menu";
gotoxy(34,9);
cout<<"^^^^^^^^^^^^^^^^^^^";
gotoxy(28,12);
cout<<"1.Daily Booking Status";
gotoxy(28,13);
cout<<"2.Monthly Booking Status";
gotoxy(28,14);
cout<<"0.Exit";
gotoxy(28,16);
cout<<"Enter Your Choice";
ch1=getchar();
switch(ch1)
{
case'1':
c.dailylist();
break;
case'2':
c.monthlylist();
break;
}
}
while (ch1!='0'&&ch1!=27);
break;
case'6':
do
{
system("cls");
gotoxy(31,8);
cout<<"Edit Station Menu";
gotoxy(31,9);
cout<<"^^^^^^^^^^^^^^^^^^^^^^^";
gotoxy(28,12);
cout<<"1.Add New Station Record";
gotoxy(28,13);
cout<<"2.Delete Station Record";
gotoxy(28,14);
cout<<"3.Modify Station Record";
gotoxy(28,15);
cout<<"0.Exit";
gotoxy(28,17);
cout<<"Enter Your Choice";
ch1=getchar();
switch(ch1)
{

case'1':
s.addition();
break;
case'2':
s.deletion();
break;
case'3':
s.modification();
break;
}
}
while(ch1!='0'&& ch1!=27);
break;
}
}
while(ch!='0'&& ch!=27);
}