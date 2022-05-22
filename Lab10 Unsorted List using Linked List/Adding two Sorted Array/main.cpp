#include <iostream>
#include "UnsortedList.cpp"
using namespace std;

int main()
{
    UnsortedList<int> list1;
    UnsortedList<int> list2;
    UnsortedList<int> resultList;

    int num1,num2,input;
    cout <<"How many elements to be inserted in List 1 ? " ;
    cin >> num1;
    cout <<"Enter elements : ";

    for(int i=0; i<num1; i++){
        cin >> input;
        list1.InsertItem(input);
    }
    cout <<"\nHow many elements to be inserted in List 2 ? " ;
    cin >> num2;
    cout <<"Enter elements : ";

    for(int i=0; i<num2; i++){
        cin >> input;
        list2.InsertItem(input);
    }
    cout <<"\nList 1 : ";
    list1.PrintList();
    cout <<"List 2 : ";
    list2.PrintList();

    //Merging two list in sorted order
    int i=0,j=0;
    int arr1,arr2;
    list1.GetNextItem(arr1);
    list2.GetNextItem(arr2);

    while(i<num1 && j<num2)
    {
        if(arr1 <= arr2){
            resultList.InsertItem(arr1);
            i++;
            /*------------------------------------------------------------
              After each Insertion the i value should be increased. Since,
              GetNextItem(T&) has a pointer variable. So at some point it
              may refer to NULL.So, we should check the i value after each
              insertion so that pointer doesn't reach NULL
              ----------------------------------------------------------*/
            if(i<num1)
            list1.GetNextItem(arr1);
        }
        else{
            resultList.InsertItem(arr2);
            j++;
            /*-------------------------------------------------
             Same as i : Let's trace this part of the code
             Let's say the list is 2->4->7->NULL
             Skipping the Insertion of 2 and 4 & j is 2 now
             In case of 7 : resultList.InsertItem(arr2) inserts
                            7 to the List and j is 3 now
                            3<3 is false
             so this time GetNextItem(arr2) will be skipped &
             that's what we want.
             If j was not increased after insertion and it was
             not checked them it won't happen and the program
             would terminate abnormally
             ------------------------------------------------*/
            if(j<num2)
            list2.GetNextItem(arr2);
        }
    }
    //If anything is left inside the 1st list 1
    while(i<num1){
        resultList.InsertItem(arr1);
        i++;

        if(i<num1)
            list1.GetNextItem(arr1);
    }
    //If anything is left inside the 1st list 2
    while(j<num2){
        resultList.InsertItem(arr2);
        j++;

        if(j<num2)
            list2.GetNextItem(arr2);
    }
    cout <<"After merging both lists in sorted Order : ";
    resultList.PrintList();
    return 0;
}
