#include<iostream>
#include<windows.h>
#include<conio.h>
#include<unistd.h>   //for sleep
#include<ctime>      //for Get Real Time From Window
#include"MMSystem.h" //for Music library
#include"Question2.h" // Header File for quiz
#include<thread>

using namespace std;


void Beep(void)
{
  PlaySound(TEXT("alarm"), NULL, SND_FILENAME | SND_LOOP);

}
void play_music (void)
{
    while(true){
    PlaySound(TEXT("alarm"),NULL, SND_FILENAME | SND_LOOP);
    }
}

void Tic_tac(void)
{
    PlaySound(TEXT("cheak"), NULL, SND_SYNC);
}



// -> This Function Help Us To Set Alarm Time From User

void Set_Alarm_Data(int &h, int &m, int &s)
{
    cout<<"\n\t\t\t Enter alarm  time in HH MM SS format (24 Hour) ";
    cout<<"\n\n\t\t\t ";
    cin>>h>>m>>s;
}



//  This function help us to fetch real time data through windows

void Get_Real_Time(int &H,int &M,int &S)
{
    time_t t = time(NULL);
    tm* tmp = localtime(&t);
    H = tmp->tm_hour;
    M = tmp->tm_min;
    S = tmp->tm_sec;
}

// Manage Alarm Stuff
void Alarm(int H,int M,int S,int h, int m,int s)
{

    while(true)
        {
        S++;
        sleep(1);
        if(S==59)
        {
           M++;
           S=0;
        }
        if(M==59)
        {
            H++;
            M=0;
            S=0;
        }
        if(H==24)
        {
            H==0;
            S==0;
            M==0;
        }
        system("CLS");
        cout<<"\n\n\t\t   ***************** "<<H<<":"<<M<<":"<<S;
        if(H<12)
            {
            cout<<" AM *****************";
        }
        else{
            cout<<" PM *****************";
        }
        if(H==h && M==m && S==s)
        {
               break;

        }
        }

}


// Display the Time

void Show_time(int H,int M,int S)
{
        while(!kbhit())
        {
        S++;
        sleep(1);
        if(S==59)
        {
           M++;
           S=0;
        }
        if(M==59)
        {
            H++;
            M=0;
            S=0;
        }
        if(H==24)
        {
            H==0;
            S==0;
            M==0;
        }
        system("CLS");
        cout<<"\n\n\t\t   ***************** "<<H<<":"<<M<<":"<<S;
        if(H<12)
        {
            cout<<" AM *****************";
        }
        else{
            cout<<" PM *****************";
        }

        }
}



// Timer function

void Timer(int &h,int &m,int &s)
{
    system("CLS");
    cout<<"\n\t\t\t       ******Timer****** ";
    cout<<"\n\n\t\t\t Enter time in HH MM SS Format";
    cout<<"\n\n\t\t\t";
    cout<<" ";
    cin>>h>>m>>s;
    while(!kbhit())
    {
        //sleep(1);
        Tic_tac();
        //s--;
        if(m==0 && s==0 && h==0)
        {
           break;

        }
        if(m==0 && s==0)
        {
            h--;
            m=60;
            s=60;
        }
        if(s==0)
        {
            m--;
            s=60;
        }
        s--;
        system("CLS");
        cout<<"\n\t\t\t       ******Timer****** ";
        cout<<"\n\t\t\t";
        cout<<"\n\t\t\t\t    "<<h<<":"<<m<<":"<<s;
    }
    cout<<endl<<"Press Any Key To Stop Beep & Wait for a Second"<<endl;
    while(!kbhit())
            {
               Beep();
            }
}


// Stopwatch function

void Stopwatch(int h,int m,int s)
{
    system("CLS");
    cout<<"\n\t\t\t Pres any key to start";
    cout<<"\n\t\t\t Stopwatch ";
    cout<<"\n\t\t\t "<<h<<":"<<m <<":" <<s;
    getch();

    while(!kbhit())
    {
        Tic_tac();
        s++;
        //sleep(1);
        if(s==59)
        {
           m++;
           s=0;
        }
        if(m==59)
        {
            h++;
            s=0;
            m=0;
        }
        if(h==24)
        {
            h==0;
            s==0;
            m==0;
        }
    system("CLS");
    cout<<"\n\n\t\t\t Stopwatch ";
    cout<<"\n\t\t\t "<<h<<":"<<m <<":" <<s;
    cout<<"\n\n\t\t\t press any key to stop";
    }
    getch();
    cout<<"\n\n\t\t\t After pausing the stopwath";
    cout<<"\n\t\t\t "<<h<<":"<<m <<":" <<s;
    cout<<endl<<endl;
    system("PAUSE");
}


// This function help us to get the input from user
int input(void)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color,3);
    system("color F1");
    //system("color 3");
    int c;
    cout<<"\n\t\t\t\tEnter your choice";
    cout<<"\n\n\t\t\t 1.Stopwatch";
    cout<<"\n\t\t\t 2.Timer";
    cout<<"\n\t\t\t 3.Alarm";
    cout<<"\n\t\t\t 4.Exit";
    cout<<"\n\n\t\t\t";
    cout<<" ";
    cin>>c;
    return c;


}

// This is the main function

void Sound()
{

        thread t1(play_music);
        system("CLS");
        cout<<"\n \n if you want to close this alaram please give answers of quetions";
        sleep(3);
        system("CLS");
        thread t2(Question_clock);
        t1.join();
}
int main()
{
    int h=0,m=0,s=0;
    int H=0,M=0,S=0;
    int num;
    while(true)
{
    system("CLS");
    num = input();
    system("CLS");
    switch(num)
    {
    case 1 :
        Stopwatch(h,m,s);
        break;
    case 2 :
        Timer(h,m,s);
        break;
    case 3 :
        Set_Alarm_Data(h,m,s);
        Get_Real_Time(H,M,S);
        Alarm(H,M,S,h,m,s);
        Sound();

        break;
    case 4 :
        exit(0);
    default :
          cout<<"Wrong input";
          getch();

    }
    }
}
