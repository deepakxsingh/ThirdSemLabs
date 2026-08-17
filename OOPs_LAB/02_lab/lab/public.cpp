
class Number {
    public:
    int num1 , num2;
    void getInput(){
        cout<<"Enter first no. s ";
        cin>>num1;
        cout<<"Enter Second no. s ";
        cin>>num2;

    }
    void show(){
        cout<<"Number is ",num1;
        cout<<"second num is " ,num2;
    }
}
int main(){
    Number N ;
    N.getInput();
    N.show();
    
}