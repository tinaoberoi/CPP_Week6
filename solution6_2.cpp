#include <iostream>
#include <memory>
using namespace std;

class A {
    private:
        int member1 { 0 };
        double member2 { 1.2 };
    public:
        A (int m1 = 0, double m2 = 1.2): member1{m1}, member2{m2} {}
        friend ostream& operator<<(ostream& out, A a1){
            out << a1.member1 << " and "<<a1.member2<<endl;
            return out;
        }
};

struct B {
    int i;
    double j;
    void foo(double);
    void bar(double);
};

int func(float a, int b){
    return a+b;
}

int main(){
    int i = 5;
    int *ip = &i;
    cout<<"Before changing int ref: "<<i<<endl;
    int &ir = i;
    // Assign new value to x using ref
    ir = 20;
    cout<<"After changing int ref: "<<i<<endl;

    double d = 1.2;

    A a(1, 2.6);
    A *pObj = &a;
    cout << "Membes of class A is: " << *pObj << endl;

    char const* constVal = "Char value cannot be changed";
    char const &constRef = *constVal;

    // Array of triplets
    int arr[][3] = {1, 2, 3, 4, 5, 6, 7};
    cout<<"No of triplets in arr"<<endl;
    cout << "sizeof(ar) / sizeof(int[3]) : "<< sizeof(arr) / sizeof(int[3]) << endl;

    int **ipp = &ip;
    int *&ipr = ip;

    float fval = 1.2;
    cout<<"Before changing float ref: "<<fval<<endl;
    float &fref = fval;
    //Chnage fval
    fref = 3.6;
    cout<<"After changing float ref: "<<fval<<endl;

    int (*pt2func)(float, int) = NULL;
    pt2func = &func;
    cout<<"Printing result of func \n";
    cout<<(*pt2func)(1.2, 3)<<endl;

    int B::*bip = &B::i;
    
    return 0;
}