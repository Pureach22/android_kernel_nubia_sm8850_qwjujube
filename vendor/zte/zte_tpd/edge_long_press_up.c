#include "defs.h"

__int64 edge_long_press_up(struct input_dev *input, int index)
{
    struct point_info_struct *point_report;
    int other_index;
    struct point_info_struct *other_point;
    bool any_other_active = false;
    int i;

    // Check bounds
    if ((unsigned int)index > 9) {
        BUG();
        return 0;
    }

    point_report = &((struct point_info_struct *)point_report_info)[index];

    // If we haven't reported edge for this touch, do nothing
    if (!point_report->field_84) {
        return 0;
    }

    // Acquire lock (mutex on tpd_cdev + 2776)
    mutex_lock((struct mutex *)(tpd_cdev + 2776));

    // Report MT up events
    input_event(input, EV_ABS, ABS_MT_SLOT, index);
    input_mt_report_slot_state(input, MT_TOOL_FINGER, 0);

    // Check if any other finger in the pairs is active
    for (i = 0; i < 10; ++i) {
        if (i != index) {
            other_point = &((struct point_info_struct *)point_report_info)[i];
            if (other_point->field_83 || other_point->field_84) {
                any_other_active = true;
                break;
            }
        }
    }

    if (!any_other_active) {
        // If no other finger is active, report BTN_TOUCH up
        input_event(input, EV_KEY, BTN_TOUCH, 0);
    }

    // Report SYN
    input_sync(input);

    // Release lock
    mutex_unlock((struct mutex *)(tpd_cdev + 2776));

    // Clear edge report flag
    point_report->field_84 = 0;

    // Optional bounds assertion
    BUG_ON((136 * index + 4) > 1360);

    // Print debug message
    printk("%s: id = %d, x = %d, y = %d\n", "edge_long_press_up", index, point_report->x, point_report->y);

    return 0;
}
