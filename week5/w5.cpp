#include<bits/stdc++.h>

using namespace std;

string input;
int i, error;

void E();
void T();
void F();
void Eds();
void Tds();

void E() {
    T();
    Eds();
}

void T() {
    F();
    Tds();
}

void Eds() {
    if(input[i]=='+') {
        i++;
        E();
    }
}

void Tds() {
    if(input[i]=='*') {
        i++;
        T();
    }
}

void F() {
    if(input[i]=='a') {
        i++;
        if(input[i]=='(') {
            i++;
            E();
            if(input[i]==')') {
                i++;
            } else {
                error = 1;
            }
        }
    } else {
        error = 1;
    }
}

int main() {
    cout<<"The grammar is\nE->TE'\nE'->+TE'/^\nT->FT'\nT'-*FT'/^\nF->(E)/id";
    cout<<"\nEnter the string: ";
    cin>>input;
    E();
    if(input.size()==i and error!=1) cout<<"String is accepted";
    else cout<<"String is not accepted";
}