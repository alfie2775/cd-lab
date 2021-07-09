#include<bits/stdc++.h>

using namespace std;

int main() {
    int choice;
    cout<<"Enter\n";
    cout<<"1 for assignment expression\n";
    cout<<"2 for arithmetic expression\n";
    cout<<"3 for relational expression\n";
    cout<<"4 for Exit\n";
    while(1) {
        cout<<"Enter your choice\n";
        cin>>choice;
        if(choice==4) break;
        string exp;
        cout<<"Enter expression\n";
        cin>>exp;
        switch (choice) {
            case 1: {
                cout<<"temp="<<exp[2]<<endl;
                cout<<exp[0]<<"=temp\n";
                break;
            }
            case 2: {
                bool flag = false;
                if(exp[1]=='+' or exp[1]=='-') {
                    if(!(exp[3]=='*' and exp[3]=='/')) flag = true;
                }
                if(flag) {
                    cout<<"temp="<<exp.substr(2)<<endl;
                    cout<<"temp1="<<exp.substr(0, 2)<<"temp\n";
                } else {
                    cout<<"temp="<<exp.substr(0, 3)<<endl;
                    cout<<"temp1=temp"<<exp.substr(3)<<endl;
                }
                break;
            }
            case 3: {
                int addr = 100;
                cout<<addr<<" if"<<exp<<" then goto "<<addr+3<<endl;
                cout<<++addr<<" T:=0"<<endl;
                cout<<++addr<<" goto "<<addr+2<<endl;
                cout<<++addr<<" T:=1"<<endl;
            }

            default:
                break;
        }
    }
}