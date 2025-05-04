    #include<iostream>
#include<vector>
using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a+b;
    }

    double add(double a, double b)
    {
       return a+b;
    }

    double add(int a, double b)
    {
        return a+b;
    }
};

int main()
{
    Calculator calc;

    vector<double> stlResults;
    stlResults.push_back(calc.add(10,20));
    stlResults.push_back(calc.add(5.5,5.5));
    stlResults.push_back(calc.add(10,5.5));

    cout<<"\n Results using STL vector: ";
    for(size_t i=0; i< stlResults.size(); ++i)
    {
        cout<<"\n Result"<<i+1<<": "<<stlResults[i];
    }
    cout<<endl;

    double nonStlResults[3];
    nonStlResults[0]=calc.add(30,40);
    nonStlResults[1]=calc.add(7.2,8.3);
    nonStlResults[2]=calc.add(15,4.5);

    cout<<"\nResults using basic array: ";
    for(int i=0;i<3;++i)
    {
        cout<<"\n Result "<<i+1<<": "<< nonStlResults[i];
    }
    return 0;
}
