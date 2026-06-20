__int64 __fastcall bam_pipe_reset(__int64 result, unsigned int a2)
{
  __int64 v2; // x19

  v2 = result;
  if ( result == 216 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&bam_pipe_reset__rs, "bam_pipe_reset"), (_DWORD)result) )
      {
        result = printk(&unk_27124, "bam_pipe_reset", 216);
      }
    }
    if ( sps )
      return ipc_log_string(
               *(_QWORD *)(sps + 272),
               "%s: Failed to get dev for base addr 0x%pK\n",
               "bam_pipe_reset",
               &_ksymtab_sps_get_free_count);
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 2u
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_reset__rs_43, "bam_pipe_reset")) )
    {
      printk(&unk_248D3, "bam_pipe_reset", v2 - 192);
    }
    if ( *(_DWORD *)(v2 + 352) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v2 + 328),
        "%s: sps: bam=%pa 0x%pK(va).pipe=%d\n",
        "bam_pipe_reset",
        (const void *)(v2 - 192),
        *(const void **)v2,
        a2);
    bam_write_reg(v2, 0x1Du, a2, 1u);
    __dsb(0xEu);
    result = bam_write_reg(v2, 0x1Du, a2, 0);
    __dsb(0xEu);
  }
  return result;
}
