#include <iostream>
#include <stack>

using namespace std;
 
struct Problem
{
    int n;
    char src, mid, dst;
    Problem(int nn, char s, char m, char d) : n(nn), src(s), mid(m), dst(d) {}
};
 
int main()
{
    int n;
    cin >> n;
    stack<Problem> stk;
    stk.push(Problem(n, 'A', 'B', 'C'));
    while (!stk.empty()) {
        Problem curPrb = stk.top();
        stk.pop();
        if (curPrb.n == 1)
            cout << curPrb.src << "->" << curPrb.dst << endl;
        else {
            stk.push(Problem(curPrb.n-1, curPrb.mid, curPrb.src, curPrb.dst));
            //cout << curPrb.src << "->" << curPrb.dst << endl;
            stk.push(Problem(curPrb.1, curPrb.src, curPrb.mid, curPrb.dst));
            stk.push(Problem(curPrb.n-1, curPrb.src, curPrb.dst, curPrb.mid));
        }
    }
}