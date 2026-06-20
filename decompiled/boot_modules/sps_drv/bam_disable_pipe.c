__int64 __fastcall bam_disable_pipe(__int64 result, unsigned int a2)
{
  __int64 v2; // x19

  v2 = result;
  if ( result == 216 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&bam_disable_pipe__rs, "bam_disable_pipe"), (_DWORD)result) )
      {
        result = printk(&unk_27124, "bam_disable_pipe", 216);
      }
    }
    if ( sps )
      return ipc_log_string(
               *(_QWORD *)(sps + 272),
               "%s: Failed to get dev for base addr 0x%pK\n",
               "bam_disable_pipe",
               &_ksymtab_sps_get_free_count);
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 2u
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_disable_pipe__rs_46, "bam_disable_pipe")) )
    {
      printk(&unk_2364D, "bam_disable_pipe", v2);
    }
    if ( *(_DWORD *)(v2 + 352) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v2 + 328),
        "%s: sps: bam=0x%pK(va).pipe=%d\n",
        "bam_disable_pipe",
        (const void *)v2,
        a2);
    result = bam_write_reg_field(v2, 0x1Cu, a2, 2u, 0);
    __dsb(0xEu);
  }
  return result;
}
