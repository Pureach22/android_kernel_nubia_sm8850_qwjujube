#ifndef _WCD939X_I2C_H
#define _WCD939X_I2C_H

enum wcd_usbss_cable_status {
    WCD_USBSS_CABLE_DISCONNECT = 0,
    WCD_USBSS_CABLE_CONNECT = 1,
};

enum wcd_usbss_cable_types {
    WCD_USBSS_DP_AUX_CC1 = 1,
    WCD_USBSS_DP_AUX_CC2 = 2,
};

static inline int wcd_usbss_switch_update(int e, int s) { return 0; }
#define wcd_usbss_reg_notifier NULL
#define wcd_usbss_unreg_notifier NULL

#endif
