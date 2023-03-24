#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();
    int left = -1, right = 0, maxDist = 0;

    for (int i = 0; i < n; i++) {
        if (seats[i] == 1) {
            if (left == -1) {
                maxDist = i;
            }
            else {
                maxDist = max(maxDist, (i - left) / 2);
            }
            left = i;
        }
        else {
            right++;
        }
    }

    maxDist = max(maxDist, n - 1 - left);
    return maxDist;
}

int main() {
    int n;
    cin >> n;
    vector<int> seats(n);
    for (int i = 0; i < n; i++) {
        cin >> seats[i];
    }

    int maxDist = maxDistToClosest(seats);
    cout << maxDist << endl;

    return 0;
}
