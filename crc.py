def crc32(data):
    crc = 0xFFFFFFFF
    for byte in data:
        crc ^= byte
        for _ in range(8):
            if crc & 1:
                crc = (crc >> 1) ^ 0xEDB88320
            else:
                crc >>= 1
    return crc ^ 0xFFFFFFFF

if __name__ == "__main__":
    input_data = input("Enter the input data: ")
    checksum = crc32(input_data.encode())
    print(f"CRC32 Checksum: {checksum:#010x}")
