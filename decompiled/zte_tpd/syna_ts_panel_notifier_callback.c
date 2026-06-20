void __fastcall syna_ts_panel_notifier_callback(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  void *v8; // x0
  __int64 v9; // x19
  __int64 v10; // x1
  __int64 v11; // x2

  if ( !a2 )
  {
    v8 = &unk_31F2D;
LABEL_18:
    printk(v8, a2, a3);
    return;
  }
  v3 = *(_DWORD *)a2;
  if ( *(int *)a2 <= 2 )
  {
    if ( v3 == 1 )
    {
      if ( panel_enter_low_power == 1 )
      {
        panel_enter_low_power = 0;
        v9 = a2;
        ufp_notifier_cb(0);
        printk(&unk_35A7D, v10, v11);
        a2 = v9;
      }
      if ( *(_BYTE *)(a2 + 12) == 1 )
      {
        ((void (__fastcall *)(__int64))change_tp_state)(3);
        return;
      }
      v8 = &unk_32F7F;
      goto LABEL_18;
    }
    if ( v3 == 2 )
    {
      if ( panel_enter_low_power == 1 )
      {
        panel_enter_low_power = 0;
        v4 = a2;
        ufp_notifier_cb(0);
        a2 = v4;
      }
      if ( *(_BYTE *)(a2 + 12) != 1 )
      {
        ((void (__fastcall *)(__int64))change_tp_state)(2);
        return;
      }
      v8 = &unk_347E1;
      goto LABEL_18;
    }
LABEL_11:
    printk(&unk_3C4D0, v3, a3);
    return;
  }
  if ( v3 == 3 )
  {
    panel_enter_low_power = 1;
    v5 = ufp_notifier_cb(1);
    ufp_report_lcd_state(v5, v6, v7);
    return;
  }
  if ( v3 != 4 )
    goto LABEL_11;
}
