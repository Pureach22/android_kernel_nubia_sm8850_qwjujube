__int64 __fastcall ipclite_driver_resume(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  unsigned int v9; // w21
  __int16 v10; // w9
  bool v11; // zf
  __int64 v12; // x19
  __int64 result; // x0
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  const char *v20; // x0
  unsigned int v21; // w19
  unsigned int v22; // w20
  char v23; // [xsp+0h] [xbp+0h]

  if ( pm_suspend_target_state != 3 )
  {
    if ( (ipclite_debug_level & 8) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_1105F, "ipclite", "ipclite_driver_resume");
        if ( (ipclite_debug_control & 4) == 0 )
          return 0;
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        return 0;
      }
      v20 = "APPS:%s:Resumed from ipclite suspend successfully\n";
      goto LABEL_30;
    }
    return 0;
  }
  v8 = ipclite;
  if ( !ipclite )
  {
    printk(&unk_FE88, "ipclite", "ipclite_driver_resume");
    return 4294967284LL;
  }
  if ( *(_DWORD *)(ipclite + 6424) )
  {
    v9 = 0;
    do
    {
      ipclite_global_atomic_store_i32(*(_QWORD *)(*(_QWORD *)(v8 + 6432) + 8LL * (int)v9) + 28LL, 0);
      v8 = ipclite;
      ++v9;
    }
    while ( v9 < *(_DWORD *)(ipclite + 6424) );
  }
  ipclite_update_channel_status();
  v10 = enabled_hosts;
  if ( (enabled_hosts & 1) != 0 )
  {
    **(_DWORD **)(*(_QWORD *)(v8 + 16) + 16LL) = 0;
    **(_DWORD **)(*(_QWORD *)(v8 + 24) + 8LL) = 0;
    v10 = enabled_hosts;
    if ( (enabled_hosts & 2) == 0 )
    {
LABEL_8:
      if ( (v10 & 4) == 0 )
        goto LABEL_9;
      goto LABEL_35;
    }
  }
  else if ( (enabled_hosts & 2) == 0 )
  {
    goto LABEL_8;
  }
  **(_DWORD **)(*(_QWORD *)(v8 + 720) + 16LL) = 0;
  **(_DWORD **)(*(_QWORD *)(v8 + 728) + 8LL) = 0;
  v10 = enabled_hosts;
  if ( (enabled_hosts & 4) == 0 )
  {
LABEL_9:
    if ( (v10 & 8) == 0 )
      goto LABEL_10;
    goto LABEL_36;
  }
LABEL_35:
  **(_DWORD **)(*(_QWORD *)(v8 + 1424) + 16LL) = 0;
  **(_DWORD **)(*(_QWORD *)(v8 + 1432) + 8LL) = 0;
  v10 = enabled_hosts;
  if ( (enabled_hosts & 8) == 0 )
  {
LABEL_10:
    if ( (v10 & 0x10) == 0 )
      goto LABEL_11;
    goto LABEL_37;
  }
LABEL_36:
  **(_DWORD **)(*(_QWORD *)(v8 + 2128) + 16LL) = 0;
  **(_DWORD **)(*(_QWORD *)(v8 + 2136) + 8LL) = 0;
  v10 = enabled_hosts;
  if ( (enabled_hosts & 0x10) == 0 )
  {
LABEL_11:
    if ( (v10 & 0x20) == 0 )
      goto LABEL_12;
    goto LABEL_38;
  }
LABEL_37:
  **(_DWORD **)(*(_QWORD *)(v8 + 2832) + 16LL) = 0;
  **(_DWORD **)(*(_QWORD *)(v8 + 2840) + 8LL) = 0;
  v10 = enabled_hosts;
  if ( (enabled_hosts & 0x20) == 0 )
  {
LABEL_12:
    if ( (v10 & 0x40) == 0 )
      goto LABEL_13;
    goto LABEL_39;
  }
LABEL_38:
  **(_DWORD **)(*(_QWORD *)(v8 + 3536) + 16LL) = 0;
  **(_DWORD **)(*(_QWORD *)(v8 + 3544) + 8LL) = 0;
  v10 = enabled_hosts;
  if ( (enabled_hosts & 0x40) == 0 )
  {
LABEL_13:
    if ( (v10 & 0x80) == 0 )
      goto LABEL_14;
    goto LABEL_40;
  }
LABEL_39:
  **(_DWORD **)(*(_QWORD *)(v8 + 4240) + 16LL) = 0;
  **(_DWORD **)(*(_QWORD *)(v8 + 4248) + 8LL) = 0;
  v10 = enabled_hosts;
  if ( (enabled_hosts & 0x80) == 0 )
  {
LABEL_14:
    if ( (v10 & 0x100) == 0 )
      goto LABEL_16;
    goto LABEL_15;
  }
LABEL_40:
  **(_DWORD **)(*(_QWORD *)(v8 + 4944) + 16LL) = 0;
  **(_DWORD **)(*(_QWORD *)(v8 + 4952) + 8LL) = 0;
  if ( (enabled_hosts & 0x100) != 0 )
  {
LABEL_15:
    **(_DWORD **)(*(_QWORD *)(v8 + 5648) + 16LL) = 0;
    **(_DWORD **)(*(_QWORD *)(v8 + 5656) + 8LL) = 0;
  }
LABEL_16:
  if ( (feature_mask & 4) != 0 )
    memset(*(void **)(v8 + 6448), 0, 0x400u);
  v11 = *(_DWORD *)(v8 + 704) == 2;
  *(_BYTE *)(v8 + 6440) = 1;
  if ( !v11 )
  {
LABEL_22:
    if ( (ipclite_debug_level & 8) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_FB1F, "ipclite", "ipclite_driver_resume");
        if ( (ipclite_debug_control & 4) == 0 )
          return 0;
        goto LABEL_25;
      }
      if ( (ipclite_debug_control & 4) != 0 )
      {
LABEL_25:
        v20 = "APPS:%s:Exited ipclite deep sleep successfully\n";
LABEL_30:
        ipclite_inmem_log(v20, (__int64)&unk_1039F, a3, a4, a5, a6, a7, a8, v23);
        return 0;
      }
    }
    return 0;
  }
  v12 = *(_QWORD *)(v8 + 200);
  result = mbox_send_message(v12, 0);
  if ( (result & 0x80000000) == 0 )
  {
    mbox_client_txdone(v12, 0);
    goto LABEL_22;
  }
  if ( (ipclite_debug_level & 1) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      v22 = result;
      printk(&unk_1026B, "ipclite", "ipclite_driver_resume");
      result = v22;
      if ( (ipclite_debug_control & 4) != 0 )
        goto LABEL_45;
    }
    else if ( (ipclite_debug_control & 4) != 0 )
    {
LABEL_45:
      v21 = result;
      ipclite_inmem_log(
        "APPS:%s:Failed to broadcast ipclite mem init signal",
        (__int64)"ERR",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v23);
      return v21;
    }
  }
  return result;
}
