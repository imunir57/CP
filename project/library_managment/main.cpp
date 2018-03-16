#include<bits/stdc++.h>
using namespace std;
class Book
{
protected:
    char id[10];
    bool available;
    char name[20],author[20];
    double price;
public:
    void info();
    bool avail(string);
    void avail_change(string,int);
    string get_id(){return id;}
    void add();
    void modify();
    void delet();
    friend ostream &operator<<(ostream &,Book);
};
class Member
{
protected:
    int noOfBook;
    char m_id[10],name[20],address[20],phone[20];
    char id[10];
    char dept[20];
public:
    bool nib(string);
    void info();
    void add();
    void modify();
    void delet();
    void nib_change(string,string,int);
    friend ostream &operator<<(ostream&,Member);
};

class Main:public Book,public Member
{
    int d,m,y;
public:
    void get_date(){cin>>d>>m>>y;}
    void issue_book();
    void return_book();
    bool fine();
    int diff();
    friend ostream &operator<<(ostream&,Main);
};
ostream &operator<<(ostream &stream,Book ob)
{
    stream<<"Book id: "<<ob.id<<'\n';
    stream<<"Name: "<<ob.name<<'\n';
    stream<<"Author name: "<<ob.author<<'\n';
    stream<<"Available: ";(ob.available)?stream<<"yes\n":stream<<"no\n";
    stream<<"Price: "<<ob.price<<'\n';
    return stream;
}
ostream &operator<<(ostream &stream,Member ob)
{
    stream<<"Member id: "<<ob.m_id<<'\n';
    stream<<"Personal id: "<<ob.id<<'\n';
    stream<<"Department: "<<ob.dept<<'\n';
    stream<<"Name: "<<ob.name<<'\n';
    stream<<"Address: "<<ob.address<<'\n';
    stream<<"Phone no.: "<<ob.phone<<'\n';
    stream<<"No. of books issued: "<<ob.noOfBook<<'\n';
    return stream;
}
ostream &operator<<(ostream &stream,Main ob)
{
    stream<<"Book id: "<<ob.Book::id<<'\n';
    stream<<"Name: "<<ob.Book::name<<'\n';
    stream<<"Date of issue: "<<ob.d<<'-'<<ob.m<<'-'<<ob.y<<'\n';
    return stream;
}
void Book::add()
{
    getchar();
    cout<<"Enter Book id: ";
    cin.getline(id,10);
    cout<<"Enter Book name: ";
    cin.getline(name,20);
    cout<<"Enter Book author: ";
    cin.getline(author,20);
    cout<<"Enter Book price: ";
    cin>>price;
    available=1;
    fstream f;
    f.open(id,ios::out);
    f.write((char*)this,sizeof(Book));
    f.close();
}
void Book::info()
{
    cout<<"Book id: ";
    getchar();
    string i;getline(cin,i);
    fstream f;
    f.open(i,ios::in);
    if(!f){cout<<"book not found\n";return;}
    f.read((char*)this,sizeof(Book));
    cout<<*this;
    f.close();
}
void Book::delet()
{
    cout<<"enter book id:";
    getchar();
    string i;getline(cin,i);
    if(!remove(i.c_str()))cout<<"Book deleted\n";
    else cout<<"Book not found\n";
}
bool Book::avail(string bk_id)
{
    ifstream f(bk_id);
    f.read((char*)this,sizeof(Book));
    f.close();
    return available;
}
void Book::avail_change(string bk_id,int i=0)
{
    ifstream f(bk_id);
    f.read((char*)this,sizeof(Book));
    if(i)available=0;
    else available=1;
    ofstream t("temp");
    t.write((char*)this,sizeof(Book));
    f.close();
    t.close();
    remove(bk_id.c_str());
    rename("temp",bk_id.c_str());
}
void Book::modify()
{
    getchar();
    cout<<"Book id: ";
    string s;getline(cin,s);
    ifstream f(s);
    if(!f)
    {
        cout<<"Book not found\n";
        return;
    }
    f.read((char*)this,sizeof(Book));
    string c;
    cout<<"Book id: "<<id;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new id: ";
        cin>>id;
    }
    cout<<"Book name: "<<name;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new name: ";
        cin.getline(name,20);
    }
    cout<<"Author name: "<<author;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new Author name: ";
        cin.getline(author,20);
    }
    cout<<"Price: "<<price;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new price: ";
        cin>>price;
    }
    ofstream t("temp");
    t.write((char*)this,sizeof(Book));
    f.close();
    t.close();
    remove(s.c_str());
    rename("temp",s.c_str());
}

void Member::add()
{
    getchar();
    cout<<"Enter personal id: ";
    cin.getline(id,10);
    cout<<"Enter department name: ";
    cin.getline(dept,20);
    cout<<"Enter member name: ";
    cin.getline(name,20);
    cout<<"Enter address: ";
    cin.getline(address,20);
    cout<<"Enter phone no.: ";
    cin.getline(phone,20);
    cout<<"Enter member id: ";
    cin.getline(m_id,10);
    noOfBook=0;
    fstream f;
    f.open(m_id,ios::out);
    f.write((char*)this,sizeof(Member));
    f.close();
}
void Member::delet()
{
    cout<<"enter member id:";
    getchar();
    string i;getline(cin,i);
    if(!remove(i.c_str()))cout<<"Member deleted\n";
    else cout<<"Member not found\n";
}
void Member::info()
{
    cout<<"Member id: ";
    getchar();
    string i;getline(cin,i);
    fstream f;
    f.open(i,ios::in);
    if(!f){cout<<"member not found\n";return;}
    f.read((char*)this,sizeof(Member));
    cout<<*this;
    Main ob;
    for(int i=0;i<noOfBook;i++){

        f.read((char*)&ob,sizeof(Main));
        cout<<ob;
    }
    f.close();
}
void Member::modify()
{
    getchar();
    cout<<"Member id: ";
    string s;getline(cin,s);
    ifstream f(s);
    if(!f)
    {
        cout<<"Book not found\n";
        return;
    }
    f.read((char*)this,sizeof(Member));
    string c;
    cout<<"Member id: "<<m_id;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new id: ";
        cin>>m_id;
    }
    cout<<"Student id: "<<id;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new id: ";
        cin>>id;
    }
    cout<<"Department name: "<<dept;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new department name: ";
        cin.getline(dept,20);
    }
    cout<<"Member name: "<<name;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new name: ";
        cin.getline(name,20);
    }
    cout<<"Address: "<<address;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new address: ";
        cin.getline(address,20);
    }
    cout<<"Phone no.: "<<phone;
    cout<<"\nchange (y/n)? ";
    getline(cin,c);
    if(c=="y")
    {
        cout<<"Enter new phone no.: ";
        cin.getline(phone,20);
    }
    ofstream t("temp");
    t.write((char*)this,sizeof(Member));
    f.close();
    t.close();
    remove(s.c_str());
    rename("temp",s.c_str());
}
bool Member::nib(string i)
{
    ifstream f(i);
    f.read((char*)this,sizeof(Member));
    f.close();
    return (noOfBook<=3);
}
void Main::issue_book()
{
    getchar();
    string t_bookid,t_mid;
    cout<<"Enter member id: ";
    getline(cin,t_mid);
    cout<<"Enter book id: ";
    getline(cin,t_bookid);
    ifstream f1(t_mid),f2(t_bookid);
    if(!f1)
        cout<<"Member not found\n";
    if(!f2)
        cout<<"Book not found\n";
    if(!f1 || !f2)
    {
        cout<<"Can not change\n";
        return;
    }
    f1.close();
    f2.close();
    bool flag1,flag2;
    flag1=avail(t_bookid);
    if(!flag1)
        cout<<"Book is not available\n";
    flag2=nib(t_mid);
    if(!flag2)
        cout<<"You can not issue more than 3 books\n";
    if(!flag1||!flag2)
    {
        cout<<"operation failed\n";
            return;
    }
    avail_change(t_bookid,1);
    nib_change(t_mid,t_bookid,1);
    cout<<"Enter current date(d-m-y): ";
    get_date();
    fstream f(t_mid,ios::app);
    f.write((char*)this,sizeof(Main));
    f.close();

}
void Main::return_book()
{
    getchar();
    string t_bookid,t_mid;
    cout<<"Enter member id: ";
    getline(cin,t_mid);
    cout<<"Enter book id: ";
    getline(cin,t_bookid);
    ifstream f1(t_mid),f2(t_bookid);
    if(!f1)
        cout<<"Member not found\n";
    if(!f2)
        cout<<"Book not found\n";
    if(!f1 || !f2)
    {
        cout<<"Can not return\n";
        return;
    }
    f2.close();
    bool flag=avail(t_bookid);
    if(flag)
    {
        cout<<"Book is not issued\n";
        return;
    }
    f1.read((char*)this,sizeof(Member));
    while(f1.read((char*)this,sizeof(Main)))
    {
        if(t_bookid==this->Book::id)flag=1;
    }
    if(!flag)
    {
        cout<<"you have not issued this book\n";
        return;
    }
    f1.close();
    flag=fine();
    if(flag){
        avail_change(t_bookid);
        nib_change(t_mid,t_bookid,0);
        cout<<"Book returned\n";
    }
    else
    {
        cout<<"Book not returned\n";
    }
}
void Member::nib_change(string s,string b,int j)
{
    ifstream f(s);
    f.read((char*)this,sizeof(Member));
    Main ob;
    ofstream t("temp");
    if(j){

        noOfBook++;
        t.write((char*)this,sizeof(Member));
        while(f.read((char*)&ob,sizeof(Main)))
            t.write((char*)&ob,sizeof(Main));

    }
    else
    {
        noOfBook--;
        t.write((char*)this,sizeof(Member));
        while(f.read((char*)&ob,sizeof(Main))) {
            if(b==ob.get_id())continue;
            t.write((char*)&ob,sizeof(Main));
        }
    }
    f.close();
    t.close();
    remove(s.c_str());
    rename("temp",s.c_str());
}
bool Main::fine()
{
    int d=diff();
    if(d>30)
    {
        double f=(double)(d-30)/2;
        cout<<"You have to pay "<<fixed<<setprecision(2)<<f<<" Tk. for fine\n";
        while(1){
        cout<<"Do you want to pay?(y/n): ";
        string c;
        cin>>c;
        if(c=="y")
        {
            cout<<"Pay total "<<fixed<<setprecision(2)<<f<<" Tk.\n";
            double x;
            cin>>x;
            if(x==f)
                return 1;
            else
                cout<<"you have to pay exactly "<<fixed<<setprecision(2)<<f<<" Tk.\n";

        }
        else
            return 0;
        }
    }
    return 1;
}
int Main::diff()
{
    cout<<"Enter current date(d-m-y): ";
    int d2,m2,y2;
    cin>>d2>>m2>>y2;
    int d1=d,m1=m,y1=y;
	const int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;

	long int n1 = y1*365 + d1;
    for (int i=0; i<m1 - 1; i++)
        n1 += month[i];

    long int n2 = y2*365 + d2;
    for (int i=0; i<m2 - 1; i++)
        n2 += month[i];

    return n1 - n2;
}
int main()
{
    int n;
    do
    {
        cout<<"\t\t [1]add book\n";
        cout<<"\t\t [2]view book\n";
        cout<<"\t\t [3]remove book\n";
        cout<<"\t\t [4]modify book\n";
        cout<<"\t\t [5]add Member\n";
        cout<<"\t\t [6]view Member\n";
        cout<<"\t\t [7]remove Member\n";
        cout<<"\t\t [8]modify Member\n";
        cout<<"\t\t [9]issue book\n";
        cout<<"\t\t[10]return book\n";
        cout<<"\t\t[11]exit\n";
        cout<<"Enter your choice: ";
        cin>>n;
        system("cls");
        if(n==1){Book b;b.add();cin.ignore();}
        else if(n==2){Book b;b.info();cin.ignore(); }
        else if(n==3){Book b;b.delet();cin.ignore(); }
        else if(n==4){Book b;b.modify();cin.ignore(); }
        else if(n==5){Member b;b.add();cin.ignore();}
        else if(n==6){Member b;b.info();cin.ignore(); }
        else if(n==7){Member b;b.delet();cin.ignore(); }
        else if(n==8){Member b;b.modify();cin.ignore(); }
        else if(n==9){Main b;b.issue_book();cin.ignore(); }
        else if(n==10){Main b;b.return_book();cin.ignore(); }
        else cout<<"invalid choice\n";
        system("cls");
    }while(n!=11);

    return 0;
}
