__int64 __fastcall bam_security_init(const void **a1, int a2, int a3, int a4)
{
  int reg_field; // w23
  unsigned int v9; // w0
  unsigned int v11; // w24
  unsigned int v12; // w23
  int v13; // w25

  if ( a1 == &_ksymtab_sps_get_free_count )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&bam_security_init__rs, "bam_security_init")) )
    {
      printk(&unk_27124, "bam_security_init", 216);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: Failed to get dev for base addr 0x%pK\n",
        "bam_security_init",
        &_ksymtab_sps_get_free_count);
    return 0xFFFFFFFFLL;
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && debug_level_option
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_security_init__rs_14, "bam_security_init")) )
    {
      printk(&unk_2526C, "bam_security_init", a1 - 24);
    }
    if ( *((_DWORD *)a1 + 88) <= 3u )
      ipc_log_string(a1[42], "%s: sps: bam=%pa 0x%pK(va)\n", "bam_security_init", a1 - 24, *a1);
    reg_field = bam_read_reg_field((__int64)a1, 1u, 0, 0xFFu);
    v9 = bam_read_reg_field((__int64)a1, 3u, 0, 0xFFu);
    if ( (unsigned int)(reg_field - 32) <= 0xFFFFFFE2 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&bam_security_init__rs_17, "bam_security_init")) )
      {
        printk(&unk_27C13, "bam_security_init", *a1);
      }
      ipc_log_string(
        a1[42],
        "%s: sps:bam 0x%pK(va) security is not supported for this BAM version 0x%x\n",
        "bam_security_init",
        *a1,
        reg_field);
      return 4294967277LL;
    }
    v11 = v9;
    if ( v9 > 0x1F )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&bam_security_init__rs_20, "bam_security_init")) )
      {
        printk(&unk_23B17, "bam_security_init", *a1);
      }
      ipc_log_string(
        a1[42],
        "%s: sps:bam 0x%pK(va) the number of pipes is more than the maximum number allowed\n",
        "bam_security_init",
        *a1);
      return 4294967277LL;
    }
    if ( v9 )
    {
      v12 = 0;
      v13 = 1;
      do
      {
        if ( (v13 & a4) != 0 )
        {
          bam_write_reg_field((__int64)a1, 0x3Au, v12, 7u, a2);
          bam_write_reg_field((__int64)a1, 0x3Au, v12, 0x1F00u, a3);
        }
        ++v12;
        v13 *= 2;
      }
      while ( v11 != v12 );
    }
    if ( a4 < 0 )
    {
      bam_write_reg_field((__int64)a1, 0x14u, 0, 7u, a2);
      bam_write_reg_field((__int64)a1, 0x14u, 0, 0x1F00u, a3);
      bam_write_reg_field((__int64)a1, 0x14u, 0, 0x80u, 0);
    }
    return 0;
  }
}
