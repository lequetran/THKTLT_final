#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Bai 1: Ham kiem tra chuoi co chua toan ky so hay khong
int kiemTraChuoiKySo(char* s) {
    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

// Bai 2: Ham doi ky tu dau tien cua moi tu thanh chu in hoa va cac ky tu con lai thanh chu thuong
void doiKyTuDauThanhInHoa(char* s) {
    int capitalize = 1;
    while (*s) {
        if (isspace(*s)) {
            capitalize = 1;
        }
        else if (capitalize && isalpha(*s)) {
            *s = toupper(*s);
            capitalize = 0;
        }
        else {
            *s = tolower(*s);
        }
        s++;
    }
}

// Bai 3: Ham xoa khoang trang thua trong chuoi
void xoaKhoangTrangThua(char* s) {
    char* d = s;
    int space = 0;
    while (*s) {
        if (!isspace(*s)) {
            if (space) {
                *d++ = ' ';
                space = 0;
            }
            *d++ = *s;
        }
        else {
            space = 1;
        }
        s++;
    }
    *d = '\0';
}

// Bai 4: Ham tim kiem ten trong chuoi ho ten
void timKiemTenTrongHoTen(char* fullName, char* name) {
    char* found = strstr(fullName, name);
    if (found) {
        printf("Ten '%s' ton tai trong chuoi ho ten '%s'.\n", name, fullName);
    }
    else {
        printf("Ten '%s' khong ton tai trong chuoi ho ten.\n", name);
    }
}

// Bai 5: Ham cat chuoi ho ten thanh ho lot va ten
void catChuoiHoTen(char* fullName, char* firstName, size_t firstNameSize, char* lastName, size_t lastNameSize) {
    char* lastSpace = strrchr(fullName, ' ');
    if (lastSpace) {
        strncpy_s(firstName, firstNameSize, fullName, lastSpace - fullName);
        firstName[lastSpace - fullName] = '\0';
        strncpy_s(lastName, lastNameSize, lastSpace + 1, _TRUNCATE);
    }
    else {
        strncpy_s(firstName, firstNameSize, "", _TRUNCATE);
        strncpy_s(lastName, lastNameSize, fullName, _TRUNCATE);
    }
}

// Bai 6: Nhap vao danh sach sinh vien va tim kiem chuoi trong T
void nhapDanhSachVaTimKiem() {
    char T[100], P[50];
    printf("Nhap chuoi T: ");
    fgets(T, sizeof(T), stdin);
    T[strcspn(T, "\n")] = '\0';
    printf("Nhap chuoi P: ");
    fgets(P, sizeof(P), stdin);
    P[strcspn(P, "\n")] = '\0';

    char* found = strstr(T, P);
    if (found) {
        printf("Chuoi P tim thay tai vi tri: %ld\n", found - T);
    }
    else {
        printf("Chuoi P khong ton tai trong T.\n");
    }
}

// Ham dung man hinh
void dungManHinh() {
    printf("Nhan phim bat ky de tiep tuc...");
    getchar();
}

// Ham hien thi menu
void hienThiMenu() {
    printf("Menu:\n");
    printf("1. Kiem tra chuoi co chua toan ky so\n");
    printf("2. Doi ky tu dau tien cua moi tu thanh chu in hoa\n");
    printf("3. Xoa khoang trang thua trong chuoi\n");
    printf("4. Tim kiem ten trong chuoi ho ten\n");
    printf("5. Cat chuoi ho ten thanh ho lot va ten\n");
    printf("6. Nhap danh sach sinh vien va tim kiem chuoi\n");
    printf("0. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    int choice;
    char str[100], str2[50], firstName[50], lastName[50];
    do {
        hienThiMenu();
        scanf_s("%d", &choice);
        getchar(); // Doc ky tu '\n' con lai tu bo dem

        switch (choice) {
        case 1:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            if (kiemTraChuoiKySo(str)) {
                printf("Chuoi chua toan ky so.\n");
            }
            else {
                printf("Chuoi khong chua toan ky so.\n");
            }
            dungManHinh();
            break;

        case 2:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            doiKyTuDauThanhInHoa(str);
            printf("Chuoi sau khi doi: %s\n", str);
            dungManHinh();
            break;

        case 3:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            xoaKhoangTrangThua(str);
            printf("Chuoi sau khi xoa khoang trang thua: %s\n", str);
            dungManHinh();
            break;

        case 4:
            printf("Nhap ho ten: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("Nhap ten can tim: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            timKiemTenTrongHoTen(str, str2);
            dungManHinh();
            break;

        case 5:
            printf("Nhap ho ten: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            catChuoiHoTen(str, firstName, sizeof(firstName), lastName, sizeof(lastName));
            printf("Ho lot: %s\n", firstName);
            printf("Ten: %s\n", lastName);
            dungManHinh();
            break;

        case 6:
            nhapDanhSachVaTimKiem();
            dungManHinh();
            break;

        case 0:
            printf("Thoat chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le.\n");
            dungManHinh();
            break;
        }
    } while (choice != 0);

    return 0;
}
