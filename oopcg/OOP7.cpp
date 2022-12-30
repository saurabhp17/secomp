#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    string s;
    map<string,int>mymap;
    map<string,int>::iterator i;
    mymap.insert(pair<string,int>("maharashtra",150000));
    mymap.insert(pair<string,int>("gujrat",120000));
    mymap.insert(pair<string,int>("delhi",450000));
    mymap.insert(pair<string,int>("goa",30000));
    mymap.insert(pair<string,int>("J&K",9000));
    for(i=mymap.begin();i!=mymap.end();i++)
    {
        cout<<(*i).first<<""<<(*i).second<<endl;
    }
    cout<<"Enter the state name"<<endl;
    cin>>s;
    cout<<"population of state is:"<<mymap[s];
    return 0;
}