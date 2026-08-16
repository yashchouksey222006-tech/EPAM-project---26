#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long B;

    cin >> N >> B;

    vector<long long> scholarship(N);

    for (int i = 0; i < N; i++) {
        cin >> scholarship[i];
    }

    // Sort scholarship requirements in increasing order
    sort(scholarship.begin(), scholarship.end());

    long long spent = 0;
    int count = 0;

    // Select students with the smallest requirements first
    for (int i = 0; i < N; i++) {
        if (spent + scholarship[i] <= B) {
            spent += scholarship[i];
            count++;
        } else {
            break;
        }
    }

    cout << count << endl;

    return 0;
}