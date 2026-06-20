#!/system/bin/sh
# post-fs-data.sh - KernelSU module script
# Bind mounts the reconstructed zte_charger_policy.ko over the official one
# This runs during post-fs-data stage, BEFORE modules are loaded by init

MODDIR="${0%/*}"
KO_SRC="${MODDIR}/vendor_dlkm/lib/modules/zte_charger_policy.ko"
KO_DST="/vendor_dlkm/lib/modules/zte_charger_policy.ko"

if [ -f "${KO_SRC}" ] && [ -f "${KO_DST}" ]; then
    mount --bind "${KO_SRC}" "${KO_DST}"
    log -t "zte_charger_policy_custom" "Bind mounted custom ko over ${KO_DST}"
else
    log -t "zte_charger_policy_custom" "ERROR: Source or destination ko not found"
fi
