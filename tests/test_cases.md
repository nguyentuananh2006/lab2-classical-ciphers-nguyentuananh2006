# Test Cases – FIT4012 Lab 2

## Caesar Cipher
- [x] Encrypt `HELLO WORLD` với key `3` -> Kết quả: `KHOOR ZRUOG`
- [x] Encrypt `hello world` với key `5` -> Kết quả: `mjqqt btwqi`
- [x] Decrypt `KHOOR ZRUOG` với key `3` -> Kết quả: `HELLO WORLD`

## Rail Fence Cipher
- [x] Encrypt `HELLO WORLD` với `2` rails -> Kết quả: `HLOORDE LWLD`
- [x] Encrypt `HELLO WORLD` với `3` rails -> Kết quả: `HORELLWLD O`
- [x] Decrypt một bản mã Rail Fence hợp lệ thành công

## Validation / File input
- [x] Kiểm tra đầu vào không hợp lệ (số, ký tự đặc biệt) bị từ chối thành công
- [x] Đọc thông điệp từ `data/input.txt` và mã hóa thành công
