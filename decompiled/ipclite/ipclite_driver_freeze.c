__int64 ipclite_driver_freeze()
{
  __int64 v0; // x0
  __int64 v1; // x2
  __int64 v2; // x3
  __int64 v3; // x4
  __int64 v4; // x5
  __int64 v5; // x6
  __int64 v6; // x7
  __int64 result; // x0
  char v8; // [xsp+0h] [xbp+0h]

  if ( !ipclite )
  {
    printk(&unk_FE88, "ipclite", "ipclite_driver_freeze");
    return 4294967284LL;
  }
  v0 = *(_QWORD *)(ipclite + 6432);
  *(_BYTE *)(ipclite + 6440) = 0;
  kfree(v0);
  result = 0;
  if ( (ipclite_debug_level & 8) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      printk(&unk_108F9, "ipclite", "ipclite_driver_freeze");
      if ( (ipclite_debug_control & 4) == 0 )
        return 0;
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      return 0;
    }
    ipclite_inmem_log(
      "APPS:%s:Entered ipclite hibernate successfully\n",
      (__int64)&unk_1039F,
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v8);
    return 0;
  }
  return result;
}
