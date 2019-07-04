#include<iostream>

using namespace std;
static unsigned int count =0;
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
        cout<<"----The details of CD ----"<<endl;
        cout<<endl;
        cout<<"IDENTIFICATION CODE : "<<id_code<<endl;
        cout<<"TITLE : "<<title<<endl;
        cout<<"QUANTITY : "<<quantity<<endl;
        cout<<"PRICE : "<<price<<endl;
        cout<<"SUBTOTAL : "<<subtotal<<endl;
        cout<<"TOTAL_PRICE : "<<total_price<<endl;
    }
    string getuniqueid()
    {
         count++;
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d/%m/%Y.%X", &tstruct);

    return buf;

    }
};

int main()
{
    int idcode,qty;
    string title;
    float price;
    cout<<"Enter the identification code :";
    cin>>idcode;
    cout<<"Enter the title : ";
    cin.ignore();
    getline(cin,title);
    cout<<"Enter the price : ";
    cin>>price;
    cout<<"Enter the  quantity : ";
    cin>>qty;
    cout<<endl;
    MusicWorld mw(idcode,title,price,qty);
    mw.getData();
    string td=mw.getuniqueid();
    cout<<"Transaction ID: "<<count<<" "<<"Time : "<<td<<endl;
    return 0;
}
