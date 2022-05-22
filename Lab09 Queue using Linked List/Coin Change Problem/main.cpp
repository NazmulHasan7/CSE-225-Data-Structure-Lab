#include <iostream>
#include "Queue.cpp"
using namespace std;

int main()
{
    Queue<int> q;
    Queue<int> box1,box2;
    int n=3;

    int arr[n] ={5,10,30};
    int temp;

    int money =40;
    temp =0;
    box1.Enqueue(temp);
    box2.Enqueue(0);
    int temp1,temp2;
    bool found=false;
    while(true)
    {
        if(found)
            break;
        box1.Dequeue(temp1);
        box2.Dequeue(temp2);
        cout << temp1 << "  " << temp2 << endl;
        for(int i=0;i<n;i++)
        {
            if(temp1==money)
            {
                found =true;
                break;
            }

        box1.Enqueue(temp1+arr[i]);
        cout <<"Pushing " << temp1+arr[i] <<" in box 1" <<endl;
        box2.Enqueue(temp2+1);
        cout <<"Pushing " << temp2+1 <<" in box 2" <<endl;
        cout <<endl;
        }

    }
    cout << "Answer " << temp2 << endl;

}
