#include<bits/stdc++.h>

using namespace std;

map<char, set<char>> followMap;
map<char, vector<string>> productions;

bool isNonTerminal(char ch) {
    return 'A'<=ch and ch<='Z';
}

set<char> first(char ch) {
    if(isNonTerminal(ch)) {
        set<char> temp;
        for(auto production:productions[ch]) {
            for(auto x:first(production[0])) {
                temp.insert(x);
            }
        }
        return temp;
    } return {ch};
}

set<char> follow(char ch) {
    set<char> temp;
    if(productions.count(ch)) temp.insert('$');
    for(auto [j, p]:productions) {
        for(string s:p) {
            for(int i=0; i<s.size(); i++) {
                if(s[i]==ch) {
                    if(i!=s.size()-1) {
                        if(not isNonTerminal(s[i+1])) temp.insert(s[i+1]);
                        else {
                            for(char x:first(s[i+1])) {
                                temp.insert(x);
                            }
                        }
                    } else if(j!=ch) {
                        for(auto x:follow(j)) {
                            temp.insert(x);
                        }
                    }
                }
            }
        }
    }
    return temp;
}

int main() {
    int n;
    cout<<"Enter number of productions: ";
    cin>>n;
    for(int i=0; i<n; i++) {
        string temp;
        cin>>temp;
        productions[temp[0]].push_back(temp.substr(2));
    }
    for(auto production:productions) {
        followMap[production.first] = follow(production.first);
        cout<<production.first<<": {";
        for(auto it=followMap[production.first].begin(); it!=followMap[production.first].end(); it++) {
            cout<<*it;
            if(next(it)!=followMap[production.first].end()) cout<<", ";
        } 
        cout<<"}\n";
    }
}

// 8
// S=AB
// B=aAB
// B=b
// A=CD
// D=cCD
// D=b
// C=(E)
// C=d
