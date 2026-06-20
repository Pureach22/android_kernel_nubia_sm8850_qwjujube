__int64 __fastcall sps_set_config(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x21
  unsigned int v8; // w22

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_set_config__rs, "sps_set_config")) )
    {
      printk(&unk_228D4, "sps_set_config", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_set_config");
    return 0xFFFFFFFFLL;
  }
  if ( !a2 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_set_config__rs_108, "sps_set_config")) )
    {
      printk(&unk_2A614, "sps_set_config", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: config pointer is NULL\n", "sps_set_config");
    return 0xFFFFFFFFLL;
  }
  v5 = sps_bam_lock(a1, a2, a3);
  if ( !v5 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_set_config__rs_109, "sps_set_config")) )
    {
      printk(&unk_2A637, "sps_set_config", v6);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM is NULL\n", "sps_set_config");
    return 0xFFFFFFFFLL;
  }
  v7 = v5;
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_set_config__rs_112, "sps_set_config")) )
  {
    printk(&unk_2AA77, "sps_set_config", v7 + 24);
  }
  if ( !*(_DWORD *)(v7 + 568) )
    ipc_log_string(
      *(_QWORD *)(v7 + 528),
      "%s: sps: BAM: %pa; pipe index:%d, config-options:0x%x\n",
      "sps_set_config",
      (const void *)(v7 + 24),
      *(_DWORD *)(a1 + 188),
      *(_DWORD *)(a2 + 52));
  v8 = sps_bam_pipe_set_params(v7, *(unsigned int *)(a1 + 188), *(unsigned int *)(a2 + 52));
  if ( !v8 )
    *(_DWORD *)(a1 + 84) = *(_DWORD *)(a2 + 52);
  raw_spin_unlock_irqrestore(v7 + 232, *(_QWORD *)(v7 + 240));
  return v8;
}
