#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n,a[100005];
int minv = ~(-(1<<31)), ms, me;
int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<n; i++) {
        int *pt = lower_bound(a,a+n,-a[i]);
        if(pt != a + i && pt != a + n && minv > abs(*pt + a[i])){
            minv = abs(*pt + a[i]);
            ms = *pt;
            me = a[i];
        }
        pt--;
        if(pt != a + i && pt >= a && minv > abs(*pt + a[i])){
            minv = abs(*pt + a[i]);
            ms = *pt;
            me = a[i];
        }
        if(pt == a + i){
            pt--;
            if(pt != a + i && pt >= a && minv > abs(*pt + a[i])){
                minv = abs(*pt + a[i]);
                ms = *pt;
                me = a[i];
            }
        }
        else if(++pt == a + i){
            pt++;
            if(pt != a + i && pt != a + n && minv > abs(*pt + a[i])){
                minv = abs(*pt + a[i]);
                ms = *pt;
                me = a[i];
            }
        }
    }
    if(ms > me) swap(ms,me);
    printf("%d %d",ms,me);
}