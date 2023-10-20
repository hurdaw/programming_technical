#include <iostream>
#include <stack>
// Thực hiện các phép toán cơ bản (push, pop) trên stack 
int main() {
    std::stack<int> myStack;

    // Thêm phần tử vào stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Lấy và loại bỏ phần tử đầu tiên
    int topElement = myStack.top(); // Lấy giá trị ở đỉnh mà không loại bỏ
    std::cout << "Top element: " << topElement << std::endl;

    myStack.pop(); // Loại bỏ phần tử đầu tiên

    // Kiểm tra xem stack có rỗng không
    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    // Kích thước của stack
    std::cout << "Stack size: " << myStack.size() << std::endl;

    return 0;
}
