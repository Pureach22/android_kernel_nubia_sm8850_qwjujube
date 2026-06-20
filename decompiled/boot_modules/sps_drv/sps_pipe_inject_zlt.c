__int64 __fastcall sps_pipe_inject_zlt(_QWORD *a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // w20
  _QWORD *v5; // x0
  __int64 v6; // x2
  _QWORD *v7; // x19
  __int64 v8; // x1
  __int64 v9; // x2

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_inject_zlt__rs, "sps_pipe_inject_zlt")) )
    {
      printk(&unk_261D8, "sps_pipe_inject_zlt", a3);
    }
    if ( sps )
    {
      v3 = -1;
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM handle is NULL\n", "sps_pipe_inject_zlt");
      return v3;
    }
    return (unsigned int)-1;
  }
  if ( a2 >= 0x1F )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_inject_zlt__rs_250, "sps_pipe_inject_zlt")) )
    {
      printk(&unk_24FC9, "sps_pipe_inject_zlt", a3);
    }
    if ( sps )
    {
      v3 = -1;
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe index is invalid\n", "sps_pipe_inject_zlt");
      return v3;
    }
    return (unsigned int)-1;
  }
  v5 = sps_h2bam(a1);
  if ( !v5 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_inject_zlt__rs_251, "sps_pipe_inject_zlt")) )
    {
      printk(&unk_25470, "sps_pipe_inject_zlt", v6);
    }
    if ( sps )
    {
      v3 = -1;
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM is not found by handle\n", "sps_pipe_inject_zlt");
      return v3;
    }
    return (unsigned int)-1;
  }
  v7 = v5;
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_pipe_inject_zlt__rs_252, "sps_pipe_inject_zlt")) )
  {
    printk(&unk_299D3, "sps_pipe_inject_zlt", v7 + 3);
  }
  v8 = a2;
  if ( !*((_DWORD *)v7 + 142) )
  {
    ipc_log_string(v7[66], "%s: sps: BAM: %pa; pipe index:%d\n", "sps_pipe_inject_zlt", v7 + 3, a2);
    v8 = a2;
  }
  v3 = sps_bam_pipe_inject_zlt(v7, v8);
  if ( v3 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_pipe_inject_zlt__rs_253, "sps_pipe_inject_zlt")) )
    {
      printk(&unk_2589E, "sps_pipe_inject_zlt", v9);
    }
    ipc_log_string(v7[69], "%s: sps: failed to inject a ZLT\n", "sps_pipe_inject_zlt");
  }
  return v3;
}
