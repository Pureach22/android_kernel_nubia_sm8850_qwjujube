#include <linux/soc/qcom/panel_event_notifier.h>

void __fastcall syna_ts_panel_notifier_callback(enum panel_event_notifier_tag tag, struct panel_event_notification *notification, void *client_data)
{
  unsigned int v3;
  void *v8;

  if ( !notification )
  {
    v8 = unk_31F2D;
    printk(v8, notification, client_data);
    return;
  }
  v3 = notification->notif_type;
  if ( v3 <= 2 )
  {
    if ( v3 == DRM_PANEL_EVENT_BLANK )
    {
      if ( panel_enter_low_power == 1 )
      {
        panel_enter_low_power = 0;
        ufp_notifier_cb(0);
        printk(unk_35A7D, notification, client_data);
      }
      if ( notification->notif_data.early_trigger == 1 )
      {
        change_tp_state(3);
        return;
      }
      v8 = unk_32F7F;
      printk(v8, notification, client_data);
      return;
    }
    if ( v3 == DRM_PANEL_EVENT_UNBLANK )
    {
      if ( panel_enter_low_power == 1 )
      {
        panel_enter_low_power = 0;
        ufp_notifier_cb(0);
      }
      if ( notification->notif_data.early_trigger != 1 )
      {
        change_tp_state(2);
        return;
      }
      v8 = unk_347E1;
      printk(v8, notification, client_data);
      return;
    }
    printk(unk_3C4D0, v3, client_data);
    return;
  }
  if ( v3 == DRM_PANEL_EVENT_BLANK_LP )
  {
    panel_enter_low_power = 1;
    ufp_notifier_cb(1);
    ufp_report_lcd_state(0, 0, 0);
    return;
  }
  printk(unk_3C4D0, v3, client_data);
}
