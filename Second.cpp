#include<iostream>
#include<time.h>

using namespace std;
static int order=10230;
class MusicWorld
{
    int id_code;
    string title;
    int quantity;
    float price,subtotal,tax,total_price;
public:
    MusicWorld(int id,string t,float p,int q)
    {
        id_code=id;
        title=t;
        price=p;
        quantity=q;
    }
    void getData()
    {
        subtotal=price*quantity;
        tax=subtotal*0.0625;
        total_price=subtotal+tax;
        cout<<"The details of CD are as follows--"<<endl;
        cout<<"IDENTIFICATION CODE:  "<<id_code<<endl;
        cout<<"TITLE:  "<<title<<endl;
        cout<<"QUANTITY:  "<<quantity<<endl;
        cout<<"PRICE:  "<<price<<endl;
        cout<<"SUBTOTAL:  "<<subtotal<<endl;
        cout<<"TOTAL_PRICE:  "<<total_price<<endl;
    }
    void getUID()
    {
        order++;
        time_t rawtime=time(0);
        struct tm timeinfo;
        char buffer[100];
        timeinfo = *localtime(&rawtime);
        strftime(buffer,100,"%d/%m/%Y %X %z",&timeinfo);
        cout<<"unique id:"<<order<<endl;
        cout<<buffer<<endl;
    }
};

int main()
{
    int idcode,quan;
    string title;
    float price;

    cout<<"enter identification code"<<endl;
    cin>>idcode;
    cout<<"enter title"<<endl;
    cin.ignore();
    getline(cin,title);
    cout<<"enter price"<<endl;
    cin>>price;
    cout<<"enter quantity"<<endl;
    cin>>quan;
    MusicWorld msw1(idcode,title,price,quan);
    msw1.getData();
    msw1.getUID();
    MusicWorld msw2(2541,"linkin park",6985,10);
    msw2.getData();
    msw2.getUID();
    MusicWorld msw3(3652,"chester bennington",10000,15);
    msw2.getData();
    msw2.getUID();

    //cout<<"do you want to enter more data?";
    //cin>>ans;


    return 0;
}
