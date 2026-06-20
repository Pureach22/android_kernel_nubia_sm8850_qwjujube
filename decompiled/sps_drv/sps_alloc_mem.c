__int64 __fastcall sps_alloc_mem(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  _QWORD *v5; // x21
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x21
  __int64 v9; // x21
  __int64 v10; // x21
  int v11; // w8
  __int64 v12; // x21
  int v13; // w0
  __int64 v14; // [xsp+18h] [xbp+18h]

  if ( !sps )
    return 4294967277LL;
  if ( *(_DWORD *)(sps + 48) )
  {
    if ( !a3 || !*(_DWORD *)(a3 + 24) )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_alloc_mem__rs_122, "sps_alloc_mem")) )
      {
        printk(&unk_266B5, "sps_alloc_mem", a3);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: invalid memory buffer address or size\n", "sps_alloc_mem");
      return 0xFFFFFFFFLL;
    }
    if ( a1 )
    {
      if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
      {
        v14 = a1;
        if ( !print_limit_option
          || (v10 = a3, v11 = __ratelimit(&sps_alloc_mem__rs_128, "sps_alloc_mem"), a1 = v14, a3 = v10, v11) )
        {
          v8 = a3;
          printk(&unk_22DBF, "sps_alloc_mem", *(unsigned int *)(a1 + 188));
          a1 = v14;
          a3 = v8;
        }
      }
      if ( !sps || *(_DWORD *)(sps + 288) > 2u )
        goto LABEL_27;
      v3 = a3;
      ipc_log_string(
        *(_QWORD *)(sps + 264),
        "%s: sps:allocate pipe memory for pipe %d\n",
        "sps_alloc_mem",
        *(_DWORD *)(a1 + 188));
    }
    else
    {
      if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
      {
        if ( !print_limit_option
          || (v12 = a3, v13 = __ratelimit(&sps_alloc_mem__rs_125, "sps_alloc_mem"), a3 = v12, v13) )
        {
          v9 = a3;
          printk(&unk_24A49, "sps_alloc_mem", a3);
          a3 = v9;
        }
      }
      if ( !sps || *(_DWORD *)(sps + 288) > 2u )
        goto LABEL_27;
      v3 = a3;
      ipc_log_string(*(_QWORD *)(sps + 264), "%s: sps: allocate pipe memory before setup pipe\n", "sps_alloc_mem");
    }
    a3 = v3;
LABEL_27:
    v5 = (_QWORD *)a3;
    v6 = sps_mem_alloc_io(*(unsigned int *)(a3 + 24));
    v5[1] = v6;
    if ( v6 != 3735928559LL )
    {
      *v5 = spsi_get_mem_ptr(v6);
      return 0;
    }
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_alloc_mem__rs_131, "sps_alloc_mem")) )
    {
      printk(&unk_24A7C, "sps_alloc_mem", v7);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: invalid address of allocated memory\n", "sps_alloc_mem");
    return 0xFFFFFFFFLL;
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_alloc_mem__rs, "sps_alloc_mem")) )
  {
    printk(&unk_28D16, "sps_alloc_mem", a3);
  }
  if ( sps )
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps driver is not ready\n", "sps_alloc_mem");
  return 4294967285LL;
}
