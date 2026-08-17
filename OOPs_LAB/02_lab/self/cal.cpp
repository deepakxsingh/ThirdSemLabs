#include<iostream>
using namespace std;
class Cal {
    private:
    int num1 , num2 , logic;
    public:
    void setValues(int a , int b , int c  ){
        num1 = a ;
        num2 = b ;
        logic = c;

    }
    void operation(){
        switch(logic){
        case 1:
        add();
        break;
        case 2:
        sub();
        break;
        case 3:
        multi();
        break;
        case 4:
        divide();
        break;
        default :
        cout<<"Invalid Input";
        break ;
    }
    }
    void add(){
        cout <<  "Ans:" << num1 + num2 ;
    }
    void sub(){
        if(num1>num2){
            cout <<  "Ans:" <<  num1 - num2 ;
        }
        else(cout <<  "Ans: -" << num2 - num1);
        
    }
    void multi(){
        cout <<  "Ans:" << num1 * num2 ;
    }
    void divide(){
        if ( num2 == 0 ){
            cout << " Cannot be Divide by zero " ;
        }
        else{
            cout <<  "Ans:" << num1 / num2 ;
        }
    }

};
int main(){
    int a , b , c ;

    cout << "Enter first Num : ";
    cin >> a ;

    cout << "Enter second Num : ";
    cin >> b ;

    cout << "Enter 1 for + " << endl ;
    cout << "Enter 2 for - " << endl ;
    cout << "Enter 3 for * " << endl ;
    cout << "Enter 4 for / " << endl ;
    cin >> c ;

    Cal C ;
    C.setValues(a,b,c);
    C.operation();
   

}