#include "defs.h"

static const char *get_lcd_state_string(int state)
{
    switch (state) {
        case 0: return "TP_POWER_STATUS=2";
        case 1: return "TP_POWER_STATUS=1";
        case 2: return "TP_POWER_STATUS=3";
        default: return "TP_POWER_STATUS=unknown";
    }
}

extern int current_lcd_state;
extern __int64 tpd_cdev;
extern __int64 ufp_report_gesture_uevent(const char *a1);

void report_ufp_uevent(unsigned int val)
{
    char field_a1 = ufp_tp_ops.field_a1;

    if (val != 0 && !(field_a1 & 1)) {
        ufp_tp_ops.field_a1 = 1;
        if (current_lcd_state != 0) {
            if (ufp_tp_ops.pdev == NULL) {
                printk(KERN_ERR "tpd_ufp_err: uevent pdev is null!\n\n");
                ufp_tp_ops.field_a1 = 1;
                return;
            }
            ufp_report_gesture_uevent("single_tap=true");
            char *envp[3] = { "aod_areameet_down=true", (char *)get_lcd_state_string(current_lcd_state), NULL };
            kobject_uevent_env(&ufp_tp_ops.pdev->dev.kobj, KOBJ_CHANGE, envp);
        } else {
            if (ufp_tp_ops.pdev == NULL) {
                printk(KERN_ERR "tpd_ufp_err: uevent pdev is null!\n\n");
                ufp_tp_ops.field_a1 = 1;
                return;
            }
            char *envp[3] = { "areameet_down=true", (char *)get_lcd_state_string(current_lcd_state), NULL };
            kobject_uevent_env(&ufp_tp_ops.pdev->dev.kobj, KOBJ_CHANGE, envp);
        }
        ufp_tp_ops.field_a1 = 1;
    }
    else if (val == 0 && (field_a1 == 1)) {
        ufp_tp_ops.field_a1 = 0;
        if (ufp_tp_ops.pdev == NULL) {
            printk(KERN_ERR "tpd_ufp_err: uevent pdev is null!\n\n");
        } else {
            char *envp[3] = { "areameet_up=true", (char *)get_lcd_state_string(current_lcd_state), NULL };
            kobject_uevent_env(&ufp_tp_ops.pdev->dev.kobj, KOBJ_CHANGE, envp);
        }
        int cdev_458 = *(int *)(tpd_cdev + 0x458);
        if (cdev_458 != 0) {
            if (ufp_tp_ops.field_a1 != 0 && !(ufp_tp_ops.field_a2 & 1)) {
                complete(&ufp_tp_ops.gesture_complete);
                ufp_tp_ops.field_a0 = 0;
            }
            if (ufp_tp_ops.field_a1 == 1 && !(ufp_tp_ops.field_a2 & 1)) {
                printk(KERN_INFO "tpd_ufp_info: areameet_down_flag is false\n");
                ufp_tp_ops.field_a1 = 0;
            }
        } else {
            if (ufp_tp_ops.field_a1 != 0) {
                complete(&ufp_tp_ops.gesture_complete);
                ufp_tp_ops.field_a0 = 0;
            }
        }
    }
}
