__int64 __fastcall sps_get_unused_desc_num(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x20
  unsigned int unused_desc_num; // w19

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_get_unused_desc_num__rs, "sps_get_unused_desc_num")) )
    {
      printk(&unk_228D4, "sps_get_unused_desc_num", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_get_unused_desc_num");
    return 0xFFFFFFFFLL;
  }
  if ( !a2 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_get_unused_desc_num__rs_145, "sps_get_unused_desc_num")) )
    {
      printk(&unk_22D9C, "sps_get_unused_desc_num", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: result pointer is NULL\n", "sps_get_unused_desc_num");
    return 0xFFFFFFFFLL;
  }
  v5 = sps_bam_lock(a1, a2, a3);
  if ( !v5 )
    return 0xFFFFFFFFLL;
  v6 = v5;
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_get_unused_desc_num__rs_146, "sps_get_unused_desc_num")) )
  {
    printk(&unk_299D3, "sps_get_unused_desc_num", v6 + 24);
  }
  if ( !*(_DWORD *)(v6 + 568) )
    ipc_log_string(
      *(_QWORD *)(v6 + 528),
      "%s: sps: BAM: %pa; pipe index:%d\n",
      "sps_get_unused_desc_num",
      (const void *)(v6 + 24),
      *(_DWORD *)(a1 + 188));
  unused_desc_num = sps_bam_pipe_get_unused_desc_num(v6, *(unsigned int *)(a1 + 188), a2);
  raw_spin_unlock_irqrestore(v6 + 232, *(_QWORD *)(v6 + 240));
  return unused_desc_num;
}
