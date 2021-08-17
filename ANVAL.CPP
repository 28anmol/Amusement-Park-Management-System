#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>
struct rides
{
int rid;
int eidr;
char rname[30];
char rintro[40];
float rprice;
char func;
float rbill;
};
struct member
{
int mid;
float mdue;
float mpay;
char mname[30];
char mgen;
float mprice;
char cno[10];
char addr[50];
char adhno[20];
char mob[12];
char mtype[5];
};
struct rest
{
char iname[30];
float iprice;
int fid;
float rebill;
};

void addride()
 {
 fstream f;
 f.open("rides.dat",ios::app|ios::binary);

 rides x;
 top:
 clrscr();
  cout<<"Enter ride ID:";
    cin>>x.rid;
  cout<<"Enter name of ride:";
    gets(x.rname);
  cout<<"Enter summary of ride:";
    gets(x.rintro);
  cout<<"Enter price of ride:";    //not more than 200//
    cin>>x.rprice;
  cout<<"Is the ride functioning?(Y/N)";
  cin>>x.func;
  cout<<"Are you sure [Y/N]";
    char ch;
    cin>>ch;

 if(ch=='Y' || ch=='y')
    f.write((char*)&x,sizeof(x));
 else goto top;

 f.close();
}


////////////////////////////////////////////////////////////////////////////////


void memadd()          //adding MEMBERS//
{
 fstream f;
 int flag1;
 member x,y;
 top:
 flag1=0;
 clrscr();
 cout<<"Enter member ID: ";
 cin>>x.mid;
 f.open("member.dat",ios::in|ios::binary);
  while(f.read((char*)&y,sizeof(y)))
  {
    if(x.mid==y.mid)
     {
       flag1=1;
       break;
     }
   }
   f.close();
 if(flag1==1)
 {
 cout<<"THIS ID ALREADY EXIST. TRY AGAIN.";
 getch();
 goto top;
 }
 cout<<"\n\nEnter Member Name :";
 gets(x.mname);
 p:
 cout<<"\n\nEnter Gender :";
 cin>>x.mgen;
 if(x.mgen=='m'||x.mgen=='f'||x.mgen=='M'||x.mgen=='F')
 {;
 }
 else
 {
 cout<<"\n\nPLEASE ENTER CORRECT GENDER !\n";
 getch();
 goto p;
 }
 cout<<"\n\nEnter Card Number :";
 gets(x.cno);
 cout<<"\n\nEnter Adhar Number :";
 gets(x.adhno);
 cout<<"\n\nEnter Address :";
 gets(x.addr);
 a:
 cout<<"\n\nEnter Mobile Number :";
 gets(x.mob);
 if(strlen(x.mob)>10||strlen(x.mob)<10)
 {
 cout<<"\n\nENTER CORRECT MOBILE NUMBER !";
  goto a;
 }
else
{
int mf=0;
for(int i=0;i<strlen(x.mob);i++)
 if(!isdigit(x.mob[i])) mf=1;

if(mf==1)
 {
  cout<<"\n\nENTER CORRECT MOBILE NUMBER !";
  goto a;
 }
}

 flag:
 cout<<"\n\nMembership types are :\n\n 1. VIP\n\n 2. GENERAL\n\n ENTER CHOICE: ";
 int m;
 cin>>m;
 switch(m)
 {
 case 1: strcpy(x.mtype,"VIP"); x.mprice= 2000; x.mdue=1000; break;
 case 2: strcpy(x.mtype,"GENERAL"); x.mdue=1000; x.mprice=1000; break;
 default: goto flag;
 }
 cout<<"\n\nThe amount credited to expense : "<<x.mprice;
 f:
 cout<<"\n\nAmount to be paid : "<<x.mdue;
 cout<<"\n\nPlease pay the amount : ";
 float n;
 cin>>n;
 if(n!=x.mdue)
 {
 cout<<"Please pay the correct amount!";
 goto f;
 }

 cout<<"\n\nAre you sure [Y/N]";
 char ch;
 cin>>ch;
 f.open("member.dat",ios::app|ios::binary);
 if(ch=='Y' || ch=='y')
 f.write((char*)&x,sizeof(x));
 else goto top;

 f.close();
}

///////////////////////////////////////////////////////////////////

void restadd()                   //ADD REST ITEM//
{
 fstream f;
 f.open("rest.dat",ios::app|ios::binary);

 rest x;
 top:
 clrscr();
  cout<<"Enter item id:";
    cin>>x.fid;
  cout<<"Enter name of the delicacy:";
    gets(x.iname);
  cout<<"Enter price of the delicacy:";    //not more than 100//
    cin>>x.iprice;
  cout<<"Are you sure [Y/N]";
    char ch;
    cin>>ch;

 if(ch=='Y' || ch=='y')
    f.write((char*)&x,sizeof(x));
 else goto top;

 f.close();
}

///////////////////////////////////////////////////////////////////



void disprid()
{
fstream f;
f.open("rides.dat",ios::in|ios::binary);
 rides s;
 while(f.read((char*)&s,sizeof(s)))
 {
clrscr();
cout<<"\n\nRide ID:"<<s.rid;
cout<<"\n\nRide name:"<<s.rname;
cout<<"\n\nFuntioning:"<<s.func;
cout<<"\n\nPrice of ride:"<<s.rprice;
cout<<"\n\nRide intro:"<<s.rintro;

cout<<" \n\nPress enter to view next ride.";
getch();
 }
 f.close();
}

////////////////////////////////////////////////////////////

void dispmem()
{
fstream f;
f.open("member.dat",ios::in|ios::binary);
member s;
int n,i=0;
x:
clrscr();
cout<<"Enter member ID:";
cin>>n;
while(f.read((char*)&s,sizeof(s)))
{
if(n==s.mid)
{
clrscr();
cout<<"\n\n Member name:"<<"   "<<s.mname;
cout<<"\n\n Member ID:"<<"   "<<s.mid;
cout<<"\n\n Membership type:"<<"   "<<s.mtype;
cout<<"\n\n Member gender:"<<"   "<<s.mgen;
cout<<"\n\n Address:"<<"   "<<"   "<<s.addr;
cout<<"\n\n Card number:"<<"   "<<s.cno;
cout<<"\n\n Adhar number:"<<"   "<<s.adhno;
cout<<"\n\n Mobile number:"<<"   "<<s.mob;
cout<<"\n\n Amount left in account:"<<"   "<<s.mprice;
i++;
}
 }
if(i==0)
{
cout<<"\n\nPlease enter correct ID !";
goto x;
}
 getch();
 f.close();
}

/////////////////////////////////////////////////////////////

void disprest()
{
fstream f;
f.open("rest.dat",ios::in|ios::binary);
rest s;

cout<<"                MENU                   "<<endl<<endl<<endl;
cout<<"ID            ITEM NAME           PRICE"<<endl<<endl;

while(f.read((char*)&s,sizeof(s)))
{
cout<<"\n\n"<<s.fid<<"           "<<s.iname<<"           "<<s.iprice<<"\n\n";
}

f.close();
}
////////////////////////////////////////////////////////////////////
void billrid()
{
fstream f;
f.open("member.dat",ios::in|ios::binary);
fstream g;
g.open("tem.dat",ios::out|ios::binary);
fstream h;
h.open("rides.dat",ios::in|ios::binary);
 int pr,pr2;
 rides y;
 cout<<"enter ride id;";
 int r=0;
 cin>>r;
 cout<<"enter member id:";
 int m=0;
 cin>>m;
 while(h.read((char*)&y,sizeof(y)))
 {
	if(y.rid==r)
	pr=y.rprice;
 }
 h.close();
 member x;
 int k=0;
 while(f.read((char*)&x,sizeof(x)))
 {
	if(x.mid==m)
	{	pr2=x.mprice;
		if(pr2>=pr)
		{	x.mprice-=pr;
			cout<<"\n\nTRANSACTION COMPLETE !";

			getch();
			k=1;
		}
		else
		{	cout<<"You don't have enough balance come some other time. ";
			cout<<"\nHave a nice day!!!";
			getch();
			goto down;
		}
	}
	g.write((char*)&x,sizeof(x));
 }
 down:
 g.close();
 f.close();
 if(k==1)
 {
 remove("member.dat");
 rename("tem.dat","member.dat");
 }
 f.open("member.dat",ios::in|ios::binary);
 while(f.read((char*)&x,sizeof(x)))
 {	if(x.mid==m)
		cout<<"Member balance is "<<x.mprice<<endl;
 }
 f.close();
 getch();
}

//////////////////////////////////////////////////////////////////////////

void billrest()
{
fstream f;

fstream g;
g.open("tem.dat",ios::out|ios::binary);
fstream h;

 float pr,pr2;
 rest y;

top:
cout<<"\n\nEnter Item  ID:";
int r;
cin>>r;
int flag1=0;
 h.open("rest.dat",ios::in|ios::binary);
  while(h.read((char*)&y,sizeof(y)))
  {
    if(r==y.fid)
     {
       flag1=1;
       break;
     }
   }
   h.close();
 if(flag1!=1)
 {
 cout<<"ENTER CORRECT ITEM ID !";
 getch();
 goto top;
 }

 top1:
 flag1=0;
 member z;
 cout<<"\n\nEnter member ID: ";
 int a;
 cin>>a;
 f.open("member.dat",ios::in|ios::binary);
  while(f.read((char*)&z,sizeof(z)))
  {
    if(a==z.mid)
     {
       flag1=1;
       break;
     }
   }
   f.close();
 if(flag1!=1)
 {
 cout<<"PLEASE ENTER CORRECT ID.";
 getch();
 goto top1;
 }
f.close();

 h.open("rest.dat",ios::in|ios::binary);
 while(h.read((char*)&y,sizeof(y)))
 {	if(y.fid==r)
	pr=y.iprice;
 }
 h.close();
 member x;
 int k=0;
 f.open("member.dat",ios::in|ios::binary);
 while(f.read((char*)&x,sizeof(x)))
 {
	if(x.mid==a)
	{	pr2=x.mprice;
		if(pr2>=pr)
		{	x.mprice-=pr;
			cout<<"\n\nYOUR ORDER HAS BEEN PLACED !";
			getch();
			k=1;
		}
		else
		{	cout<<"\n\nYou don't have enough balance come some other time. ";
			cout<<"\n\nHave a nice day!!!";

			goto down;
		}
	}
	g.write((char*)&x,sizeof(x));
 }
 down:
 g.close();
 f.close();
 if(k==1)
 {
 remove("member.dat");
 rename("tem.dat","member.dat");
 }
 else
	remove("tem.dat");
}

/////////////////////////////////////////////////////////////////////////////

void addcred()
{

fstream f;


int flag1=0,m=0;
 member z;
 top1:
 cout<<"\n\nEnter member ID: ";

 cin>>m;

 f.open("member.dat",ios::in|ios::binary);
 while(f.read((char*)&z,sizeof(z)))
  {
    if(m==z.mid)
     {
       flag1=1;
       break;
     }
   }

 if(flag1!=1)
 {
 cout<<"PLEASE ENTER CORRECT ID.";
 getch();
 goto top1;
 }
f.close();


cout<<"\n\nSPECIAL OFFER !!!!";
cout<<"\n PRICE:1000  CREDIT:1200";
cout<<"\n Would you like to avail the offer ?(Y/N):";
char p;
cin>>p;
if(p=='y'||p=='Y')
{
z.mprice+=1200.0;
z.mdue+=1000.0;
cout<<"\nAmount Paid:"<<z.mdue;
cout<<"\nAmount Credited:"<<z.mprice;
}

else if(strcmp(z.mtype,"VIP")==0)
{
int f;
cout<<"\nEnter Price:";
cin>>f;
z.mdue+=f;
z.mprice=z.mprice+f+f;
cout<<"Amount Paid:"<<z.mdue;
cout<<"Amount Credited:"<<z.mprice;
}
else if(strcmp(z.mtype,"GENERAL")==0)
{
int p;
cout<<"\nEnter Price:";
cin>>p;
z.mdue+=p;
z.mprice+=z.mdue;
cout<<"Amount Paid:"<<z.mdue;
cout<<"Amount Credited:"<<z.mprice;
}
member z2;
fstream g;
f.open("member.dat",ios::in|ios::binary);
g.open("t.dat",ios::out|ios::binary);
while(f.read((char*)&z2,sizeof(z2)))
{	if(z2.mid==m)
		z2=z;
g.write((char*)&z,sizeof(z));
}

g.close();
f.close();
if(flag1==1)
{
remove("member.dat");
rename("t.dat","member.dat");
}
}

//////////////////////////////////////////////////////////////////////////

void delmem()
{
int m;
cout<<"Enter member ID:";
cin>>m;
fstream f,g;
member z2;
f.open("member.dat",ios::in|ios::binary);
g.open("t.dat",ios::out|ios::binary);
while(f.read((char*)&z2,sizeof(z2)))
{	if(z2.mid!=m)
g.write((char*)&z2,sizeof(z2));
}

g.close();
f.close();
remove("member.dat");
rename("t.dat","member.dat");
}

/////////////////////////////////////////////////////////////




void ANVAL()
{
loop1:
while(1)
{
clrscr();
cout<<"     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
cout<<"     |             WELCOME TO THE AMUSEMENT PARK.          |"<<endl;
cout<<"     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
cout<<"     |    A place to spend time with Family and Friends.   |"<<endl;
cout<<"     |                                                     |"<<endl;
cout<<"     |                        MENU                         |"<<endl;
cout<<"     |                                                     |"<<endl;
cout<<"     |       1.            RIDES.                          |"<<endl;
cout<<"     |       2.            MEMBERSHIP.                     |"<<endl;
cout<<"     |       3.            RESTAURENT.                     |"<<endl;
cout<<"     |       4.            EXIT.                           |"<<endl;
cout<<"     |                                                     |"<<endl;
cout<<"     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout<<endl<<endl;
cout<<"     SELECT ANY OF THE ABOVE OPTION : ";
int ch;
cin>>ch;
switch(ch)
{
case 1:             //main menu//
int ch1;
while(1)
{
clrscr();
cout<<"     *******************************************************"<<endl;
cout<<"     *              WELCOME TO THE RIDES MENU.             *"<<endl;
cout<<"     *******************************************************"<<endl;
cout<<"     +                                                     +"<<endl;
cout<<"     +                        MENU                         +"<<endl;
cout<<"     +                                                     +"<<endl;
cout<<"     +       1.            LIST OF RIDES.                  +"<<endl;
cout<<"     +       2.            ADD A RIDE.                     +"<<endl;
cout<<"     +       3.            USE A RIDE.                     +"<<endl;
cout<<"     +       4.            RETURN TO MENU.                 +"<<endl;
cout<<"     +                                                     +"<<endl;
cout<<"     *******************************************************"<<endl;
cout<<endl<<endl;
cout<<"     ENTER ANY OF THE ABOVE OPTION : ";
cin>>ch1;
switch(ch1)
{
case 1:
clrscr();
disprid();
break;
case 2:
clrscr();
addride();
break;
case 3:
clrscr();
billrid();
break;
case 4:
clrscr();
cout<<endl<<endl<<endl;
cout<<" \t\t   PRESS ANY KEY TO RETURN TO THE MAIN MENU.";
getch();
goto loop1;
}//ride switch
}//ride while
case 2:                   //main menu//
int ch2;
while(1)
{
clrscr();
cout<<"     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"     $              WELCOME TO THE MEMBERSHIP MENU.        $"<<endl;
cout<<"     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"     *                                                     *"<<endl;
cout<<"     *                        MENU                         *"<<endl;
cout<<"     *                                                     *"<<endl;
cout<<"     *       1.            NEW MEMBER.                     *"<<endl;
cout<<"     *       2.            DISPLAY MEMBER INFO.            *"<<endl;
cout<<"     *       3.            MEMBER REMOVAL.                 *"<<endl;
cout<<"     *       4.            ADD CREDIT.                     *"<<endl;
cout<<"     *       5.            RETURN TO MENU.                 *"<<endl;
cout<<"     *                                                     *"<<endl;
cout<<"     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<endl<<endl;
cout<<"     ENTER ANY OF THE ABOVE OPTION : ";
cin>>ch2;
switch(ch2)
{
case 1:
clrscr();
memadd();
break;

case 2:
clrscr();
dispmem();
break;

case 3:
clrscr();
delmem();
break;

case 4:
clrscr();
addcred();
break;

case 5:
clrscr();
cout<<endl<<endl<<endl;
cout<<" \t\t   PRESS ANY KEY TO RETURN TO THE MAIN MENU.";
getch();
goto loop1;
}//MEM switch
}//MEM while

case 3:       //main menu//
int ch3;
while(1)
{
clrscr();
cout<<"     !@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!"<<endl;
cout<<"                    WELCOME TO THE RESTAURENT.              "<<endl;
cout<<"     !@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!"<<endl;
cout<<"     +                                                     +"<<endl;
cout<<"     +                        MENU                         +"<<endl;
cout<<"     +                                                     +"<<endl;
cout<<"     +       1.           FOOD MENU/PLACE AN ORDER.        +"<<endl;
cout<<"     +       2.           ADD A DISH.                      +"<<endl;
cout<<"     +       3.           RETURN TO MENU.                  +"<<endl;
cout<<"     +                                                     +"<<endl;
cout<<"     !@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!"<<endl;
cout<<endl<<endl;
cout<<"     ENTER ANY OF THE ABOVE OPTION : ";
cin>>ch3;
switch(ch3)
{
case 1:
clrscr();
disprest();
cout<<"DO YOU WANT TO PLACE AN ORDER? (Y/N):";
char ch;
cin>>ch;
if(ch=='Y'||ch=='y')
{
billrest();
}
else
{
clrscr();
cout<<"HAVE A NICE DAY!"<<endl;
cout<<endl<<endl<<endl;
cout<<" \t\t   PRESS ANY KEY TO RETURN TO THE MAIN MENU.";
getch();
}
break;
case 2:
clrscr();
restadd();
break;
case 3:
clrscr();
cout<<endl<<endl<<endl;
cout<<" \t\t   PRESS ANY KEY TO RETURN TO THE MAIN MENU.";
getch();
goto loop1;
}//RES switch
}//RES while
case 4:      // main menu//

exit(0);
default:
clrscr();
cout<<"INVALID INPUT :"<<endl;
cout<<"PRESS ANY KEY TO GO BACK TO THE MAIN MENU :"<<endl;
getch();
}//outer switch
}//while
}



void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 a:
 setbkcolor(1);
 textcolor(5);
 setcolor(15);
settextstyle(1,0,2);
 outtextxy(210,330,"COMPUTER PROJECT");
 outtextxy(210,360,"YEAR : 2016-2017");
outtextxy(20,420,"PROGRAMMERS : AVIRAL AMIT SRIVASTAV AND ANMOL SINGH");
settextstyle(3,1,6);
outtextxy(10,1,"AMUSEMENT");
settextstyle(3,1,8);
outtextxy(540,25,"PARK");
 setcolor(15);
 line(0,400,640,400);
 line(0,400,320,5);
 line(320,5,640,400);
 line(65,319,575,319);
 line(320,200,320,5);
 line(65,319,320,200);
 line(320,200,575,319);
settextstyle(1,0,4);
outtextxy(280,100,"1");
outtextxy(210,150,"START.");
outtextxy(345,100,"3");
outtextxy(345,150,"EXIT.");
outtextxy(313,220,"2");
outtextxy(215,260," INFORMATION.");
int i=0;
char ch;
while(!kbhit())
{
setcolor(i);
delay(50);
settextstyle(1,0,2);
outtextxy(230,450," ENTER CHOICE! ");
delay(50);
outtextxy(230,450,"               ");
i++;
delay(10);
}

ch=getch();
switch(ch)
{
case '1':
cleardevice();
closegraph();
restorecrtmode();
clrscr();
ANVAL();
break;

case '2':
clrscr();
setcolor(14);
settextstyle(4,0,5);
outtextxy(110,10,"The Pearl Paradise Park");
settextstyle(1,0,1);
outtextxy(1,100,"Our theme park is a group of entertainment attractions, rides,");
outtextxy(1,150,"and other events in a location for the enjoyment of large numbers");
outtextxy(1,200,"of people.Amusement parks have a fixed location,as opposed to");
outtextxy(1,250,"travelling funfairs and traveling carnivals,and are more elaborate ");
outtextxy(1,300,"than simple city parks or playgrounds, usually providing");
outtextxy(1,350,"attractions meant to cater you.");
getch();
break;




case '3':
clrscr();
setcolor(14);
settextstyle(4,0,20);
outtextxy(20,140,"Thank You");
getch();
exit(0);
break;

default:
goto a;
}

closegraph();
restorecrtmode();

}