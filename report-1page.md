# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Bài lab này nhằm mục đích giúp sinh viên hiểu rõ nguyên lý hoạt động của các hệ mã hóa cổ điển bao gồm Caesar Cipher (thay thế) và Rail Fence Cipher (hoán vị). Thông qua việc cài đặt các thuật toán này bằng ngôn ngữ C++, sinh viên rèn luyện kỹ năng xử lý chuỗi, quản lý dữ liệu từ file và làm quen với quy trình phát triển phần mềm chuyên nghiệp sử dụng GitHub Classroom và GitHub Actions.

## 2. Cách làm
- **Caesar Cipher:** Hoàn thiện hàm mã hóa hỗ trợ cả chữ hoa và chữ thường bằng cách sử dụng bảng mã ASCII. Xử lý giữ nguyên các ký tự không phải chữ cái (như dấu cách) và xây dựng hàm giải mã dựa trên việc dịch ngược khóa (key).
- **Rail Fence Cipher:** Cài đặt thuật toán theo mô hình zigzag. Sử dụng mảng 2 chiều (vector of strings) để lưu trữ các ký tự trên từng "đường ray". Bổ sung tính năng giải mã bằng cách đánh dấu vị trí zigzag trước khi điền bản mã vào.
- **Kiểm thử và Tích hợp:** Viết hàm kiểm tra đầu vào (input validation) để đảm bảo dữ liệu chỉ chứa chữ cái và khoảng trắng. Thực hiện đọc dữ liệu trực tiếp từ file `data/input.txt` và ghi lại kết quả vào hệ thống log.

## 3. Kết quả chính

### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX | Mã hóa thành công chữ hoa, giữ dấu cách. |
| hello world | 5 | mjqqt btwqi | Xử lý tốt chữ thường (Q1) và dấu cách (Q2). |
| LORYH BRX | 3 | I LOVE YOU | Giải mã (Q3) về đúng bản rõ ban đầu. |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | ILV O OEYU | Mã hóa zigzag với 2 ray thành công. |
| I LOVE YOU | 4 | I  EYU LVO O | Kết quả thay đổi khi tăng số ray (Q4). |
| IOEOLVYU | 2 | I LOVE YOU | Giải mã (Q5) thành công bản mã zigzag. |

### 3.3 Input validation / file input
- **Trường hợp đầu vào không hợp lệ:** Chương trình báo lỗi khi nhập ký tự đặc biệt hoặc số (ví dụ: "Hello 123!").
- **Kết quả đọc từ `data/input.txt`:** Chương trình đọc file thành công và thực hiện mã hóa chính xác nội dung bên trong.

## 4. Kết luận
Qua bài lab này, em đã nắm vững cách triển khai hai loại mã hóa cổ điển tiêu biểu là thay thế và hoán vị. Khó khăn lớn nhất nằm ở việc triển khai thuật toán giải mã Rail Fence khi phải xác định chính xác ma trận zigzag. Bài tập này giúp em hiểu rõ hơn về tầm quan trọng của việc kiểm tra dữ liệu đầu vào và quy trình tự động hóa kiểm thử bằng GitHub Actions.
