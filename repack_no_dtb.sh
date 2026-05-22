#!/bin/bash
# repack_no_dtb.sh - Package pure kernel Image without DTB and sign it

cd "$(dirname "$(readlink -f "$0")")"

KERNEL_IMAGE="kernel_platform/common/arch/arm64/boot/Image"
FINAL_IMG="dev_reverse_no_dtb.img"

echo "🔥 Starting packaging of pure kernel (no DTB)..."

if [ ! -f "$KERNEL_IMAGE" ]; then
    echo "❌ Error: Kernel Image not found at $KERNEL_IMAGE"
    exit 1
fi

# 1. Package using mkbootimg_v4.py
echo "🔨 Generating boot image..."
python3 mkbootimg_v4.py "$KERNEL_IMAGE" "/dev/null" "$FINAL_IMG"

if [ ! -f "$FINAL_IMG" ]; then
    echo "❌ Error: Failed to generate boot image."
    exit 1
fi

# 2. Sign using avbtool
echo "🔑 Applying AVB signature (64MB, ALGORITHM NONE)..."
python3 avbtool add_hash_footer \
    --image "$FINAL_IMG" \
    --partition_name boot \
    --partition_size 100663296 \
    --algorithm NONE \
    --prop com.android.build.boot.security_patch:2026-09-05

if [ $? -eq 0 ]; then
    echo "✨ SUCCESS!"
    echo "📂 Pure boot image generated: $FINAL_IMG"
    echo "🚀 Ready for testing via: fastboot boot $FINAL_IMG"
else
    echo "❌ Error signing the image."
    exit 1
fi
