__int64 __fastcall sps_get_config(__int64 a1, void *dest, __int64 a3)
{
  __int64 v4; // x9
  __int64 v5; // x20
  __int64 v7; // x20
  int v8; // w8
  __int64 v9; // x20
  int v10; // w8
  __int64 v11; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_get_config__rs, "sps_get_config")) )
    {
      printk(&unk_228D4, "sps_get_config", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_get_config");
    return 0xFFFFFFFFLL;
  }
  if ( !dest )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(
                                                                      &sps_get_config__rs_99,
                                                                      "sps_get_config")) )
    {
      printk(&unk_2A614, "sps_get_config", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: config pointer is NULL\n", "sps_get_config");
    return 0xFFFFFFFFLL;
  }
  v4 = *(_QWORD *)(a1 + 24);
  if ( !v4 )
  {
    if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
    {
      if ( !print_limit_option || (v9 = a1, v10 = __ratelimit(&sps_get_config__rs_102, "sps_get_config"), a1 = v9, v10) )
      {
        v7 = a1;
        printk(&unk_2A155, "sps_get_config", "sps_get_config");
        a1 = v7;
      }
    }
    if ( !sps || *(_DWORD *)(sps + 288) )
      goto LABEL_23;
    v5 = a1;
    ipc_log_string(*(_QWORD *)(sps + 248), "%s: sps:%s\n", "sps_get_config", "sps_get_config");
    goto LABEL_22;
  }
  if ( (unsigned __int8)logging_option >= 2u )
  {
    if ( (unsigned __int8)debug_level_option < 4u )
      goto LABEL_25;
    v11 = a1;
    if ( print_limit_option )
    {
      v8 = __ratelimit(&sps_get_config__rs_105, "sps_get_config");
      a1 = v11;
      if ( !v8 )
      {
LABEL_25:
        v4 = *(_QWORD *)(a1 + 24);
        if ( !v4 )
          goto LABEL_23;
        goto LABEL_5;
      }
      v4 = *(_QWORD *)(v11 + 24);
    }
    printk(&unk_2AA45, "sps_get_config", v4 + 24);
    a1 = v11;
    goto LABEL_25;
  }
LABEL_5:
  if ( !*(_DWORD *)(v4 + 568) )
  {
    v5 = a1;
    ipc_log_string(
      *(_QWORD *)(v4 + 528),
      "%s: sps: BAM: %pa; pipe index:%d; options:0x%x\n",
      "sps_get_config",
      (const void *)(v4 + 24),
      *(_DWORD *)(a1 + 188),
      *(_DWORD *)(a1 + 84));
LABEL_22:
    a1 = v5;
  }
LABEL_23:
  memcpy(dest, (const void *)(a1 + 32), 0x90u);
  return 0;
}
