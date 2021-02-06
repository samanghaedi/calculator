#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Number
{
    public:
        vector <bool> ipart;
};
Number fact(Number , int );
Number multi(Number , Number );
Number sum(Number , Number );
Number sub(Number );


int main()
{
    cout << "enter number: ";
    int n, m;
    cin >> n;
    m = n;
    Number x;
    while(n == 0)
    {
        x.ipart.insert(x.ipart.begin(), n % 2);
        n /= 2;
    }

    auto it1 = x.ipart.begin();
    auto it2 = x.ipart.end();

    while(it1 != it2)
    {
        cout << *it1 << endl;
        it1++;
    }
    //Number z = fact(x, m);
    //print_result(z);
}

Number fact(Number x, int m)
{
    Number z;
    z.ipart.push_back(true);
    for (int i = m ; i > 1  ; i--)
    {
        z = multi(z, x);
        x = sub(x);
    }
    return z;
}

Number multi(Number x, Number y)
{
    Number temp1, temp2;
    temp1.ipart.push_back(0);
    temp2.ipart.push_back(0);
    int n = 0;
    int m = 0;
    for(int i = x.ipart.size() - 1 ; i >= 0 ; i--)
    {
        n = 0;
        if(x.ipart[i])
        {
            temp1 = y;
            n++;
            for(int j = x.ipart.size() - 1 ; j > i ; j--)
                temp1.ipart.push_back(0);
            
            temp2 = sum(temp2, temp1);
            temp1.ipart.clear();
        }
    }
    return temp2;
}

Number sum(Number x, Number y)
{
    Number z;
    bool temp = 0;
    auto it1 = x.ipart.end() - 1;
    auto it2 = y.ipart.end() - 1;
    
    while(it1 >= x.ipart.begin() && it2 >= y.ipart.begin())
    {
        if(*it1 && *it2)
        {
            *it2 = temp;
            temp = 1;
        }
        else
        {
            *it2 = temp ^ (*it1 || *it2);
            temp = temp && (*it1 || *it2);
        }
        it1--;
        it2--;
    }
    if(temp)
    {
        if(it1 >= x.ipart.begin())
        {
            while(it1 >= x.ipart.begin())
            {
                *it1 = temp ^ *it1;
                y.ipart.insert(y.ipart.begin(), *it1);
                temp = temp && *it1;
                it1--;
            }
            if(temp)
                y.ipart.insert(y.ipart.begin(), temp);
        }
        else if(it2 >= y.ipart.begin())
        {
            while(it2 >= y.ipart.begin())
            {
                *it2 = temp ^ *it2;
                temp = temp && *it2;
                it2--;
            }
            if(temp)
                y.ipart.insert(y.ipart.begin(), temp);
        }
    }
    else
    {
        if(it1 >= x.ipart.begin())
        {
            while(it1 >= x.ipart.begin())
            {
                y.ipart.insert(y.ipart.begin(), *it1);
                it1--;
            }
        }
    }
    return y;
}

Number sub(Number x)
{
    int i = x.ipart.size() - 1;
    bool temp = 1;
    do
    {
        temp = x.ipart[i] ^ temp;
        if(temp)
            x.ipart[i--] = 1;
        else
            x.ipart[i] = 0;
    }while(temp != 0);
    return x;
}

/*
void print_result(Number z)
{
    int n = z.ipart.size();
    vector <Number> two;
    for(int i = 0 ; i < n ; i--)
    {
        two(two.begin(), pow(2, i), z.ipart[n - 1 - i]);
    }
}

Number pow(int x, int y)
{

}
*/