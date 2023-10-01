#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool validBrackets(string s) {
		int i=-1;
		for(auto& ch:s){
			if(ch=='(' || ch=='{' || ch=='[')
				s[++i]=ch;
			else{
				if(i>=0 && ((s[i]=='(' && ch==')') || (s[i]=='{' && ch=='}') || (s[i]=='[' && ch==']')))
					i--;
				else
					return false;
			}
		}
		return i==-1;
	}

int main()
{
	string expr = "{()}[]";


	if (validBrackets(expr))
		cout << "Brackets are Balanced";
	else
		cout << "Brackets are Not Balanced";
	return 0;
}
