# Lab 2: Classical Ciphers - Nguyễn Tuấn Anh

## Thông tin sinh viên
* **Họ và tên:** Nguyễn Tuấn Anh
* **Mã sinh viên:** 1871020065
* **Lớp:** CNTT 18-02

---

## Nội dung bài tập (Q1 - Q8)
Dự án này hoàn thiện các yêu cầu về mã hóa cổ điển:
- **Caesar** Cipher: Xử lý chữ hoa, chữ thường, giữ nguyên dấu cách và chức năng giải mã (Q1, Q2, Q3).
- **Rail Fence** Cipher: Cài đặt zic-zac, giải mã, giữ dấu cách, kiểm tra đầu vào và đọc dữ liệu từ file `input.txt` (Q4, Q5, Q6, Q7, Q8).

## Cấu trúc thư mục
Dự án tuân thủ cấu trúc chuẩn trên **GitHub**:
- `src/`: Chứa `caesar.cpp` và `rail_fence.cpp`.
- `data/`: Chứa file dữ liệu `input.txt`.
- `tests/` & `logs/`: Minh chứng kiểm thử và nhật ký chạy chương trình.

## Cách biên dịch và chạy
Biên dịch bằng g++ chuẩn C++17:
```bash
# Caesar
g++ -std=c++17 -O2 -o caesar_bin src/caesar.cpp
./caesar_bin

# Rail Fence
g++ -std=c++17 -O2 -o rail_bin src/rail_fence.cpp
./rail_bin
