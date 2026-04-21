#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Hàm mã hóa Caesar
string caesar_encrypt(string text, int key) {
    string result = "";
    key = key % 26;
    if (key < 0) key += 26;

    for (char c : text) {
        if (isupper(c)) {
            result += char((c - 'A' + key) % 26 + 'A');
        } 
        else if (islower(c)) {
            result += char((c - 'a' + key) % 26 + 'a'); // Q1: Xử lý chữ thường
        } 
        else {
            result += c; // Q2: Giữ nguyên dấu cách và ký tự đặc biệt
        }
    }
    return result;
}

// Hàm giải mã Caesar (Q3) - Tên hàm đúng chuẩn hệ thống yêu cầu
string caesar_decrypt(string text, int key) {
    int decryptKey = 26 - (key % 26);
    return caesar_encrypt(text, decryptKey);
}

int main() {
    cout << "=== CAESAR CIPHER ===" << endl;
    string plainText = "hello world";
    int key = 5;

    cout << "Plaintext: " << plainText << " (Key: " << key << ")" << endl;
    
    string cipherText = caesar_encrypt(plainText, key);
    cout << "Ciphertext: " << cipherText << endl;

    string decryptedText = caesar_decrypt(cipherText, key);
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}
