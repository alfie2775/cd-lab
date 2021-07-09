#include<iostream>
#include<set>

std::set<std::string> keywords{"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};

std::set<char> operators{'*', '/', '+', '-', '%'};

bool isOperator(char op) {
	return operators.find(op)!=operators.end();
}

bool isKeyword(std::string word) {
	return keywords.find(word)!=keywords.end();
}

bool isNotDelimiter(char ch) {
	return isalnum(ch);
}

int main() {
	FILE *fp = fopen("code.txt", "r");
	std::string temp = "";
	char ch;
	while((ch=fgetc(fp))!=EOF) {
		if(isOperator(ch)) {
			std::cout<<ch<<" is an operator\n";
		}
		if(isNotDelimiter(ch)) {
			temp += ch;
			continue;
		} else if(not temp.size()) {
			continue;
		}
		if(isKeyword(temp)) {
			std::cout<<temp<<" is a keyword\n";
		} else {
			std::cout<<temp<<" is a identifier\n";
		}
		temp = "";
	}
}