#include <cctype>
#include <iostream>
#include <string>

using namespace std;

// Kiểm tra thông điệp hợp lệ (chỉ chữ cái và dấu cách)
bool is_valid_message(const string &text) {
    if (text.empty()) return false;
    for (char c : text) {
        // Ép kiểu (unsigned char) là chính xác để tránh lỗi với giá trị âm trong bảng ASCII
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

// Hàm dịch chuyển ký tự lẻ
char shift_char(char c, int shift) {
    if (!isalpha(static_cast<unsigned char>(c))) return c;

    char base = isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
    
    // Xử lý shift để luôn nằm trong khoảng [0, 25]
    shift %= 26;
    if (shift < 0) shift += 26;
    
    // Công thức: (vị trí hiện tại + dịch chuyển) % 26 + ký tự gốc
    return static_cast<char>((c - base + shift) % 26 + base);
}

// Hàm mã hóa
string caesar_encrypt(const string &plaintext, int shift) {
    string ciphertext = "";
    for (char c : plaintext) {
        ciphertext += shift_char(c, shift);
    }
    return ciphertext;
}

// Hàm giải mã: Chỉ cần mã hóa với giá trị dịch chuyển ngược lại
string caesar_decrypt(const string &ciphertext, int shift) {
    return caesar_encrypt(ciphertext, -shift);
}

int main() {
    cout << "=== Caesar Cipher Demo ===\n";
    cout << "1. Encrypt\n2. Decrypt\nChoose: ";

    int choice;
    if (!(cin >> choice)) return 1; // Kiểm tra nếu người dùng nhập không phải số
    cin.ignore(1000, '\n'); // Xóa sạch bộ đệm để tránh lỗi getline

    string message;
    int shift;

    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter key (integer): ";
    if (!(cin >> shift)) {
        cout << "Invalid key. Please enter an integer.\n";
        return 1;
    }

    if (!is_valid_message(message)) {
        cout << "Error: Message contains invalid characters (only letters and spaces allowed).\n";
        return 1;
    }

    ---
    
    if (choice == 1) {
        cout << "Result (Ciphertext): " << caesar_encrypt(message, shift) << "\n";
    } else if (choice == 2) {
        cout << "Result (Plaintext): " << caesar_decrypt(message, shift) << "\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
