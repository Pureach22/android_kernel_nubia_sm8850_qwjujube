__int64 __fastcall sps_bam_pipe_reg_event(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v7; // w19
  __int64 v8; // x20
  __int64 v9; // x8
  __int64 v11; // x26
  __int64 v12; // x28
  __int64 v13; // x8
  __int64 v14; // x8

  if ( (unsigned int)a2 >= 0x1F )
  {
LABEL_28:
    __break(0x5512u);
    return sps_bam_pipe_transfer_one(a1, a2, a3, a4, a5, a6);
  }
  else
  {
    v7 = a2;
    v8 = a1;
    v9 = *(_QWORD *)(a1 + 8LL * (unsigned int)a2 + 256);
    if ( *(_DWORD *)(v9 + 624) && *(_QWORD *)(a3 + 8) && (a5 = *(unsigned int *)(a3 + 4), (_DWORD)a5) )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_reg_event__rs, "sps_bam_pipe_reg_event")) )
      {
        printk(&unk_295BD, "sps_bam_pipe_reg_event", v8 + 24);
      }
      if ( v8 )
        ipc_log_string(
          *(_QWORD *)(v8 + 552),
          "%s: sps:Only callback events support for NO_Q: BAM %pa pipe %d mode %d\n",
          "sps_bam_pipe_reg_event",
          (const void *)(v8 + 24),
          v7,
          *(_DWORD *)(a3 + 4));
      return 0xFFFFFFFFLL;
    }
    else
    {
      v11 = 0;
      v12 = v9 + 272;
      do
      {
        if ( (*(_DWORD *)((_BYTE *)&opt_event_table + v11 + 4) & *(_DWORD *)a3) != 0 )
        {
          v13 = (unsigned int)(*(_DWORD *)((char *)&opt_event_table + v11) - 1);
          if ( (int)v13 < 0 )
          {
            if ( logging_option != 1 )
            {
              if ( (unsigned __int8)print_limit_option < 3u
                || (a1 = __ratelimit(&sps_bam_pipe_reg_event__rs_185, "sps_bam_pipe_reg_event"), (_DWORD)a1) )
              {
                a1 = printk(&unk_2A360, "sps_bam_pipe_reg_event", v8 + 24);
              }
            }
            if ( v8 )
              a1 = ipc_log_string(
                     *(_QWORD *)(v8 + 552),
                     "%s: sps:Negative event index: BAM %pa pipe %d mode %d\n",
                     "sps_bam_pipe_reg_event",
                     (const void *)(v8 + 24),
                     v7,
                     *(_DWORD *)(a3 + 4));
          }
          else
          {
            if ( (unsigned int)v13 > 9 )
              goto LABEL_28;
            v14 = v12 + 32 * v13;
            *(_QWORD *)v14 = *(_QWORD *)(a3 + 8);
            *(_QWORD *)(v14 + 8) = *(_QWORD *)(a3 + 16);
            *(_DWORD *)(v14 + 16) = *(_DWORD *)(a3 + 4);
            *(_QWORD *)(v14 + 24) = *(_QWORD *)(a3 + 24);
          }
        }
        v11 += 12;
      }
      while ( v11 != 96 );
      return 0;
    }
  }
}
