__int64 __fastcall ipclite_driver_suspend(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 result; // x0
  char v9; // w9
  const char *v10; // x0
  char v11; // [xsp+0h] [xbp+0h]

  if ( pm_suspend_target_state != 3 )
  {
    if ( (ipclite_debug_level & 8) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_F242, "ipclite", "ipclite_driver_suspend");
        if ( (ipclite_debug_control & 4) == 0 )
          return 0;
      }
      else if ( (ipclite_debug_control & 4) == 0 )
      {
        return 0;
      }
      v10 = "APPS:%s:Entered ipclite suspend successfully\n";
      goto LABEL_11;
    }
    return 0;
  }
  if ( !ipclite )
  {
    printk(&unk_FE88, "ipclite", "ipclite_driver_suspend");
    return 4294967284LL;
  }
  result = 0;
  v9 = ipclite_debug_level;
  *(_BYTE *)(ipclite + 6440) = 0;
  if ( (v9 & 8) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_108C4, "ipclite", "ipclite_driver_suspend");
      if ( (ipclite_debug_control & 4) == 0 )
        return 0;
      goto LABEL_6;
    }
    if ( (ipclite_debug_control & 4) != 0 )
    {
LABEL_6:
      v10 = "APPS:%s:Entered ipclite deep sleep successfully\n";
LABEL_11:
      ipclite_inmem_log(v10, (__int64)&unk_1039F, a3, a4, a5, a6, a7, a8, v11);
      return 0;
    }
    return 0;
  }
  return result;
}
