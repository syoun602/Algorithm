#include <iostream>

using namespace std;

int N, ans = 0;

void recursive(int N, int cnt) {
    if(ans != 0 && cnt > ans)
        return;

    if(N == 1) {
        if(ans == 0 || ans > cnt)
            ans = cnt;
    }
    else {
        if(N % 3 == 0)
            recursive(N/3, cnt+1);
        if(N % 2 == 0)
            recursive(N/2, cnt+1);
        recursive(N-1, cnt+1);
    }
}
int main(void) {

    cin >> N;
    recursive(N, 0);
    cout << ans << endl;
    
    return 0;
}