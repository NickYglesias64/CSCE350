//Nicholas Yglesias
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int steps = 0;
void PrintVectors(vector<string> a, vector<string> b, vector<string> c) {
        cout << " 0:";
        for(int i = 0; i < (int)a.size(); i++) {
            cout << a.at(i);
        }
        cout << endl <<" 1:";
        for(int i = 0; i < (int)b.size(); i++) {
            cout << b.at(i);
        }
        cout << endl << " 2:";
        for(int i = 0; i < (int)c.size(); i++) {
            cout << c.at(i);
     }   
}
void MoveADisk(vector<string> &from, vector<string> &to, int pegFrom, int pegTo){
    steps++;
    cout << endl << "Step: " << steps << ": Move disk "<< from.back() << " from peg " << pegFrom << " to peg " << pegTo << "." << endl;
    to.push_back(from.back());
    from.pop_back();
}

void MoveStackOfPairs(int n, vector<string> &a, vector<string> &b, vector<string> &c) {
    if(n < 2) {
        //Move a disk from a to c
        PrintVectors(a,b,c);
        MoveADisk(a,c,0,2);
        //Move a disk from a to b
        PrintVectors(a,b,c);
        MoveADisk(a,b,0,1);
        //Move a disk form c to b
        PrintVectors(a,b,c);
        MoveADisk(c,b,2,1);
    }
    else {
        MoveStackOfPairs(n-1,a,b,c);
        //Move a disk from a to c
        PrintVectors(a,b,c);
        MoveADisk(a,c,0,2);
        //Move another disk from a to c
        PrintVectors(a,b,c);
        MoveADisk(a,c,0,2);
        MoveStackOfPairs(n-1,b,a,c);
        //Move a disk from c to b
        PrintVectors(a,b,c);
        MoveADisk(c,b,2,1);
        //Move another disk from c to b
        PrintVectors(a,b,c);
        MoveADisk(c,b,2,1);
        MoveStackOfPairs(n-1,a,b,c);
    }

}

void SolveHuger(int n, vector<string> &a, vector<string> &b, vector<string> &c) {
    if(n < 2) {
        //Move a disk from a to c
        PrintVectors(a,b,c);
        MoveADisk(a,c,0,2);
        //Move a disk from a to b
        PrintVectors(a,b,c);
        MoveADisk(a,b,0,1);
        PrintVectors(a,b,c);
    }
    else {
        MoveStackOfPairs(n-1,a,b,c);
        //Move a disk from a to c
        PrintVectors(a,b,c);
        MoveADisk(a,c,0,2);
        //Move another disk from a to c
        PrintVectors(a,b,c);
        MoveADisk(a,c,0,2);
        MoveStackOfPairs(n-1,b,a,c);
        //Move disk from c to b
        PrintVectors(a,b,c);
        MoveADisk(c,b,2,1);
        SolveHuger(n-1,a,b,c);
    }
}
int main() {
    while(cin.good()) {
        string input; string inputs = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        vector<string> a; vector<string> b; vector<string> c;
        int n=0; steps=0;
        cout << "Enter the number of disk pairs: " << endl;
        cin >> n;
        for(int i=0;i<n;i++) {
            input = inputs.at(i);
            a.push_back(input);
            input = to_string(i+1);
            a.push_back(input);
        }
        cout << "Starting at" << endl;
        SolveHuger(n,a,b,c);
        cout << endl << "Done!" << endl;
    }
}



