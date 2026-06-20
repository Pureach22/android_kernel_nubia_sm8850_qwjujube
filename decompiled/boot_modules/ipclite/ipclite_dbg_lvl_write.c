__int64 __fastcall ipclite_dbg_lvl_write(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  unsigned int v12; // w25
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  const char *v18; // x0
  const char *v19; // x1
  int v20; // w20
  char vars0; // [xsp+0h] [xbp+0h]

  v5 = kstrtoint(a3, 0, &ipclite_debug_level);
  if ( v5 < 0 )
  {
    v20 = v5;
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_10A4E, "ipclite", "ipclite_dbg_lvl_write");
        if ( (ipclite_debug_control & 4) == 0 )
          return v20;
        goto LABEL_23;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_23:
        ipclite_inmem_log("APPS:%s:Error parsing the sysfs value", (__int64)"ERR", v6, v7, v8, v9, v10, v11, vars0);
    }
    return v20;
  }
  if ( (debug_status & 1) != 0 )
  {
    *(_DWORD *)(ipclite_dbg_info + 4) = ipclite_debug_level;
    v12 = 1;
    __dsb(0xEu);
    while ( 1 )
    {
      if ( (((unsigned int)enabled_hosts >> v12) & 1) != 0 )
      {
        if ( (ipclite_notify_core(v12, 5) & 0x80000000) != 0 )
        {
          if ( (ipclite_debug_level & 1) == 0 )
            goto LABEL_5;
          if ( (ipclite_debug_control & 1) != 0 )
          {
            printk(&unk_10F9A, "ipclite", "ipclite_dbg_lvl_write");
            if ( (ipclite_debug_control & 4) == 0 )
              goto LABEL_5;
          }
          else if ( (ipclite_debug_control & 4) == 0 )
          {
            goto LABEL_5;
          }
          v18 = "APPS:%s:Failed to send the debug info %d\n";
          v19 = "ERR";
        }
        else
        {
          if ( (ipclite_debug_level & 0x10) == 0 )
            goto LABEL_5;
          if ( (ipclite_debug_control & 1) != 0 )
          {
            printk(&unk_1092D, "ipclite", "ipclite_dbg_lvl_write");
            if ( (ipclite_debug_control & 4) == 0 )
              goto LABEL_5;
          }
          else if ( (ipclite_debug_control & 4) == 0 )
          {
            goto LABEL_5;
          }
          v18 = "APPS:%s:Debug info sent to host %d\n";
          v19 = "LOW";
        }
        ipclite_inmem_log(v18, (__int64)v19, v12, v13, v14, v15, v16, v17, vars0);
      }
LABEL_5:
      if ( ++v12 == 9 )
        return a4;
    }
  }
  printk(&unk_EEDB, "ipclite", "ipclite_dbg_lvl_write");
  return -12;
}
