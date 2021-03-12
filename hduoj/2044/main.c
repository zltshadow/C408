#include<stdio.h>
long long a[50] = { 0 };
long long divide(int n) {
    if (n < 2) {
        return a[n] = 1;
    }
    if (a[n] > 0) {
        return a[n];
    }
    return a[n] = divide(n - 1) + divide(n - 2);
}

int main() {
    int n;
    int a, b;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", divide(b - a));
    }
    return 0;
}