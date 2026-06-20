__int64 __fastcall usb_gsi_rw_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 connected_gsi; // x0
  __int64 v6; // x20
  int v7; // w0
  int v8; // w8
  int v9; // w9
  __int64 v10; // x0
  __int64 v11; // x21
  __int64 v12; // x0
  _BYTE v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  connected_gsi = get_connected_gsi();
  if ( connected_gsi )
  {
    v6 = connected_gsi;
    if ( a2 )
    {
      v7 = kstrtou8_from_user(a2, a3, 0, v14);
      if ( v7 )
      {
        ipc_log_string(*(_QWORD *)(v6 + 1344), "%s: Invalid value. err:%d\n", "usb_gsi_rw_write", v7);
        printk(&unk_11404, "usb_gsi_rw_write");
      }
      else
      {
        v8 = v14[0];
        v9 = v14[0] != 0;
        if ( *(unsigned __int8 *)(v6 + 1400) == v9 )
        {
          v10 = *(_QWORD *)(v6 + 1344);
          if ( v14[0] )
            ipc_log_string(v10, "%s: RW already enabled\n", "usb_gsi_rw_write");
          else
            ipc_log_string(v10, "%s: RW already disabled\n", "usb_gsi_rw_write");
        }
        else
        {
          *(_BYTE *)(v6 + 1400) = v9;
          if ( v8 )
          {
            v11 = jiffies;
            v12 = _msecs_to_jiffies(*(unsigned __int16 *)(v6 + 1402));
            mod_timer(v6 + 1360, v12 + v11);
            ipc_log_string(*(_QWORD *)(v6 + 1344), "%s: timer initialized\n", "usb_gsi_rw_write");
          }
          else
          {
            timer_delete_sync(v6 + 1360);
            ipc_log_string(*(_QWORD *)(v6 + 1344), "%s: timer deleted\n", "usb_gsi_rw_write");
          }
        }
      }
    }
    else
    {
      ipc_log_string(*(_QWORD *)(connected_gsi + 1344), "%s: buffer is Null.\n", "usb_gsi_rw_write");
    }
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
