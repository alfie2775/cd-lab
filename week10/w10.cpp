#include<bits/stdc++.h>

using namespace std;

map<string, char> productions;
vector<char> st;

bool reduce() {
    string temp = "";
    for(auto it=st.rbegin(); it!=st.rend(); it++) {
        temp = *it+temp;
        if(productions.count(temp)) {
            cout<<"REDUCE: "<<temp<<" - "<<productions[temp]<<endl;
            while(st.rbegin()!=it) {
                st.pop_back();
            }
            st.pop_back();
            st.push_back(productions[temp]);
            return true;
        }
    }
    return false;
}

void shift(char ch) {
    cout<<"SHIFT: "<<ch<<endl;
    st.push_back(ch);
}

int main() {
    int n;
    cout<<"Enter the number of productions: ";
    cin>>n;
    cout<<"Enter the productions\n";
    for(int i=0; i<n; i++) {
        string prod;
        cin>>prod;
        productions[prod.substr(2)] = prod[0];
    }
    string input;
    cout<<"Enter input string: ";
    cin>>input;
    for(char c:input) {
        shift(c);
        if(reduce())
            while(reduce()) {}
    }
    if(st.size()==1) cout<<"String is accpeted";
    else cout<<"String is not accepted";
}