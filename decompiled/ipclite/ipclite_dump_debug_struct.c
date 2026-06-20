__int64 ipclite_dump_debug_struct()
{
  __int64 result; // x0
  __int64 v1; // x21
  __int64 v2; // x23
  unsigned int v3; // w8
  __int64 v4; // x24
  __int64 v5; // x28
  __int64 v6; // x24

  if ( (ipclite_debug_control & 2) == 0 )
    return printk(&unk_EB4E, "ipclite", "ipclite_dump_debug_struct");
  if ( (debug_status & 1) == 0 )
  {
    printk(&unk_EEDB, "ipclite", "is_debug_config");
    return printk(&unk_EB4E, "ipclite", "ipclite_dump_debug_struct");
  }
  result = printk(&unk_FF74, "ipclite", "ipclite_dump_debug_struct");
  v1 = 0;
  v2 = 40;
  v3 = enabled_hosts;
  do
  {
    if ( ((v3 >> v1) & 1) != 0 )
    {
      v4 = ipclite_dbg_struct;
      printk(&unk_100A0, "ipclite", "ipclite_dump_debug_struct");
      printk(&unk_E69A, "ipclite", "ipclite_dump_debug_struct");
      printk(&unk_10AA6, "ipclite", "ipclite_dump_debug_struct");
      result = printk(&unk_10BFD, "ipclite", "ipclite_dump_debug_struct");
      v3 = enabled_hosts;
      v5 = 0;
      v6 = v4 + v2;
      do
      {
        if ( ((v3 >> v5) & 1) != 0 )
        {
          printk(&unk_1068E, "ipclite", "ipclite_dump_debug_struct");
          printk(&unk_F05C, "ipclite", "ipclite_dump_debug_struct");
          printk(&unk_FFC6, "ipclite", "ipclite_dump_debug_struct");
          printk(&unk_EF01, "ipclite", "ipclite_dump_debug_struct");
          printk(&unk_11104, "ipclite", "ipclite_dump_debug_struct");
          printk(&unk_EB75, "ipclite", "ipclite_dump_debug_struct");
          printk(&unk_F455, "ipclite", "ipclite_dump_debug_struct");
          printk(&unk_F7FD, "ipclite", "ipclite_dump_debug_struct");
          result = printk(&unk_103A3, "ipclite", "ipclite_dump_debug_struct");
          v3 = enabled_hosts;
        }
        ++v5;
        v6 += 60;
      }
      while ( v5 != 9 );
    }
    ++v1;
    v2 += 564;
  }
  while ( v1 != 9 );
  return result;
}
