#include<bits/stdc++.h>

using namespace std;

int pres(char ch) {
    switch (ch)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}

int main() {
    string exp;
    cout<<"Enter the expression: ";
    cin>>exp;
    stack<char> st;
    string ans = "";
    for(char c:exp) {
        if(isalnum(c)) {
            ans += c;
        } else if(pres(c)) {
            while(!st.empty() and pres(c)<pres(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        } else {
            if(c=='(') {
                st.push(c);
            } else {
                while(st.top()!='(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
        }
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout<<"Postfix expression is: "<<ans;
}