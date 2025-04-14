#include<iostream>
using namespace std;
class plot
{
    int l,w;

public:
    void add_data();
    void update_data();
    void display_data();
};

void plot::add_data()
{
    cout<<"\n Enter the length of the rectangular plot: ";
    cin>>l;
    cout<<"\n Enter the width of the rectangular plot: ";
    cin>>w;
}
void plot::update_data()
{
    int u;
    cout<<"\n Enter 1 if you want to update the dimensions: ";
    cin>>u;
    if(u==1)
    {
        cout<<"\n Enter the updated length of the rectangular plot: ";
        cin>>l;
        cout<<"\n Enter the updated width of the rectangular plot: ";
        cin>>w;
    }
    else
        cout<<"\n Nothing updated";
}

void plot::display_data()
{
    int a,p;
    a=l*w;
    p=2*(l+w);
    cout<<"\n Area of the rectangular plot is: "<<a;
    cout<<"\n Perimeter of the rectangular plot is: "<<p;
}

int main()
{
    int n;
    cout<<"\n Enter the number of rectangular plots: ";
    cin>>n;
    plot aa[n];
    for(int i=0;i<n;i++)
    {
        aa[i].add_data();
        aa[i].update_data();
        aa[i].display_data();
    }
    return 0;
}
