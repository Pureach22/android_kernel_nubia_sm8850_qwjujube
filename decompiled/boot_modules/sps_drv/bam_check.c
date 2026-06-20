__int64 __fastcall bam_check(const void **a1, int *a2, __int64 a3, _DWORD *a4)
{
  unsigned int v7; // w22
  unsigned int v8; // w1
  unsigned int v9; // w3
  __int64 result; // x0
  int reg; // w22
  int reg_field; // w8
  unsigned int v13; // w22
  unsigned int v14; // w22
  int v15; // w0

  if ( a1 == &_ksymtab_sps_get_free_count )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&bam_check__rs, "bam_check")) )
    {
      printk(&unk_27124, "bam_check", 216);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: Failed to get dev for base addr 0x%pK\n",
        "bam_check",
        &_ksymtab_sps_get_free_count);
    return 0xFFFFFFFFLL;
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u )
    {
      if ( debug_level_option )
      {
        if ( !print_limit_option || (v14 = a3, v15 = __ratelimit(&bam_check__rs_23, "bam_check"), a3 = v14, v15) )
        {
          v13 = a3;
          printk(&unk_2526C, "bam_check", a1 - 24);
          a3 = v13;
        }
      }
    }
    if ( *((_DWORD *)a1 + 88) <= 3u )
    {
      v7 = a3;
      ipc_log_string(a1[42], "%s: sps: bam=%pa 0x%pK(va)\n", "bam_check", a1 - 24, *a1);
      a3 = v7;
    }
    if ( (enhd_pipe & 1) != 0 )
    {
      v8 = 27;
      v9 = 0x80000000;
    }
    else
    {
      v8 = 0;
      a3 = 0;
      v9 = 2;
    }
    bam_read_reg_field((__int64)a1, v8, a3, v9);
    reg = (unsigned __int8)bam_read_reg(a1, 1, 0);
    reg_field = bam_read_reg_field((__int64)a1, 3u, 0, 0xFFu);
    result = 0;
    *a4 = reg_field;
    *a2 = reg;
    if ( (unsigned int)(reg - 48) <= 0xFFFFFFD1 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&bam_check__rs_24, "bam_check")) )
      {
        printk(&unk_275AC, "bam_check", *a1);
      }
      ipc_log_string(a1[42], "%s: sps: bam 0x%pK(va) Invalid BAM version 0x%x\n", "bam_check", *a1, reg);
      return 4294967277LL;
    }
  }
  return result;
}
