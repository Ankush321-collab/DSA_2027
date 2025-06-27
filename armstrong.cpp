#include<iostream>
#include<cmath>
using namespace std;

bool isarm(int num){
    int copy = num;
    int ans = 0;
    int digit = 0;

    while(num != 0){
        digit = num % 10;
        ans += pow(digit, 3);
        num /= 10;
    }
    return ans == copy;
}

int main(){
    int n;
    cout << "Enter your number: ";
    cin >> n;

    if(isarm(n)){
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }
    return 0;
}