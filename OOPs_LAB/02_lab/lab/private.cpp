#include<iostream>

using namespace std;

class Number {
   private:
   int num1 , num2;
   public:
  void getInput(int a , int b ) {
    num1 = a ;
    num2 = b ;
   }
   void show(){
      cout<<"First num is "<< num1 << endl;
      cout<<"Second num is "<< num2 << endl;
   }

  
  
};
int main() {
     int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    Number N ;

    N.getInput(a,b);
    N.show();
   
   return 0;
}