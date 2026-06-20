__int64 __fastcall sps_get_iovec(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x20
  unsigned int iovec; // w19

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_get_iovec__rs, "sps_get_iovec")) )
    {
      printk(&unk_228D4, "sps_get_iovec", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_get_iovec");
    return 0xFFFFFFFFLL;
  }
  if ( !a2 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_get_iovec__rs_213, "sps_get_iovec")) )
    {
      printk(&unk_293ED, "sps_get_iovec", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: iovec pointer is NULL\n", "sps_get_iovec");
    return 0xFFFFFFFFLL;
  }
  v5 = sps_bam_lock(a1, a2, a3);
  if ( !v5 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_get_iovec__rs_216, "sps_get_iovec")) )
    {
      printk(&unk_25470, "sps_get_iovec", v6);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM is not found by handle\n", "sps_get_iovec");
    return 0xFFFFFFFFLL;
  }
  v7 = v5;
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_get_iovec__rs_219, "sps_get_iovec")) )
  {
    printk(&unk_299D3, "sps_get_iovec", v7 + 24);
  }
  if ( !*(_DWORD *)(v7 + 568) )
    ipc_log_string(
      *(_QWORD *)(v7 + 528),
      "%s: sps: BAM: %pa; pipe index:%d\n",
      "sps_get_iovec",
      (const void *)(v7 + 24),
      *(_DWORD *)(a1 + 188));
  iovec = sps_bam_pipe_get_iovec(v7, *(unsigned int *)(a1 + 188), a2);
  raw_spin_unlock_irqrestore(v7 + 232, *(_QWORD *)(v7 + 240));
  return iovec;
}
