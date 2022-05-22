#include <iostream>
#include "unsortedtype.cpp"
#define siZe 5
using namespace std;

int main(void) {

    UnsortedType <int> student_id;
    UnsortedType <string> student_name;
    UnsortedType <double> student_cgpa;

    cout<< "######Insert details for five students######"<<endl;

    int id;
    string name;
    double cgpa;

    for (int i=0;i<siZe;i++){

            cout<<"Enter ID of student "<<(i+1)<<"  :";
            cin>>id;
            student_id.InsertItem(id);

            cout<<"Enter name of student "<<(i+1)<<":";
            cin>>name;
            student_name.InsertItem(name);

            cout<<"Enter CGPA of student "<<(i+1)<<":";
            cin>>cgpa;
            student_cgpa.InsertItem(cgpa);
            cout <<endl;
    }
    //Write code for search
    int searchId;
    bool found = false;
    cout <<"\nEnter student id to search : ";
    cin >> searchId;
        student_id.RetrieveItem(searchId,found);
        if (found)
            {
            cout <<"Is found? " <<found <<endl;
            for(int i=0; i<student_id.LengthIs(); i++)
            {
                student_id.GetNextItem(id);
                student_name.GetNextItem(name);
                student_cgpa.GetNextItem(cgpa);
                if(id == searchId)
                   cout<<id<<" "<<name<<" "<<cgpa<<endl;
            }
            }
        else if(!found)
        cout <<"\nSorry! couldn't find it!!"<<endl;

        // Resetting the list to move the pointer at the first index
        student_id.ResetList();
        student_name.ResetList();
        student_cgpa.ResetList();
        //Write code for deletion
    int deleteId;
    bool isfound = false;
    cout <<"\nEnter student id to delete : ";
    cin >> deleteId;
    student_id.RetrieveItem(deleteId,isfound);
        if (isfound)
            {
            for(int i=0; i<student_id.LengthIs(); i++)
            {
                student_id.GetNextItem(id);
                student_name.GetNextItem(name);
                student_cgpa.GetNextItem(cgpa);
                if(id == deleteId)
                {
                   student_id.DeleteItem(id);
                   student_name.DeleteItem(name);
                   student_cgpa.DeleteItem(cgpa);
                   cout <<"Deleted successfully!"<<endl;
                }
            }
            }
        else if(!isfound)
        cout <<"\nSorry! couldn't find it to delete!!"<<endl;

    // Resetting the list to move the pointer at the first index
    student_id.ResetList();
    student_name.ResetList();
    student_cgpa.ResetList();
    cout<< "\n######The inserted list is printed below######"<<endl;
    for (int i=0;i<student_id.LengthIs();i++){

            student_id.GetNextItem(id);
            student_name.GetNextItem(name);
            student_cgpa.GetNextItem(cgpa);

            cout<<id<<" "<<name<<" "<<cgpa<<endl;
    }

    return 0;
}
