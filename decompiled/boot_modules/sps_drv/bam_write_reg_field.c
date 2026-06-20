__int64 __fastcall bam_write_reg_field(__int64 result, unsigned int a2, __int64 a3, unsigned int a4, int a5)
{
  _QWORD *v5; // x19
  unsigned int register_offset; // w0
  __int64 v10; // x24
  int v11; // w20
  __int64 v12; // x0
  char v13; // w8
  char v14; // w21
  unsigned int v15; // w21
  int v16; // w22

  v5 = (_QWORD *)result;
  if ( result == 216 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&bam_write_reg_field__rs, "bam_write_reg_field"), (_DWORD)result) )
      {
        result = printk(&unk_27124, "bam_write_reg_field", 216);
      }
    }
    if ( sps )
      return ipc_log_string(
               *(_QWORD *)(sps + 272),
               "%s: Failed to get dev for base addr 0x%pK\n",
               "bam_write_reg_field",
               &_ksymtab_sps_get_free_count);
  }
  else
  {
    register_offset = bam_get_register_offset(result);
    if ( register_offset == -1 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&bam_write_reg_field__rs_301, "bam_write_reg_field")) )
      {
        printk(&unk_23135, "bam_write_reg_field", a2);
      }
      return ipc_log_string(v5[42], "%s: Failed to get the register offset for %d\n", "bam_write_reg_field", a2);
    }
    else
    {
      v10 = register_offset;
      v11 = register_offset;
      v12 = *v5 + register_offset;
      v13 = __clz(__rbit64(a4));
      if ( a4 )
        v14 = v13;
      else
        v14 = 32;
      v15 = a5 << v14;
      v16 = readl(v12) & ~a4;
      result = writel(v16 | v15, *v5 + v10);
      if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
      {
        if ( !print_limit_option
          || (result = __ratelimit(&bam_write_reg_field__rs_302, "bam_write_reg_field"), (_DWORD)result) )
        {
          result = printk(&unk_2A0F6, "bam_write_reg_field", *v5);
        }
      }
      if ( !*((_DWORD *)v5 + 88) )
        return ipc_log_string(
                 v5[39],
                 "%s: sps:bam 0x%pK(va) write reg 0x%x w_val 0x%x\n",
                 "bam_write_reg_field",
                 (const void *)*v5,
                 v11,
                 v16 | v15);
    }
  }
  return result;
}
