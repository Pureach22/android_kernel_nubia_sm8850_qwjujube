__int64 __fastcall get_global_partition_info_v0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int *v8; // x8
  __int64 v9; // x4
  char v10; // w9
  __int64 v11; // x5
  __int64 v13; // x20
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !ipclite )
  {
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_1054E, "ipclite", "get_global_partition_info_v0");
        if ( (ipclite_debug_control & 4) == 0 )
          return 4294967284LL;
        goto LABEL_11;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_11:
        ipclite_inmem_log("APPS:%s:IPCLite not initialized\n", (__int64)"ERR", a3, a4, a5, a6, a7, a8, vars0);
    }
    return 4294967284LL;
  }
  if ( a1 )
  {
    v8 = *(unsigned int **)(ipclite + 6416);
    v9 = (__int64)v8 + v8[1];
    *(_QWORD *)a1 = v9;
    v10 = ipclite_debug_level;
    v11 = v8[2];
    *(_DWORD *)(a1 + 8) = v11;
    *(_DWORD *)(a1 + 12) = v8[3];
    if ( (v10 & 0x10) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        v13 = a1;
        printk(&unk_FCA2, "ipclite", "get_global_partition_info_v0");
        a1 = v13;
        if ( (ipclite_debug_control & 4) == 0 )
          return 0;
        goto LABEL_6;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_6:
        ipclite_inmem_log(
          "APPS:%s:base = %p, size= %u ",
          (__int64)"LOW",
          *(_QWORD *)a1,
          *(unsigned int *)(a1 + 8),
          v9,
          v11,
          a7,
          a8,
          vars0);
    }
    return 0;
  }
  return 4294967274LL;
}
