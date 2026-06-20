__int64 __fastcall sps_flow_off(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  unsigned int v5; // w1
  __int64 v6; // x19

  if ( a1 )
  {
    v4 = sps_bam_lock(a1, a2, a3);
    if ( v4 )
    {
      v5 = *(_DWORD *)(a1 + 188);
      v6 = v4;
      bam_pipe_halt(v4 + 216, v5, 1);
      raw_spin_unlock_irqrestore(v6 + 232, *(_QWORD *)(v6 + 240));
      return 0;
    }
  }
  else
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_flow_off__rs, "sps_flow_off")) )
    {
      printk(&unk_228D4, "sps_flow_off", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_flow_off");
  }
  return 0xFFFFFFFFLL;
}
