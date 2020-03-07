#include <bits/stdc++.h>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;
//      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{x,y});
int choose(vector<string> s)
{
    if(s.size()<2) return -1;
    CONSOLE_SCREEN_BUFFER_INFO c;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    for(string a: s)
        cout<<a<<endl;
    unsigned int cur=0;
    bool finish=0;
    while(!finish)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y+cur});

        cout<<'\r';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),74);
        cout<<s[cur];
        switch(_getch())
        {
            case 13:
                finish=1;
                break;
            case 72:
                if(cur!=0)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    cout<<"\r";
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y+cur});
                    for(int i=0;i<s[cur].size();++i)
                        cout<<' ';
                    cout<<'\r';

                    cout<<s[cur];
                    cur--;
                }
                break;
            case 80:
                if(cur< s.size()-1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    cout<<"\r";
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y+cur});
                    for(int i=0;i<s[cur].size();++i)
                        cout<<' ';
                    cout<<'\r';

                    cout<<s[cur];
                    cur++;
                    break;
                }
        }


    }
    cout<<"  #";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y+s.size()+1});

    return cur;

}
