import struct
import sys

def pack_boot_v4(kernel_path, ramdisk_path, output_path):
    with open(kernel_path, "rb") as f:
        kernel = f.read()
    
    if ramdisk_path == "/dev/null":
        ramdisk = b""
    else:
        with open(ramdisk_path, "rb") as f:
            ramdisk = f.read()

    # Header Android v4 Oficial (AOSP Specification)
    magic = b"ANDROID!"
    header_version = 4
    header_size = 1584
    
    header = struct.pack("<8s9I1536sI", 
        magic, 
        len(kernel),       # kernel_size
        len(ramdisk),      # ramdisk_size
        0,                 # os_version (None)
        header_size,       # header_size
        0, 0, 0, 0,        # reserved[4]
        header_version,    # header_version (4)
        b"module_blacklist=kernelsu" + b"\x00" * (1536 - len("module_blacklist=kernelsu")),    # cmdline
        0                  # signature_size
    )
    
    # Preenche com zeros até atingir 4096 bytes (BOOT_IMAGE_HEADER_V3_PAGESIZE)
    header += b"\x00" * (4096 - len(header))

    with open(output_path, "wb") as f:
        f.write(header)
        f.write(kernel)
        # Alinha kernel em página de 4096 bytes
        if len(kernel) % 4096 != 0:
            f.write(b"\x00" * (4096 - (len(kernel) % 4096)))
        f.write(ramdisk)
        if len(ramdisk) > 0 and len(ramdisk) % 4096 != 0:
            f.write(b"\x00" * (4096 - (len(ramdisk) % 4096)))
    
    print(f"✅ Boot Image v4 gerada com sucesso: {output_path}")

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Uso: python3 mkbootimg_v4.py <kernel> <ramdisk> <output>")
    else:
        pack_boot_v4(sys.argv[1], sys.argv[2], sys.argv[3])
