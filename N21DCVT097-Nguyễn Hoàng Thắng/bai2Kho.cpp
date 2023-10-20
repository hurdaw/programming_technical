#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu cua day: ";
    cin >> n;

    vector<int> arr(n);
    vector<int> freq(100000, 0); // Khởi tạo mảng freq với giá trị mặc định là 0

    cout << "Nhap cac phan tu cua day:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int maxUnique = -1; // Số lớn nhất không lặp lại
    for (int i = 0; i < n; ++i) {
        if (freq[arr[i]] == 1) {
            maxUnique = max(maxUnique, arr[i]);
        }
    }

    if (maxUnique == -1) {
        cout << "Khong co so nao khong lap lai trong day.\n";
    } else {
        cout << "So lon nhat khong lap lai trong day la: " << maxUnique << endl;
    }

    return 0;
}
