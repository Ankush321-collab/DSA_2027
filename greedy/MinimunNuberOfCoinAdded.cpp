#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, int> minimum(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());

    vector<int> ans;
    int count = 0;

    for (int coin : coins) {
        while (amount >= coin) { // Use as many of this coin as possible
            ans.push_back(coin);
            amount -= coin;
            count++;
        }
    }

    if (amount == 0)
        return {ans, count};
    else
        return {{}, -1}; // return empty vector and -1 if not possible
}

int main() {
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter the amount to be made: ";
    cin >> amount;

    auto result = minimum(coins, amount);
    vector<int> usedCoins = result.first;
    int minCoins = result.second;

    if (minCoins == -1) {
        cout << "It is not possible to make the amount with the given coins.\n";
    } else {
        cout << "Minimum number of coins: " << minCoins << "\n";
        cout << "Coins used: ";
        for (int coin : usedCoins) {
            cout << coin << " ";
        }
        cout << endl;
    }

    return 0;
}
