__int64 __fastcall sps_pipe_pending_desc(_QWORD *a1, unsigned int a2, _BYTE *a3)
{
  _QWORD *v5; // x0
  __int64 v6; // x2
  __int64 v7; // x1
  _QWORD *v8; // x21
  _QWORD *v10; // x21
  int v11; // w8
  _QWORD *v12; // [xsp+18h] [xbp+18h]

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_pending_desc__rs, "sps_pipe_pending_desc")) )
    {
      printk(&unk_261D8, "sps_pipe_pending_desc", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM handle is NULL\n", "sps_pipe_pending_desc");
    return 0xFFFFFFFFLL;
  }
  if ( a2 >= 0x1F )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_pending_desc__rs_230, "sps_pipe_pending_desc")) )
    {
      printk(&unk_24FC9, "sps_pipe_pending_desc", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe index is invalid\n", "sps_pipe_pending_desc");
    return 0xFFFFFFFFLL;
  }
  if ( !a3 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_pending_desc__rs_231, "sps_pipe_pending_desc")) )
    {
      printk(&unk_22973, "sps_pipe_pending_desc", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: input flag is NULL\n", "sps_pipe_pending_desc");
    return 0xFFFFFFFFLL;
  }
  v5 = sps_h2bam(a1);
  if ( !v5 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_pending_desc__rs_234, "sps_pipe_pending_desc")) )
    {
      printk(&unk_22992, "sps_pipe_pending_desc", v6);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: :BAM is not found by handle\n", "sps_pipe_pending_desc");
    return 0xFFFFFFFFLL;
  }
  v7 = a2;
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
  {
    if ( !print_limit_option
      || (v12 = v5, v11 = __ratelimit(&sps_pipe_pending_desc__rs_237, "sps_pipe_pending_desc"), v5 = v12, v7 = a2, v11) )
    {
      v10 = v5;
      printk(&unk_299D3, "sps_pipe_pending_desc", v5 + 3);
      v5 = v10;
      v7 = a2;
    }
  }
  if ( !*((_DWORD *)v5 + 142) )
  {
    v8 = v5;
    ipc_log_string(v5[66], "%s: sps: BAM: %pa; pipe index:%d\n", "sps_pipe_pending_desc", v5 + 3, a2);
    v5 = v8;
    v7 = a2;
  }
  *a3 = sps_bam_pipe_pending_desc(v5, v7) & 1;
  return 0;
}
