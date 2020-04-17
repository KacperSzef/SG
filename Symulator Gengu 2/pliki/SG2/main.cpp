#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int w;

int main()
{
    cout << "Menu!" << endl;
    cout<<"<1> Zacznij od poczatku"<<endl;
    cout<<"<2> Zacznij od 2 aktu | NIE ZALECANE"<<endl;
    cout<<"<3> Zacznij od 3 aktu | We no"<<endl;
    cin>>w;
    if(w==1)system("start Akt1.lnk");


    return 0;
}
