//
//  main.cpp
//  myFirstProgi
//
//  Created by Kutman Amangeldiev on 8/10/22.
//

#include <iostream>
using namespace std;

class AbstractEmployee{
    virtual void askForPromotion() = 0;
};

class Employee: AbstractEmployee{
private:
    string Company;
    int Age;
protected:
    string Name;
public:
    Employee(string name, int age, string company){
        Name = name;
        Company = company;
        Age = age;
    }
    
    void askForPromotion(){
        if (Age >= 30){
            cout << Name << " Got promoted" << endl;
        } else {
            cout << Name << " Sorry no promotion for you" << endl;
        }
    }
    
    void setName(string name){
        Name = name;
    }
    
    void setCompany(string company){
        Company = company;
    }
    
    void setAge(int age){
        if (age >= 18){
            Age = age;
        }
    }
    
    int getAge(){
        return Age;
    }
    
    string getCompany(){
        return Company;
    }
    
    string getName(){
        return Name;
    }
    
    void IntroduceYourself(){
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Company: " << Company << endl;
    }
    
    virtual void work(){
        cout << Name << " is checking email , task backlog" << endl;
    }
};

class Developer: public Employee{
public:
    string favoriteProgrammingLanuage;
    
    Developer(string name, int age, string company, string language)
    :Employee(name,age,company){
        favoriteProgrammingLanuage = language;
    }
    
    void work(){
        cout << Name << " is writing " << favoriteProgrammingLanuage << " code" << endl;
    }
    
    void fixBug(){
        cout << Name << " is fixing bugs using " << favoriteProgrammingLanuage << endl;
    }
};

class Teacher: public Employee{
public:
    Teacher(string name, int age, string company, string lesson)
    :Employee(name, age, company){
        subject = lesson;
    }
    string subject;
    
    void prepareLesson(){
        cout << Name << " is preparing " << subject << " lesson" << endl;
    }
    
    void work(){
        cout << Name << " is teaching " << subject << endl;
    }
};

int main(){
    Developer  ku = Developer("Kutman", 23, "Google", "C++");
    Teacher th = Teacher("Thuong", 21, "NDHU", "Chinese");
    
   //parent class reference is used to refer to a child class object
    Employee *developer = &ku;
    Employee *teacher = &th;

    developer->work();
    teacher->work();
}
