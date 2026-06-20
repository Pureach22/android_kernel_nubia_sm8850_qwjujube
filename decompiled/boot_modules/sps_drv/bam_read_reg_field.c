__int64 __fastcall bam_read_reg_field(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  unsigned int register_offset; // w0
  int v8; // w21
  __int64 v9; // x0
  char v10; // w8
  char v11; // w22
  __int64 result; // x0
  __int64 v13; // x8
  const void *v14; // x3
  unsigned int v15; // w19
  unsigned int v16; // w22
  unsigned int v17; // w22
  int v18; // w8

  if ( a1 == 216 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&bam_read_reg_field__rs, "bam_read_reg_field")) )
    {
      printk(&unk_27124, "bam_read_reg_field", 216);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: Failed to get dev for base addr 0x%pK\n",
        "bam_read_reg_field",
        &_ksymtab_sps_get_free_count);
    return 0xFFFFFFFFLL;
  }
  register_offset = bam_get_register_offset(a1);
  if ( register_offset == -1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&bam_read_reg_field__rs_295, "bam_read_reg_field")) )
    {
      printk(&unk_23135, "bam_read_reg_field", a2);
    }
    ipc_log_string(*(_QWORD *)(a1 + 336), "%s: Failed to get the register offset for %d\n", "bam_read_reg_field", a2);
    return 0xFFFFFFFFLL;
  }
  v8 = register_offset;
  v9 = *(_QWORD *)a1 + register_offset;
  v10 = __clz(__rbit64(a4));
  if ( a4 )
    v11 = v10;
  else
    v11 = 32;
  result = ((unsigned int)readl(v9) & a4) >> v11;
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
  {
    if ( !print_limit_option
      || (v17 = result, v18 = __ratelimit(&bam_read_reg_field__rs_298, "bam_read_reg_field"), result = v17, v18) )
    {
      v16 = result;
      printk(&unk_28CB7, "bam_read_reg_field", *(_QWORD *)a1);
      result = v16;
    }
  }
  if ( !*(_DWORD *)(a1 + 352) )
  {
    v13 = *(_QWORD *)(a1 + 312);
    v14 = *(const void **)a1;
    v15 = result;
    ipc_log_string(
      v13,
      "%s: sps:bam 0x%pK(va) read reg 0x%x mask 0x%x r_val 0x%x\n",
      "bam_read_reg_field",
      v14,
      v8,
      a4,
      result);
    return v15;
  }
  return result;
}
