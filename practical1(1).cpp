#include<iostream>
using namespace std;
class bankaccount
{
    char name[15];
    double acc_num;
    double balance=0;

public:
    void getdata();
    void putdata();
    void deposit();
    void withdraw();
    void display_balance();
};

void bankaccount::getdata()
{
    cout<<"\n Enter your name: ";
    cin>>name;
    cout<<"\n Enter your account number: ";
    cin>>acc_num;
    cout<<"\n Enter your initial balance:";
    cin>>balance;
}

void bankaccount::putdata()
{
    cout<<"\n Your name is "<<name;
    cout<<"\n Your account number is "<<acc_num;
    cout<<"\n Your initial balance is "<<balance;
}

void bankaccount::deposit()
{
    int a;
    cout<<"\n Enter the amount you want to deposit: ";
    cin>>a;
    balance=balance+a;
}

void bankaccount::withdraw()
{
    int w;
    cout<<"\n Enter the amount you want to withdraw: ";
    cin>>w;
    balance=balance-w;
    if(balance<0)
    {
        cout<<"Insufficient balance in account.";
    }
}

void bankaccount::display_balance()
{
    cout<<"\n Your current balance is: "<<balance;
}

int main()
{
    bankaccount b1;
    b1.getdata();
    b1.putdata();
    b1.deposit();
    b1.withdraw();
    b1.display_balance();
}
