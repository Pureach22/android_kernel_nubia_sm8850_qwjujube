__int64 __fastcall sps_pipe_disable(_QWORD *a1, unsigned int a2, __int64 a3)
{
  _QWORD *v4; // x0
  __int64 v5; // x2
  unsigned int v6; // w1
  _QWORD *v7; // x20
  _QWORD *v9; // x20
  int v10; // w8
  _QWORD *v11; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_disable__rs, "sps_pipe_disable")) )
    {
      printk(&unk_261D8, "sps_pipe_disable", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM handle is NULL\n", "sps_pipe_disable");
    return 0xFFFFFFFFLL;
  }
  if ( a2 >= 0x1F )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_disable__rs_227, "sps_pipe_disable")) )
    {
      printk(&unk_24FC9, "sps_pipe_disable", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe index is invalid\n", "sps_pipe_disable");
    return 0xFFFFFFFFLL;
  }
  v4 = sps_h2bam(a1);
  if ( !v4 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_disable__rs_228, "sps_pipe_disable")) )
    {
      printk(&unk_25470, "sps_pipe_disable", v5);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM is not found by handle\n", "sps_pipe_disable");
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
  {
    if ( !print_limit_option
      || (v11 = v4, v10 = __ratelimit(&sps_pipe_disable__rs_229, "sps_pipe_disable"), v4 = v11, v10) )
    {
      v9 = v4;
      printk(&unk_299D3, "sps_pipe_disable", v4 + 3);
      v4 = v9;
    }
  }
  v6 = a2;
  if ( !*((_DWORD *)v4 + 142) )
  {
    v7 = v4;
    ipc_log_string(v4[66], "%s: sps: BAM: %pa; pipe index:%d\n", "sps_pipe_disable", v4 + 3, a2);
    v4 = v7;
    v6 = a2;
  }
  bam_disable_pipe((__int64)(v4 + 27), v6);
  return 0;
}
