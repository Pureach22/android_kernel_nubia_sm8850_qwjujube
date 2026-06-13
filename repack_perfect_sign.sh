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

# 4. Sign using AVB (96MB, ALGORITHM NONE)
echo "🔑 Applying AVB signature (96MB, ALGORITHM NONE)..."
python3 avbtool add_hash_footer \
    --image "$FINAL_IMG" \
    --partition_name boot \
    --partition_size 100663296 \
    --algorithm NONE \
    --prop com.android.build.boot.security_patch:2026-09-05

if [ $? -eq 0 ]; then
    echo "✨ SUCCESS!"
    echo "📂 Perfect boot image generated: $FINAL_IMG"
    echo "🚀 Ready for testing via: fastboot boot $FINAL_IMG"
    
    # Check for zte_tpd.ko and msm_kgsl.ko to generate flashable Magisk/KernelSU module zip
    TPD_KO=""
    if [ -f "vendor/zte/zte_tpd/zte_tpd.ko" ]; then
        TPD_KO="vendor/zte/zte_tpd/zte_tpd.ko"
    elif [ -f "kernel_platform/common/drivers/soc/qcom/zte/zte_tpd/zte_tpd.ko" ]; then
        TPD_KO="kernel_platform/common/drivers/soc/qcom/zte/zte_tpd/zte_tpd.ko"
    fi

    KGSL_KO=""
    if [ -f "vendor/qcom/opensource/graphics-kernel/msm_kgsl.ko" ]; then
        KGSL_KO="vendor/qcom/opensource/graphics-kernel/msm_kgsl.ko"
    fi
    
    if [ ! -z "$TPD_KO" ] || [ ! -z "$KGSL_KO" ]; then
        echo "📦 Packaging custom drivers into Magisk/KernelSU flashable zip..."
        rm -rf "ksu_module_temp" && mkdir -p "ksu_module_temp/vendor_dlkm/lib/modules"
        if [ -f "vendor/qcom/opensource/zte-drivers/ksu_module/module.prop" ]; then
            cp vendor/qcom/opensource/zte-drivers/ksu_module/module.prop "ksu_module_temp/"
        elif [ -f "module.prop" ]; then
            cp module.prop "ksu_module_temp/"
        fi
        
        if [ ! -z "$TPD_KO" ]; then
            cp "$TPD_KO" "ksu_module_temp/vendor_dlkm/lib/modules/"
        fi
        if [ ! -z "$KGSL_KO" ]; then
            cp "$KGSL_KO" "ksu_module_temp/vendor_dlkm/lib/modules/"
        fi
        
        # Create post-fs-data.sh
        cat <<'EOF' > ksu_module_temp/post-fs-data.sh
#!/system/bin/sh
MODDIR="${0%/*}"

# Bind mount touchscreen driver
KO_SRC_TPD="${MODDIR}/vendor_dlkm/lib/modules/zte_tpd.ko"
KO_DST_TPD="/vendor_dlkm/lib/modules/zte_tpd.ko"
if [ -f "${KO_SRC_TPD}" ] && [ -f "${KO_DST_TPD}" ]; then
    mount --bind "${KO_SRC_TPD}" "${KO_DST_TPD}"
    log -t "zte_custom_drivers" "Bind mounted custom zte_tpd.ko successfully"
fi

# Bind mount GPU driver
KO_SRC_KGSL="${MODDIR}/vendor_dlkm/lib/modules/msm_kgsl.ko"
KO_DST_KGSL="/vendor_dlkm/lib/modules/msm_kgsl.ko"
if [ -f "${KO_SRC_KGSL}" ] && [ -f "${KO_DST_KGSL}" ]; then
    mount --bind "${KO_SRC_KGSL}" "${KO_DST_KGSL}"
    log -t "zte_custom_drivers" "Bind mounted custom msm_kgsl.ko successfully"
fi
EOF
        chmod +x ksu_module_temp/post-fs-data.sh
        
        # Create update-binary placeholder
        mkdir -p ksu_module_temp/META-INF/com/google/android
        cat <<'EOF' > ksu_module_temp/META-INF/com/google/android/update-binary
#!/system/bin/sh
# MAGISK
EOF
        touch ksu_module_temp/META-INF/com/google/android/updater-script
        
        # Zip it
        (cd ksu_module_temp && zip -q -r ../zte_custom_drivers.zip .)
        rm -rf "ksu_module_temp"
        echo "✅ Generated flashable module: zte_custom_drivers.zip"
    else
        echo "⚠️ Note: Neither zte_tpd.ko nor msm_kgsl.ko was found, skipping Magisk/KernelSU module packaging."
    fi

    # Check for adreno_overclock.ko and generate flashable Magisk/KernelSU module zip
    OC_KO="vendor/qcom/opensource/zte-drivers/zte_adreno_overclock/adreno_overclock.ko"
    if [ -f "$OC_KO" ]; then
        echo "📦 Packaging Adreno Overclock module into Magisk/KernelSU flashable zip..."
        rm -rf "ksu_oc_temp" && mkdir -p "ksu_oc_temp"
        cp "$OC_KO" "ksu_oc_temp/"
        cp vendor/qcom/opensource/zte-drivers/zte_adreno_overclock/ksu_module/module.prop "ksu_oc_temp/"
        cp vendor/qcom/opensource/zte-drivers/zte_adreno_overclock/ksu_module/post-fs-data.sh "ksu_oc_temp/"
        cp vendor/qcom/opensource/zte-drivers/zte_adreno_overclock/ksu_module/service.sh "ksu_oc_temp/"
        if [ -f "vendor/qcom/opensource/zte-drivers/zte_adreno_overclock/ksu_module/analysis.md" ]; then
            cp vendor/qcom/opensource/zte-drivers/zte_adreno_overclock/ksu_module/analysis.md "ksu_oc_temp/"
        fi
        
        # Create update-binary placeholder
        mkdir -p ksu_oc_temp/META-INF/com/google/android
        cat <<'EOF' > ksu_oc_temp/META-INF/com/google/android/update-binary
#!/system/bin/sh
# MAGISK
EOF
        touch ksu_oc_temp/META-INF/com/google/android/updater-script
        
        # Zip it
        (cd ksu_oc_temp && zip -q -r ../rm11pro_gpu_oc_1250.zip .)
        rm -rf "ksu_oc_temp"
        echo "✅ Generated flashable overclock module: rm11pro_gpu_oc_1250.zip"
    else
        echo "⚠️ Note: adreno_overclock.ko not found, skipping Overclock Magisk/KernelSU module packaging."
    fi
else
    echo "❌ Error signing the image."
    exit 1
fi
