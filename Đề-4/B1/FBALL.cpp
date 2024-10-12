#include <bits/stdc++.h>
using namespace std;

// Hàm tính điểm cho từng trận đấu
void tinh(int luoiA, int luoiB, int &diemA, int &diemB) {
    if (luoiA > luoiB) {
        diemA += 3;
    } else if (luoiA < luoiB) {
        diemB += 3;
    } else {
        diemA += 1;
        diemB += 1;
    }
}

int main() {
    // Mở file để đọc dữ liệu
    freopen("FBALL.inp", "r", stdin);
    freopen("FBALL.out", "w", stdout);

    int p, q, r, s, u, v;
    cin >> p >> q >> r >> s >> u >> v;

    int diemA = 0, diemB = 0, diemC = 0;

    // Tính điểm cho từng trận đấu
    tinh(p, q, diemA, diemB); // Trận a gặp b
    tinh(r, s, diemA, diemC); // Trận a gặp c
    tinh(u, v, diemB, diemC); // Trận b gặp c

    // Ghi kết quả ra file
    cout << diemA << " " << diemB << " " << diemC << endl;

    return 0;
}
