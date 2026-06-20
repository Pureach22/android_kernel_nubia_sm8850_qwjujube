__int64 __fastcall sps_free_mem(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v7; // x19
  __int64 v8; // x21
  __int64 v9; // x20
  __int64 v10; // x21
  __int64 v11; // x20
  __int64 v12; // x19
  __int64 v13; // x21
  int v14; // w0
  int v15; // w8
  __int64 v16; // x20
  __int64 v17; // x21
  int v18; // w0
  int v19; // w8
  __int64 v20; // x20
  int v21; // w0

  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
  {
    if ( !print_limit_option
      || (v12 = a1, v13 = a2, v14 = __ratelimit(&sps_free_mem__rs, "sps_free_mem"), a2 = v13, v15 = v14, a1 = v12, v15) )
    {
      v7 = a1;
      v8 = a2;
      printk(&unk_299F7, "sps_free_mem", a3);
      a1 = v7;
      a2 = v8;
    }
  }
  if ( sps && !*(_DWORD *)(sps + 288) )
  {
    v4 = a1;
    v5 = a2;
    ipc_log_string(*(_QWORD *)(sps + 248), "%s: sps: Enter\n", "sps_free_mem");
    a1 = v4;
    a2 = v5;
    if ( !v5 )
      goto LABEL_12;
  }
  else if ( !a2 )
  {
    goto LABEL_12;
  }
  if ( *(_QWORD *)(a2 + 8) != 3735928559LL )
  {
    if ( a1 )
    {
      if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
      {
        if ( !print_limit_option
          || (v16 = a1,
              v17 = a2,
              v18 = __ratelimit(&sps_free_mem__rs_142, "sps_free_mem"),
              a2 = v17,
              v19 = v18,
              a1 = v16,
              v19) )
        {
          v9 = a1;
          v10 = a2;
          printk(&unk_28042, "sps_free_mem", *(unsigned int *)(a1 + 188));
          a1 = v9;
          a2 = v10;
        }
      }
      if ( !sps || *(_DWORD *)(sps + 288) > 2u )
        goto LABEL_23;
      v3 = a2;
      ipc_log_string(
        *(_QWORD *)(sps + 264),
        "%s: sps:free pipe memory for pipe %d\n",
        "sps_free_mem",
        *(_DWORD *)(a1 + 188));
    }
    else
    {
      if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
      {
        if ( !print_limit_option || (v20 = a2, v21 = __ratelimit(&sps_free_mem__rs_139, "sps_free_mem"), a2 = v20, v21) )
        {
          v11 = a2;
          printk(&unk_29A09, "sps_free_mem", a3);
          a2 = v11;
        }
      }
      if ( !sps || *(_DWORD *)(sps + 288) > 2u )
        goto LABEL_23;
      v3 = a2;
      ipc_log_string(*(_QWORD *)(sps + 264), "%s: sps: free pipe memory\n", "sps_free_mem");
    }
    a2 = v3;
LABEL_23:
    sps_mem_free_io(*(_QWORD *)(a2 + 8), *(unsigned int *)(a2 + 24));
    return 0;
  }
LABEL_12:
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_free_mem__rs_136, "sps_free_mem")) )
  {
    printk(&unk_24F51, "sps_free_mem", a3);
  }
  if ( sps )
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: invalid memory to free\n", "sps_free_mem");
  return 0xFFFFFFFFLL;
}
