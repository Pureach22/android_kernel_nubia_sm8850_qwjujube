__int64 __fastcall usb_gsi_rw_timer_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 connected_gsi; // x0
  __int64 v6; // x20
  int v7; // w0
  unsigned __int16 v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  connected_gsi = get_connected_gsi();
  if ( connected_gsi )
  {
    v6 = connected_gsi;
    if ( a2 )
    {
      v7 = kstrtou16_from_user(a2, a3, 0, &v9);
      if ( v7 )
      {
        ipc_log_string(*(_QWORD *)(v6 + 1344), "%s: Invalid value. err:%d\n", "usb_gsi_rw_timer_write", v7);
        printk(&unk_11404, "usb_gsi_rw_timer_write");
      }
      else if ( (unsigned int)v9 - 10001 <= 0xFFFFD8EF )
      {
        ipc_log_string(*(_QWORD *)(v6 + 1344), "%s: value must be > 0 and < 10000.\n", "usb_gsi_rw_timer_write");
        printk(&unk_11644, "usb_gsi_rw_timer_write");
      }
      else
      {
        *(_WORD *)(v6 + 1402) = v9;
      }
    }
    else
    {
      ipc_log_string(*(_QWORD *)(connected_gsi + 1344), "%s: buffer is NULL.\n", "usb_gsi_rw_timer_write");
    }
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
