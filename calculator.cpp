#include<iostream>
#include<stack>
#include <unordered_map>
#define N 10010
using namespace std;
//优先级对照表
unordered_map<char, int> h{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };
stack<char> operStack;
stack<int> numStack;
void eval(void){
    int a = numStack.top();
    numStack.pop();

    int b = numStack.top();
    numStack.pop();

    char c = operStack.top();
    operStack.pop();

    int r = 0;
    if(c == '+') r = b + a;
    if(c == '-') r = b - a;
    if(c == '/') r = b / a;
    if(c == '*') r = b * a;

    numStack.push(r);
}
int main(){
    char c = ' ';
    int t = 0;
    while(scanf("%c", &c) != EOF && c != '\n'){
        if(c == ' ') continue;
        if(c <= 57 && c >= 48)
            t = t * 10 - '0' + c;
        else{
            if(t) numStack.push(t);
            t = 0;
            //括号特殊
            if(c == '(')
                operStack.push(c);
            else if(c == ')'){
                while(operStack.top() != '(')
                    eval();
                operStack.pop();
            }
            else{
                while(!operStack.empty() && h[operStack.top()] >= h[c])
                    eval();
                operStack.push(c);
            }
        }
    }
    if(t) numStack.push(t);
    while(!operStack.empty()) eval();
    cout << numStack.top() <<endl;
    return 0;
}