#!/system/bin/sh
# post-fs-data.sh - KernelSU/Magisk module script
# Bind mounts reconstructed ZTE drivers over the official ones
# This runs during post-fs-data stage, BEFORE modules are loaded by init

MODDIR="${0%/*}"

MODULES="zte_charger_policy zte_tpd zte_led zte_power_supply zte_misc zte_reboot_ext zte_imem_info zte_fingerprint zte_stats_info zte_sensor_sensitivity zte_ir"

for m in $MODULES; do
    KO_SRC="${MODDIR}/vendor_dlkm/lib/modules/${m}.ko"
    KO_DST="/vendor_dlkm/lib/modules/${m}.ko"
    if [ -f "${KO_SRC}" ] && [ -f "${KO_DST}" ]; then
        mount --bind "${KO_SRC}" "${KO_DST}"
        log -t "zte_custom_drivers" "Bind mounted custom ${m} over ${KO_DST}"
    else
        log -t "zte_custom_drivers" "ERROR: ${m} source or destination not found"
    fi
done

