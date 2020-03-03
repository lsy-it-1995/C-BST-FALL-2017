#include <iostream>
#include "classbst.h"
#include <locale>

using namespace std;

void testtree();
int createnumber(int f);
int main()
{
    testtree();

    cout << "Hello World!" << endl;
    return 0;
}


int createnumber(int f)
{
    f= rand()%100;//0-99
    return f;
}

void testtree()
{
    char userinput;
    int userinputnumber;
    classBST<int> test1;
    classBST<int> test2;
    int item=0;
    srand(time(NULL));
    cout<<"[R]andom [I]nsert [C]lear [E]rase [S]earch c[O]py [A]dd e[X]it"<<endl;
    cin>>userinput;
    do{
        userinput = toupper(userinput);
        if(userinput=='R')
        {
            item= createnumber(item);
            cout<<"Your random number is " << item<<endl;
        }
        else if(userinput=='I')
        {
            test1.insert(item);
            cout<<test1<<endl;
        }
        else if(userinput=='C')
        {
            test1.clearall();
        }
        else if(userinput=='E')
        {
            tree_node<int> *found = NULL;
            cout<<"which number you want to erase from the tree"<<endl;
            cin>>userinputnumber;
            if(test1.search(userinputnumber,found))
            {
                test1.erase(userinputnumber);
                cout<<"here is your tree"<<endl<<test1<<endl;
            }
            else
            {
                cout<<"the number isn't in the tree"<<endl;
            }
        }
        else if(userinput=='S')
        {
            tree_node<int> *found = NULL;
            cout<<" WHAT NUMBER ARE YOU LOOKING FOR"<<endl;
            cin>>item;
            if(test1.search(item,found))
            {
                cout << "item found: " << endl;
            }
            else
            {
                cout<<"item isn't found"<<endl;
            }
        }
        else if(userinput=='X')
        {
            return;
        }
        else if(userinput == 'O')
        {
            test2 = test1;
            cout<<"copy tree looks like: "<<endl<<test2;
        }
        else if(userinput == 'A')
        {
            cout<<"adding your copied tree to your original tree"<<endl;
            test1+=test2;
            cout<<"the combination of tree is : "<<endl<<test1;
        }
        else if(userinput!='R'||userinput!='I'||userinput!='C'||userinput!='E'||userinput!='S'||userinput!='X'||userinput == 'O'||(userinput == 'A'))
        {
            cout<<"try again"<<endl;
        }
        cout<<"[R]andom [I]nsert [C]lear [E]rase [S]earch c[O]py [A]dd e[X]it"<<endl;
    }while(cin>>userinput);
}
