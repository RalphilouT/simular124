#include <iostream>
#include "testinghiding.h"
using namespace std;
void hiding::function1(){
    cout << "function1()" << endl;
}
struct hiding::Internal{
    int id;
    Internal()
    {
        id =1;
    }
};

void hiding::init () { 
    intwin = new Internal; 
}
int hiding::run(){ 

}
// int main(int argc, char**arv)
// {

// }