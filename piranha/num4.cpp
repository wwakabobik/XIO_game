//-------------�������� ������ ���������-������� "�������"-------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/* ��������� ���������� �������� � ���������� */

const char filename[]="users.lib"; //������� ���� ���� ������
const char tempfile[]="old.lib";   //��������� ����-���� ���� ������
int errstat=0;                     //���������� ��� ��������� ������ ����������
int temphone;                      //���������� ��� ����������� � ������� (�����)
int tempweight=0;                  //���������� ��� ������ �������� �������� (��������� ���� ������)
char tempchat[61];                 //����-���������� ��� �������� ��������� ������
char temptalk[21];                 //����-���������� ��� �������������� ������ ��� �������� ���������
char tempname[21];                 //���������� ��� ������ ����� �������� (��������� ����� ������)

struct unit {     //������������� ��������� ���� ������
int phone;        //���������� ������ �������� ---!!!---���� ������ 7 ����---!!!---
int weight;       //���������� �������� �������� (����)
int status;       //���������� ������� (��� ��������� ������� ��������)
int answer;       //���������� ������� ������� (��� ��������� ������� �������)
char name[21];    //��� ������
char enemy[21];   //��� ����������/�����������
char chat[61];    //������� ��������� ���������
} user;

rewrite() //������� ������ � �� (����������)
{
int k1, k2;                          //��������, ��������� ������������ ������
ifstream r;                     //������ �����
ofstream w;                     //������ � ���� (������� ����������)
r.open(filename);               //������ �� ��������� ����� ��
if(!r)
{
cout << "Error open file";
getch();
exit(1);
}
w.open(tempfile, ios::app);     //������ �� ��������� ����
if(!w)
{
cout << "Error open file";
getch();
exit(1);
}
w << "0 0 0 0 0 0 0\n";         //������� ������� (������ ��)
w << user.phone << " " << user.weight << " " << user.status << " " << user.answer << " " << user.name << " " << user.enemy << " " << user.chat << " " <<endl;
while (!r.eof())
{
strcpy(tempname, user.name);   //���������� � ���� ��������� ������������ ���
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
k1=strcmp(temptalk, user.name);
k2=strcmp(tempname, user.name); //���������, ���������� �� ��� ���
if (user.phone==0) k1=0;        //�������� �� ���� (�� ������ ����� ��� ������ ����������)
if (k1!=0 && k2!=0)                      //�������� ���������
w << user.phone << " " << user.weight << " " << user.status << " " << user.answer << " " << user.name << " " << user.enemy << " " << user.chat << " " <<endl;
}
r.close();
w.close();
ofstream f;                     //�������� ����������� �����
f.open(filename,ios::trunc);    //�������� �������� ��
if(!f)
{
cout << "Error open file";
getch();
exit(1);
}
f.close();
r.open(tempfile);               //������ �� ���������� �����
if(!r)
{
cout << "Error open file";
getch();
exit(1);
}
w.open(filename, ios::app);     //������ � �������� ���� ��
if(!w)
{
cout << "Error open file";
getch();
exit(1);
}
w << "0 0 0 0 0 0 0\n";         //������� ������� (������ ��)
while (!r.eof())
{
strcpy(tempname, user.name);
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
k2=strcmp(tempname, user.name); //���������, ���������� �� ��� ���
if (user.phone==0) k2=0;
if (k2!=0)
w << user.phone << " " << user.weight << " " << user.status << " " << user.answer << " " << user.name << " " << user.enemy << " " << user.chat << " " <<endl;
}
r.close();
w.close();
f.open(tempfile,ios::trunc);     //�������� ����������� ���������� �����
if(!f)
{
cout << "Error open file";
getch();
exit(1);
}
f.close();
return 0;
}

sentmes()  //�������� ��������� ������� ������
{
strcpy(tempname, user.name);    //��� �������� ������ ���������� � ����
int k=0;                        //��������, ��������� ������������ ������
errstat=0;                      //��������� ���������� ��� ��������� ������ ����������
cout << "Choose companion: "; cin >> temptalk;   //������ ����� ������, �������� ���������� ���������
cout << "\nWhat do you want to say to " << temptalk << "? Max 60 simbols\n"; cin >> tempchat; //������ ������ ��������� (���������� 60 ���������)
/* � ����� ������ ������������ ��� ������ ������
   � ����� ������, �������������� ������������ ����� �� ���� ���
   ---!!!---��������---!!!---
   ��� ����� ������� ������ ��� �������, ������� ��� "_"
   ����� ��� �������� ����� ������ ��� �������� �������������
   ---!!!---��������---!!!--- */
ifstream r;                     //����� ������ �� ��
r.open(filename);               //������ �� ��
if(!r)
{
cout << "Error open file. Programm terminated.";
getch();
exit(1);
}
while (!r.eof() || errstat!=0) //�� ����� �� ��� �� ����������� ������
{
k = 0;
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
k=strcmp(temptalk, user.name); //��������� ������� ���������� � ����-��������
if (k==0)
{
errstat++;                     //���� ����������, �� ���������� ��������, ����������� ����
break;
}
}
if (k!=0) exit(1);
r.close();
user.answer=9;                //���������� ��� ������� ��� ������ ������
strcpy(user.enemy, tempname); //� ���� ��������� ����������� ������ ���������� ������,
strcpy(user.chat, tempchat);  //���������� ������� �������
return 0;
}

readbase() //������ �� �� � ��������� �������� ��� �������� ������
{
errstat = 0;
ifstream r;                     //����� ������ ��
r.open(filename);
if(!r)
{
cout << "Error open file. Programm terminated.";
getch();
exit(1);
}
while (!r.eof() || errstat!=0)
{
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
//cout << "User phone: "<< user.phone << "\nUser weight: " << user.weight << "\nUser status: " << user.status << "\nUser answer: " << user.answer << "\nUser name: " << user.name << "\n";
if (temphone==user.phone)       //��������� ������� � �� � ���������� ����� (���������) ������
{
errstat++;
break;
}
}
r.close();
return 0;
}

newbase() //�������� ������ � �� � ����� ������
{
ofstream w;
w.open(filename, ios::app); //���������� ������ � ����� ��
if(!w)
{
cout << "Error open file. Programm terminated.";
getch();
exit(1);
}
user.phone=temphone; //
user.weight=10;      // ���������
user.status=0;       //  ��
user.answer=0;       //   ���������
user.enemy[0]='\0';  //
user.chat[0]='\0';   //
cout << "\nUser name: "; cin >> user.name; //������� ������ ������ �����
/* ---!!!---��������---!!!---
���� � ��������� �� ������������� �������� ��
������ � ������������ ������� ������ ����������� �����
---!!!---��������---!!!--- */
w << user.phone << " " << user.weight << " " << user.status << " " << user.answer << " " << user.name <<  " " << user.enemy << " " << user.chat <<"\n";
w.close();
exit(1);
return 0;
}

auth() //����������� ������ � �������
{
readbase();     //����� ��������� ��
if (errstat==0) //���� �� �������
newbase();      //���������� �����������
return 0;
}

viewself()     //�������� ��������� �������� ������ !!!---� ���������� ����������---!!!
{
cout << "\n\nUser phone: "<< user.phone << "\nUser weight: " << user.weight << "\nUser status: " << user.status << "\nUser answer: " << user.answer << "\nUser name: " << user.name << "\nUser enemy: " << user.enemy << "\nUser chat: " << user.chat <<"\n";
getch();
return 0;
}


viewlider()  //�������� ������ ---!!!---���� ������ ������---!!!---
{
ifstream r;        //������ �� ��
r.open(filename);
if(!r)
{
cout << "Error open file. Programm terminated.";
getch();
exit(1);
}
while (!r.eof()) //��������������� ��� �� �����
{
r >> user.phone >> user.weight >> user.status >> user.answer >> user.name >> user.enemy >> user.chat;
if (tempweight<user.weight)
{
tempweight=user.weight;         //����-���������
strcpy(tempname, user.name);    //������������� �������� ������
}
}
r.close();
cout << "\n\nCurrent lider " << tempname << " with " << tempweight << " weight\n"; //����� ����������
getch();
exit(1);
return 0;
}

menu() //������� ���� ���������� ����������
{
char buf;
cout << "\n\nEnter operation:\nS: Sleep\nH: Hunt\nD: Defend\nR: Rating\nV: View self\nC: Chat\n";
cin >> buf;
switch(buf)
{
case 'S':          //��������������� �����, � ������� ������ � ������� ������� ���������� ��� (����)
user.status=0;
break;
case 'H':          //��������������� �����, � ������� ���� ��������� � ������� �� ������ �����
user.status=3;
break;
case 'D':         //��������������� ����� ������ (��� ����� �� � ������������ ������)
user.status=2;
break;
case 'R':         //�������� ������
viewlider();
break;
case 'V':         //�������� ����������� ����������
viewself();
break;
case 'C':         //�������� ��������� ������� ������
sentmes();
break;
}
rewrite();
return 0;
}

revstat() //������� ��������� ������� �������
{
if (user.answer==3)
 {
 cout << "You have been attacked " << user.enemy << ".\nResult: you defeated";
 user.answer=0;
 }
if (user.answer==2)
 {
 cout << "You have been attacked " << user.enemy << ".\nResult: you win";
 user.answer=0;
 }
if (user.answer==1)
 {
 cout << "You have been attacked " << user.enemy << ".\nResult: draw";
 user.answer=0;
 }
if (user.answer==6)
 {
 cout << "You attack " << user.enemy << ".\nResult: you defeated";
 user.answer=0;
 }
if (user.answer==5)
 {
 cout << "You attack " << user.enemy << ".\nResult: you win";
 user.answer=0;
 }
if (user.answer==4)
 {
 cout << "You attack " << user.enemy << ".\nResult: draw";
 user.answer=0;
 }
if (user.answer==9)
 {
 cout << endl << user.enemy << " said: \"" << user.chat << "\"";
 user.answer=0;
 rewrite();
 getch();
 exit(1);
 }
return 0;
}

main() //������� ��������� � ������� �����������, ��������� ������� � ����
{
cout << "Enter your phone number: "; cin >> temphone;
auth();
revstat();
menu();
return 0;
}

