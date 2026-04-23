# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Mục tiêu của bài lab là tìm hiểu và cài đặt hai thuật toán mật mã cổ điển: Caesar Cipher và Rail Fence Cipher bằng ngôn ngữ C++. Bài tập cũng giúp làm quen với quy trình quản lý dự án, kiểm thử tự động và sử dụng GitHub Actions trong thực tế.

## 2. Cách làm
- Hoàn thiện Caesar Cipher: Xử lý logic dịch chuyển cho chữ thường, giữ nguyên khoảng trắng và viết hàm giải mã dựa trên hàm mã hóa gốc.
- Hoàn thiện Rail Fence Cipher: Sử dụng mô hình zigzag (zic-zac) để mã hóa/giải mã, xử lý mảng động để lưu trữ các "rail", tích hợp kiểm tra đầu vào hợp lệ và đọc dữ liệu từ file `input.txt`.
- Thực hiện kiểm thử trên các bộ dữ liệu khác nhau để đảm bảo tính chính xác của thuật toán.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| HELLO WORLD | 3 | KHOOR ZRUOG | Mã hóa đúng, giữ khoảng trắng |
| hello world | 5 | mjqqt btwqi | Xử lý tốt chữ thường |
| KHOOR ZRUOG | 3 | HELLO WORLD | Giải mã chính xác về bản rõ gốc |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| HELLO WORLD | 2 | HLOORDE LWLD | Mã hóa theo 2 đường ray |
| HELLO WORLD | 3 | HORELLWLD O | Mã hóa theo 3 đường ray zigzag |
| HLOORDE LWLD | 2 | HELLO WORLD | Giải mã zic-zac chính xác |

### 3.3 Input validation / file input
- **Trường hợp đầu vào không hợp lệ:** Chương trình phát hiện các ký tự đặc biệt (như @, #, $, 123) và thông báo lỗi "Invalid input", chỉ chấp nhận chữ cái và khoảng trắng.
- **Kết quả đọc từ `data/input.txt`:** Chương trình đọc thành công thông điệp "HELLO WORLD" từ file và thực hiện mã hóa chính xác theo yêu cầu.

## 4. Kết luận
Qua bài lab, em đã nắm vững nguyên lý hoạt động của các hệ mã thay thế và hoán vị cổ điển. Khó khăn lớn nhất nằm ở việc thiết lập chỉ số dòng/cột cho mô hình zigzag trong Rail Fence Cipher, nhưng việc vẽ mô hình ra giấy trước khi code đã giúp em giải quyết vấn đề. Bài tập này giúp em hiểu rõ hơn về tầm quan trọng của việc kiểm soát luồng dữ liệu và xử lý ngoại lệ trong lập trình C++.
