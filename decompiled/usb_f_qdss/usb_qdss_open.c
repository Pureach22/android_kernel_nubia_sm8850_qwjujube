_UNKNOWN **__fastcall usb_qdss_open(const char *a1, void *a2, void *a3)
{
  const char *v3; // x20
  __int64 v6; // x22
  _UNKNOWN **v7; // x27
  _UNKNOWN **v8; // x22
  int v9; // w9

  v3 = a1;
  ipc_log_string(qdss_ipc_log, "%s: called for channel:%s\n", "usb_qdss_open", a1);
  if ( a3 )
  {
    v6 = raw_spin_lock_irqsave(&channel_lock);
LABEL_5:
    v7 = &usb_qdss_ch_list;
    while ( 1 )
    {
      v7 = (_UNKNOWN **)*v7;
      if ( v7 == &usb_qdss_ch_list )
        break;
      if ( !strcmp(v3, (const char *)*(v7 - 1)) )
      {
        if ( !strcmp(v3, "qdss_sw") )
        {
          if ( v7 != (_UNKNOWN **)&qdss_attr_enable_debug_inface && *(v7 - 38) )
          {
            raw_spin_unlock_irqrestore(&channel_lock, v6);
            goto LABEL_14;
          }
LABEL_4:
          ipc_log_string(qdss_ipc_log, "%s: qdss_sw not added to config, fall back to qdss_mdm\n", "usb_qdss_open");
          v3 = "qdss_mdm";
          goto LABEL_5;
        }
        raw_spin_unlock_irqrestore(&channel_lock, v6);
        if ( v7 != (_UNKNOWN **)&qdss_attr_enable_debug_inface )
        {
LABEL_14:
          v8 = v7 - 1;
          mutex_lock(v7 + 21);
          ipc_log_string(qdss_ipc_log, "%s: qdss ctx found for channel:%s\n", "usb_qdss_open", v3);
          *((_DWORD *)v7 + 56) = 0;
          v7[2] = a3;
          v7[3] = a2;
          v9 = *((_DWORD *)v7 - 7);
          *((_BYTE *)v7 + 216) = 1;
          if ( v9 )
            queue_work_on(32, v7[20], v7 + 11);
          mutex_unlock(v7 + 21);
          return v8;
        }
LABEL_17:
        ipc_log_string(qdss_ipc_log, "%s: failed to find channel:%s\n", "usb_qdss_open", v3);
        return nullptr;
      }
    }
    if ( !strcmp(v3, "qdss_sw") )
      goto LABEL_4;
    raw_spin_unlock_irqrestore(&channel_lock, v6);
    goto LABEL_17;
  }
  printk(&unk_84D4, "usb_qdss_open");
  return nullptr;
}
