__int64 __fastcall ipclite_driver_restore(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x19
  __int64 result; // x0
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x6
  __int64 v9; // x7
  const char *v10; // x8
  unsigned int v11; // w19
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  __int64 v18; // x19
  char v19; // w10
  __int64 v20; // x9
  int v21; // w8
  unsigned int v22; // w20
  unsigned int v23; // w20
  char v24; // [xsp+0h] [xbp+0h]

  if ( !ipclite )
  {
    printk(&unk_FE88, "ipclite", "ipclite_driver_restore");
    return 4294967284LL;
  }
  v1 = ipclite;
  v2 = *(_QWORD *)(a1 + 744);
  memset(*(void **)(ipclite + 6400), 0, *(unsigned int *)(ipclite + 6408));
  result = ipcmem_init((_BYTE *)(v1 + 6344), v2);
  if ( !(_DWORD)result )
  {
    ipclite_update_channel_status();
    if ( *(_DWORD *)(ipclite + 704) == 2 )
    {
      v18 = *(_QWORD *)(ipclite + 200);
      result = mbox_send_message(v18, 0);
      if ( (result & 0x80000000) != 0 )
      {
        if ( (ipclite_debug_level & 1) == 0 )
          return result;
        if ( (ipclite_debug_control & 1) != 0 )
        {
          v23 = result;
          printk(&unk_1026B, "ipclite", "ipclite_driver_restore");
          result = v23;
          if ( (ipclite_debug_control & 4) == 0 )
            return result;
        }
        else if ( (ipclite_debug_control & 4) == 0 )
        {
          return result;
        }
        v10 = "APPS:%s:Failed to broadcast ipclite mem init signal";
        goto LABEL_7;
      }
      mbox_client_txdone(v18, 0);
    }
    v19 = ipclite_debug_level;
    v20 = ipclite_dbg_info;
    v21 = ipclite_debug_control;
    *(_DWORD *)(ipclite_dbg_info + 4) = ipclite_debug_level;
    *(_DWORD *)(v20 + 8) = v21;
    if ( (v19 & 8) != 0 )
    {
      if ( (v21 & 1) != 0 )
      {
        printk(&unk_10F46, "ipclite", "ipclite_driver_restore");
        if ( (ipclite_debug_control & 4) == 0 )
          return 0;
        goto LABEL_14;
      }
      if ( (v21 & 4) != 0 )
LABEL_14:
        ipclite_inmem_log(
          "APPS:%s:Exited ipclite hibernate successfully\n",
          (__int64)&unk_1039F,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v24);
    }
    return 0;
  }
  if ( (ipclite_debug_level & 1) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      v22 = result;
      printk(&unk_FF0D, "ipclite", "ipclite_driver_restore");
      result = v22;
      if ( (ipclite_debug_control & 4) != 0 )
        goto LABEL_6;
    }
    else if ( (ipclite_debug_control & 4) != 0 )
    {
LABEL_6:
      v10 = "APPS:%s:Failed to set up ipcmem during ipclite hibernate exit";
LABEL_7:
      v11 = result;
      ipclite_inmem_log(v10, (__int64)"ERR", v4, v5, v6, v7, v8, v9, v24);
      return v11;
    }
  }
  return result;
}
