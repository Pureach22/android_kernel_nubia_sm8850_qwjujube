__int64 __fastcall bam_exit(__int64 result, unsigned int a2)
{
  __int64 v2; // x19

  v2 = result;
  if ( result == 216 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u || (result = __ratelimit(&bam_exit__rs, "bam_exit"), (_DWORD)result) )
        result = printk(&unk_27124, "bam_exit", 216);
    }
    if ( sps )
      return ipc_log_string(
               *(_QWORD *)(sps + 272),
               "%s: Failed to get dev for base addr 0x%pK\n",
               "bam_exit",
               &_ksymtab_sps_get_free_count);
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && debug_level_option
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_exit__rs_27, "bam_exit")) )
    {
      printk(&unk_2A42C, "bam_exit", v2 - 192);
    }
    if ( *(_DWORD *)(v2 + 352) <= 3u )
      ipc_log_string(
        *(_QWORD *)(v2 + 336),
        "%s: sps: bam=%pa 0x%pK(va).ee=%d\n",
        "bam_exit",
        (const void *)(v2 - 192),
        *(const void **)v2,
        a2);
    bam_write_reg_field(v2, 0x19u, a2, 0x80000000, 0);
    bam_write_reg(v2, 0xCu, 0, 0);
    return bam_write_reg_field(v2, 0, 0, 2u, 0);
  }
  return result;
}
