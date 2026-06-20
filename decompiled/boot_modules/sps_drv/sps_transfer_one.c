__int64 __fastcall sps_transfer_one(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  unsigned int v8; // w20
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x5
  __int64 v14; // x21
  unsigned int v15; // w19

  if ( a1 )
  {
    v8 = a3;
    if ( !(unsigned int)sps_check_iovec_flags(a5, a2, a3) )
    {
      v12 = sps_bam_lock(a1, v10, v11);
      if ( v12 )
      {
        v13 = BYTE4(a2) & 0xF | (unsigned int)a5;
        v14 = v12;
        v15 = sps_bam_pipe_transfer_one(v12, *(unsigned int *)(a1 + 188), (unsigned int)a2, v8, a4, v13);
        raw_spin_unlock_irqrestore(v14 + 232, *(_QWORD *)(v14 + 240));
        return v15;
      }
    }
  }
  else
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_transfer_one__rs, "sps_transfer_one")) )
    {
      printk(&unk_228D4, "sps_transfer_one", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_transfer_one");
  }
  return 0xFFFFFFFFLL;
}
