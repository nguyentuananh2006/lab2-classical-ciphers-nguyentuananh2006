#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid_message(const string &text) {
    if (text.empty()) return false;
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

string rail_fence_encrypt(const string &plaintext, int rails) {
    if (rails <= 1 || plaintext.empty()) return plaintext;

    vector<string> fence(rails, "");
    int rail = 0;
    int direction = 1;

    for (char c : plaintext) {
        fence[rail] += c;
        if (rail == 0) direction = 1;
        else if (rail == rails - 1) direction = -1;
        rail += direction;
    }

    string ciphertext;
    for (const string &row : fence) ciphertext += row;
    return ciphertext;
}

string rail_fence_decrypt(const string &ciphertext, int rails) {
    if (rails <= 1 || ciphertext.empty()) return ciphertext;

    int n = ciphertext.length();
    vector<vector<char>> fence(rails, vector<char>(n, '\0'));
    
    int rail = 0;
    int direction = 1;
    for (int i = 0; i < n; i++) {
        fence[rail][i] = '*';
        if (rail == 0) direction = 1;
        else if (rail == rails - 1) direction = -1;
        rail += direction;
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < n; j++) {
            if (fence[i][j] == '*' && index < n) {
                fence[i][j] = ciphertext[index++];
            }
        }
    }

    string plaintext = "";
    rail = 0;
    direction = 1;
    for (int i = 0; i < n; i++) {
        plaintext += fence[rail][i];
        if (rail == 0) direction = 1;
        else if (rail == rails - 1) direction = -1;
        rail += direction;
    }

    return plaintext;
}

string read_message_from_file(const string &path) {
    ifstream fin(path);
    if (!fin.is_open()) return "";
    string line;
    getline(fin, line);
    return line;
}

int main() {
    cout << "=== Rail Fence Cipher Demo ===\n";
    cout << "1. Encrypt\n2. Decrypt\n3. Read from file and encrypt\nChoose: ";

    int choice;
    if (!(cin >> choice)) return 0;
    cin.ignore(1000, '\n');

    string message;
    int rails;

    if (choice == 3) {
        message = read_message_from_file("data/input.txt");
        if (message.empty()) {
            cout << "File error or empty.\n";
            return 0;
        }
        cout << "Message from file: " << message << "\n";
    } else {
        cout << "Enter message: ";
        getline(cin, message);
    }

    cout << "Enter rails: ";
    if (!(cin >> rails)) return 0;

    if (!is_valid_message(message)) {
        cout << "Invalid input. Only letters and spaces are allowed.\n";
        return 0;
    }

    if (choice == 1 || choice == 3) {
        cout << "Ciphertext: " << rail_fence_encrypt(message, rails) << "\n";
    } else if (choice == 2) {
        cout << "Plaintext: " << rail_fence_decrypt(message, rails) << "\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
