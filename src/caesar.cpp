#include <iostream>
#include <string>
#include <cctype> // Thư viện cung cấp isupper(), islower()

using namespace std;

// Hàm mã hóa Caesar
string caesarEncrypt(string text, int key) {
    string result = "";
    
    // Đảm bảo key luôn nằm trong khoảng 0-25 (tránh lỗi khi key quá lớn hoặc âm)
    key = key % 26;
    if (key < 0) key += 26;

    for (char c : text) {
        if (isupper(c)) {
            // Xử lý chữ in hoa
            result += char((c - 'A' + key) % 26 + 'A');
        } 
        else if (islower(c)) {
            // Q1: Xử lý chữ in thường
            result += char((c - 'a' + key) % 26 + 'a');
        } 
        else {
            // Q2: Xử lý dấu cách (và các ký tự đặc biệt khác)
            // Nếu không phải chữ cái, ta giữ nguyên ký tự đó
            result += c;
        }
    }
    return result;
}

// Hàm giải mã Caesar (Q3)
string caesarDecrypt(string text, int key) {
    // Mẹo nhỏ: Giải mã bản chất là dịch ngược lại. 
    // Dịch lùi 'key' bước tương đương với việc dịch tới '26 - key' bước.
    // Do đó ta có thể tái sử dụng luôn hàm Encrypt!
    int decryptKey = 26 - (key % 26);
    return caesarEncrypt(text, decryptKey);
}

int main() {
    string plainText = "hello world";
    int key = 5;

    // Test mã hóa
    string cipherText = caesarEncrypt(plainText, key);
    cout << "Ciphertext: " << cipherText << endl;

    // Test giải mã
    string decryptedText = caesarDecrypt(cipherText, key);
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}
