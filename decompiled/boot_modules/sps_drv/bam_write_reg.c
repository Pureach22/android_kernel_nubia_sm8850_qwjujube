__int64 __fastcall bam_write_reg(__int64 result, unsigned int a2, __int64 a3, unsigned int a4)
{
  _QWORD *v4; // x19
  unsigned int register_offset; // w0
  int v8; // w21

  v4 = (_QWORD *)result;
  if ( result == 216 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&bam_write_reg__rs, "bam_write_reg"), (_DWORD)result) )
      {
        result = printk(&unk_27124, "bam_write_reg", 216);
      }
    }
    if ( sps )
      return ipc_log_string(
               *(_QWORD *)(sps + 272),
               "%s: Failed to get dev for base addr 0x%pK\n",
               "bam_write_reg",
               &_ksymtab_sps_get_free_count);
  }
  else
  {
    register_offset = bam_get_register_offset(result);
    if ( register_offset == -1 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&bam_write_reg__rs_305, "bam_write_reg")) )
      {
        printk(&unk_23135, "bam_write_reg", a2);
      }
      return ipc_log_string(v4[42], "%s: Failed to get the register offset for %d\n", "bam_write_reg", a2);
    }
    else
    {
      v8 = register_offset;
      result = writel(a4, *v4 + register_offset);
      if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
      {
        if ( !print_limit_option || (result = __ratelimit(&bam_write_reg__rs_306, "bam_write_reg"), (_DWORD)result) )
          result = printk(&unk_2A0F6, "bam_write_reg", *v4);
      }
      if ( !*((_DWORD *)v4 + 88) )
        return ipc_log_string(
                 v4[39],
                 "%s: sps:bam 0x%pK(va) write reg 0x%x w_val 0x%x\n",
                 "bam_write_reg",
                 (const void *)*v4,
                 v8,
                 a4);
    }
  }
  return result;
}
