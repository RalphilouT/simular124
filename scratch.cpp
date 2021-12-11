#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string.h>
#include "testinghiding.cpp"
using namespace std;
int j =0;
class virtualtesting{
    int id;
    
    //friend void testingfriend();
    public:
        int testingPROTECTED;
        virtualtesting(){cout << "virtualtesting constructor" << endl;};
        virtualtesting(int x):id(x){};
        void display(){
            cout << "Regular display function in virtualtesting class" << endl;
        }
        //virtual void displayvirtual(){cout << "in base class" << endl;};
        virtual void displayvirtual()=0;
        virtual void displayvirtualBoth(){
            cout << "In virtual testing class"<< endl;
        }
        virtual void displayvirtualonlyinbase(){
            cout << "In virtual testing class in base"<< endl;
        }
        virtual ~virtualtesting(){cout << "Destructor in virtualtesting" << endl;};
        // ~virtualtesting(){cout << "Destructor in virtualtesting" << endl;};
};

class inheritVS:public virtualtesting{
    int id;
    
    public:
        static int data;
        friend void testingfriend();
        inheritVS(){cout << "inheritVS constructor" << endl;};
        void display(){
            cout << "Regular display function in inheritVS class" << endl;
        }
        void displayvirtual(){
            cout << "In the inheritVS class" << endl;
        }
        virtual void displayvirtualBoth(){
            cout << "In inheritVS class" << endl;
        }
        void displayintID()
        {
            cout << id << endl;
        }
        static void displaystatic(){
            cout << "Testing static function" << endl;
        }
        ~inheritVS(){cout << "Destructor in inheritVS" << endl;};
};

class inheritVSPROTECTED:protected virtualtesting{
    int id;
    
    public:
        static int data;
        friend void testingfriend();
        inheritVSPROTECTED(){cout << "inheritVSPROTECTED constructor" << endl;};
        void display(){
            cout << "Regular display function in inheritVSPROTECTED class" << endl;
        }
        void displayvirtual(){
            cout << "In the inheritVSPROTECTED class" << endl;
        }
        virtual void displayvirtualBoth(){
            cout << "In inheritVSPROTECTED class" << endl;
        }
        void displayintID()
        {
            cout << id << endl;
        }
        static void displaystatic(){
            cout << "Testing static function" << endl;
        }
        ~inheritVSPROTECTED(){cout << "Destructor in inheritVSPROTECTED" << endl;};
};
int inheritVS::data = 10;
void testingfriend()
{
    inheritVS testingfriend;
    testingfriend.id = 10;
    testingfriend.displayintID();
}
int testingstatic()
{
    static int i = 0;
    i++;
    return i;
}
int testinglobal()
{
    ::j = 0;
    j++;
}
void testingrefrerence(int &p)
{
    p++;
    
}
void testingclassrefrerence(const virtualtesting &p)
{
    
    cout << "Inside testingclassrefrence" <<endl;
}
void testingclassrefrerence(const inheritVS &p)
{
    
    cout << "Inside testingclassrefrence" <<endl;
}
void testingpointer(int*p)
{
    (*p)++;
}
struct A{
    A(){
        cout << "A" << endl;
    }
    ~A(){
        cout << "~A" << endl;
    }
};
class B:public A{
    public:
        B(){
            cout << "B" << endl;
        }
        ~B(){
            cout << "~B" << endl;
        }
};
class C:public B{
    public:
        C(){
            cout << "C" << endl;
        }
        ~C(){
            cout << "~C" << endl;
        }
};
int f()
{
    static int s = 0;
}
class X{
    public:
        char *s;
        bool isref;
        X( const char * msg)
        {
            s = new char[strlen(msg)+1]; 
            strcpy(s,msg);
        }
        ~X(){
            cout << s << " gone." << endl;
            delete[] s;
        }

};
// class X{
//     public:
//         char *s;
//         bool isref;
//         X( const char * msg)
//         {
//             s = new char[strlen(msg)+1]; 
//             strcpy(s,msg);
//         }
//         ~X(){
//             if(!isref)
//             {
//                 cout << s << " gone." << endl;
//                 delete[] s;
//             }
//         }
//         void operator= (const X&x)
//         {
//             delete[]s; s= x.s; isref = true;
//         }
// };
// class X{
//     public:
//         char *s;
//         bool isref;
//         X( const char * msg)
//         {
//             s = new char[strlen(msg)+1]; 
//             strcpy(s,msg);
//         }
//         ~X(){
//             cout << s << " gone." << endl;
//             delete[] s;
//         }
//         void operator= (const X&x)
//         {
//             delete[] s;
//             s = new char[strlen(x.s)+1];
//             strcpy(s,x.s);
//         }

// };
class Person{
    public:
        Person(int x){
            cout << "Person" << endl;
        }
};

class Faculty:virtual public Person{
    public:
        Faculty(int x):Person(x){
            cout << "Faculty" << endl;
        }
};
class Student:virtual public Person{
    public:
        Student(int x):Person(x){
            cout <<"Student" << endl;
        }
};
// class TA:public Faculty,public Student{
//     public:
//         TA(int x):Faculty(x),Student(x){
//             cout << "Faculty" << endl;
//         }
// };
class TA:public Faculty,public Student{
    public:
        TA(int x):Person(x), Faculty(x),Student(x){
            cout << "Faculty" << endl;
        }
};
void overloading(int x);
//int overloading(int x);
int overloading(int x, int y);
int main(int argc, char *argv[]){
    double * a1;
    void *b1 = a1;
    
    // int testingref = 10;
    // inheritVS testing;
    // //virtualtesting testing3;
    // //virtualtesting testin6;
    // inheritVSPROTECTED testingPROTECTED;
    // virtualtesting * testing1 =&testing;
    // cout << endl << "Testing virtual" << endl;
    // testing1->display();
    // testing.display();
    // testing1->displayvirtual();
    // testing1->displayvirtualBoth();
    // testing1->displayvirtualonlyinbase();
    // testing.displayvirtualBoth();
    // cout << endl;
    // testing.displayvirtual();
    // //testin6.displayvirtual();
    // cout << endl << "Testing friend" << endl;
    // testingfriend();
    // cout << endl << "Testing friend function" << endl;
    // inheritVS::displaystatic();
    // cout << endl << "Testing friend data using different syntax" << endl;
    // cout << "Displaying inheritVS static data " << inheritVS::data << endl;
    // //cout << testingPROTECTED.testingPROTECTED << endl;
    // cout << endl << "Testing static" << endl;
    // for(int i = 0; i < 3;i++)
    // {
    //     cout << testingstatic()<< endl;
    // }
    // cout << endl << "Testing global" << endl;
    // for(int i = 0; i < 3;i++)
    // {
    //     cout << testinglobal()<< endl;
    // }
    // cout << endl << "Testing static" << endl;
    // cout << "Before function is called " << testingref << endl;
    // testingrefrerence(testingref);
    // cout << "After function is called " << testingref << endl;
    // // cout << endl << "Testing constructor/destructor order with inheritance and virtual" << endl;
    // // virtualtesting * testing5;
    // // inheritVS testing4;
    // // testing5 = &testing4;
    // // delete testing5;
    // cout << endl << "Testing using testinghiding" << endl;
    // hiding hide; 
    // hide.function1();
    // cout << endl << "Testing using testingpointer" << endl;
    // cout << "Before testingpointer " << testingref << endl;
    // testingpointer(&testingref);
    // cout << "After testingpointer " << testingref << endl;
    // cout << endl << "Testing testing class refrerence" << endl;
    // testingclassrefrerence(*testing1);
    // testingclassrefrerence(testing);
    // cout << endl << "Testing constructor" << endl;
    // if(true){
    //     B b;
    // }
    // if(true){
    //     A * ca = new B;
    //     delete ca;
    // }
    // A * a = new B;
    // B * c = new C;
    // delete c;
    //delete a;
    // cout << endl << "Testing shallow and deep copy" << endl;
    // // X a("Obj A");
    // // X b("Obj B");
    // X a("Obj A");
    // X b("Obj B");
    //a = b;
    TA a(10);
}


// class A{
//     public:
//         int i;
//         A(int x){
//             i = x;
//         }
//         virtual void f() const{
//             cout << i << endl;
//         }
// };
// class B:public A{
//     public:
//         B(int x):A(x){}
//         virtual void f() const{
//             cout << i*2 << endl;
//         }
// };
// void print(A a){
//     a.f();
// }
// void print(A * a){
//     a->f();
// }
// int main()
// {
//     A * a = new B(1);
//     print(*a);
//     print(a);
// }

// class A{
//     public:
//         virtual int f(int x ){
//             return x;
//         }
// };
// class B:public A{
//     public:
//         int f(int x ){
//             return x+1;
//         }
// };
// class C:public B{
//     public:
//         int f(int x ){
//             return x+2;
//         }
// };
// int main()
// {
//     C * c = new C;
//     cout << c->f(0) << endl;
//     cout << c->C::f(0) << endl;
//     cout << c->B::f(0) << endl;
//     cout << c->A::f(0) << endl;
//     delete c;
//     B * b = new C;
//     cout << b->f(10) << endl;
//     cout << b->B::f(10) << endl;
//     cout << b->A::f(10) << endl;
//     delete b;
//     A * a = new C;
//     cout << a->f(100) << endl;
//     cout << a->A::f(100) << endl;
//     delete a;

// }