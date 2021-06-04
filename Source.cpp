#include "Header.h"

void Person::setName(string temp)
{
    Name = temp;
}

void Person::setAge(int temp)
{
    Age = temp;
}

void Person::setGender(char temp)
{
    Gender = temp;
}

void Adult::setOccupation(string temp)
{
    Occupation = temp;
}

void Adult::setQualification(string temp)
{
    Qualification = temp;
}

void Adult::setNIC(string temp)
{
    NIC = temp;
}

void kid::setBform(string temp)
{
    B_form_number = temp;
}

void Adult::print()
{
    cout<<"Name: "<<Name<<endl;
    cout<<"Age: "<<Age<<endl;
    cout<<"Gender: "<<Gender<<endl;
    cout<<"Occupation: "<<Occupation<<endl;
    cout<<"Qualification: "<<Qualification<<endl;
    cout<<"NIC: "<<NIC<<endl;
}

void kid::print()
{
    cout<<"Name: "<<Name<<endl;
    cout<<"Age: "<<Age<<endl;
    cout<<"Gender: "<<Gender<<endl;
    cout<<"B Form Number: "<<B_form_number<<endl;
}

Bogie::Bogie(int id)
{
    Bogie_ID = id;
//    Adults = new Adult[4];
//    kids = new kid[6];
    is_engine = false;
}

Bogie::~Bogie()
{
//    delete[] Adults;
//    delete[] kids;
}

void Bogie::AddPassengers()
{
    cout<<"Enter Family Name:"<<endl;
    cin>>familyName;
    do
    {
    cout<<"Enter the number of adults to add (must be 4 or less):"<<endl;
    cin>>num_adults;
    } while (num_adults>4 || num_adults<0);
    
     do
       {
       cout<<"Enter the number of kids to add (must be 6 or less):"<<endl;
       cin>>num_kids;
       } while (num_kids>6 || num_kids<0);
    
    for (int i=0;i<num_adults;i++)
    {
        string name, occupation,qualification,nic;
        int age;
        char gender;
        cout<<"Entering information for adult "<<(i+1)<<endl;
        cout<<"Enter Name: "<<endl;
        cin>>name;
        Adults[i].setName(name);
        cout<<"Enter Age: "<<endl;
        cin>>age;
        Adults[i].setAge(age);
        cout<<"Enter Gender: "<<endl;
        cin>>gender;
        Adults[i].setGender(gender);
        cout<<"Enter Occupation: "<<endl;
        cin>>occupation;
        Adults[i].setOccupation(occupation);
        cout<<"Enter Qualification: "<<endl;
        cin>>qualification;
        Adults[i].setQualification(qualification);
        cout<<"Enter NIC: "<<endl;
        cin>>nic;
        Adults[i].setNIC(nic);
        
    }
    
    for (int i=0;i<num_kids;i++)
       {
           string name, bform;
           int age;
           char gender;
           cout<<"Entering information for kid "<<(i+1)<<endl;
           cout<<"Enter Name: "<<endl;
           cin>>name;
           kids[i].setName(name);
           cout<<"Enter Age: "<<endl;
           cin>>age;
           kids[i].setAge(age);
           cout<<"Enter Gender: "<<endl;
           cin>>gender;
           kids[i].setGender(gender);
           cout<<"Enter B form number: "<<endl;
           cin>>bform;
           kids[i].setBform(bform);
       }
}

void Bogie::Print()
{
    cout<<"Bogie# "<<Bogie_ID<<endl;
    
if (!is_engine)
{
    
    cout<<"Family Name: "<<familyName<<endl;
    
    
    for (int i=0; i<num_adults;i++)
    {
        cout<<"Adult "<<(i+1)<<endl;
        Adults[i].print();
    }
    for (int i=0; i<num_kids;i++)
    {
        cout<<"Kid "<<(i+1)<<endl;
        kids[i].print();
    }
}
    
}

void Bogie::Print_bogienum()
{
    cout<<"Bogie# "<<Bogie_ID<<endl;
}

void Bogie::set_is_engine()
{
    is_engine = true;
}

void train::addBogie(int ID)
{
    Bogie* newbogie = new Bogie(ID);
    
    newbogie->next = NULL;
    if (engine==NULL)
    {
        cout<<"Creating engine"<<endl;
        newbogie->set_is_engine();
        engine = newbogie;
    }
    else
    {
        Bogie* temp = engine;
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        newbogie->AddPassengers();
        temp->next = newbogie;
    }
}

bool train::removeBogie(int ID)
{
    
    if (engine->get_bogie_ID() == ID)
    {
        cout<<"Engine cannot be removed"<<endl;
        return false;
    }
        
    Bogie* prev = engine;
    while(prev->next!=NULL && prev->next->get_bogie_ID()!=ID)
    {
        prev = prev->next;
    }
    if (prev->next==NULL)
    {
        cout<<"Bogie not found"<<endl;
        return false;
    }
    
    else
    {
        Bogie* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        cout<<"Bogie removed"<<endl;
        return true;
    }
}

void train::printTrain()
{
    Bogie* temp = engine;
    while (temp != NULL)
    {
        temp->Print_bogienum();
        cout<<endl;
        temp = temp->next;
    }
}

bool train::SearchBogie(int ID)
{
    Bogie* temp = engine;
    while(temp!=NULL && temp->get_bogie_ID()!=ID)
    {
        temp = temp->next;
    }
    if (temp==NULL)
    {
        cout<<"Bogie not found"<<endl;
        return false;
    }
    
    else
    {
        cout<<"Bogie found"<<endl;
        temp->Print();
        return true;
    }
}

train::~train()
{
    
}

int main()
{
    train t;
    t.addBogie(1);
    t.addBogie(2);
 
    t.SearchBogie(2);
    return 0;
}
