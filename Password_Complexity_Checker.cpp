#include<iostream>
#include<string>
using namespace std;

void Password_Complexity_Checker(string input){
    int n = input.length();
    bool hasLower = false;
    bool hasUpper = false;
    bool hasNumber = false;
    bool specialCharacter = false;
    string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    for (size_t i = 0; i < n; i++)
    {
        if (islower(input[i]))
            hasLower = true;
        if(isupper(input[i]))
            hasUpper = true;
        if(isdigit(input[i]))
            hasNumber = true;
        size_t special = input.find_first_not_of(normalChars);
        if(special != string::npos)
            specialCharacter = true;
    }
    cout<<"Strength of Password : ";
    if(hasLower && hasUpper && hasNumber && specialCharacter && (n>= 8))
        cout<<"Strong"<<endl;
    else if((hasLower || hasUpper) && (specialCharacter && (n >= 6))){
        cout<<"Moderate"<<endl;
        if(hasLower && !hasUpper)
            cout<<"Add atleast one Uppercase Letter"<<endl;
        if(!hasLower && hasUpper)
            cout<<"Add atleast one Lowercase Letter"<<endl;
    }
    else{
        cout<<"Weak"<<endl;
        cout<<"Add atleast one Uppercase Letter"<<endl;
        cout<<"Add atleast one Lowercase Letter"<<endl;
        cout<<"Add at least one special character. The special characters are: !@#$%^&*()-+"<<endl;
        cout<<"Its length is at least 8."<<endl;
        cout<<"It contains at least one digit."<<endl;
    }
    
}

int main(){
    string password;
    cout<<"Enter your Password : ";
    cin>>password;
    Password_Complexity_Checker(password);
    return 0;
}