#include "Header.h"

int main() {
    int choice;
    do {
        Menu();
        printf_s("Chon: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            MenuQLMH();
            int qlmhChoice;
            printf_s("Chon: ");
            scanf_s("%d", &qlmhChoice);
            switch (qlmhChoice) {
            case 1:
                InListSp1();
                break;
            case 2:
                ThemSanPham();
                break;
            case 3:
                MenuSua();
                int suaChoice;
                printf_s("Chon: ");
                scanf_s("%d", &suaChoice);
                switch (suaChoice) {
                case 1:
                    SuaMaSanPham();
                    break;
                case 2:
                    SuaTenSanPham();
                    break;
                case 3:
                    SuaSoLuong();
                    break;
                case 4:
                    SuaGiaNhap();
                    break;
                case 5:
                    SuaGiaBan();
                    break;
                case 6:
                    SuaSize();
                    break;
                case 7:
                    SuaMauSac();
                    break;
                default:
                    printf_s("Lua chon khong hop le!\n");
                    break;
                }
                break;
            case 4:
                XoaSanPham();
                break;
            case 5:
                TimKiemTheoMa();
                break;
            case 6:
                TimKiemTheoTen();
                break;
            case 7:
                TimKiemTrenKhoangGiaBan();
                break;
            case 8:
                MenuSapXepGia();
                int sapXepChoice;
                printf_s("Chon: ");
                scanf_s("%d", &sapXepChoice);
                switch (sapXepChoice) {
                case 1:
                    SapXepGiaTangDan();
                    break;
                case 2:
                    SapXepGiaGiamDan();
                    break;
                default:
                    printf_s("Lua chon khong hop le!\n");
                    break;
                }
                break;
            default:
                printf_s("Lua chon khong hop le!\n");
                break;
            }
            break;
        case 2:
            MenuQLHD();
            int qlhdChoice;
            printf_s("Chon: ");
            scanf_s("%d", &qlhdChoice);
            switch (qlhdChoice) {
            case 1:
                themHoaDon();
                break;
            case 2:
                MenuSuaHD();
                int suaHDChoice;
                printf_s("Chon: ");
                scanf_s("%d", &suaHDChoice);
                switch (suaHDChoice) {
                case 1:
                    suaNgayHoaDon();
                    break;
                case 2:
                    suaSoSPHoaDon();
                    break;
                case 3:
                    suaTongGiaTriHoaDon();
                    break;
                default:
                    printf_s("Lua chon khong hop le!\n");
                    break;
                }
                break;
            case 3:
                xoaHoaDon();
                break;
            case 4:
                xuatHoaDon();
                break;
            case 5:
                timKiemHoaDonTheoNgay();
                break;
            case 6:
                inListHoaDon1();
                break;
            default:
                printf_s("Lua chon khong hop le!\n");
                break;
            }
            break;
        default:
            if (choice != 3) {
                printf_s("Lua chon khong hop le!\n");
            }
            break;
        }
    } while (choice != 3);

    return 0;
}
