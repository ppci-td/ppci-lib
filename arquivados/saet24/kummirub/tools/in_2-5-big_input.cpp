#include <bits/stdc++.h>

using namespace std;

int n = 10;

int main() {
    random_device rd;
    mt19937 rng(rd());

    printf("%d\n", n);

    vector<int> nums(n*n);
    iota(nums.begin(), nums.end(), 1);
    shuffle(nums.begin(), nums.end(), rng);

    for (int i = 0; i<n; ++i) {
        printf("%d", nums[i*n]);
        for (int j = 1; j<n; ++j) {
            printf(" %d", nums[i*n + j]);
        }
        printf("\n");
    }

    int t = 99999900 + rd()%100;
    printf("%d\n", t);

    vector<int> choices(n);
    iota(choices.begin(), choices.end(), 1);

    for (int i = 0; i<n; ++i) {
        shuffle(choices.begin(), choices.end(), rng);
        printf("%d", choices[0]);
        for (int j = 1; j<n; ++j) {
            printf(" %d", choices[j]);
        }
        printf("\n");
    }
}
