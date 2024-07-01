#include "Header.h"

#define MAX_SANPHAM 100
#define MAX_HOADON 100

SanPham danhSachSanPham[MAX_SANPHAM];
HoaDon danhSachHoaDon[MAX_HOADON];
int soLuongSanPham = 0;
int soLuongHoaDon = 0;

// Hien thi menu
void Menu() {
    printf_s("1. Quan ly mat hang\n");
    printf_s("2. Quan ly hoa don\n");
    printf_s("3. Thoat\n");
}

void MenuQLMH() {
    printf_s("1. In danh sach san pham\n");
    printf_s("2. Them san pham\n");
    printf_s("3. Sua san pham\n");
    printf_s("4. Xoa san pham\n");
    printf_s("5. Tim kiem san pham theo ma\n");
    printf_s("6. Tim kiem san pham theo ten\n");
    printf_s("7. Tim kiem san pham tren khoang gia ban\n");
    printf_s("8. Sap xep san pham theo gia\n");
    printf_s("0. Thoat\n");
}

void MenuQLHD() {
    printf_s("1. Them hoa don\n");
    printf_s("2. Sua hoa don\n");
    printf_s("3. Xoa hoa don\n");
    printf_s("4. Xuat hoa don\n");
    printf_s("5. Tim kiem hoa don theo ngay\n");
    printf_s("6. In danh sach hoa don\n");
    printf_s("0. Thoat\n");
}

void MenuThongKe() {
    printf_s("1. Thong ke san pham\n");
    printf_s("2. Thong ke hoa don\n");
    printf_s("0. Thoat\n");
}

void MenuSua() {
    printf_s("1. Sua ma san pham\n");
    printf_s("2. Sua ten san pham\n");
    printf_s("3. Sua so luong\n");
    printf_s("4. Sua gia nhap\n");
    printf_s("5. Sua gia ban\n");
    printf_s("6. Sua size\n");
    printf_s("7. Sua mau sac\n");
    printf_s("0. Thoat\n");
}

void MenuSuaHD() {
    printf_s("1. Sua ngay hoa don\n");
    printf_s("2. Sua so luong san pham\n");
    printf_s("3. Sua tong gia tri hoa don\n");
    printf_s("0. Thoat\n");
}

// San pham
void ThemSanPham() {
    if (soLuongSanPham >= MAX_SANPHAM) {
        printf_s("Danh sach san pham da day.\n");
        return;
    }
    SanPham sp;
    printf_s("Nhap ma san pham: ");
    scanf_s("%s", sp.maSP);
    printf_s("Nhap ten san pham: ");
    scanf_s("%s", sp.tenSP);
    printf_s("Nhap mau sac: ");
    scanf_s("%s", sp.mauSac);
    printf_s("Nhap so luong con: ");
    scanf_s("%d", &sp.soluongCon);
    printf_s("Nhap gia nhap: ");
    scanf_s("%lf", &sp.giaNhap);
    printf_s("Nhap gia ban: ");
    scanf_s("%lf", &sp.giaBan);
    printf_s("Nhap size: ");
    scanf_s("%s", sp.size);
    danhSachSanPham[soLuongSanPham++] = sp;
}

void InListSp(SanPham ds[], int soLuong) {
    for (int i = 0; i < soLuong; i++) {
        printf_s("Ma: %s, Ten: %s, Mau sac: %s, So luong: %d, Gia nhap: %.2f, Gia ban: %.2f, Size: %s\n",
               ds[i].maSP, ds[i].tenSP, ds[i].mauSac, ds[i].soluongCon, ds[i].giaNhap, ds[i].giaBan, ds[i].size);
    }
}

void InListSp1() {
    InListSp(danhSachSanPham, soLuongSanPham);
}

char* canGiua1(const char* str, int width, char* buffer) {
    int len = strlen(str);
    int padding = (width - len) / 2;
    printf_s(buffer, "%*s%s%*s", padding, "", str, padding, "");
    return buffer;
}

char* canGiua2(double value, int width, char* buffer) {
    char str[50];
    sprintf_s(str, "%.2f", value);
    return canGiua1(str, width, buffer);
}

int find_vitri_maSP(const char* maSP) {
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(danhSachSanPham[i].maSP, maSP) == 0) {
            return i;
        }
    }
    return -1;
}

void SuaTenSanPham() {
    char maSP[50];
    printf_s("Nhap ma san pham can sua: ");
    scanf_s("%s", maSP);
    int viTri = find_vitri_maSP(maSP);
    if (viTri == -1) {
        printf_s("Khong tim thay san pham.\n");
        return;
    }
    printf_s("Nhap ten san pham moi: ");
    scanf_s("%s", danhSachSanPham[viTri].tenSP);
}

void SuaMaSanPham() {
    char maSP[50];
    printf_s("Nhap ma san pham can sua: ");
    scanf_s("%s", maSP);
    int viTri = find_vitri_maSP(maSP);
    if (viTri == -1) {
        printf_s("Khong tim thay san pham.\n");
        return;
    }
    printf_s("Nhap ma san pham moi: ");
    scanf_s("%s", danhSachSanPham[viTri].maSP);
}

void SuaSoLuong() {
    char maSP[50];
    printf_s("Nhap ma san pham can sua: ");
    scanf_s("%s", maSP);
    int viTri = find_vitri_maSP(maSP);
    if (viTri == -1) {
        printf_s("Khong tim thay san pham.\n");
        return;
    }
    printf_s("Nhap so luong moi: ");
    scanf_s("%d", &danhSachSanPham[viTri].soluongCon);
}

void SuaGiaNhap() {
    char maSP[50];
    printf_s("Nhap ma san pham can sua: ");
    scanf_s("%s", maSP);
    int viTri = find_vitri_maSP(maSP);
    if (viTri == -1) {
        printf_s("Khong tim thay san pham.\n");
        return;
    }
    printf_s("Nhap gia nhap moi: ");
    scanf_s("%lf", &danhSachSanPham[viTri].giaNhap);
}

void SuaGiaBan() {
    char maSP[50];
    printf_s("Nhap ma san pham can sua: ");
    scanf_s("%s", maSP);
    int viTri = find_vitri_maSP(maSP);
    if (viTri == -1) {
        printf_s("Khong tim thay san pham.\n");
        return;
    }
    printf_s("Nhap gia ban moi: ");
    scanf_s("%lf", &danhSachSanPham[viTri].giaBan);
}

void SuaSize() {
    char maSP[50];
    printf_s("Nhap ma san pham can sua: ");
    scanf_s("%s", maSP);
    int viTri = find_vitri_maSP(maSP);
    if (viTri == -1) {
        printf_s("Khong tim thay san pham.\n");
        return;
    }
    printf_s("Nhap size moi: ");
    scanf_s("%s", danhSachSanPham[viTri].size);
}

void SuaMauSac() {
    char maSP[50];
    printf_s("Nhap ma san pham can sua: ");
    scanf_s("%s", maSP);
    int viTri = find_vitri_maSP(maSP);
    if (viTri == -1) {
        printf_s("Khong tim thay san pham.\n");
        return;
    }
    printf_s("Nhap mau sac moi: ");
    scanf_s("%s", danhSachSanPham[viTri].mauSac);
}

void XoaSanPham() {
    char maSP[50];
    printf_s("Nhap ma san pham can xoa: ");
    scanf_s("%s", maSP);
    int viTri = find_vitri_maSP(maSP);
    if (viTri == -1) {
        printf_s("Khong tim thay san pham.\n");
        return;
    }
    for (int i = viTri; i < soLuongSanPham - 1; i++) {
        danhSachSanPham[i] = danhSachSanPham[i + 1];
    }
    soLuongSanPham--;
}

void TimKiemTheoMa() {
    char maSP[50];
    printf_s("Nhap ma san pham can tim: ");
    scanf_s("%s", maSP);
    int viTri = find_vitri_maSP(maSP);
    if (viTri == -1) {
        printf_s("Khong tim thay san pham.\n");
        return;
    }
    InSP(danhSachSanPham[viTri]);
}

void InSP(SanPham sp) {
    printf_s("Ma: %s, Ten: %s, Mau sac: %s, So luong: %d, Gia nhap: %.2f, Gia ban: %.2f, Size: %s\n",
           sp.maSP, sp.tenSP, sp.mauSac, sp.soluongCon, sp.giaNhap, sp.giaBan, sp.size);
}

void TimKiemTheoTen() {
    char tenSP[100];
    printf_s("Nhap ten san pham can tim: ");
    scanf_s("%s", tenSP);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strstr(danhSachSanPham[i].tenSP, tenSP)) {
            InSP(danhSachSanPham[i]);
        }
    }
}

int KiemtraChuoicon(const char* subStr, const char* str) {
    return strstr(str, subStr) != NULL;
}

void TimKiemTrenKhoangGiaBan() {
    double giaMin, giaMax;
    printf_s("Nhap gia ban thap nhat: ");
    scanf_s("%lf", &giaMin);
    printf_s("Nhap gia ban cao nhat: ");
    scanf_s("%lf", &giaMax);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (danhSachSanPham[i].giaBan >= giaMin && danhSachSanPham[i].giaBan <= giaMax) {
            InSP(danhSachSanPham[i]);
        }
    }
}

void SapXepGiaTangDan() {
    for (int i = 0; i < soLuongSanPham - 1; i++) {
        for (int j = i + 1; j < soLuongSanPham; j++) {
            if (danhSachSanPham[i].giaBan > danhSachSanPham[j].giaBan) {
                swapSp(&danhSachSanPham[i], &danhSachSanPham[j]);
            }
        }
    }
    InListSp1();
}

void SapXepGiaGiamDan() {
    for (int i = 0; i < soLuongSanPham - 1; i++) {
        for (int j = i + 1; j < soLuongSanPham; j++) {
            if (danhSachSanPham[i].giaBan < danhSachSanPham[j].giaBan) {
                swapSp(&danhSachSanPham[i], &danhSachSanPham[j]);
            }
        }
    }
    InListSp1();
}

void MenuSapXepGia() {
    printf_s("1. Sap xep gia tang dan\n");
    printf_s("2. Sap xep gia giam dan\n");
}

void swapSp(SanPham* a, SanPham* b) {
    SanPham temp = *a;
    *a = *b;
    *b = temp;
}

// Hoa Don
void inHoaDon(HoaDon HD) {
    printf_s("Ma HD: %s, Ngay: %02d/%02d/%04d, So luong SP: %d, Tong gia tri: %.2f\n",
           HD.maHD, HD.ngaynhapDon.ngay, HD.ngaynhapDon.thang, HD.ngaynhapDon.nam,
           HD.soLuongSanPham, HD.tongGiaTriHD);
}

void themHoaDon() {
    if (soLuongHoaDon >= MAX_HOADON) {
        printf_s("Danh sach hoa don da day.\n");
        return;
    }
    HoaDon hd;
    printf_s("Nhap ma hoa don: ");
    scanf_s("%s", hd.maHD);
    printf_s("Nhap ngay (dd mm yyyy): ");
    scanf_s("%d %d %d", &hd.ngaynhapDon.ngay, &hd.ngaynhapDon.thang, &hd.ngaynhapDon.nam);
    printf_s("Nhap so luong san pham: ");
    scanf_s("%d", &hd.soLuongSanPham);
    printf_s("Nhap tong gia tri hoa don: ");
    scanf_s("%lf", &hd.tongGiaTriHD);
    danhSachHoaDon[soLuongHoaDon++] = hd;
}

int findHoaDon(const char* maHD) {
    for (int i = 0; i < soLuongHoaDon; i++) {
        if (strcmp(danhSachHoaDon[i].maHD, maHD) == 0) {
            return i;
        }
    }
    return -1;
}

void suaNgayHoaDon() {
    char maHD[50];
    printf_s("Nhap ma hoa don can sua: ");
    scanf_s("%s", maHD);
    int viTri = findHoaDon(maHD);
    if (viTri == -1) {
        printf_s("Khong tim thay hoa don.\n");
        return;
    }
    printf_s("Nhap ngay moi (dd mm yyyy): ");
    scanf_s("%d %d %d", &danhSachHoaDon[viTri].ngaynhapDon.ngay, &danhSachHoaDon[viTri].ngaynhapDon.thang, &danhSachHoaDon[viTri].ngaynhapDon.nam);
}

void suaSoSPHoaDon() {
    char maHD[50];
    printf_s("Nhap ma hoa don can sua: ");
    scanf_s("%s", maHD);
    int viTri = findHoaDon(maHD);
    if (viTri == -1) {
        printf_s("Khong tim thay hoa don.\n");
        return;
    }
    printf_s("Nhap so luong san pham moi: ");
    scanf_s("%d", &danhSachHoaDon[viTri].soLuongSanPham);
}

void suaTongGiaTriHoaDon() {
    char maHD[50];
    printf_s("Nhap ma hoa don can sua: ");
    scanf_s("%s", maHD);
    int viTri = findHoaDon(maHD);
    if (viTri == -1) {
        printf_s("Khong tim thay hoa don.\n");
        return;
    }
    printf_s("Nhap tong gia tri hoa don moi: ");
    scanf_s("%lf", &danhSachHoaDon[viTri].tongGiaTriHD);
}

void xuatHoaDon() {
    for (int i = 0; i < soLuongHoaDon; i++) {
        inHoaDon(danhSachHoaDon[i]);
    }
}

void xoaHoaDon() {
    char maHD[50];
    printf_s("Nhap ma hoa don can xoa: ");
    scanf_s("%s", maHD);
    int viTri = findHoaDon(maHD);
    if (viTri == -1) {
        printf_s("Khong tim thay hoa don.\n");
        return;
    }
    for (int i = viTri; i < soLuongHoaDon - 1; i++) {
        danhSachHoaDon[i] = danhSachHoaDon[i + 1];
    }
    soLuongHoaDon--;
}

void inListHoaDon(HoaDon ds[], int soLuong) {
    for (int i = 0; i < soLuong; i++) {
        inHoaDon(ds[i]);
    }
}

void inListHoaDon1() {
    inListHoaDon(danhSachHoaDon, soLuongHoaDon);
}

void timKiemHoaDonTheoNgay() {
    Date date;
    printf_s("Nhap ngay can tim (dd mm yyyy): ");
    scanf_s("%d %d %d", &date.ngay, &date.thang, &date.nam);
    for (int i = 0; i < soLuongHoaDon; i++) {
        if (danhSachHoaDon[i].ngaynhapDon.ngay == date.ngay &&
            danhSachHoaDon[i].ngaynhapDon.thang == date.thang &&
            danhSachHoaDon[i].ngaynhapDon.nam == date.nam) {
            inHoaDon(danhSachHoaDon[i]);
        }
    }
}
