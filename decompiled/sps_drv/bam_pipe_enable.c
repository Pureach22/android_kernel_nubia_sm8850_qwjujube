__int64 __fastcall bam_pipe_enable(__int64 result, unsigned int a2)
{
  _QWORD *v2; // x19

  v2 = (_QWORD *)result;
  if ( result == 216 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&bam_pipe_enable__rs, "bam_pipe_enable"), (_DWORD)result) )
      {
        result = printk(&unk_27124, "bam_pipe_enable", 216);
      }
    }
    if ( sps )
      return ipc_log_string(
               *(_QWORD *)(sps + 272),
               "%s: Failed to get dev for base addr 0x%pK\n",
               "bam_pipe_enable",
               &_ksymtab_sps_get_free_count);
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 2u
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_enable__rs_74, "bam_pipe_enable")) )
    {
      printk(&unk_248D3, "bam_pipe_enable", v2 - 24);
    }
    if ( *((_DWORD *)v2 + 88) <= 2u )
      ipc_log_string(v2[41], "%s: sps: bam=%pa 0x%pK(va).pipe=%d\n", "bam_pipe_enable", v2 - 24, (const void *)*v2, a2);
    result = bam_read_reg_field((__int64)v2, 0x1Cu, a2, 2u);
    if ( (_DWORD)result )
    {
      if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
      {
        if ( !print_limit_option || (result = __ratelimit(&bam_pipe_enable__rs_75, "bam_pipe_enable"), (_DWORD)result) )
          result = printk(&unk_23B6C, "bam_pipe_enable", *v2);
      }
      if ( *((_DWORD *)v2 + 88) <= 2u )
        return ipc_log_string(
                 v2[41],
                 "%s: sps:bam=0x%pK(va).pipe=%d is already enabled\n",
                 "bam_pipe_enable",
                 (const void *)*v2,
                 a2);
    }
    else
    {
      return bam_write_reg_field((__int64)v2, 0x1Cu, a2, 2u, 1);
    }
  }
  return result;
}
