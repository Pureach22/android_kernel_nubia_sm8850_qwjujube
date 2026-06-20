__int64 __fastcall sps_pipe_reset(_QWORD *a1, unsigned int a2, __int64 a3)
{
  _QWORD *v4; // x0
  __int64 v5; // x2
  _QWORD *v6; // x20
  _QWORD *v8; // x20
  int v9; // w8
  _QWORD *v10; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_pipe_reset__rs, "sps_pipe_reset")) )
    {
      printk(&unk_261D8, "sps_pipe_reset", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM handle is NULL\n", "sps_pipe_reset");
    return 0xFFFFFFFFLL;
  }
  if ( a2 >= 0x1F )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_reset__rs_222, "sps_pipe_reset")) )
    {
      printk(&unk_24FC9, "sps_pipe_reset", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe index is invalid\n", "sps_pipe_reset");
    return 0xFFFFFFFFLL;
  }
  v4 = sps_h2bam(a1);
  if ( !v4 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_reset__rs_225, "sps_pipe_reset")) )
    {
      printk(&unk_25470, "sps_pipe_reset", v5);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM is not found by handle\n", "sps_pipe_reset");
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
  {
    if ( !print_limit_option || (v10 = v4, v9 = __ratelimit(&sps_pipe_reset__rs_226, "sps_pipe_reset"), v4 = v10, v9) )
    {
      v8 = v4;
      printk(&unk_299D3, "sps_pipe_reset", v4 + 3);
      v4 = v8;
    }
  }
  if ( *((_DWORD *)v4 + 142) <= 2u )
  {
    v6 = v4;
    ipc_log_string(v4[68], "%s: sps: BAM: %pa; pipe index:%d\n", "sps_pipe_reset", v4 + 3, a2);
    v4 = v6;
  }
  bam_pipe_reset((__int64)(v4 + 27), a2);
  return 0;
}
