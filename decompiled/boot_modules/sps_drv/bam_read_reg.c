__int64 __fastcall bam_read_reg(__int64 a1, unsigned int a2)
{
  unsigned int register_offset; // w0
  int v5; // w21
  __int64 result; // x0
  __int64 v7; // x8
  const void *v8; // x3
  unsigned int v9; // w19
  int v10; // w8
  unsigned int v11; // [xsp+1Ch] [xbp+1Ch]

  if ( a1 == 216 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&bam_read_reg__rs, "bam_read_reg")) )
    {
      printk(&unk_27124, "bam_read_reg", 216);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: Failed to get dev for base addr 0x%pK\n",
        "bam_read_reg",
        &_ksymtab_sps_get_free_count);
    return 0xFFFFFFFFLL;
  }
  register_offset = bam_get_register_offset(a1);
  if ( register_offset == -1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&bam_read_reg__rs_307, "bam_read_reg")) )
    {
      printk(&unk_23135, "bam_read_reg", a2);
    }
    ipc_log_string(*(_QWORD *)(a1 + 336), "%s: Failed to get the register offset for %d\n", "bam_read_reg", a2);
    return 0xFFFFFFFFLL;
  }
  v5 = register_offset;
  result = readl(*(_QWORD *)a1 + register_offset);
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
  {
    v11 = result;
    if ( !print_limit_option || (v10 = __ratelimit(&bam_read_reg__rs_308, "bam_read_reg"), result = v11, v10) )
    {
      printk(&unk_29255, "bam_read_reg", *(_QWORD *)a1);
      result = v11;
    }
  }
  if ( !*(_DWORD *)(a1 + 352) )
  {
    v7 = *(_QWORD *)(a1 + 312);
    v8 = *(const void **)a1;
    v9 = result;
    ipc_log_string(v7, "%s: sps:bam 0x%pK(va) offset 0x%x reg 0x%x r_val 0x%x\n", "bam_read_reg", v8, v5, a2, result);
    return v9;
  }
  return result;
}
