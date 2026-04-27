#include <iostream>
#include <vector>
using namespace std;

vector<int> radix0[1024];
vector<int> radix1[1024];

unsigned char vst[1048576 + 1];
int cnt[1048576 + 1];
long long vstCount = 1;

int na[4001];
int nb[4001];
int nc[4001];
int nd[4001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long i, j;

	long long n;
	cin >> n;
	for (long long ni = 0; ni < n; ni++) {
		cin >> na[ni] >> nb[ni] >> nc[ni] >> nd[ni];
	}

	for (int ni = 0; ni < n; ni++) {
		for (int nj = 0; nj < n; nj++) {
			int a = na[ni] + nb[nj];
            radix0[((a & 0b10000000000000000000000000000000) >> 22) | (a & 0b111111111)].push_back((a >> 9) & 0b11111111111111111111);
			int b = -nc[ni] - nd[nj];
            radix1[((b & 0b10000000000000000000000000000000) >> 22) | (b & 0b111111111)].push_back((b >> 9) & 0b11111111111111111111);
		}
	}

	long long total = 0;
	for (i = 0; i < 200; i++) {
		vstCount++;
		for (int a : radix0[i]) {
			if (vst[a] < vstCount) {
				vst[a] = vstCount;
				cnt[a] = 1;
			} else {
				cnt[a]++;
			}
		}
		for (int a : radix1[i]) {
			if (vst[a] == vstCount) {
				total += cnt[a];
			}
		}
	}
    for(i=0;i<1048576;i++){
        vst[i] = 0;
    }
    vstCount = 1;
    for (i = 200; i < 400; i++) {
		vstCount++;
		for (int a : radix0[i]) {
			if (vst[a] < vstCount) {
				vst[a] = vstCount;
				cnt[a] = 1;
			} else {
				cnt[a]++;
			}
		}
		for (int a : radix1[i]) {
			if (vst[a] == vstCount) {
				total += cnt[a];
			}
		}
	}
    for(i=0;i<1048576;i++){
        vst[i] = 0;
    }
    vstCount = 1;
    for (i = 400; i < 600; i++) {
		vstCount++;
		for (int a : radix0[i]) {
			if (vst[a] < vstCount) {
				vst[a] = vstCount;
				cnt[a] = 1;
			} else {
				cnt[a]++;
			}
		}
		for (int a : radix1[i]) {
			if (vst[a] == vstCount) {
				total += cnt[a];
			}
		}
	}
    
    for(i=0;i<1048576;i++){
        vst[i] = 0;
    }
    vstCount = 1;
    for (i = 600; i < 800; i++) {
		vstCount++;
		for (int a : radix0[i]) {
			if (vst[a] < vstCount) {
				vst[a] = vstCount;
				cnt[a] = 1;
			} else {
				cnt[a]++;
			}
		}
		for (int a : radix1[i]) {
			if (vst[a] == vstCount) {
				total += cnt[a];
			}
		}
	}
    
    for(i=0;i<1048576;i++){
        vst[i] = 0;
    }
    vstCount = 1;
    for (i = 800; i < 1024; i++) {
		vstCount++;
		for (int a : radix0[i]) {
			if (vst[a] < vstCount) {
				vst[a] = vstCount;
				cnt[a] = 1;
			} else {
				cnt[a]++;
			}
		}
		for (int a : radix1[i]) {
			if (vst[a] == vstCount) {
				total += cnt[a];
			}
		}
	}
    
	cout << total << '\n';

}