__int64 __fastcall ipclite_dbg_dump_write(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  __int64 v11; // x7
  char v12; // w8
  int v13; // w20
  char vars0; // [xsp+0h] [xbp+0h]

  v5 = kstrtoint(a3, 0, &ipclite_debug_dump);
  if ( v5 < 0 )
  {
    v13 = v5;
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_10A4E, "ipclite", "ipclite_dbg_dump_write");
        if ( (ipclite_debug_control & 4) == 0 )
          return v13;
        goto LABEL_10;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_10:
        ipclite_inmem_log("APPS:%s:Error parsing the sysfs value", (__int64)"ERR", v6, v7, v8, v9, v10, v11, vars0);
    }
    return v13;
  }
  if ( (debug_status & 1) != 0 )
  {
    v12 = ipclite_debug_dump;
    if ( (ipclite_debug_dump & 1) != 0 )
    {
      ipclite_dump_debug_struct();
      v12 = ipclite_debug_dump;
    }
    if ( (v12 & 2) != 0 )
      ipclite_dump_inmem_logs();
  }
  else
  {
    printk(&unk_EEDB, "ipclite", "ipclite_dbg_dump_write");
    return -12;
  }
  return a4;
}
