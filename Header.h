#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string Name;
    int    Age;
    char Gender;
    
public:
    virtual void print(){};
    void setName(string);
    void setAge(int);
    void setGender(char);
    virtual void setOccupation(string){};
    virtual void setQualification(string){};
    virtual void setNIC(string){};
    virtual void setBform(string){};
    virtual ~Person() {};

    
};

class Adult: public Person {
    string Occupation;
    string Qualification;
    string NIC;
public:
    void print();
    void setOccupation(string);
    void setQualification(string);
    void setNIC(string);

    
};

class kid: public Person {
    string B_form_number;
public:
    void print();
    void setBform(string);

};

class Bogie {
    int    Bogie_ID;
   
//    Person *Adults;
//    Person *kids;
    Adult Adults[4];
    kid kids[6];
    string familyName;
    int num_adults;
    int num_kids;
    bool is_engine;
public:
    Bogie  *next;
    Bogie(int id);
    Bogie(){};
    void AddPassengers(); // should add adults and kids information etc
    void Print();
    void Print_bogienum();
    void set_is_engine();
    int get_bogie_ID(){return Bogie_ID;}
    ~Bogie();
};

class train {
    Bogie * engine;
public:
    train() {
        engine = nullptr;
    }
    void addBogie(int ID); //add bogie at the end of the train
    bool removeBogie(int ID); //search the bogie and delete it
    void printTrain(); //print only the Bogie_ID of all bogies
    bool SearchBogie(int ID);//search the particular bogie
    ~train();
};


#endif
