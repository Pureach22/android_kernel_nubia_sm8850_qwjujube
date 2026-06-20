#!/bin/bash
# reboot_and_boot_kernel.sh - Automates fastboot boot and ramoops log collection

set -e

echo "🔄 Rebooting device to bootloader..."
adb reboot bootloader

echo "⏳ Waiting for device in fastboot mode..."
# Loop until fastboot devices shows the device
while true; do
    if fastboot devices | grep -q "."; then
        echo "✅ Device detected in fastboot mode!"
        break
    fi
    sleep 1
done

echo "🚀 Booting dev_reverse_perfect.img via fastboot..."
fastboot boot dev_reverse_perfect.img

echo "⏳ Waiting for Android to boot and ADB to become available..."
adb wait-for-device

echo "🎉 Android is back online!"
echo "Coletando logs do kernel / pstore para verificar se inicializou limpo..."
bash scratch/get_ramoops.sh
