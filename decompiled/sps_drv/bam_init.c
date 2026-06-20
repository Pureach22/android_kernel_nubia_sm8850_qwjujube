__int64 __fastcall bam_init(
        const void **a1,
        unsigned int a2,
        unsigned __int16 a3,
        unsigned int a4,
        int *a5,
        _DWORD *a6,
        unsigned int a7)
{
  int reg_field; // w24
  unsigned int v16; // w27

  if ( a1 != &_ksymtab_sps_get_free_count )
  {
    if ( (unsigned __int8)logging_option >= 2u
      && debug_level_option
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_init__rs_2, "bam_init")) )
    {
      printk(&unk_2A42C, "bam_init", a1 - 24);
    }
    if ( *((_DWORD *)a1 + 88) <= 3u )
      ipc_log_string(a1[42], "%s: sps: bam=%pa 0x%pK(va).ee=%d\n", "bam_init", a1 - 24, *a1, a2);
    reg_field = bam_read_reg_field(a1, 1, 0, 255);
    if ( (unsigned int)(reg_field - 48) <= 0xFFFFFFD1 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&bam_init__rs_5, "bam_init")) )
      {
        printk(&unk_23AE4, "bam_init", *a1);
      }
      ipc_log_string(a1[42], "%s: sps:bam 0x%pK(va) Invalid BAM REVISION 0x%x\n", "bam_init", *a1, reg_field);
      return 4294967277LL;
    }
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 4u
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_init__rs_8, "bam_init")) )
    {
      printk(&unk_2A450, "bam_init", *a1);
    }
    if ( *((_DWORD *)a1 + 88) )
    {
      if ( !a3 )
      {
LABEL_22:
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&bam_init__rs_11, "bam_init")) )
        {
          printk(&unk_25FD6, "bam_init", *a1);
        }
        ipc_log_string(a1[42], "%s: sps:bam 0x%pK(va) summing_threshold is zero,use default 4\n", "bam_init", *a1);
        a3 = 4;
      }
    }
    else
    {
      ipc_log_string(a1[39], "%s: sps:REVISION of BAM 0x%pK is 0x%x\n", "bam_init", *a1, reg_field);
      if ( !a3 )
        goto LABEL_22;
    }
    if ( (a7 & 0x10) != 0 )
      v16 = -6145;
    else
      v16 = -2049;
    bam_write_reg_field(a1, 0, 0, 1, 1);
    bam_write_reg_field(a1, 0, 0, 1, 0);
    bam_write_reg_field(a1, 0, 0, 2, 1);
    bam_write_reg_field(a1, 0, 0, 0x80000, 0);
    bam_write_reg_field(a1, 0, 0, 393216, (a7 & 0x20) == 0);
    if ( enhd_pipe == 1 )
      bam_write_reg_field(a1, 0, 0, 0x100000, (a7 >> 6) & 1);
    bam_write_reg(a1, 6, 0, a3);
    bam_write_reg(a1, 23, 0, v16);
    bam_write_reg_field(a1, 25, a2, 0x80000000LL, 1);
    bam_write_reg(a1, 12, 0, a4);
    *a6 = bam_read_reg_field(a1, 3, 0, 255);
    *a5 = reg_field;
    return 0;
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&bam_init__rs, "bam_init")) )
  {
    printk(&unk_27124, "bam_init", 216);
  }
  if ( sps )
    ipc_log_string(
      *(_QWORD *)(sps + 272),
      "%s: Failed to get dev for base addr 0x%pK\n",
      "bam_init",
      &_ksymtab_sps_get_free_count);
  return 0xFFFFFFFFLL;
}
