#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Item{
    public:
    char name[10];
    int quantity;
    int cost;
    int code;

    bool operator ==(Item b){
        if(code == b.code) return true;
        return false;
    }
};

bool compare(Item i1, Item i2){
    if(i1.cost < i2.cost) return true;

    return false;
}

vector<Item> v;

void insert(){
    Item i1;

    cout<<"\nEnter Item Name : ";
    cin>>i1.name;
    cout<<"\nEnter Item Quantity : ";
    cin>>i1.quantity;
    cout<<"\nEnter Item Cost : ";
    cin>>i1.cost;
    cout<<"\nEnter Item Code : ";
    cin>>i1.code;

    v.push_back(i1);

}

void print(Item &i1){
    cout<<"\n";
    cout<<"\nItem Name : "<<i1.name;
    cout<<"\nItem Quantity : "<<i1.quantity;
    cout<<"\nItem Cost : "<<i1.cost;
    cout<<"\nItem Code : "<<i1.code;
    cout<<"\n\n";
}
void display(){
    for_each(v.begin(), v.end(), print);
}

void search(){
    Item i1;
    vector<Item>::iterator it;
    cout<<"Enter Item to Search: ";
    cin>>i1.code;

    it = find(v.begin(), v.end(), i1);

    if(it == v.end()){
        cout<<"\nElement Not Found\n";
    }
    else{
        cout<<"\nElement Found\n";
    }
}

void Delete(){
    Item i1;
    vector<Item>::iterator it;
    
    cout<<"Enter Item code to Delete\n";
    cin>>i1.code;

    it = find(v.begin(), v.end(), i1);

    if(it == v.end()){
        cout<<"\nElement Not Found\n";
    }
    else{
        v.erase(it);
        cout<<"\nDeleted\n";
    }
}

int main(){
    int a = 0;
    do{
        int ch;
        cout<<"\n* * * * * Menu * * * * *";
        cout<<"\n1.Insert";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Sort";
        cout<<"\n5.Delete";
        cout<<"\n6.Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        
        switch (ch)
        {
        case 1:
            insert();
            break;
        
        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            sort(v.begin(), v.end(), compare);
            cout<<"\nSorted Item on the basis of Cost\n";
            break;
        
        case 5:
            Delete();
            break;
        
        case 6:
            a = 6;
            break;
        
        default:
            cout<<"\nWrong Choice!!\n";
            break;
        }
    }while(a != 6);


    return 0;
}