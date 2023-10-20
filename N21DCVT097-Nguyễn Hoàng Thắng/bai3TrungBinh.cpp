#include <iostream>
#include <stack>
#include <string>
// Kiểm tra xem một biểu thức dấu ngoặc có hợp lệ không bằng cách sử dụng stack.
bool isValidExpression(const std::string& expression) {
    std::stack<char> brackets;

    for (char c : expression) {
        if (c == '(') {
            brackets.push(c);
        } else if (c == ')') {
            if (brackets.empty()) {
                return false; // Không có dấu ngoặc mở tương ứng
            } else {
                brackets.pop(); // Lấy dấu ngoặc mở ra khỏi stack
            }
        }
    }

    return brackets.empty(); // Nếu stack trống, biểu thức hợp lệ
}

int main() {
    std::string expression;
    std::cout << "Nhap bieu thuc dấu ngoặc: ";
    std::cin >> expression;

    if (isValidExpression(expression)) {
        std::cout << "Bieu thuc hop le.\n";
    } else {
        std::cout << "Bieu thuc khong hop le.\n";
    }

    return 0;
}
