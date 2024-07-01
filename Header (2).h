#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Cấu trúc dữ liệu
typedef struct {
    unsigned int ngay;
    unsigned int thang;
    unsigned int nam;
} Date;

typedef struct {
    char maSP[50];
    char tenSP[100];
    char mauSac[20];
    int soluongCon;
    double giaNhap;
    double giaBan;
    char size[10];
} SanPham;

typedef struct {
    char maHD[50];
    Date ngaynhapDon;
    int soLuongSanPham;
    double tongGiaTriHD;
} HoaDon;

// Hien thi
void Menu();
void MenuQLMH();
void MenuQLHD();
void MenuThongKe();
void MenuSua();
void MenuSuaHD();

// San pham
void ThemSanPham();
void InListSp(SanPham ds[], int soLuong);
void InListSp1();
char* canGiua1(const char* str, int width, char* buffer);
char* canGiua2(double value, int width, char* buffer);
int find_vitri_maSP(const char* maSP);
void SuaTenSanPham();
void SuaMaSanPham();
void SuaSoLuong();
void SuaGiaNhap();
void SuaGiaBan();
void SuaSize();
void SuaMauSac();
void XoaSanPham();
void TimKiemTheoMa();
void InSP(SanPham sp);
void TimKiemTheoTen();
int KiemtraChuoicon(const char* subStr, const char* str);
void TimKiemTrenKhoangGiaBan();
void SapXepGiaTangDan();
void SapXepGiaGiamDan();
void MenuSapXepGia();
void swapSp(SanPham* a, SanPham* b);

// Hoa Don
void inHoaDon(HoaDon HD);
void themHoaDon();
int findHoaDon(const char* maHD);
void suaNgayHoaDon();
void suaSoSPHoaDon();
void suaTongGiaTriHoaDon();
void xuatHoaDon();
void xoaHoaDon();
void inListHoaDon(HoaDon ds[], int soLuong);
void inListHoaDon1();
void timKiemHoaDonTheoNgay();

#endif
