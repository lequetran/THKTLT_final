#include <stdio.h>

// Cách 1: Đệ quy

// Tính S(n) = 1 + 2 + 3 + ... + n
int tongdequy(int n) {
    if (n == 1)
        return 1;
    return n + tongdequy(n - 1);
}

// Tính S(n) = 1/2 + 2/3 + 3/4 + ... + n/(n+1)
double dayphansodequy(int n) {
    if (n == 1)
        return 1.0 / 2.0;
    return ((double)n / (n + 1)) + dayphansodequy(n - 1);
}

// Tính S(n) = 1 + (1 + 2 + 3 + ... + n) + (1 + 2 + 3 + ... + n) + ... + n
int tongphucdequy(int n) {
    if (n == 1)
        return 1;
    return tongdequy(n) + tongphucdequy(n - 1);
}

// Hàm tính giai thừa
int giaithua(int n) {
    if (n == 0)
        return 1;
    return n * giaithua(n - 1);
}

// Tính S(n) = 1/2! + 2/3! + 3/4! + ... + n/(n+1)!
double daygiaithuadequy(int n) {
    if (n == 1)
        return 1.0 / 2.0;
    return (double)n / giaithua(n + 1) + daygiaithuadequy(n - 1);
}

// Cách 2: Khử đệ quy

// Tính S(n) = 1 + 2 + 3 + ... + n
int tongkhudequy(int n) {
    return n * (n + 1) / 2;
}

// Tính S(n) = 1/2 + 2/3 + 3/4 + ... + n/(n+1)
double dayphansokhudequy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (double)i / (i + 1);
    }
    return sum;
}

// Tính S(n) = 1 + (1 + 2 + 3 + ... + n) + (1 + 2 + 3 + ... + n) + ... + n
int tongphuckhudequy(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += tongkhudequy(i);
    }
    return sum;
}

// Tính S(n) = 1/2! + 2/3! + 3/4! + ... + n/(n+1)!
double daygiaithuakhudequy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (double)i / giaithua(i + 1);
    }
    return sum;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    printf("Cach 1: De quy\n");
    printf("S(n) = 1 + 2 + 3 + ... + n: %d\n", tongdequy(n));
    printf("S(n) = 1/2 + 2/3 + 3/4 + ... + n/(n+1): %.5lf\n", dayphansodequy(n));
    printf("S(n) = 1 + (1 + 2 + 3 + ... + n) + ... + n: %d\n", tongphucdequy(n));
    printf("S(n) = 1/2! + 2/3! + 3/4! + ... + n/(n+1)!: %.5lf\n", daygiaithuadequy(n));

    printf("\nCach 2: Khu de quy\n");
    printf("S(n) = 1 + 2 + 3 + ... + n: %d\n", tongkhudequy(n));
    printf("S(n) = 1/2 + 2/3 + 3/4 + ... + n/(n+1): %.5lf\n", dayphansokhudequy(n));
    printf("S(n) = 1 + (1 + 2 + 3 + ... + n) + ... + n: %d\n", tongphuckhudequy(n));
    printf("S(n) = 1/2! + 2/3! + 3/4! + ... + n/(n+1)!: %.5lf\n", daygiaithuakhudequy(n));

    printf("Nhan enter de thoat chuong trinh");
    getchar();
    getchar();

    return 0;
}
