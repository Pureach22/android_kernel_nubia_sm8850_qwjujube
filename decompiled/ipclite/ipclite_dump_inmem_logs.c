__int64 ipclite_dump_inmem_logs()
{
  __int64 result; // x0
  unsigned int v1; // w23
  __int64 v2; // x25
  __int64 v3; // x8
  __int64 v4; // x24
  __int64 v5; // x9
  __int64 v6; // x24
  __int64 v7; // x23
  __int64 v8; // x9

  if ( (ipclite_debug_control & 4) == 0 )
    return printk(&unk_ECFC, "ipclite", "ipclite_dump_inmem_logs");
  if ( (debug_status & 1) == 0 )
  {
    printk(&unk_EEDB, "ipclite", "is_debug_config");
    return printk(&unk_ECFC, "ipclite", "ipclite_dump_inmem_logs");
  }
  printk(&unk_112F6, "ipclite", "ipclite_dump_inmem_logs");
  result = ((__int64 (__fastcall *)(__int64))ipclite_global_atomic_load_u32)(ipclite_dbg_info + 16);
  v1 = result & 0x1FF;
  v2 = 100 * (result & 0x1FF);
  v3 = ipclite_dbg_inmem;
  v4 = 0;
  do
  {
    if ( *(_BYTE *)(v3 + v2 + v4) )
    {
      result = printk(&unk_10AF8, "ipclite", "ipclite_dump_inmem_logs");
      v3 = ipclite_dbg_inmem;
      v5 = ipclite_dbg_inmem + v2 + v4;
      *(_QWORD *)v5 = 0;
      *(_QWORD *)(v5 + 8) = 0;
      *(_QWORD *)(v5 + 16) = 0;
      *(_QWORD *)(v5 + 24) = 0;
      *(_QWORD *)(v5 + 32) = 0;
      *(_QWORD *)(v5 + 40) = 0;
      *(_QWORD *)(v5 + 48) = 0;
      *(_QWORD *)(v5 + 56) = 0;
      *(_QWORD *)(v5 + 64) = 0;
      *(_QWORD *)(v5 + 72) = 0;
      *(_QWORD *)(v5 + 80) = 0;
      *(_QWORD *)(v5 + 88) = 0;
      *(_DWORD *)(v5 + 96) = 0;
    }
    v4 += 100;
  }
  while ( v2 + v4 != 51200 );
  if ( v1 )
  {
    v6 = 0;
    v7 = 100LL * v1;
    do
    {
      if ( *(_BYTE *)(v3 + v6) )
      {
        result = printk(&unk_10AF8, "ipclite", "ipclite_dump_inmem_logs");
        v3 = ipclite_dbg_inmem;
        v8 = ipclite_dbg_inmem + v6;
        *(_QWORD *)v8 = 0;
        *(_QWORD *)(v8 + 8) = 0;
        *(_QWORD *)(v8 + 16) = 0;
        *(_QWORD *)(v8 + 24) = 0;
        *(_QWORD *)(v8 + 32) = 0;
        *(_QWORD *)(v8 + 40) = 0;
        *(_QWORD *)(v8 + 48) = 0;
        *(_QWORD *)(v8 + 56) = 0;
        *(_QWORD *)(v8 + 64) = 0;
        *(_QWORD *)(v8 + 72) = 0;
        *(_QWORD *)(v8 + 80) = 0;
        *(_QWORD *)(v8 + 88) = 0;
        *(_DWORD *)(v8 + 96) = 0;
      }
      v6 += 100;
    }
    while ( v7 != v6 );
  }
  return result;
}
