#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "walka.h"

using namespace std;

string budynki[15]={"Siedziba","melina","mieszkanie","dom","hodowla ziola","fabryka mdma","wytwornia koksu","klub","bar","garaz","kebab","skatepark","szopa","kasyno"};
string postacie[10]={"AsmodusRex","lamus","zlodziej","ziomek","gangster","mafioza","motocyklista","kierowca","gruby","diler"};                                                           //15         //16
string przedmioty[20]={"kominiara","kamizelka","ciezka zbroja","kastet","kosa","pistolet","ak-47","granat","bomba","Rodwajler","flacha","marlboro","blancior","pakiet thrax","krzak","samochod","tajemnicza flacha"};
string p_zapis[1000]={""};
string sklep[5];
int tura=1;
bool wygrana;
int licznik=0;


class przeciwnik{
public:
    string nazwa;
    string jednostki[20];
};


class gang{
public:
    int hajs,hajs_na_ture;                              //hajs
    int ludzie, ludzie_miejsca, kupione_jednostki;      //jednostki
    bool budowanie,ciemnylas;                                     //budowanie iciemny las
    bool ruch;                                          //ruch
    int atak,obrona;                                    //staty

    bool kasyno,klub,bar,garaz,kebab,sk8park,szopa;                                       //koszary

    string teren[1000];
    string jednostki[1000];
    string ekwipunek[1000];

//####################### Metody
    gang(){
    teren[0]=budynki[0];
    hajs=50;
    hajs_na_ture=0;
    ludzie=0;
    ludzie_miejsca=0;
    kasyno=false;klub=false;bar=false;garaz=false;kebab=false;sk8park=false;szopa=false;
    budowanie=true;ciemnylas=true;
    kupione_jednostki=0;
    }

    void wyswietl(){
        cout<<"____Budynki____"<<endl;
        int i=0;while(teren[i]!=""){
            cout<<"|"<<i<<"| "<<teren[i]<<endl;
            i++;
        }
        cout<<"---------------"<<endl;
        cout<<"#hajs: "<<hajs<<endl;
        cout<<"#hajs na ture: "<<hajs_na_ture<<endl;
        cout<<"#ludzie: "<<ludzie<<endl;
        cout<<"#lozka: "<<ludzie_miejsca<<endl;
        cout<<"______Menu_______"<<endl;
    }
    void wyswietl_armie(){
        system("cls");
        cout<<"#Oto twoja armia:"<<endl;
        int i=0;while(jednostki[i]!=""){
        cout<<"|"<<i+1<<"| "<<jednostki[i]<<endl;
        i++;
        }
    }
    void wyswietl_eq(){
        system("cls");
        cout<<"#Oto twoje przedmioty:"<<endl;
        int i=0;while(ekwipunek[i]!=""){
        cout<<"|"<<i+1<<"| "<<ekwipunek[i]<<endl;
        i++;
        }
    }

    void buduj(int co){
        int i=0;while(teren[i]!="")i++;
        teren[i]=budynki[co];
        budowanie=false;
    }
    void kup_jednostke_klub(int jaka){
    if(jaka!=0)if(kupione_jednostki<5)
    if(ludzie_miejsca>ludzie){
        if(jaka==1&&hajs>=5){hajs-=5;dodaj_jednostke(1);ludzie++;}
        if(jaka==2&&hajs>=10){hajs-=10;dodaj_jednostke(2);ludzie++;}
        if(jaka==3&&hajs>=15){hajs-=15;dodaj_jednostke(3);ludzie++;}
        }
    else {cout<<"Nie masz miejsca na wiecej ludzi"; Sleep(1000);}
    else {cout<<"Mozesz znalezc tylko 3 ludzi na ture"; Sleep(1000);}
    }
    void kup_jednostke_bar(int jaka){
    if(jaka!=0){if(kupione_jednostki<5)
    if(ludzie_miejsca>ludzie){
        if(jaka==1&&hajs>=20){hajs-=20;dodaj_jednostke(4);
        ludzie++;}}
    if(ludzie_miejsca>ludzie+1){
        if(jaka==2&&hajs>=30){hajs-=30;dodaj_jednostke(5);
        ludzie+=2;}}
    else {cout<<"Nie da rady mordeczko"; Sleep(1000);}}
    }
    void kup_jednostke_garaz(int jaka){
    if(jaka!=0){if(kupione_jednostki<5)
    if(ludzie_miejsca>ludzie+1){
        if(jaka==1&&hajs>=30){hajs-=30;dodaj_jednostke(6);
        ludzie+=2;}}
    if(ludzie_miejsca>ludzie+2){
        if(jaka==2&&hajs>=35){hajs-=35;dodaj_jednostke(7);
        ludzie+=3;}}
    if(jaka==3&&hajs>=25){hajs-=25;dodaj_przedmiot("samochod");}
    else {cout<<"Nie da rady mordeczko"; Sleep(1000);}}
    }
    void kup_kebab(string co){
    if(co=="gruby")if(kupione_jednostki<5)if(ludzie_miejsca>ludzie){
        if(hajs>=20){hajs-=20;dodaj_jednostke(8);}
        ludzie++;}
    if(co=="blancior")if(hajs>=15){hajs-=15;dodaj_przedmiot(co);}
    if(co=="pakiet thrax")if(hajs>=22){hajs-=22;dodaj_przedmiot(co);}
    if(co=="krzak")if(hajs>=16){hajs-=16;dodaj_przedmiot(co);}
    }
    void kup_sk8park(string co){
    if(co=="diler")if(kupione_jednostki<5)if(ludzie_miejsca>ludzie){
        if(hajs>=30){hajs-=30;hajs_na_ture+=5;dodaj_jednostke(9);}
        ludzie++;}
    if(co=="rodwajler")if(hajs>=15){hajs-=15;dodaj_przedmiot(co);}
    if(co=="flacha")if(hajs>=20){hajs-=20;dodaj_przedmiot(co);}
    if(co=="marlboro")if(hajs>=17){hajs-=17;dodaj_przedmiot(co);}
    }
    void kup_szopa(string co){
    if(co=="kominiara")    if(hajs>=15){hajs-=15;dodaj_przedmiot(co);}
    if(co=="kamizelka")    if(hajs>=25){hajs-=25;dodaj_przedmiot(co);}
    if(co=="ciezka zbroja")if(hajs>=25){hajs-=25;dodaj_przedmiot(co);}
    if(co=="kastet")       if(hajs>=10){hajs-=10;dodaj_przedmiot(co);}
    if(co=="kosa")         if(hajs>=15){hajs-=15;dodaj_przedmiot(co);}
    if(co=="pistolet")     if(hajs>=20){hajs-=20;dodaj_przedmiot(co);}
    if(co=="bomba")        if(hajs>=20){hajs-=20;dodaj_przedmiot(co);}
    }




    void dodaj_jednostke(int jaka){
        int i=0;while(jednostki[i]!="")i++;
        jednostki[i]=postacie[jaka];
    }
    void dodaj_przedmiot(string jaki){
        int i=0;while(ekwipunek[i]!="")i++;
        ekwipunek[i]=jaki;
                                            //  What items do
        if(jaki=="kastet")atak+=5;
        if(jaki=="kosa")atak+=8;
        if(jaki=="pistolet")atak+=13;
        if(jaki=="ak-47")atak+=20;
        if(jaki=="kominiara")obrona+=10;
        if(jaki=="kamizelka")obrona+=20;
        if(jaki=="ciezka zbroja"){obrona+=40;atak-=10;}
        if(jaki=="krzak")hajs_na_ture+=3;
        if(jaki=="samochod"){obrona+=15;ludzie_miejsca+=1;}
    }

    void w_p_zapis(){
        int i=0;while(ekwipunek[i]!=""){
        ekwipunek[i]="";i++;}
        i=0;while(p_zapis[i]!=""){ekwipunek[i]=p_zapis[i];}

    }

    void umarl(){
        int i=0;while(jednostki[i]!=""){
        jednostki[i]="";
        i++;
        }
        i=0;while(ekwipunek[i]!=""){
        ekwipunek[i]="";
        i++;
        }
        ludzie=0;
    }

    void nastepna(){
    budowanie = true;
    ruch = true;
    hajs+=hajs_na_ture;
    }

};                  //######################################    KONIEC KLASY GANG ##########################################

                    // ################     Map     ###############################
class KlasaMapa{
public:
    string podstawowa[20]={"ciemny las","las","pieczury","monopol","East street","palac","arhelan","kosciol","park","rondo","New street","garaze","blokowisko","tory","cmentarz","kaplica","las","lotnisko"};
    string mapa[20];
    int b1x,b2x;
    int g1x,bossx;     // X gang
    int p1x,p2x,p3x;    // X mobs
    int wybor;
    int granica;


    //  $$$$$$$$$$$$$$$     Methods  $$$$$$$$$$$$$
    KlasaMapa(){
    //cout<<"wybierz mape - <1>Podstawowa :";cin>>wybor;system("cls");
    //if(wybor==1){
        int i=0;while(podstawowa[i]!=""){
        mapa[i] = podstawowa[i];i++;}//}
    //else if(wybor==2)cout<<"Nie ma jeszcze";
    //else {cout<<"Debil z ciebie";Sleep(10000);}
        i=0;while(mapa[i]!="cmentarz"){
        cout<<"|"<<i<<"| "<<mapa[i]<<endl;i++;}
    granica=i;
    cout<<"---------------"<<endl;
    cout<<"Gdzie chcesz stworzyc gang ?: ";cin>>b1x;g1x=b1x;
    cout<<"Twoj gang jest na "<<mapa[b1x];
    b2x=-1000;bossx=17;
    Sleep(1000);
    p1x = rand() % i;
    while(p1x==b1x||p1x==b2x)p1x = rand() % i;
    p2x = rand() % i;
    while(p2x==b1x||p2x==p1x)p2x = rand() % i;
    p3x = rand() % i;
    while(p3x==b1x||p3x==p1x||p3x==p2x)p3x = rand() % i;
    }

    void wyswietl(int gracz){
        if(gracz==1){
                system("cls");
            cout<<"___Mapa______"<<endl;
            int i=0;while(mapa[i]!=""){
            cout<<"|"<<i<<"| "<<mapa[i];
            if(b1x==i)cout<<" |Baza 1|"; if(b2x==i)cout<<" |Baza 2|";
            if(g1x==i)cout<<" {Gracz 1}"; if(bossx==i)cout<<" <<Ucieczka z kraju>>";
            if(p1x==i)cout<<" |teren ballasow|";if(p2x==i)cout<<" |Patusy|";if(p3x==i)cout<<" |teren podlaskiej mafi|";
            cout<<endl;i++;}
            cout<<"---------------"<<endl;
        }}
    bool ruch(int gracz,bool ruch, string gdzie){
        if(gracz==1){
            if(ruch==true){
            if(gdzie=="gora"){
                g1x-=1;}
            if(gdzie=="dol"){
                g1x+=1;}
            if(g1x==-1)g1x=0;
            else {
            return false;}
            }}
    }
};



string skrzynia(){           //*********************************************     Function chest     ****************************************
    string item;
    int losowosc;
    for(int i=1;i<18;i++){
        losowosc = rand() % 100 + 1;      //Items and chance
        if(losowosc>=1&&losowosc<=10)losowosc=0;
        if(losowosc>=10&&losowosc<=20)losowosc=12;
        if(losowosc>=20&&losowosc<=30)losowosc=3;
        if(losowosc>=30&&losowosc<=40)losowosc=10;
        if(losowosc>=40&&losowosc<=50)losowosc=4;
        if(losowosc>=50&&losowosc<=60)losowosc=7;
        if(losowosc>=60&&losowosc<=70)losowosc=11;
        if(losowosc>=70&&losowosc<=75)losowosc=1;
        if(losowosc>=75&&losowosc<=80)losowosc=5;
        if(losowosc>=80&&losowosc<=87)losowosc=14;
        if(losowosc>=87&&losowosc<=90)losowosc=14;
        if(losowosc>=90&&losowosc<=93)losowosc=15;
        if(losowosc>=93&&losowosc<=95)losowosc=6;
        if(losowosc>=95&&losowosc<=100)losowosc=2;
        cout<<przedmioty[losowosc];Sleep(i*30);
        system("cls");cout<<"#########";Sleep(50);system("cls");
    }
    cout<<przedmioty[losowosc];Sleep(700);system("cls");
    cout<<"Gratuluje trafiles "<<przedmioty[losowosc];
    Sleep(1000);
    item = przedmioty[losowosc];
    return item;
}

bool kreator_walki(walka_klasa wojna, bool bot, gang gracz_1, przeciwnik wrog){// *********************************************** fight creator  **********************************

    wojna.bot = bot;
    bool wygrana;

    int i=0;while(gracz_1.jednostki[i]!=""){
    wojna.dodaj_armie_1(gracz_1.jednostki[i]);
    i++;}
    i=0;while(gracz_1.ekwipunek[i]!=""){
    wojna.dodaj_ity_1(gracz_1.ekwipunek[i]);           //  Gracz 1
    i++;}
    wojna.bonus_atak_1=gracz_1.atak;
    wojna.bonus_obrona_1=gracz_1.obrona;

    if(bot==true){
    i=0;while(wrog.jednostki[i]!=""){
    wojna.dodaj_armie_2(wrog.jednostki[i]);
    i++;}
    }

    wojna.zaladuj();
    wygrana=wojna.start();

    i=0;while(p_zapis[i]!=""){p_zapis[i]="";i++;}
    i=0;while(wojna.przedmioty_1[i]!=""){p_zapis[i]=wojna.przedmioty_1[i];i++;}

    return wygrana;
}

void zegar(int tura){
    system("cls");
    int miesiac,dzien;
    miesiac=tura/30;
    dzien=tura%30;
    cout<<"D";Sleep(50);cout<<"z";Sleep(50);cout<<"i";Sleep(50);cout<<"e";Sleep(50);cout<<"n ";Sleep(50);cout<<dzien<<endl;Sleep(50);
    cout<<"M";Sleep(60);cout<<"i";Sleep(60);cout<<"e";Sleep(60);cout<<"s";Sleep(60);cout<<"i";Sleep(60);cout<<"a";Sleep(70);cout<<"c ";Sleep(60);cout<<miesiac<<endl;Sleep(800);

}








int main()                  // &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&      INT MAIN      &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
{
    srand (time(NULL));
    walka_klasa walka;
    gang g1;

    przeciwnik ballasi;                         //  Ballasi
    ballasi.nazwa="ballasi";
    ballasi.jednostki[0]="zlodziej";ballasi.jednostki[1]="zlodziej";ballasi.jednostki[2]="ziomek";ballasi.jednostki[3]="ziomek";ballasi.jednostki[4]="gruby";
    ballasi.jednostki[5]="lamus";ballasi.jednostki[6]="diler";

    przeciwnik patusy;                         //  patusy
    patusy.nazwa="patusy";
    patusy.jednostki[0]="lamus";patusy.jednostki[1]="lamus";patusy.jednostki[2]="lamus";patusy.jednostki[3]="lamus";patusy.jednostki[4]="gruby";
    patusy.jednostki[5]="zlodziej";

    przeciwnik podlaska_mafia;                  //  podlaska mafia
    podlaska_mafia.nazwa="podlaska_mafia";
    podlaska_mafia.jednostki[0]="gangster";podlaska_mafia.jednostki[1]="gangster";podlaska_mafia.jednostki[2]="gangster";podlaska_mafia.jednostki[3]="mafioza";
    podlaska_mafia.jednostki[4]="mafioza";podlaska_mafia.jednostki[5]="mafioza";podlaska_mafia.jednostki[6]="motocyklista";podlaska_mafia.jednostki[7]="kierowca";

    przeciwnik lotnisko;    lotnisko.nazwa="Ucieczka";  lotnisko.jednostki[0]="ochroniarz";        //boss

    Sleep(1000);
    cout<<">zyjesz w Polsce"<<endl;Sleep(1000);
    cout<<">masz juz dosc zycia tutaj"<<endl;Sleep(1000);
    cout<<">dlatego zebrales 50$ i zaplanowales ucieczke"<<endl;Sleep(1000);
    cout<<">zrob wszystko aby pokonac straznikow i uciec"<<endl;Sleep(1000);


    KlasaMapa mapa;
    char w;
    int w2,w3;
    bool next;

    for(;;){
        zegar(tura);tura++;                     //Tour          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        licznik++;
        if(tura>20)licznik++;
        if(tura>30)licznik++;
        system("cls");
        next=false;

        if(licznik>=8){
            int i=0;while(lotnisko.jednostki[i]!="")i++;
            lotnisko.jednostki[i]="ochroniarz";
            licznik=0;
        }
        if(tura==30||tura==40||tura==50||tura==60||tura==70||tura==80||tura==89||tura==90||tura==95||tura==100||tura>100){
            int j=0;while(lotnisko.jednostki[j]!="")j++;
            lotnisko.jednostki[j]="CIA";
        }


    while(next==false){
                    system("cls");
                    g1.wyswietl();
                    cout<<"<0> Nastepna tura"<<endl;
    if(g1.ruch)     cout<<"<1> Podroz"<<endl;
    if(g1.budowanie)cout<<"<2> Buduj"<<endl;
    //if(g1.koszary)  cout<<"<3> Kup jednostki"<<endl;
                    cout<<"<3> Armia"<<endl;
                    cout<<"<4> Ekwipunek"<<endl;
                    cout<<"----------------"<<endl;
       if(g1.klub)  cout<<"<5> Klub"<<endl;
       if(g1.bar)   cout<<"<6> Bar"<<endl;
       if(g1.garaz)   cout<<"<7> Garaz"<<endl;
       if(g1.kebab)   cout<<"<8> Kebab"<<endl;
       if(g1.sk8park)   cout<<"<9> Skatepark"<<endl;
       if(g1.szopa)   cout<<"<s> Szopa"<<endl;
       if(g1.kasyno)cout<<"<h> Hazard"<<endl;

    w = getch();
    if(w=='2')                                          //#########<       Budowanie             >#########
    if(g1.budowanie){
        system("cls");
        cout<<"<0> Wroc"<<endl;
        cout<<"<1> melina       |10$  -   slabe warunki ale 2 sie zmiesci"<<endl;
        cout<<"<2> mieszkanie   |22$  -   fajne mieszkanie 4 chlopa upchasz | wymagania: sk8park"<<endl;
        cout<<"<3> dom          |50$  -   kozak chata cala ekipe 8 osob moze tu mieszkac"<<endl;
        cout<<"<4> hodowla ziola  |20$ -   zarobki okolo 5$ dziennie"<<endl;
        cout<<"<5> fabryka mdma   |40$ -   12$ dziennie  |  Wymagania: szopa"<<endl;
        cout<<"<6> wytwornia koksu|60$ -   chlopie 20 na ture  |  Wymagania: bar, garaz"<<endl;
if(!g1.klub)cout<<"<7> klub         |10$  -   mozesz zebrac gangmemberow"<<endl;
if(!g1.bar)cout<<"<8> bar          |30$  -   tu ekskluzywni ludzie|  Wymagania: kebab"<<endl;
if(!g1.garaz)cout<<"<9> garaz        |50$  -   pojazdy!!!"<<endl;
if(!g1.kebab)cout<<"<10> kebab         |10$ -   kebab"<<endl;
if(!g1.sk8park)cout<<"<11> skatepark     |15$ -   pieski i cpuny"<<endl;
if(!g1.szopa)cout<<"<12> szopa         |20$ -   co ture mozesz kupic item"<<endl;
if(!g1.kasyno)cout<<"<13> kasyno        |0$ -   skrzynki i takie tam | wymagania: bar, szopa"<<endl;



        cin>>w2;
        if(w2==1){
            if(g1.hajs>=10){
            g1.buduj(1); g1.hajs-=10;
            g1.ludzie_miejsca+=2;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==2){
            if(g1.hajs>=20&&g1.sk8park){
            g1.buduj(2); g1.hajs-=20;
            g1.ludzie_miejsca+=4;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==3){
            if(g1.hajs>=50){
            g1.buduj(3); g1.hajs-=50;
            g1.ludzie_miejsca+=8;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==4){
            if(g1.hajs>=20){
            g1.buduj(4); g1.hajs-=20;
            g1.hajs_na_ture+=5;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==5){
            if(g1.hajs>=40&&g1.szopa){
            g1.buduj(6); g1.hajs-=40;
            g1.hajs_na_ture+=12;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==6){
            if(g1.hajs>=60&&g1.bar&&g1.garaz){
            g1.buduj(6); g1.hajs-=60;
            g1.hajs_na_ture+=20;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==7&&g1.klub==false){
            if(g1.hajs>=10){
            g1.buduj(7); g1.hajs-=10;
            g1.klub=true;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==8&&g1.bar==false){
            if(g1.hajs>=30&&g1.kebab==true){
            g1.buduj(8); g1.hajs-=30;
            g1.bar=true;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==9&&g1.garaz==false){
            if(g1.hajs>=50){
            g1.buduj(8); g1.hajs-=50;
            g1.garaz=true;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==10){
            if(g1.hajs>=10&&g1.kebab==false){
            g1.buduj(10); g1.hajs-=10;
            g1.kebab=true;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==11&&g1.sk8park==false){
            if(g1.hajs>=15){
            g1.buduj(11); g1.hajs-=15;
            g1.sk8park=true;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==12&&g1.szopa==false){
            if(g1.hajs>=20){
            g1.buduj(12); g1.hajs-=20;
            g1.szopa=true;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}
        if(w2==13&&g1.kasyno==false){
            if(g1.bar&&g1.szopa){
            g1.buduj(12); g1.hajs-=0;
            g1.kasyno=true;
            }
            else    {cout<<"nie da rady mordeczko"<<endl;Sleep(1000);}}

    }
    if(w=='5')                                              //#########<3>#########
    if(g1.klub){
        system("cls");
        cout<<"_____'K'L'U'B'_____"<<endl;
        cout<<"<0> Wroc"<<endl;
        cout<<"<1> lamus    |5$  -   zwykly typo zwykle staty hp-25 dmg-5"<<endl;
        cout<<"<2> zlodziej |10$ -   slaby ale chytry dlatego hp-12 dmg-10"<<endl;
        cout<<"<3> ziomek   |15$ -   spoko typ hp-50 dmg-7"<<endl;
        cin>>w3;
        g1.kup_jednostke_klub(w3);
        }
    if(w=='6')                                              //#########<3>#########
    if(g1.bar){
        system("cls");
        cout<<"\\____~~BAR~~____/"<<endl;
        cout<<"<0> Wroc"<<endl;
        cout<<"<1> gangster |20$ -   dobry hp-50 dmg-12"<<endl;
        cout<<"<2> mafioza  |30$ -   lubi luksus potrzebuje 2miejsc ale hp-80 dmg-15"<<endl;
        cin>>w3;
        g1.kup_jednostke_bar(w3);
        }
    if(w=='7')                                              //#########<3>#########
    if(g1.garaz){
        system("cls");
        cout<<"====Garaz===="<<endl;
        cout<<"<0> Wroc"<<endl;
        cout<<"<1> motocyklista |30$ -   szybki zabojca hp-50 dmg-20 zajmuje 2 miejsca"<<endl;
        cout<<"<2> kierowca     |35$ -   drive shooter hp-120 dm-10 zajmuje 3 miejsca"<<endl;
        cout<<"<3> samochod     |25$ -   daje ci obrone a do tego 1 osoba moze w nim spac |przedmiot|"<<endl;
        cin>>w3;
        g1.kup_jednostke_garaz(w3);
        }
    if(w=='8')                                              //#########<3>#########
    if(g1.kebab){
        system("cls");
        cout<<"*~~~~Kebab~~~~*"<<endl;
        cout<<"<0> Wroc"<<endl;
        cout<<"<1> Gruby       |17$ -   Gruby hp-70 dmg-7"<<endl;
        cout<<"<2> blancior    |15$ -   odnawia 30hp"<<endl;
        cout<<"<3> pakiet thrax|22$ -   odnawia 50hp"<<endl;
        cout<<"<4> krzak       |16$ -   3 hajsu dziennie"<<endl;
        cin>>w3;
        if(w3==1)g1.kup_kebab("gruby");
        if(w3==2)g1.kup_kebab("blancior");
        if(w3==3)g1.kup_kebab("pakiet thrax");
        if(w3==4)g1.kup_kebab("krzak");
        }
    if(w=='9')
    if(g1.sk8park){
        system("cls");
        cout<<"\\/\\/\\Skatepark/\\/\\/"<<endl;
        cout<<"<0> Wroc"<<endl;
        cout<<"<1> diler       |30$ -   Diler zarabia 5$na ture hp-50 dmg-7"<<endl;
        cout<<"<2> rodwajler   |15$ -   grozny pies zadaje 50hp"<<endl;
        cout<<"<3> flacha      |20$ -   zwieksza obrone zmniejsza atak"<<endl;
        cout<<"<4> marlboro    |17$ -   zwieksza atak zmniejsza obrone"<<endl;
        cin>>w3;
        if(w3==1)g1.kup_sk8park("diler");
        if(w3==2)g1.kup_sk8park("rodwajler");
        if(w3==3)g1.kup_sk8park("flacha");
        if(w3==4)g1.kup_sk8park("marlboro");
        }
    if(w=='s')
    if(g1.szopa){
        system("cls");
        cout<<":&&&:Szopa:&&&:"<<endl;
        cout<<"<0> Wroc"<<endl;
        cout<<"<1> kominiara     |15$ -   zwieksza obrone"<<endl;
        cout<<"<2> kamizelka     |25$ -   zwieksza obrone"<<endl;
        cout<<"<3> ciezka zbroja |25$ -   zwieksza obrone ale zmniejsza atak"<<endl;
        cout<<"<4> kastet        |10$ -   zwieksza atak "<<endl;
        cout<<"<5> kosa          |15$ -   zwieksza atak "<<endl;
        cout<<"<6> pistolet      |20$ -   zwieksza atak "<<endl;
        cout<<"<7> bomba         |20$ -   wysadza wszystkich na -80hp"<<endl;
        cin>>w3;
        if(w3==1)g1.kup_szopa("kominiara");
        if(w3==2)g1.kup_szopa("kamizelka");
        if(w3==3)g1.kup_szopa("ciezka zbroja");
        if(w3==4)g1.kup_szopa("kastet");
        if(w3==5)g1.kup_szopa("kosa");
        if(w3==6)g1.kup_szopa("pistolet");
        if(w3==7)g1.kup_szopa("bomba");

        }

    if(w=='3'){g1.wyswietl_armie();g1.w_p_zapis();w2 = getch();}

    if(w=='4'){g1.wyswietl_eq();w2 = getch();}

    if(w=='1'){
        if(g1.ruch){
        mapa.wyswietl(1);
        cout<<"<0> wroc"<<endl;
        cout<<"<1> gora"<<endl;
        cout<<"<2> dol"<<endl;
        cin>>w2;
        if(w2==1){g1.ruch = mapa.ruch(1,g1.ruch,"gora");}
        if(w2==2){g1.ruch = mapa.ruch(1,g1.ruch,"dol");}
        if(mapa.g1x==mapa.p1x){                                                                         //  collisions !!!!!!!!
                cout<<"E osiedla ci sie chyba pomylily"<<endl;Sleep(2000);wygrana=kreator_walki(walka,true,g1,ballasi);
                if(wygrana==false){g1.umarl();mapa.g1x=mapa.b1x;}
                if(wygrana==true){g1.w_p_zapis();cout<<"Ukraldes im 4 skrzynie!";Sleep(1500);system("cls");
                        mapa.p1x=-34;g1.dodaj_przedmiot(skrzynia());g1.dodaj_przedmiot(skrzynia());g1.dodaj_przedmiot(skrzynia());g1.dodaj_przedmiot(skrzynia());}}
        if(mapa.g1x==mapa.p2x){
                cout<<"Pokazuj kieszenie"<<endl;Sleep(2000);wygrana=kreator_walki(walka,true,g1,patusy);
                if(wygrana==false){g1.umarl();mapa.g1x=mapa.b1x;}
                if(wygrana==true){g1.w_p_zapis();cout<<"Ukraldes im epa +50$";Sleep(1500);system("cls");mapa.p2x=-34;g1.hajs+=50;}}//walka
        if(mapa.g1x==mapa.p3x){
                cout<<"A wiec walczmy"<<endl;Sleep(2000);wygrana=kreator_walki(walka,true,g1,podlaska_mafia);
                if(wygrana==false){g1.umarl();mapa.g1x=mapa.b1x;}
                if(wygrana==true){g1.w_p_zapis();cout<<"Poszli na uklad +20$ na ture";Sleep(2000);system("cls");
                         cout<<"I do tego ukradles im 2 samochody i 2 skrzynie";Sleep(3000);system("cls");cout<<"+2 samochody";Sleep(800);system("cls");mapa.p3x=-34;g1.hajs_na_ture+=20;g1.dodaj_przedmiot("samochod");
                         g1.dodaj_przedmiot(skrzynia());g1.dodaj_przedmiot(skrzynia());}}//walka
        if(mapa.g1x==0&&g1.ciemnylas==true){
                cout<<"W lesie znalazles 2 kalachy i 2 skrzynie";Sleep(3000);system("cls");cout<<"+2 ak-47";Sleep(800);system("cls");g1.dodaj_przedmiot("ak-47");g1.dodaj_przedmiot("ak-47");
                g1.dodaj_przedmiot(skrzynia());g1.dodaj_przedmiot(skrzynia());g1.ciemnylas=false;}

         if(mapa.g1x==mapa.bossx){                                  //Koniec
                cout<<"W koncu ucieczka"<<endl;Sleep(2000);system("cls");wygrana=kreator_walki(walka,true,g1,lotnisko);
                if(wygrana==false){cout<<"Nie powstrzymacie mnie";Sleep(2000);system("cls");cout<<" po 3 latach wiezienia ...";Sleep(2000);system("cls");g1.umarl();mapa.g1x=mapa.b1x;}
                if(wygrana==true){cout<<"Member- Samolot !!"<<endl;Sleep(1500);cout<<"Ty- dawajcie szybko"<<endl;Sleep(1500);cout<<"Member- keiwea strzelaja"<<endl;Sleep(1500);
                                  cout<<"Ziomek- juz na nich za pozno wsiadaj "<<endl;Sleep(1500);cout<<"Ty- :((((("<<endl;Sleep(1500);system("cls");
                                  cout<<"wszyscy gangmemberzy umarli albo zostali zlapani...";Sleep(3000);system("cls");cout<<"Jestes juz w drodze do LA"<<endl;Sleep(2000);
                                  cout<<">Koniec aktu I< ";Sleep(2000); return 0;}
                }

    }}




    if(w=='h')if(g1.kasyno){
            system("cls");
        cout<<"|$|______$$Kasyno$$_____|$|"<<endl;
        cout<<"#hajs: "<<g1.hajs<<endl;
        cout<<"<1> Otworz skrzynie z itemami | 20$"<<endl;
        w2 = getch();
        if(w2=='1')if(g1.hajs>=20){g1.dodaj_przedmiot(skrzynia());g1.hajs-=20;}
    }


    if(w=='0')next=true;
    }
    cout<<"nastepna!";
    g1.nastepna();
    Sleep(400);
    }//update

    return 0;
}

