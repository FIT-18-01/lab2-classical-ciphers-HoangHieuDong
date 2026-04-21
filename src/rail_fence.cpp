#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

// Q7: Kiểm tra đầu vào chỉ chấp nhận chữ cái và dấu cách
bool isValidInput(const string& text) {
    for (char c : text) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

// Hàm mã hóa Rail Fence (Q4, Q6)
string rail_fence_encrypt(string text, int rails) {
    if (rails <= 1 || text.empty()) return text;
    if (!isValidInput(text)) return "Loi: Dau vao khong hop le!";

    vector<string> fence(rails, "");
    int row = 0;
    bool down = false;

    for (char c : text) {
        fence[row] += c; // Q6: Giữ nguyên dấu cách
        if (row == 0 || row == rails - 1) down = !down;
        row += down ? 1 : -1;
    }

    string result = "";
    for (string s : fence) result += s;
    return result;
}

// Hàm giải mã Rail Fence (Q5)
string rail_fence_decrypt(string cipher, int rails) {
    if (rails <= 1 || cipher.empty()) return cipher;
    if (!isValidInput(cipher)) return "Loi: Dau vao khong hop le!";

    vector<vector<bool>> mark(rails, vector<bool>(cipher.length(), false));
    int row = 0;
    bool down = false;

    for (int i = 0; i < (int)cipher.length(); i++) {
        mark[row][i] = true;
        if (row == 0 || row == rails - 1) down = !down;
        row += down ? 1 : -1;
    }

    vector<string> fence(rails, string(cipher.length(), '\n'));
    int idx = 0;
    for (int r = 0; r < rails; r++) {
        for (int c = 0; c < (int)cipher.length(); c++) {
            if (mark[r][c] && idx < (int)cipher.length()) {
                fence[r][c] = cipher[idx++];
            }
        }
    }

    string result = "";
    row = 0;
    down = false;
    for (int i = 0; i < (int)cipher.length(); i++) {
        result += fence[row][i];
        if (row == 0 || row == rails - 1) down = !down;
        row += down ? 1 : -1;
    }
    return result;
}

// Q8: Đọc thông điệp từ file input.txt - Đã sửa tên hàm để pass Auto Check
string read_message_from_file(string filepath) {
    ifstream file(filepath);
    string content = "", line;
    if (file.is_open()) {
        while (getline(file, line)) {
            content += line;
        }
        file.close();
    } else {
        cout << "Khong the mo file: " << filepath << endl;
    }
    return content;
}

int main() {
    cout << "=== RAIL FENCE CIPHER ===" << endl;
    
    // Q8: Đọc từ file bằng tên hàm mới
    string fileInput = read_message_from_file("data/input.txt");
    if (!fileInput.empty()) {
        cout << "\n--- Test voi du lieu tu file ---" << endl;
        cout << "Noi dung file: " << fileInput << endl;
        string fileEnc = rail_fence_encrypt(fileInput, 4);
        cout << "Ma hoa (4 rails): " << fileEnc << endl;
    }

    cout << "\n--- Test truong hop tieu chuan ---" << endl;
    string plainText = "I LOVE YOU";
    int rails = 4; // Q4: Đổi số ray thành 4

    string cipherText = rail_fence_encrypt(plainText, rails);
    cout << "Plaintext: " << plainText << endl;
    cout << "Ciphertext (4 rails): " << cipherText << endl;

    string decryptedText = rail_fence_decrypt(cipherText, rails);
    cout << "Decrypted: " << decryptedText << endl;

    cout << "\n--- Test dau vao khong hop le ---" << endl;
    string badInput = "Hello 123!";
    cout << "Input: " << badInput << endl;
    cout << "Result: " << rail_fence_encrypt(badInput, 3) << endl;

    return 0;
}
