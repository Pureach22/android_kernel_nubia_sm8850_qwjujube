__int64 __fastcall bam_pipe_exit(__int64 result, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x19

  v3 = result;
  if ( result == 216 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&bam_pipe_exit__rs, "bam_pipe_exit"), (_DWORD)result) )
      {
        result = printk(&unk_27124, "bam_pipe_exit", 216);
      }
    }
    if ( sps )
      return ipc_log_string(
               *(_QWORD *)(sps + 272),
               "%s: Failed to get dev for base addr 0x%pK\n",
               "bam_pipe_exit",
               &_ksymtab_sps_get_free_count);
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 2u
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_exit__rs_73, "bam_pipe_exit")) )
    {
      printk(&unk_248D3, "bam_pipe_exit", v3 - 192);
    }
    if ( *(_DWORD *)(v3 + 352) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v3 + 328),
        "%s: sps: bam=%pa 0x%pK(va).pipe=%d\n",
        "bam_pipe_exit",
        (const void *)(v3 - 192),
        *(const void **)v3,
        a2);
    bam_write_reg(v3, 0x21u, a2, 0);
    bam_write_reg_field(v3, 0x19u, a3, 1 << a2, 0);
    return bam_write_reg_field(v3, 0x1Cu, a2, 2u, 0);
  }
  return result;
}
