__int64 __fastcall usb_qdss_connect_work(__int64 a1)
{
  const char **v2; // x20
  const char *v3; // x21
  unsigned int v4; // w0
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 result; // x0
  _DWORD *v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8

  if ( *(_DWORD *)(a1 - 116) )
  {
    mutex_lock(a1 + 80);
    v2 = (const char **)(a1 - 96);
    ipc_log_string(
      qdss_ipc_log,
      "%s: channel:%s opened:%d\n",
      "usb_qdss_connect_work",
      *(const char **)(a1 - 96),
      *(unsigned __int8 *)(a1 + 128));
    if ( *(_BYTE *)(a1 + 128) == 1 )
    {
      v3 = *v2;
      if ( !strcmp(*v2, "qdss_mdm") || !strcmp(v3, "qdss_sw") )
      {
LABEL_8:
        result = mutex_unlock(a1 + 80);
        v8 = *(_DWORD **)(a1 - 72);
        if ( v8 )
        {
          v9 = *(_QWORD *)(a1 - 64);
          if ( *(v8 - 1) != 840361381 )
            __break(0x8228u);
          return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v8)(v9, 0, 0, a1 - 96);
        }
        return result;
      }
      v4 = set_qdss_data_connection(a1 - 392, 1);
      if ( v4 )
      {
        printk(&unk_86F0, v4);
      }
      else
      {
        v5 = raw_spin_lock_irqsave(a1 + 64);
        v6 = *(_QWORD *)(a1 - 104);
        raw_spin_unlock_irqrestore(a1 + 64, v5);
        if ( v6 )
        {
          if ( !(unsigned int)usb_ep_queue(*(_QWORD *)(a1 - 152), v6, 2080) )
            goto LABEL_8;
          printk(&unk_82BE, "usb_qdss_connect_work");
        }
      }
    }
    return mutex_unlock(a1 + 80);
  }
  result = cancel_work_sync(a1 + 32);
  v10 = *(_QWORD *)(a1 - 128);
  if ( v10 )
  {
    result = *(_QWORD *)(v10 + 200);
    if ( result )
      return _pm_runtime_idle(result, 5);
  }
  return result;
}
