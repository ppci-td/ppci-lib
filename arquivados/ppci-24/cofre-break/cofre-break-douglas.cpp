#include <bits/stdc++.h>

using namespace std;

long long s[1000000];
set<int> nums;

int main() {
    int n;

    scanf("%d", &n);
    if (n > 1000000) printf("n mt grande: %d\n", n);
    if (n < 1) printf("n mt pequeno: %d\n", n);

    for (int i = 0; i<n; ++i) {
        scanf("%lld", &s[i]);
        if (s[i] > 1000000000) printf("s[%d] mt grande: %lld\n", i, s[i]);
        if (s[i] < 0) printf("s[%d] menor que 0\n", i);
    }

    int l_ans = 0, r_ans = 0;

    for (int l = 0, r = 0; r<n;) {
        if (nums.count(s[r]) == 0)
            nums.insert(s[r++]);
        else
            nums.erase(nums.find(s[l++]));

        if (nums.size() > r_ans-l_ans)
            r_ans = r, l_ans = l;
    }

    if (r_ans - l_ans > 1) {
        reverse(s+l_ans, s+r_ans);
    }


    for(int i = 0; i<n; ++i)
        printf("%lld ", s[i]);

    printf("\n");

    return 0;
}
