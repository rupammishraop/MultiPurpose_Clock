#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include<conio.h>
#include<cstdio>
#include<windows.h>

using namespace std;

void coordination(int a, int b)
{
  COORD c;
     c.X = a;
     c.Y = b;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void Question_clock()
{
    int n;
    double d;
    string k;
     system("CLS");

     // 1st Question
    while(true)
    {
        coordination(20,8);
    cout << "what is the capital of japan : ? \n ";
    coordination(20,9);
    cin>>k;
    if(k=="TOKYO" || k=="Tokyo" || k=="tokyo")
        {
            coordination(20,10);
            cout<<" right answer"<<endl;
            getch();
            system("CLS");

             break;
        }
        else{
            coordination(20,10);
            cout<<"Wrong Answer"<<endl;
            getch();
            system("CLS");
        }
}


 // 2nd Question



 while(true)
    {
        coordination(20,8);
    cout << " 2.what is the value of 13 + 24 = \n ";
    coordination(20,9);
    cin>>k;
    if(k=="37")
        {
            coordination(20,10);
            cout<<" right answer"<<endl;
            getch();
            system("CLS");

             break;
        }
        else{
                coordination(20,10);
            cout<<"Wrong Answer"<<endl;
            getch();
            system("CLS");
        }
        }

  // 3rd Question
    while(true)
    {
        coordination(20,8);
    cout << " 3. What is the capital of Bihar";
    coordination(20,9);
    cin>>k;
    if(k=="PATNA" || k=="Patna" || k=="patna")
        {
            coordination(20,10);
            cout<<" right answer"<<endl;
            getch();
            system("CLS");

             break;
        }
        else{
                coordination(20,10);
            cout<<"Wrong Answer"<<endl;
            getch();
            system("CLS");
        }
        }

    //4th Question

    while(true)
    {
        coordination(20,8);
    cout << " 2.888 + 88 + 8 + 8 + 8 = \n ";
    coordination(20,9);
    cin>>k;
    if(k=="1000")
        {
            coordination(20,10);
            cout<<" right answer"<<endl;
            getch();
            system("CLS");

             break;
        }
        else{
                coordination(20,10);
            cout<<"Wrong Answer"<<endl;
            getch();
            system("CLS");
        }
        }
        coordination(30,10);
        cout<<"Good Morning"<<endl;
        exit(0);
}


