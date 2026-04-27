#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> cnt(10);
    auto tot = [&]() {
        int res = 0;
        for(int i=1; i<=9; i++) {
            if(cnt[i]) res++;
        }
        return res;
    };
    int ans = 0;
    for(int i=0, j=0; i<N; i++) {
        while(j < N && !(tot() == 2 && cnt[A[j]] == 0)) {
            cnt[A[j]]++;
            j++;
        }
        ans = max(ans, j - i);
        cnt[A[i]]--;
    }
    cout << ans << endl;
}