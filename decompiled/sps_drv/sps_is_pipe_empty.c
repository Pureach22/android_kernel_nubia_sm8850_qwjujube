__int64 __fastcall sps_is_pipe_empty(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x20
  unsigned int is_empty; // w19

  if ( a1 )
  {
    if ( a2 )
    {
      v5 = sps_bam_lock(a1, a2, a3);
      if ( v5 )
      {
        v6 = *(unsigned int *)(a1 + 188);
        v7 = v5;
        is_empty = sps_bam_pipe_is_empty(v5, v6, a2);
        raw_spin_unlock_irqrestore(v7 + 232, *(_QWORD *)(v7 + 240));
        return is_empty;
      }
    }
    else
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_is_pipe_empty__rs_90, "sps_is_pipe_empty")) )
      {
        printk(&unk_22D9C, "sps_is_pipe_empty", a3);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: result pointer is NULL\n", "sps_is_pipe_empty");
    }
  }
  else
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_is_pipe_empty__rs, "sps_is_pipe_empty")) )
    {
      printk(&unk_228D4, "sps_is_pipe_empty", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_is_pipe_empty");
  }
  return 0xFFFFFFFFLL;
}
