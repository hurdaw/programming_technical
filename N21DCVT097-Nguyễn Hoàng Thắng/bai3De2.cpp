#include <iostream>
#include <queue>
//Thực hiện các phép toán cơ bản (push, pop) trên queue
int main() {
    std::queue<int> myQueue;

    // Thêm phần tử vào queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Lấy và loại bỏ phần tử đầu tiên
    int frontElement = myQueue.front(); // Lấy giá trị ở đầu hàng mà không loại bỏ
    std::cout << "Front element: " << frontElement << std::endl;

    myQueue.pop(); // Loại bỏ phần tử đầu tiên

    // Kiểm tra xem queue có rỗng không
    if (myQueue.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    // Kích thước của queue
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    return 0;
}
