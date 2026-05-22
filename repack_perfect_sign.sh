#!/bin/bash
# repack_perfect_sign.sh - Repack and sign for RedMagic 11 Pro (NX809J)

cd "$(dirname "$(readlink -f "$0")")"

KERNEL_IMAGE="kernel_platform/common/arch/arm64/boot/Image"
DTB_IMAGE="dtb.img"
OUTPUT_DIR="repack_perfect_work"
FINAL_IMG="dev_reverse_perfect.img"

echo "🔥 Starting perfect repack (kernel + DTB)..."

if [ ! -f "$KERNEL_IMAGE" ]; then
    echo "❌ Error: Kernel Image not found at $KERNEL_IMAGE"
    exit 1
fi

if [ ! -f "$DTB_IMAGE" ]; then
    echo "❌ Error: DTB image not found at $DTB_IMAGE"
    exit 1
fi

# 1. Prepare work directory
rm -rf "$OUTPUT_DIR" && mkdir -p "$OUTPUT_DIR"

# 2. Concatenate Image and dtb.img
echo "📦 Concatenating Image with dtb.img..."
python3 -c '
with open("'"$KERNEL_IMAGE"'", "rb") as f:
    kernel = f.read()
with open("'"$DTB_IMAGE"'", "rb") as f:
    dtb = f.read()

payload = kernel + dtb
print(f"   -> Image size: {len(kernel)} bytes")
print(f"   -> DTB size: {len(dtb)} bytes")
print(f"   -> Payload size: {len(payload)} bytes")

with open("'"$OUTPUT_DIR"'/kernel_payload", "wb") as f:
    f.write(payload)
'

# 3. Generate boot image without ramdisk
echo "🔨 Generating boot image (ramdisk_size = 0)..."
python3 mkbootimg_v4.py "$OUTPUT_DIR/kernel_payload" "/dev/null" "$FINAL_IMG"

if [ ! -f "$FINAL_IMG" ]; then
    echo "❌ Error: Failed to generate boot image."
    exit 1
fi

# 4. Sign using AVB (64MB, ALGORITHM NONE)
echo "🔑 Applying AVB signature (64MB, ALGORITHM NONE)..."
python3 avbtool add_hash_footer \
    --image "$FINAL_IMG" \
    --partition_name boot \
    --partition_size 67108864 \
    --algorithm NONE \
    --prop com.android.build.boot.security_patch:2026-09-05

if [ $? -eq 0 ]; then
    echo "✨ SUCCESS!"
    echo "📂 Perfect boot image generated: $FINAL_IMG"
    echo "🚀 Ready for testing via: fastboot boot $FINAL_IMG"
else
    echo "❌ Error signing the image."
    exit 1
fi
