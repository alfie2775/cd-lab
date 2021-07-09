#include<bits/stdc++.h>

using namespace std;

map<char, set<char>> firstMap;
map<char, vector<string>> productions;

bool isNonTerminal(char ch) {
    return 'A'<=ch and ch<='Z';
}

set<char> first(char ch) {
    if(isNonTerminal(ch)) {
        set<char> temp;
        for(auto production:productions[ch]) {
            for(char c:first(production[0])) {
                temp.insert(c);
            }
        }
        return temp;
    } return set<char>{ch};
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
    for(auto p:productions) {
        firstMap[p.first] = first(p.first);
    }
    for(auto p:firstMap) {
        cout<<p.first<<": { ";
        for(auto it=p.second.begin(); it!=p.second.end(); it++) {
            cout<<*it;
            if(next(it)!=p.second.end()) cout<<", ";
        }
        cout<<" }\n";
    }
}