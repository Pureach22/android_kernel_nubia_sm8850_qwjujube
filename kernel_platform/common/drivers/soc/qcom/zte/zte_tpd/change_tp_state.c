#include "defs.h"

void change_tp_state(int state)
{
    const char *lcdstate_str = "unknown";
    const char *lcdchange_str = "unknown";

    if (!tpd_cdev) {
        pr_err("tpd_ufp_err: change_tp_state called but tpd_cdev is NULL!\n");
        return;
    }

    mutex_lock((struct mutex *)(tpd_cdev + 2824));
    if (state < 0 || state > 3 || current_lcd_state < 0 || current_lcd_state >= 3) {
        pr_warn("tpd_ufp_err: change_tp_state invalid input - state: %d, current_lcd_state: %d\n", state, current_lcd_state);
        mutex_unlock((struct mutex *)(tpd_cdev + 2824));
        return;
    }

    switch (current_lcd_state) {
        case 0: lcdstate_str = "screen_on"; break;
        case 1: lcdstate_str = "screen_off"; break;
        case 2: lcdstate_str = "screen_in_doze"; break;
    }

    switch (state) {
        case 0: lcdchange_str = "lcd_exit_lp"; break;
        case 1: lcdchange_str = "lcd_enter_lp"; break;
        case 2: lcdchange_str = "lcd_on"; break;
        case 3: lcdchange_str = "lcd_off"; break;
    }

    pr_info("tpd_ufp_info: current_lcd_state:%s, lcd change:%s\n\n",
            lcdstate_str, lcdchange_str);

    if (current_lcd_state == 2) {
        if (state == 0) {
            // Do nothing
        } else if (state == 2) {
            current_lcd_state = 0;
            queue_work_on(WORK_CPU_UNBOUND, *(struct workqueue_struct **)(tpd_cdev + 0x4b0), (struct work_struct *)(tpd_cdev + 0x9c0));
            ufp_tp_ops.field_8 = 0;
        } else if (state == 3) {
            current_lcd_state = 1;
            ufp_tp_ops.field_8 = 0;
            *(int *)((char *)&ufp_tp_ops + 128) = 0;
            queue_work_on(WORK_CPU_UNBOUND, *(struct workqueue_struct **)(tpd_cdev + 0x4b0), (struct work_struct *)(tpd_cdev + 0x9a0));
        } else {
            pr_err("tpd_ufp_err: ignore err lcd change\n");
        }
    } else if (current_lcd_state == 1) {
        if (state == 2) {
            current_lcd_state = 0;
            queue_work_on(WORK_CPU_UNBOUND, *(struct workqueue_struct **)(tpd_cdev + 0x4b0), (struct work_struct *)(tpd_cdev + 0x9c0));
            ufp_tp_ops.field_8 = 0;
        } else if (state == 1) {
            current_lcd_state = 2;
            ufp_tp_ops.field_8 = 0;
            queue_work_on(WORK_CPU_UNBOUND, *(struct workqueue_struct **)(tpd_cdev + 0x4b0), (struct work_struct *)(tpd_cdev + 0x9a0));
        } else {
            pr_err("tpd_ufp_err: ignore err lcd change\n");
        }
    } else if (current_lcd_state == 0) {
        if (state == 3) {
            current_lcd_state = 1;
            ufp_tp_ops.field_8 = 0;
            *(int *)((char *)&ufp_tp_ops + 128) = 0;
            queue_work_on(WORK_CPU_UNBOUND, *(struct workqueue_struct **)(tpd_cdev + 0x4b0), (struct work_struct *)(tpd_cdev + 0x9a0));
        } else if (state == 1) {
            current_lcd_state = 2;
            ufp_tp_ops.field_8 = 0;
            queue_work_on(WORK_CPU_UNBOUND, *(struct workqueue_struct **)(tpd_cdev + 0x4b0), (struct work_struct *)(tpd_cdev + 0x9a0));
        } else {
            pr_err("tpd_ufp_err: ignore err lcd change\n");
        }
    } else {
        current_lcd_state = 0;
        queue_work_on(WORK_CPU_UNBOUND, *(struct workqueue_struct **)(tpd_cdev + 0x4b0), (struct work_struct *)(tpd_cdev + 0x9c0));
        ufp_tp_ops.field_8 = 0;
        pr_err("tpd_ufp_err: err lcd light change\n");
    }
    mutex_unlock((struct mutex *)(tpd_cdev + 2824));
}
