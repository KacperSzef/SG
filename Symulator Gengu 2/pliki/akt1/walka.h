#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

class walka_klasa{
public:
    string armia_1[1000],przedmioty_1[1000];
    string armia_2[1000],przedmioty_2[1000];
    int bonus_atak_1,bonus_obrona_1;
    int bonus_atak_2,bonus_obrona_2;
    bool bot;
    int hp1,hp2,dm1,dm2;
    int w,w2;
    bool dalej;

    walka_klasa(){
        hp1=0;hp2=0;dm1=0;dm2=0;
        dalej=true;
    }

    void dodaj_armie_1(string kogo){
        int i=0;while(armia_1[i]!="")i++;
        armia_1[i]=kogo;
    }
    void dodaj_ity_1(string co){
        int i=0;while(przedmioty_1[i]!="")i++;
        przedmioty_1[i]=co;
    }
    void dodaj_armie_2(string kogo){
        int i=0;while(armia_2[i]!="")i++;
        armia_2[i]=kogo;
    }
    void dodaj_ity_2(string co){
        int i=0;while(przedmioty_2[i]!="")i++;
        przedmioty_2[i]=co;
    }

    void zaladuj(){
    int i=0;while(armia_1[i]!=""){
    if(armia_1[i]=="lamus"){hp1+=25;dm1+=5;}
    if(armia_1[i]=="zlodziej"){hp1+=20;dm1+=10;}
    if(armia_1[i]=="ziomek"){hp1+=50;dm1+=7;}
    if(armia_1[i]=="gangster"){hp1+=50;dm1+=12;}
    if(armia_1[i]=="mafioza"){hp1+=80;dm1+=15;}
    if(armia_1[i]=="motocyklista"){hp1+=50;dm1+=20;}
    if(armia_1[i]=="kierowca"){hp1+=100;dm1+=7;}
    if(armia_1[i]=="diler"){hp1+=40;dm1+=10;}
    if(armia_1[i]=="gruby"){hp1+=70;dm1+=7;}
    if(armia_1[i]=="AsmodusRex"){hp1+=200;dm1+=50;}
    i++;}
    i=0;while(armia_2[i]!=""){
    if(armia_2[i]=="lamus"){hp2+=25;dm2+=5;}
    if(armia_2[i]=="zlodziej"){hp2+=20;dm2+=10;}
    if(armia_2[i]=="ziomek"){hp2+=50;dm2+=7;}
    if(armia_2[i]=="gangster"){hp2+=50;dm2+=12;}
    if(armia_2[i]=="mafioza"){hp2+=80;dm2+=15;}
    if(armia_2[i]=="motocyklista"){hp2+=50;dm2+=20;}
    if(armia_2[i]=="kierowca"){hp2+=120;dm2+=10;}
    if(armia_2[i]=="diler"){hp2+=40;dm2+=10;}
    if(armia_2[i]=="gruby"){hp2+=70;dm2+=7;}
    if(armia_2[i]=="AsmodusRex"){hp2+=200;dm2+=50;}
    if(armia_2[i]=="ochroniarz"){hp2+=60;dm2+=13;}
    if(armia_2[i]=="CIA"){hp2+=100;dm2+=15;}
    i++;}
    }

    void usun(int co){
    int i=co; while(przedmioty_1[i+1]!=""){
    przedmioty_1[i]=przedmioty_1[i+1]; i++;}
    przedmioty_1[i]="";
    }


    bool start(){
     while(hp1>0&&hp2>0){
        while(dalej){
            system("cls");
            cout<<"#Gracz 1"<<endl;
            cout<<"#Hp1: "<<hp1<<endl;
            cout<<"#Hp2: "<<hp2<<endl;
            cout<<"#bonus atak: "<<bonus_atak_1<<endl;
            cout<<"#bonus obrona: "<<bonus_obrona_1<<endl;
            cout<<"<1> Przedmioty"<<endl;
            cout<<"<2> Atakuj"<<endl;
            cin>>w;
            if(w==1){
                system("cls");
                cout<<"#Hp1: "<<hp1<<endl;
                cout<<"#Hp2: "<<hp2<<endl;
                cout<<"wybierz numer przedmiotu aby uzyc | wpisz 00 aby wrocic"<<endl;
                int i=0;while(przedmioty_1[i]!=""){cout<<"|"<<i<<"| "<<przedmioty_1[i]<<endl;i++;}
                cin>>w2;
                if(przedmioty_1[w2]=="granat"){system("cls");cout<<"rzucam granat"<<endl;Sleep(700);hp2-=30;cout<<"Wysadzil 70hp";usun(w2);Sleep(1000);}
                else if(przedmioty_1[w2]=="blancior"){usun(w2);cout<<"Pale se blanta -~~";Sleep(700);system("cls");cout<<"Odnowilo 30hp"<<endl;hp1+=30;Sleep(1000);}
                else if(przedmioty_1[w2]=="pakiet thrax"){usun(w2);system("cls");cout<<"odnowilo zdrowie 50hp"<<endl;hp1+=50;Sleep(1000);}
                else if(przedmioty_1[w2]=="rodwajler"){system("cls");cout<<"spuszczam psa!!"<<endl;Sleep(700);usun(w2);system("cls");cout<<"zagryzl im 50hp"<<endl;hp2-=50;Sleep(1000);}
                else if(przedmioty_1[w2]=="flacha"){usun(w2);system("cls");cout<<"obrona +20 ale atak -7"<<endl;bonus_obrona_1+=20;bonus_atak_1-=7;Sleep(1000);}
                else if(przedmioty_1[w2]=="marlboro"){usun(w2);system("cls");cout<<"atak +10 ale obrona -10"<<endl;bonus_obrona_1-=10;bonus_atak_1+=10;Sleep(1000);}
                else if(przedmioty_1[w2]=="bomba"){usun(w2);cout<<"kdawkfhkurwaiwdajapierfolefdwvjys";Sleep(700);system("cls");cout<<"obie strony -80"<<endl;hp1-=80;hp2-=80;Sleep(1000);}
                if(hp1<1||hp2<1)break;
                if(bonus_atak_1<0)bonus_atak_1=0;
                if(bonus_obrona_1<0)bonus_obrona_1=0;

            }
            if(w==2){dalej=false;}
        }
        if(dm1+bonus_atak_1-bonus_obrona_2<=0){cout<<"Atak jest nieskuteczny";Sleep(1000);}           //
        else {hp2-=dm1+bonus_atak_1-bonus_obrona_2;                                   //damage
            system("cls");cout<<"Zadales dla typa "<<dm1+bonus_atak_1-bonus_obrona_2<<"hp"<<endl;Sleep(1000);}

        if(hp2>0)dalej=true;

        if(bot==false)while(dalej){
            system("cls");
            cout<<"#Gracz 2"<<endl;
            cout<<"#Hp1: "<<hp1<<endl;
            cout<<"#Hp2: "<<hp2<<endl;
            cout<<"<1> Przedmioty"<<endl;
            cout<<"<2> Atakuj"<<endl;
            cin>>w;
            if(w==1){
                system("cls");
                cout<<"Hp1: "<<hp1<<endl;
                cout<<"Hp2: "<<hp2<<endl;
                cout<<"wybierz numer przedmiotu aby uzyc | kliknij cos innego aby wrocic"<<endl;
                int i=0;while(przedmioty_2[i]!=""){cout<<"|"<<i<<"| "<<przedmioty_2[i]<<endl;i++;}
                cin>>w2;
            }
            if(w==2){dalej=false;}
        }
        if(hp2>0)if(dm2+bonus_atak_2-bonus_obrona_1<=0){cout<<"Atak jest nieskuteczny";Sleep(1000);}           //
        else {hp1-=dm2+bonus_atak_2-bonus_obrona_1;
        if(bot){cout<<"Straciles "<<dm2+bonus_atak_2-bonus_obrona_1<<"hp"<<endl;Sleep(1000);}}
                                 //damage
        dalej=true;
    }
        if(hp1<1&&hp2<1){cout<<"twoj gang nie zyje ale ty tak gratuluje wygranej";Sleep(5000);system("cls");

        return true;}
        if(hp2<1){cout<<"Twoj gang wygrywa !";Sleep(5000);system("cls");

        return true;}
        if(hp1<1){cout<<"Twoj gang przegral jestes frajerem !";Sleep(5000);system("cls");

        return false;}
    }



};
